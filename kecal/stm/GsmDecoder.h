#ifndef GSMDECODER_H
#define GSMDECODER_H
#include "player.h"
#include "AbstractChain.h"

class GsmDecoder : public AbstractChain {
  FIFO<PText, FIFOLEN> & fifo;
  GsmStatic  gsm;
  gsm_signal tmpbuf [GSMLEN];
  public:
    explicit GsmDecoder(FIFO<PText, FIFOLEN> & f) noexcept;
    bool send (uint16_t * ptr, const int len) override;
};

#endif // GSMDECODER_H
