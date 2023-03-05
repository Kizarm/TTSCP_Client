#include "client.h"
#include <signal.h>
#include <string.h>
#include <errno.h>

static volatile bool loop = true;
void handler (int) {
  loop = false;
}
/// main ()
int main (int argc, char *argv[]) {
  // \xHH z pythonu, nejjednodušší (embedded nebude mít iconv)
  const char * text = "P\xf8ijde kostra k doktorovi a doktor j\xed pov\xed""d\xe1. To jdete brzy.";
  
  TTSCP_Client client ("127.0.0.1");
  signal (SIGINT, handler);
  while (loop) {
    if (!client.say(text)) return -1;
  }
  return 0;
}
