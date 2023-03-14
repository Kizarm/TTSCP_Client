#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <sndfile.h>
#include "../texts.h"
#include "../gsm/inc/gsm.h"
static constexpr int maxlen = 0x1000;
static short get_sample   (SNDFILE * f, const int l, bool & result) {
  short sample = 0, buf [l];
  int   sum = 0;
  sf_count_t n = sf_read_short (f, buf, l);
  if (n) {
    for (int k=0; k<n; k++) sum += buf[k];
    sum /= n;
    sample = sum;
    result = true;
  } else {
    result = false;
  }
  return sample;
}
static bool get_gsm_frame (SNDFILE * f, short * s, const int l, const int factor) {
  bool res;
  short sample;
  memset(s, 0, l * sizeof(short));
  for (int i=0; i<l; i++) {
    sample = get_sample (f, factor, res); // fs=32/16kHz
    if (!res) {
      // printf("i=%d\n", i);
      return false;
    }
    s[i] = sample;
  }
  return true;
}

int reformat (FILE * out, const char * name) {
  GsmStatic  GSM;
  gsm_frame  s;
  const unsigned step = sizeof(s), raw = 160;
  gsm_signal d [raw];
  const int pathlen = 256;
  char path[pathlen];
  int n = 0;
  n = snprintf(path, pathlen, "../wav/%s.wav", name);
  path [n] = '\0';
  fprintf(out, "static const gsm_frame gsm_data_%s[] = {\n", name);
  
  SF_INFO info;
  SNDFILE * in = sf_open (path, SFM_READ, &info);
  if (!in) return -1;
  const int fill = strlen(path) < 25 ? 25 - strlen(path) : 0;
  printf ("FILE \"%s\"%*s: %6ld frames, ch=%d, sr=%d\n", path, fill, "", info.frames, info.channels, info.samplerate);
  const int factor = info.samplerate / 8000;
  int frames = 0;
  while (true) {
    const bool rf = get_gsm_frame(in, d, raw, factor);
    GSM.encode (d, s);
    fprintf(out, "  {");
    for (unsigned k=0; k<step; k++) {
      fprintf(out, "0x%02x,", s[k]);
    }
    fprintf(out, "},\n");
    frames += 1;
    if (!rf) break;
  }
  fprintf(out, "};\n");
  sf_close (in);
  return frames;
}

static bool check_wav (const char * name) {
  const int r = access(name, F_OK);
  if (r) {
    printf("not OK %s, %s\n", name, strerror(errno));
    return false;
  }
  return true;
}
static bool print_as_str (const eSayedTexts & st) {
  const size_t l = sizeof(st) / sizeof(text_pair);
  // printf("l=%zd\n", l);
  // strukturu lze převést na pole (prvky jsou stejně velké)
  const text_pair * p = reinterpret_cast<const text_pair*>(&st);
  bool result = true;
  for (unsigned n=0; n<l; n++) {
    const char * str = p[n].name;
    char buffer [maxlen];
    const int r = snprintf(buffer, maxlen, "../wav/%s.wav", str);
    buffer [r] = '\0';
    if (!check_wav(buffer)) result = false;
  }
  return result;
}
static const char * prefix = R"++(/* GENERATED FILE DO NOT EDIT !!! */
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
)++";
static const char * suffix = R"++(
} SayedTexts;
extern const SayedTexts sayed_texts;
#ifdef __cplusplus
};
#endif // __cplusplus
#endif //  _GSM_DATA_H
)++";
#include <string>
static void reformat_all (const eSayedTexts & st) {
  FILE * out = fopen ("../../gsmdata.c","w");
  const size_t l = sizeof(st) / sizeof(text_pair);
  const text_pair * p = reinterpret_cast<const text_pair*>(&st);
  std::string desc, head;
  fprintf(out, "/* GENERATED FILE DO NOT EDIT !!! */\n");
  fprintf(out, "#include \"gsmdata.h\"\n");
  int total = 0;
  for (unsigned n=0; n<l; n++) {
    char buffer [maxlen];
    const char * name = p[n].name;
    const int frames = reformat(out, name);
    total += frames;
    // printf("frames=%d\n", frames);
    int r = 0;
    r = snprintf(buffer, maxlen, "  .%s = { gsm_data_%s, %d },\n", name, name, frames);
    const std::string s (buffer, r);
    desc += s;
    r = snprintf(buffer, maxlen, "  text_p %s;\n", name);
    const std::string h (buffer, r);
    head += h;
  }
  fprintf(out, "const SayedTexts sayed_texts = {\n");
  fprintf(out, "%s", desc.c_str());
  fprintf(out, "};\n");
  fclose   (out);
  printf("total = %d gsm_frames, %zd bytes\n", total, sizeof(gsm_frame) * total);
  out = fopen ("../../gsmdata.h","w");
  fprintf(out, "%s", prefix);
  fprintf(out, "%s", head.c_str());
  fprintf(out, "%s", suffix);
  fclose   (out);
}

int main (void) {
  if (!print_as_str (helper_texts)) return -1;
  reformat_all (helper_texts);
  return 0;
}
