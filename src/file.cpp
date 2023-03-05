#include <stdio.h>
#include <string.h>
#include "file.h"
#include "epos_wav.h"

void print_header (const wave_header & wh) {
  return;
  printf("total %d bytes, form = %04X, ch=%d, sr=%d, hl=%d, ss=%d\n", wh.total_length, (unsigned) wh.datform,
         (int) wh.numchan, (int) wh.sf1, (int) wh.fmt_length, (int) wh.samplesize);
  const unsigned char * ptr = (const unsigned char*) &wh;
  for (unsigned n=0; n<sizeof(wave_header); n++) {
    printf("%02X", ptr[n]);
  }
  printf("\n");
}
bool WavOutput::say(const char * name, const string & s) {
  filename = name;
  if (parent == nullptr) return false;
  if (!parent->say(s))   return false;
  return true;
}
int WavOutput::send(const void * data, const int len) {
  rxcnt += len;
  // printf("reveived=%d\n", len);
  const char * ptr = reinterpret_cast<const char*>(data);
  if (outfile == nullptr) {
    if (!header(ptr, sizeof(wave_header))) return 0;
    if (!write(ptr + sizeof(wave_header), len - sizeof(wave_header))) return 0;
    return len - sizeof(wave_header);
  }
  if (!write(ptr, len)) return 0;
  return len;
}
void WavOutput::fini() {
  if (total != rxcnt) fprintf(stderr, "Warning: total (%d) != rxcnt (%d)\n", total, rxcnt);
  total = 0; rxcnt = 0;
  if (outfile == nullptr) return;
  fprintf(stdout, "close \"%s\" OK.\n", filename);
  sf_close (outfile);
  outfile = nullptr;
}
bool WavOutput::header(const char * data, const int len) {
  wave_header wh;
  memcpy (&wh, data, len);
  if ((wh.samplesize != 16) or (wh.datform != 1)) return false;
  total = wh.total_length + 8;
  print_header(wh);
  SF_INFO info;
  memset (&info, 0, sizeof(SF_INFO));
  info.channels = wh.numchan;
  info.format   = SF_FORMAT_WAV | SF_FORMAT_GSM610; // compress or SF_FORMAT_PCM_16;
  info.samplerate = wh.sf1;
  if (sf_format_check (&info) == SF_FALSE) {
    fprintf(stderr, "bad output format\n");
    return false;
  }
  outfile = sf_open (filename, SFM_WRITE, &info);
  if (!outfile) {
    fprintf(stderr, "cannot open output file \"%s\"\n", filename);
    return false;
  }
  return true;
}
bool WavOutput::write(const char * data, const int len) {
  if (outfile == nullptr) return false;
  const short * ptr = reinterpret_cast<const short *>(data);
  sf_write_short (outfile, ptr, len >> 1);
  return true;
}
