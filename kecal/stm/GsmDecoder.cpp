#include "PcmDma.h"
#include "GsmDecoder.h"

GsmDecoder::GsmDecoder(FIFO<PText, FIFOLEN> & f) noexcept : AbstractChain(), fifo(f), gsm() {
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
bool GsmDecoder::send(uint16_t * dptr, const int len) {
  PText source;
  if (fifo.Read(source)) {
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
    return true;
  }
  return false;
}
