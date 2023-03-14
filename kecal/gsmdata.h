/* GENERATED FILE DO NOT EDIT !!! */
#ifndef _GSM_DATA_H
#define _GSM_DATA_H
#include "./prep/gsm/inc/gsm.h"
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
typedef struct gsm_data_s {
#ifdef EXTROM
  unsigned long     frames;
#else
  const gsm_frame * frames;
#endif
  int            no_frames;
} text_p;
typedef struct SayedTexts_s {
  text_p nula;
  text_p jedna;
  text_p dva;
  text_p dve;
  text_p tri;
  text_p ctyri;
  text_p pet;
  text_p sest;
  text_p sedm;
  text_p osm;
  text_p devet;
  text_p deset;
  text_p jedenact;
  text_p dvanact;
  text_p trinact;
  text_p ctrnact;
  text_p patnact;
  text_p sestnact;
  text_p sedmnact;
  text_p osmnact;
  text_p devatenact;
  text_p dvacet;
  text_p tricet;
  text_p ctyricet;
  text_p padesat;
  text_p sedesat;
  text_p sedmdesat;
  text_p osmdesat;
  text_p devadesat;
  text_p sto;
  text_p dveste;
  text_p sta;
  text_p set;
  text_p tisic;
  text_p tisice;
  text_p minus;
  text_p point;
  text_p hafo;
  text_p units;

} SayedTexts;
extern const SayedTexts sayed_texts;
#ifdef __cplusplus
};
#endif // __cplusplus
#endif //  _GSM_DATA_H
