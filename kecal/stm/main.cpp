#include "fifo.h"
#include "gpio.h"
#include "player.h"
#include "PcmDma.h"
#include "Temperature.h"
#include "GsmDecoder.h"

/*        Mluvící teploměr.
 * 
 * Měří de fakto teplotu čipu, nechtělo se mi přidávat externí čidlo, ale i to by šlo.
 * Stejně by fungoval i voltmetr, byla by nutná jen drobná úprava ADC převodníku.
 * Arduino knihovna Talkie patrně funguje na podobném principu, zde je však použita
 * pro vzorky zvuků GSM komprese. To se na 8-bitu asi použít nedá, chce to údajně alespoň 2 MIPS.
 * Na Cortex-M0 taktovaném 48MHz zabere asi 15% výkonu. A není to tak velké jako třeba mp3.
 * Nicméně čísla + GSM dekomprese zaberou skoro celou flash, pokud by někdo chtěl
 * něco rozsáhlejšího, stejně by se musela přidat externí SPI flash a pak i komprese
 * postrádá smysl.
 * Docela dobrá finta je použít 75176 (budič RC485) jako výstup na 30 Ohm sluchátka.
 * Když se zapojí do série, brouku to ani moc nevadí a je to hodně hlasité.
 */

static FIFO<PText, FIFOLEN> fifo;
static TextPlayer           player (fifo);
static GsmDecoder           decoder(fifo);
static PcmDma               pcm;
static Temperature          temp;
static GpioClass but (GpioPortA, 2, GPIO_Mode_IN);

static inline int iabs (const int n) {
  return n > 0 ? n : -n;
}

int main (void) {
  pcm.attach (&decoder);
  but.setPuPd(GPIO_PuPd_UP);
  int teo = 0;
  for (;;) {
    pcm.delay (5);
    const int tem = temp.meassure();
    if ((iabs(tem - teo) < 5) and but.get()) continue;
    player.say(tem, 1);
    player.say(sayed_texts.units);
    teo = tem;
  }
  return 0;
}
