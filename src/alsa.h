#ifndef ALSA_H
#define ALSA_H
#include "client.h"
#include <alsa/asoundlib.h>

class AlsaOutput : public OutputInterface {
  const char * filename;
  snd_pcm_t  * handle;
  int total, rxcnt;
  public:
    explicit AlsaOutput (TTSCP_Client & p) noexcept :
      OutputInterface(&p), filename("default"), handle(nullptr), total(0), rxcnt(0) {
        p.attach (this);
      }
    virtual ~AlsaOutput() {}
    int  send (const void * data, const int len) override;
    void fini () override;
  protected:
    bool header (const char * data, const int len);
    bool write  (const char * data, const int len);
    
};

#endif // ALSA_H
