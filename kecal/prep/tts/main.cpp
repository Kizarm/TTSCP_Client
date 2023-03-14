#include "file.h"
#include <signal.h>
#include <unistd.h>
#include "../texts.h"
/// main ()
int main (int argc, char *argv[]) {
  const int maxlen = 0x400;
  char namebuf [maxlen];
  TTSCP_Client client ("127.0.0.1");
  WavOutput    output (client, "none.wav");
  const unsigned num = sizeof(eSayedTexts) / sizeof(text_pair);
  const text_pair * base = reinterpret_cast<const text_pair * >(&helper_texts);
  for (unsigned n=0; n<num; n++) {
    const text_pair & pair = base [n];
    int r = snprintf(namebuf, maxlen, "../wav/%s.wav", pair.name);
    namebuf [r] = '\0';
    if (!access(namebuf, F_OK)) continue; // pokud existuje, pokračuj
    if (!output.say(namebuf, utf8_to_iso (pair.text))) break;
  }

  return 0;
}
