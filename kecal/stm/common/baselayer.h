#ifndef BASELAYER_H
#define BASELAYER_H
#include <stdint.h>

#ifdef __arm__
#define debug(...)
#else  // ARCH_CM0
#ifdef DEBUG
#define debug printf
#else  // DEBUG
#define debug(...)
#endif // DEBUG
#endif // ARCH_CM0
/** @brief Bázová třída pro stack trochu obecnějšího komunikačního protokolu.
 *
 * @class BaseLayer
 * @brief Od této třídy budeme dále odvozovat ostatní.
 *
*/
class BaseLayer {
  public:
    /** Konstruktor
    */
    explicit constexpr BaseLayer () noexcept : pUp(nullptr), pDown(nullptr) {};
    /** Virtuální metoda, přesouvající data směrem nahoru, pokud s nimi nechceme dělat něco jiného.
    @param data ukazatel na pole dat
    @param len  delka dat v bytech
    @return počet přenesených bytů
    */
    virtual uint32_t    Up (const char * data, const uint32_t len) {
      if (pUp) return pUp->Up (data, len);
      return 0;
    };
    /** Virtuální metoda, přesouvající data směrem dolů, pokud s nimi nechceme dělat něco jiného.
    @param data ukazatel na pole dat
    @param len  delka dat v bytech
    @return počet přenesených bytů
    */
    virtual uint32_t    Down (const char * data, const uint32_t len) {
      if (pDown) return pDown->Down (data, len);
      return len;
    };
    /** @brief Zřetězení stacku.
     * Tohle je vlastně to nejdůležitější. V čistém C by se musely
     * nastavovat ukazatele na callback funkce, tady je to čitší - pro uživatele neviditelné,
     * ale je to to samé.
    @param bl Třída, ležící pod, spodní
    @return Odkaz na tuto třídu (aby se to dalo řetězit)
    */
    virtual BaseLayer & operator += (BaseLayer & bl) {
      bl.setUp (this);  // ta spodní bude volat při Up tuto třídu
      setDown  (& bl);  // a tato třída bude volat při Down tu spodní
      return * this;
    };
    /** Getter pro pDown
    @return pDown
    */
    BaseLayer * getDown (void) const { return pDown; };
  protected:
    /** Lokální setter pro pUp
    @param p Co budeme do pUp dávat
    */
    void setUp   (BaseLayer * p) { pUp   = p; };
    /** Lokální setter pro pDown
    @param p Co budeme do pDown dávat
    */
    void setDown (BaseLayer * p) { pDown = p; };
  private:
    // Ono to je vlastně oboustranně vázaný spojový seznam.
    BaseLayer * pUp;        //!< Ukazatel na třídu, která bude dále volat Up
    BaseLayer * pDown;      //!< Ukazatel na třídu, která bude dále volat Down
};

#endif // BASELAYER_H
