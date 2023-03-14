#include "STM32F0x1.h"
#include "Temperature.h"

  /* kalibrační konstanty
  const uint16_t & t30  = * reinterpret_cast<const uint16_t * const>(0x1FFFF7B8u);
  const uint16_t & vref = * reinterpret_cast<const uint16_t * const>(0x1FFFF7BAu);
  const uint16_t & t110 = * reinterpret_cast<const uint16_t * const>(0x1FFFF7C2u);
  */
static inline void AdcCalibrate (void) {
  // Ensure that ADEN = 0
  // Clear ADEN
  if (ADC.CR.B.ADEN != RESET) {
    ADC.CR.B.ADEN = RESET;
  }
  // Launch the calibration by setting ADCAL
  ADC.CR.B.ADCAL = SET;
  // Wait until ADCAL=0
  while (ADC.CR.B.ADCAL != RESET);
  // Lépe trochu počkat.
  for (volatile int n=0; n<10000; n++) asm volatile ("nop");
}

Temperature::Temperature() noexcept : correction0(0), correction1(0), average(0) {
  RCC.APB2ENR.B.ADCEN   = SET;  // clock
  AdcCalibrate();
  ADC.CR.B.ADEN         = SET;  // power
  // Enable sensors
  ADC.CCR.modify([](ADC_Type::CCR_DEF & r) -> auto {
    r.B.TSEN   = SET;
    r.B.VREFEN = SET;
    return r.R;
  });
  for (volatile int n=0; n<10000; n++) asm volatile ("nop");
  // PCLK / 2 - jitter
  ADC.CFGR2.B.JITOFF_D2 = SET;
  // Sampling time co nejdelší 239.5, nikam nepospícháme
  ADC.SMPR.R = 7u;
  /* Předpoklad je, že napájení je 3.3V, takže nakonec nepoužito, vref cca sedí
  ADC.CHSELR.R = (1 << 17);     // interní reference
  ADC.CR.B.ADSTART = SET;
  while (ADC.CR.B.ADSTART);
  correction0 = ADC.DR.R;       // hodnota interní reference OK, ulož pro pozdější použití
  */
  ADC.CHSELR.R = (1 << 16);     // dále pak už jen teplota
  const uint16_t & t30  = * reinterpret_cast<const uint16_t * const>(0x1FFFF7B8u);
  const uint16_t & t110 = * reinterpret_cast<const uint16_t * const>(0x1FFFF7C2u);
  correction1 = 80000 / (t30 - t110);   // v tisicinach st.C
  correction0 = t30;
}
static constexpr int BK = int (0.01 * double (1L << 16));
int Temperature::meassure() {
  ADC.CR.B.ADSTART = SET;
  while (ADC.CR.B.ADSTART);
  const int td = ADC.DR.R;
  // ono to měří teplotu čipu, ta je asi o 13 st.C větší, nutno dokalibrovat
  const int tt = (correction0 - td) * correction1 + 17000;
  average = (7 * average + tt) >> 3;  // průměrování je potřeba, ADC dost lítá
  return (average * BK) >> 16;        // ven jen desetiny (dělení konstantou nahrazeno násobením)
}

