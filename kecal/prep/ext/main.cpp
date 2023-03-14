#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "gsmdata.h"
#include "../texts.h"
/* Jedna z možností jak dostat data do externí flash. Sice to poněkud
 * nabobtná (na začátku je zbytečně celá struktura SayedTexts + padding),
 * ale funguje to.
 * 1. zdroják gsmdata.c se přeloží a pomocí linker skriptu se vytvoří elf
 * 2. z elf se udělá binárka, příp. hex soubor standardním binutils
 * 3. binárka se tímto přečte a do extdata.c se extrahují potřebné informace.
 * extdata.c pak obsahuje adresy slov a jejich délky potřebné pro čtení.
 * Nezávisí to na tom, zda se binárka vytváří na 64. nebo 32. bit stroji. */
static void test () {
  return;
  // delky sedi
  printf("l=0x%zX, f=%zd\n", sizeof(sayed_texts), sizeof(gsm_frame));
  const gsm_frame * p = sayed_texts.nula.frames;
  const int n = sayed_texts.nula.no_frames;
  const unsigned char * o = (const unsigned char *) p;
  for (int i=0; i<n; i++) {
    const unsigned char * c = p [i];
    int d = int (c - o);
    printf("p=%p, d=%d\n", c, d);
    o = c;
  }
}
class Reader {
  unsigned char * file_data;
  int file_size;
  public:
    explicit Reader() : file_data(nullptr), file_size(0) {}
    ~Reader() {
      if (file_data) delete [] file_data;
    }
    int process (const char * filename);
  protected:
    void check ();
    void compare (const size_t ne, const gsm_frame * c, const int f);
    void generate();
};
int Reader::process(const char * filename) {
  struct stat statbuf;
  int r = ::stat(filename, &statbuf);
  if (r < 0) return -1;
  if (file_data) delete [] file_data;
  file_data = new unsigned char [statbuf.st_size];
  FILE * in_file = fopen(filename, "r");
  r = fread (file_data, 1, statbuf.st_size, in_file);
  file_size = r;
  printf("readen %d bytes\n", file_size);
  if (!in_file) return -1;
  fclose(in_file);
  check();      // kontrola - mělo by sedět to co je v data.bin a přeložené gsmdata.c
  generate();   // generuje C-soubor s adresami a počty rámců
  return 0;
}
void Reader::check() {
  if (!file_size) return;
  // file_data[1000] = 0; // když něco změním, opravdu nastane chyba
  SayedTexts st;
  memcpy (&st, file_data, sizeof(SayedTexts));
  const text_p * ebase = (text_p *) & st;
  const text_p * cbase = (text_p *) & sayed_texts;
  const size_t count = sizeof(SayedTexts) / sizeof (text_p);
  printf("count=%zd\n", count);
  for (unsigned n=0; n<count; n++) {
    const text_p & ep = ebase [n];
    const text_p & cp = cbase [n];
    if (ep.no_frames != cp.no_frames) // struct SayedTexts OK.
      printf("eframe: %p len=%d, cframe: %p, len=%d\n", ep.frames, ep.no_frames, cp.frames, cp.no_frames);
    compare (size_t (ep.frames), cp.frames, cp.no_frames);
  }
}
static bool compare_frame (const unsigned char * a, const unsigned char * b, const int n) {
  for (int i=0; i<n; i++) {
    if (a [i] != b [i]) return false;
  }
  return true;
}
void Reader::compare(const size_t ne, const gsm_frame * c, const int f) {
  // ofset + adresa pameti
  const gsm_frame * e = (gsm_frame *) (ne + (size_t) file_data);
  for (int k=0; k<f; k++) {
    const unsigned char * a = c [k];
    const unsigned char * b = e [k];
    if (!k) {  // jen aby bylo neco videt
      for (int n=0; n<10; n++) printf("%02X:%02X|", a[n], b[n]);
      printf("...\n");
    }
    if (!compare_frame(a, b, sizeof(gsm_frame))) printf ("error:%d\n", k);
  }
}
// Jen toto je podstatné - vytvoření extdata.c
static const char * prefix = R"---(/* GENERATED FILE DO NOT EDIT */
#ifndef EXTROM
#error "Compile with -DEXTROM=1"
#endif
#include "gsmdata.h"
const SayedTexts sayed_texts = {
)---";
void Reader::generate() {
  FILE * out = fopen("extdata.c","w");
  fprintf(out, "%s", prefix);
  SayedTexts st;
  memcpy (&st, file_data, sizeof(SayedTexts));
  constexpr size_t count = sizeof( SayedTexts) / sizeof (text_p);
  constexpr size_t txtct = sizeof(eSayedTexts) / sizeof (text_pair);
  static_assert (count == txtct, "Bad size, regenerate sources");
  const text_p    * ebase = (text_p   *) & st;  // pole ze struktury (stejných prvků)
  const text_pair * tbase = (text_pair*) & helper_texts;
  for (unsigned n=0; n<count; n++) {
    const text_p    & ep = ebase [n];
    const text_pair & tp = tbase [n];
    fprintf(out, "  .%s = { %zdu, %d },\n", tp.name, size_t (ep.frames), ep.no_frames);
  }
  fprintf(out, "};\n");
  fclose(out);
}

/// main ()
int main (int argc, char *argv[]) {
  test(); // gsm ramce jsou pakovane, nemel by byt problem.
  Reader read;
  return read.process("data.bin");
}
