#ifndef USART_H
#define USART_H
#include "fifo.h"
#include "baselayer.h"
/** @class Usart
 * @brief Sériový port
 */
class Usart : public BaseLayer {
  FIFO<char, 64> tx_ring;
  public:
    explicit Usart (const uint32_t baud = 9600) noexcept;
    uint32_t Down  (const char * data, const uint32_t len) override;
#ifdef __arm__
    void irq            (void);
    void SetHalfDuplex  (const bool on) const;
    void SetRS485       (const bool polarity) const;    
#else
    virtual ~Usart ();
#endif
};

#endif // USART_H
