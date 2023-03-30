#include "player.h"
#include <signal.h>
/* Vytváření souboru gsmdata.c je poněkud složitější a tak stojí za to okomentovat.
 * 1. Struktura SayedTexts v gsmdata.h kopíruje strukturu eSayedTexts v hlavičce prep/texts.h.
 *    Tu je možné editovat a přidávat tam další. Spolu s tím je nutné upravit i prep/texts.c
 * 2. V adresáři prep/tts uděláme make a spustíme ./client. Pokud je spuštěn démon epos
 *    vygenerují se odpovídající wav soubory v adresáři prep/wav.
 * 3. V adresáři prep/gen uděláme make a spustíme ./generate. A je to.
 * 
 * Makefile to do jisté míry automatizuje (musí být spuštěn démon epos).
 * */
static volatile bool loop = true;
static void sigHandler (int) {
  loop = false;
}
static void play_all (TextPlayer & player) {
  const int l = sizeof (sayed_texts) / sizeof (text_p);
  printf("no of texts=%d\n", l);
  const text_p * const parray = reinterpret_cast<const text_p * const>(&sayed_texts);
  for (int n=0; n<l; n++) {
    const text_p & tp = parray[n];
    player.say(tp);
    player.dly(10);
    if (!loop) break;
  }
  printf("\n");
}
/// main ()
int main (int argc, char *argv[]) {
  signal (SIGINT, sigHandler);
  TextPlayer player (sayed_texts);
  if (!player.init()) return -1;
  play_all(player);
  int n = 12;
  while (loop) {
    n -= 1;
    player.say(n,2);
    player.dly();
    if (n == 0) break;
  }
  player.fini();
  return 0;
}
