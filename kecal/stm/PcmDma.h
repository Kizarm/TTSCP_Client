#ifndef PCMDMA_H
#define PCMDMA_H
#include <stdint.h>
#include "player.h"

static constexpr int MAXPWM = 2000;
static constexpr int PWMLEN = GSMLEN * 3;

class PcmDma {
  FIFO<PText, FIFOLEN> & fifo;
  GsmStatic gsm;
  GpioClass indicator;
  volatile int delay_counter;
  uint16_t * const ptrl;
  uint16_t * const ptrh;
  uint16_t   pwmbuf [PWMLEN << 1];
  gsm_signal tmpbuf [GSMLEN];
  public:
    explicit PcmDma(FIFO<PText, FIFOLEN> & f) noexcept;
    void delay (int n=50) {
      delay_counter = n;
      while (delay_counter) {
        asm volatile ("wfi");
      }
    }
    void drq ();
};

#endif // PCMDMA_H
