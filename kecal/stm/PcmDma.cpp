#include "STM32F0x1.h"
#include "CortexM0.h"
#include "gpio.h"
#include "PcmDma.h"

/* TIMER:
 * fs = 8000Hz, ft = 3 * fs = 24000Hz
 * reload = SystemCoreClock / ft = 48000000Hz / 24000Hz = 2000
 * PINY : +PA9[AF2], -PB0[AF2] => TIM1:CH2
 * DMA  : TIM1_UP = 5
 */
static void Dma1Ch5Init (void * addr) {
  // Configure the peripheral data register address etc
  DMA1.CPAR5.R  = reinterpret_cast<size_t> (& (TIM1.CCR2));
  DMA1.CMAR5.R  = reinterpret_cast<size_t> (addr);
  DMA1.CNDTR5.R = PWMLEN << 1;
  // Configure increment, size, interrupts and circular mode
  DMA1.CCR5.modify([](DMA1_Type::CCR5_DEF & ccr) -> auto {
    ccr.B.MINC  = 1u;
    ccr.B.MSIZE = 1u;
    ccr.B.PSIZE = 1u;
    ccr.B.DIR   = 1u;
    ccr.B.HTIE  = 1u;          // Po půlce přerušit.
    ccr.B.TCIE  = 1u;          // Po dokončení přerušit.
    ccr.B.CIRC  = 1u;
    ccr.B.EN    = 0u;
    return ccr.R;
  });
}
static PcmDma * PcmDmaInstance = nullptr;
PcmDma::PcmDma(FIFO<PText, FIFOLEN> & f) noexcept : fifo(f), gsm(), indicator(GpioPortA, 1),
    delay_counter(0), ptrl(pwmbuf), ptrh(pwmbuf + PWMLEN) {
  PcmDmaInstance = this;
  const GpioClass de (GpioPortA, 12);
  de << true;
  for (int n=0; n<(PWMLEN<<1); n++) pwmbuf[n] = MAXPWM >> 1;
  GpioClass pin1p (GpioPortA, 9, GPIO_Mode_AF);
  GpioClass pin1n (GpioPortB, 0, GPIO_Mode_AF);
  pin1p.setAF (2);
  pin1n.setAF (2);
  // 1. Enable clock peripheral
  RCC.APB2ENR.B.TIM1EN = 1u;
  RCC.AHBENR. B.DMA1EN = 1u;
  // 2. Timer
  TIM1.PSC.R  = 0u;
  TIM1.ARR.R  = MAXPWM - 1;
  TIM1.RCR.R  = 0u;
  // OC preload, CC output, Mode 6 = PWM1
  TIM1.CCMR1_Output.modify([](TIM1_Type::CCMR1_Output_DEF & r) -> auto {
    r.B.OC2PE = 1u;
    r.B.OC2M  = 6u;
    return r.R;
  });
  // povol pin + negaci
  TIM1.CCER.modify([](TIM1_Type::CCER_DEF & r) -> auto {
    r.B.CC2E  = 1u;
    r.B.CC2NE = 1u;
    return r.R;
  });
  // Set Output, dead time
  TIM1.BDTR.modify([](TIM1_Type::BDTR_DEF & r) -> auto {
    r.B.DTG  = 48u;    // dead: 1 us
    r.B.MOE  = 1u;     // Main output enable
  //r.B.OSSR = 1u;     // Off-state selection for Run mode - TODO
    return r.R;
  });
  // Preload
  TIM1.CR1.modify([](TIM1_Type::CR1_DEF & r) -> auto {
    r.B.ARPE = 1u; // TIM1_ARR register is buffered
    r.B.URS  = 1u; // Only counter overflow/underflow generates an update DMA request
    return r.R;
  });
  /* Update DMA request enable
   * Spustíme DMA - sice budou dlouhé buffery, ale přerušení jen po 20ms */
  TIM1.EGR.B.UG   = 1u; // Reinitialize the counter and generates an update of the registers
  TIM1.DIER.B.UDE = 1u; // Update DMA request enabled
  Dma1Ch5Init (pwmbuf);
  // 3. NVIC
  NVIC_EnableIRQ (DMA1_CH4_5_6_7_DMA2_CH3_4_5_IRQn);
  TIM1.CR1.R     |= 1u; // enable TIM1 (překladač bohužel bere poslední bit jako half, registr to neunese)
  DMA1.CCR5.R    |= 1u; // enable DMA  (dtto)
}
static constexpr int      INPUT_BIT_RANGE = 16;
static constexpr unsigned SIGMA_MASK      = (1u << (INPUT_BIT_RANGE  + 0)) - 1u;
static constexpr unsigned SIGNED_OFFEST   = (1u << (INPUT_BIT_RANGE  - 1));
 // Předpokládá se na vstupu signed int o šířce INPUT_BIT_RANGE
 // přičemž 0 na vstupu odpovídá MAXPWM / 2 na výstupu. Vypadá to divně, ale funguje.
static unsigned pwm_sd (const int input) {
  static unsigned sigma  = 0;   // podstatné je, že proměnná je statická
  const  unsigned sample = (input + SIGNED_OFFEST) * MAXPWM;
  sigma &= SIGMA_MASK;          // v podstatě se odečte hodnota PWM
  sigma += sample;              // integrace prostým součtem
  return sigma  >> INPUT_BIT_RANGE;
}
void PcmDma::drq() {      // obal ma přerušení od DMA uvnitř třídy
  DMA1_Type::ISR_DEF status (DMA1.ISR);
  DMA1.IFCR.R = status.R; // clear flags
  uint16_t * const dptr = status.B.HTIF5 ? ptrl : ptrh;
  PText source;
  if (fifo.Read(source)) {
    +indicator;           // měření doby trvání dekódování rámce
    gsm_frame tmp;
    memcpy (tmp, source.get(), sizeof(gsm_frame));
    gsm.decode(tmp, tmpbuf);
    int k = 0;
    for (int n=0; n<GSMLEN; n++) {
      const int16_t s = tmpbuf[n];
      dptr [k++] = pwm_sd (s);    // vyzkoušená metoda jak vylepšit PWM
      dptr [k++] = pwm_sd (s);    // pokud máme frekvenci PWM větší
      dptr [k++] = pwm_sd (s);    // než vzorkovací frekvence signálu ft = n * fs, n = 3
    }
    -indicator;
  } else {
    // vyplnit tichem - je sice zbytečné dělat to opakovaně, ale nevadí
    for (int n=0; n<PWMLEN; n++) dptr[n] = MAXPWM >> 1;
    if (delay_counter) delay_counter -= 1;
  }
}
// Přerušení od DMA
extern "C" void DMA1_CH4_5_6_7_DMA2_CH3_4_5_IRQHandler (void) {
  if (PcmDmaInstance) PcmDmaInstance->drq();
}
