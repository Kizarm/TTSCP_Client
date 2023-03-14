#ifndef ADC_CLASS_H
#define ADC_CLASS_H
#include <stdint.h>
#include "chain.h"

static constexpr unsigned PERIOD = 120u;

/** @class ADC_class
 * @brief AD převodník
 */
class ADC_class : public AbstractChain<short> {
  int16_t m_buffer [PERIOD << 1];
  int16_t * const ptr_l, * const ptr_h;
  int16_t * current;
  public:
    explicit ADC_class() noexcept;
#ifdef __arm__
    void dmaIrq (void);
#else
    virtual ~ADC_class();
    int16_t * get_buf ();
    void input ();
#endif
};
#endif // ADC_CLASS_H
