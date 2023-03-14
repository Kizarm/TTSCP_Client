#include <stdio.h>
#include <stdlib.h>
#include "player.h"

bool TextPlayer::init() {
  int err = snd_pcm_open (&handle, "default", SND_PCM_STREAM_PLAYBACK, 0);
  if (err < 0) {
    fprintf (stderr, "Playback open error: %s\n", snd_strerror(err));
    return false;
  }
  err = snd_pcm_set_params (handle,
                            SND_PCM_FORMAT_S16_LE,
                            SND_PCM_ACCESS_RW_INTERLEAVED,
                            1,
                            8000u,
                            1, 500000);
  if (err < 0) {
    fprintf (stderr, "Playback set param error: %s\n", snd_strerror(err));
    snd_pcm_close (handle);
    handle = nullptr;
    return false;
  }
  if (!handle) {
    fprintf(stderr, "cannot open output device\n");
    return false;
  }
  return true;
}
void TextPlayer::fini() {
  if (handle == nullptr) return;
  snd_pcm_drain (handle);        // wait for finish
  snd_pcm_close (handle);
  handle = nullptr;
}
bool TextPlayer::pcm() {
  int n = snd_pcm_writei (handle, pcmbuf, GSMLEN);
  // printf ("%d = write (%d)\n", n, len);
  if (n<0) n = snd_pcm_recover (handle, n, 0);
  if (n<0) {
    fprintf (stderr, "snd_pcm_writei failed\n");
    return false;
  }
  return true;
}
void TextPlayer::dly(const int pause) {
  memset (pcmbuf, 0, GSMLEN * sizeof(short));
  for (int n=0; n<pause; n++) pcm();
}

/******************************************************************/
static constexpr int dmult (const int n) {
  int r = 1;
  for (int i=0; i<n; i++) r *= 10;
  return r;
}
static constexpr int strip_zeros (const int n) {
  if ((n % 10) != 0) return n;
  return strip_zeros(n / 10);
}
void TextPlayer::say(const int number) {
  printf("number=%d: ", number);
  if (!number) out(m_t.nula);
  else sre (number);
  printf("\n");
}
void TextPlayer::say(const int number, const int dnum) {
  if (dnum <= 0 or dnum > 3) { out(m_t.hafo); return; } // meze 1..3
  if (number < 0) {
    out (m_t.minus); say (-number, dnum); return;
  }
  const div_t dt = ::div (number, dmult(dnum));
  printf("number=%d.%0*d: ", dt.quot, dnum, dt.rem);
  if (dt.quot) sre(dt.quot);
  else         out(m_t.nula);
  out(m_t.point);
  mil(dt.rem, dnum);
  printf("\n");
}
void TextPlayer::mil(const int number, const int dnum) {
  if (number == 0) { out(m_t.nula); return; }
  const int max = dmult(dnum - 1);
  if (number < max) {
    out(m_t.nula);
    mil(number * 10, dnum);
    return;
  }
  sre (strip_zeros(number));
}

void TextPlayer::sre(const int number) {
  if (number < 0) {
    out (m_t.minus);
    sre (-number);
    return;
  }
  if (number >= 1000000) {
    out(m_t.hafo);
    return;
  }
  if (number == 1000) {
    out(m_t.tisic);
    return;
  }
  if (number > 1000) {
    const div_t dt = ::div (number, 1000);
    sre (dt.quot);
    const int ln = dt.quot % 10;
    (ln < 2 or ln > 4) ? out(m_t.tisic) : out(m_t.tisice);
    sre (dt.rem);
    return;
  }  
  if (number == 100) {
    out(m_t.sto);
    return;
  }
  if (number > 100) {
    const div_t dt = ::div (number, 100);
    const int ln = dt.quot % 10;
    //printf ("stovky:%d ", ln);
    hec (ln);
    sre (dt.rem);
    return;
  }
  if (number == 20) {
    out(m_t.dvacet);
    return;
  }
  if (number > 20) {
    const div_t dt = ::div (number, 10);
    const int ln = dt.quot % 10;
    //printf ("desitky:%d ", ln);
    dek (ln);
    sre (dt.rem);
    return;
  }
  if (number == 0) return;
  // jednotky 1 .. 19
  // printf("jednotky:%d ", number);
  one (number);
}
void TextPlayer::hec(const int number) {
  switch (number) {
    case 1: out (m_t.sto);    break;
    case 2: out (m_t.dveste); break;
    case 3: 
    case 4: one(number); out (m_t.sta);  break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9: one(number); out (m_t.set);  break;
    default: break;
  };
}
void TextPlayer::dek(const int number) {
  switch (number) {
    case 2: out (m_t.dvacet);    break;
    case 3: out (m_t.tricet);    break;
    case 4: out (m_t.ctyricet);  break;
    case 5: out (m_t.padesat);   break;
    case 6: out (m_t.sedesat);   break;
    case 7: out (m_t.sedmdesat); break;
    case 8: out (m_t.osmdesat);  break;
    case 9: out (m_t.devadesat); break;
    default: break;
  };
}
void TextPlayer::one(const int number) {
  // 1..19
  switch (number) {
    case 1: out (m_t.jedna);  break;
    case 2: out (m_t.dva);    break;
    case 3: out (m_t.tri);    break;
    case 4: out (m_t.ctyri);  break;
    case 5: out (m_t.pet);    break;
    case 6: out (m_t.sest);   break;
    case 7: out (m_t.sedm);   break;
    case 8: out (m_t.osm);    break;
    case 9: out (m_t.devet);  break;
    case 10: out (m_t.deset); break;
    case 11: out (m_t.jedenact);   break;
    case 12: out (m_t.dvanact);    break;
    case 13: out (m_t.trinact);    break;
    case 14: out (m_t.ctrnact);    break;
    case 15: out (m_t.patnact);    break;
    case 16: out (m_t.sestnact);   break;
    case 17: out (m_t.sedmnact);   break;
    case 18: out (m_t.osmnact);    break;
    case 19: out (m_t.devatenact); break;
    default: break;
  };
}

void TextPlayer::out(const text_p & o) {
  printf ("%d,", o.no_frames);
  fflush(stdout);
  for (int n=0; n<o.no_frames; n++) {
    /* Těchto 33 bytů na stacku tu musí být. GSM s tím asi nějak pracuje, tak to musí být
     * nekonstantní. Ostatně, pokud by se frame tahaly z externí SPI flash, pak by zde
     * stejně muselo být něco jako spi_read (int addr, void * dst, int count) místo memcpy() */
    gsm_frame in;
    memcpy (in, o.frames[n], sizeof(gsm_frame));
    gsm.decode (in, pcmbuf);
    pcm();
  }
}
