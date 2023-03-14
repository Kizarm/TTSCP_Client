#ifndef PLAYER_H
#define PLAYER_H
#include "gsmdata.h"
#include "fifo.h"
static constexpr int GSMLEN  = 160;
static constexpr int FIFOLEN = 8;
/* Pomocná třída, fakticky zbytečná, ale na začátku jsem nevěděl co vlastně
 * budu do přerušení předávat, takže předávám toto, nechť je to cokoli.
 * Přes fifo lze předat jen ukazatel na strukturu, protože ukazuje na konstantu.
 * Předává se tedy ukazatel na kódovaný GSM rámec, který se dekóduje až v přerušení.
 * Při 48MHz SystemCoreClock dekódování trvá cca 3ms, takže je tam dostatečná rezerva.
 * Rámce GSM trvají 20ms (160 vzorků při 8kHz).
 */
class PText {
  const gsm_byte * pT;
  public:
    explicit PText () noexcept : pT(nullptr) {}
    PText (const PText    & o) : pT(o.pT) {}
    PText (const gsm_byte * o) : pT(o)   {}
    const gsm_byte * get () const { return pT; }
};
/* Algoritmus vyslovení čísla v češtině. Sémantika není dokonalá, ale dá tomu rozumět.
 * */
class TextPlayer {
  const SayedTexts       & m_t;
  FIFO<PText, FIFOLEN>   & fifo;
  public:
    explicit TextPlayer(FIFO<PText, FIFOLEN> & f) noexcept : m_t(sayed_texts), fifo(f) {}
    void say (const int number);                 // celé číslo
    void say (const int number, const int dnum); // celé číslo jako desetinné s dnum míst (1 .. 3)
    void say (const text_p & o) { out (o); }     // přetížení pro uživatelská slova
  protected:
    void sre (const int number);
    void hec (const int number);
    void dek (const int number);
    void one (const int number);
    void mil (const int number, const int dnum);
    
    void out (const text_p & o);
};

#endif // PLAYER_H
