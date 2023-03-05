#include <stdio.h>
#include <string.h>
#include "alsa.h"
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

int AlsaOutput::send(const void * data, const int len) {
  rxcnt += len;
  // printf("reveived=%d\n", len);
  const char * ptr = reinterpret_cast<const char*>(data);
  if (handle == nullptr) {
    if (!header(ptr, sizeof(wave_header))) return 0;
    if (!write(ptr + sizeof(wave_header), len - sizeof(wave_header))) return 0;
    return len - sizeof(wave_header);
  }
  if (!write(ptr, len)) return 0;
  return len;
}
bool AlsaOutput::header(const char * data, const int len) {
  wave_header wh;
  memcpy (&wh, data, len);
  if ((wh.samplesize != 16) or (wh.datform != 1)) return false;
  total = wh.total_length + 8;
  print_header(wh);
  int err = snd_pcm_open (&handle, filename, SND_PCM_STREAM_PLAYBACK, 0);
  if (err < 0) {
    fprintf (stderr, "Playback open error: %s\n", snd_strerror(err));
    return false;
  }
  err = snd_pcm_set_params (handle,
                            SND_PCM_FORMAT_S16_LE,
                            SND_PCM_ACCESS_RW_INTERLEAVED,
                            wh.numchan,
                            (unsigned int) wh.sf1,
                            1, 500000);
  if (err < 0) {
    fprintf (stderr, "Playback set param error: %s\n", snd_strerror(err));
    snd_pcm_close (handle);
    handle = nullptr;
    return false;
  }
  if (!handle) {
    fprintf(stderr, "cannot open output device \"%s\"\n", filename);
    return false;
  }
  return true;
}
bool AlsaOutput::write(const char * data, const int len) {
  if (handle == nullptr) return false;
  const short * ptr = reinterpret_cast<const short *>(data);
  int n = snd_pcm_writei (handle, ptr, len >> 1);
  // printf ("%d = write (%d)\n", n, len);
  if (n<0) n = snd_pcm_recover (handle, n, 0);
  if (n<0) {
    fprintf (stderr, "snd_pcm_writei failed\n");
    return false;
  }
  return true;
}
void AlsaOutput::fini() {
  if (total != rxcnt) fprintf(stderr, "Warning: total (%d) != rxcnt (%d)\n", total, rxcnt);
  total = 0; rxcnt = 0;
  if (handle == nullptr) return;
  snd_pcm_drain(handle);        // wait for finish - Stop a PCM preserving pending frames.
  fprintf(stdout, "close \"%s\" OK.\n", filename);
  snd_pcm_close (handle);
  handle = nullptr;
}

