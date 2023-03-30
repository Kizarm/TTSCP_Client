#ifndef PLAYER_H
#define PLAYER_H
#include "gsmdata.h"
#include <alsa/asoundlib.h>

static constexpr int GSMLEN = 160;

class TextPlayer {
  const SayedTexts & m_t;
  snd_pcm_t *handle;
  GsmStatic  gsm;
  gsm_signal pcmbuf [GSMLEN];
  public:
    explicit TextPlayer(const SayedTexts & t) noexcept : m_t(t), handle(nullptr), gsm() {}
    bool init ();
    void fini ();
    void say (const int number);                 // celé číslo
    void say (const int number, const int dnum); // celé číslo jako desetinné s dnum míst (1 .. 3)
    void say (const text_p & o) { out (o); }     // přetížení pro uživatelská slova
    void dly (const int pause = 50); // prodleva v násobcích 20ms (default 1s)
  protected:
    void sre (const int number);
    void hec (const int number);
    void dek (const int number);
    void one (const int number);
    void mil (const int number, const int dnum);
    
    void out (const text_p & o);     // výstup vzorků z pcmbuf
    
    bool pcm () const;
};

#endif // PLAYER_H
