#include "alsa.h"

/// main ()
int main (int argc, char *argv[]) {
  const string text = utf8_to_iso("Přijde kostra k doktorovi a doktor jí povídá. To jdete brzy.");
  TTSCP_Client client ("127.0.0.1");
  AlsaOutput   output (client);
  if (!client.say(text)) return -1;
  
  return 0;
}
