#ifndef TEXTS_H
#define TEXTS_H
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
typedef struct text_pair_s {
  const char * name;
  const char * text;
} text_pair;
typedef struct eSayedTexts_s {
  // mandatorní část použitá v playeru :
  text_pair nula, jedna, dva, dve, tri, ctyri, pet, sest, sedm, osm, devet;
  text_pair deset, jedenact, dvanact, trinact, ctrnact, patnact;
  text_pair sestnact, sedmnact, osmnact, devatenact;
  text_pair dvacet, tricet, ctyricet, padesat, sedesat, sedmdesat, osmdesat, devadesat;
  text_pair sto, dveste, sta, set, tisic, tisice;
  
  text_pair minus, point, hafo, units;
  // uživatelské texty :
  // text_pair svejk;
} eSayedTexts;
extern const eSayedTexts helper_texts;
#ifdef __cplusplus
};
#endif // __cplusplus
#endif // TEXTS_H
