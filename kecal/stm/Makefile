PRJ  = pcm
#TGT = f051, unix
TGT ?= f051

VPATH  = . ./common ./$(TGT)
BLD    = ./bld/
DFLAGS = -d
LFLAGS = -Wl,-Map=$(@:%.elf=%.map),-gc-sections
LDLIBS = -lgsm
BFLAGS = --strip-unneeded

CFLAGS = -Wall -g
CCPU   = -mcpu=cortex-m0
MCPU   = -mthumb $(CCPU)
# Na clang není zcela připraveno, sice se to přeloží a funguje,
# ale knihovny potřebuje z arm-none-eabi-gcc.
#include Makefile.clang
include Makefile.gcc
CFLAGS+= -fno-exceptions -ffunction-sections -fdata-sections
CFLAGS+= -I. -I.. -I./common -I./$(TGT)

all: $(BLD) $(PRJ).elf
# zdrojaky
#OBJS  = test.o print.o usart.o Temperature.o
OBJS   = main.o PcmDma.o Temperature.o GsmDecoder.o
OBJS  += player.o gsmdata.o
ifeq ($(TGT),unix)
LDLIBS+=
else
OBJS  += startup.o system.o gpio.o
endif
BOBJS = $(addprefix $(BLD),$(OBJS))

# ... atd.
-include $(BLD)*.d
# linker
$(PRJ).elf: $(BOBJS) ./f051/libgsm.a
	-@echo [LD $(TGT)] $@
	@$(LD) $(LFLAGS) -o $(PRJ).elf $(BOBJS) $(LDLIBS)
	-@echo "size:"
	@$(SIZE) $(PRJ).elf
	-@echo "listing:"
	$(DUMP) $(DFLAGS) $(PRJ).elf > $(PRJ).lst
	-@echo "OK."
	$(COPY) $(BFLAGS) -O binary $(PRJ).elf $(PRJ).bin
# preloz co je potreba
./f051/libgsm.a:
	cd ../prep/gsm/src && $(MAKE) TARGET=$(TGT) && $(MAKE) clean
$(BLD)%.o: %.c
	-@echo [CC $(TGT)] $@
	@$(CC) -MMD -c $(CFLAGS) $< -o $@
$(BLD)%.o: %.cpp
	-@echo [CX $(TGT)] $@
	@$(CX) -std=c++14 -MMD -c $(CFLAGS) -fno-rtti $< -o $@
$(BLD):
	mkdir $(BLD)
# vycisti
clean:
	$(DEL) $(BLD)* *.lst *.bin *.elf *.map *~
.PHONY: all clean
