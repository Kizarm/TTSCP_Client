#ifndef ABSTRACTCHAIN_H
#define ABSTRACTCHAIN_H
#include <stdint.h>

class AbstractChain {
  AbstractChain * next;
  public:
    explicit AbstractChain () noexcept : next(nullptr) {}
    virtual bool send (uint16_t * ptr, const int len) {
      if (next) return next->send(ptr, len);
      return false;
    }
    void attach (AbstractChain * ch) { next = ch; };
};

#endif // ABSTRACTCHAIN_H
