#ifndef FILE_H
#define FILE_H
#include "client.h"
#include <sndfile.h>

class WavOutput : public OutputInterface {
  const char * filename;
  SNDFILE    * outfile;
  int total, rxcnt;
  public:
    explicit WavOutput (TTSCP_Client & p, const char * _filename = "said.wav") noexcept :
      OutputInterface(&p), filename(_filename), outfile(nullptr), total(0), rxcnt(0) {
        p.attach (this);
      }
    virtual ~WavOutput() {}
    bool say  (const char * filename, const string & s);
    int  send (const void * data, const int len) override;
    void fini () override;
  protected:
    bool header (const char * data, const int len);
    bool write  (const char * data, const int len);
    
};

#endif // FILE_H
