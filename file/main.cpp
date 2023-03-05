#include "file.h"
#include <signal.h>

/// main ()
int main (int argc, char *argv[]) {
  const char * text = "P\xf8ijde kostra k doktorovi a doktor j\xed pov\xed""d\xe1.To jdete brzy.";

  TTSCP_Client client ("127.0.0.1");
  WavOutput    output (client, "x.wav");
  client.say (text);
  // nebo takto, pokud chceme zpracovat více souborů
  output.say ("y.wav", "\xe8""erven\xe1 modr\xe1 fiala");
  output.say ("z.wav", utf8_to_iso("Příliš žluťoučký kůň úpěl ďábelské ódy."));

  return 0;
}
