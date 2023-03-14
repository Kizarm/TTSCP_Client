TARGET ?= unix

FLAGS = -c -Os
ifeq ($(TARGET), unix)
else
CPU  ?= cortex-m0
CROSS = arm-none-eabi-
FLAGS+= -mthumb -mcpu=$(CPU)
FLAGS+= -ffunction-sections -fdata-sections
endif
FLAGS+= -I../inc
FLAGS+= -DNeedFunctionPrototypes=1 -DSASR -DWAV49 -DNDEBUG=1
AS    = $(CROSS)as -mthumb
CC    = $(CROSS)gcc
CC   += $(FLAGS)
CXX   = $(CROSS)g++
CXX  += $(FLAGS) -fno-exceptions -fno-rtti
AR    = $(CROSS)ar

CFILES = $(wildcard *.c)
CXFILES= $(wildcard *.cpp)

OBJS   = $(CFILES:%.c=%.o)
OBJS  += $(CXFILES:%.cpp=%.o)

ifeq ($(TARGET), unix)
DSTLIB = ../../libgsm.a
else
DSTLIB = ../../../stm/f051/libgsm.a
endif
%.o: %.S
	$(AS) $< -o $@
%.o: %.c
	$(CC) $< -o $@
%.o: %.cpp
	$(CXX) $< -o $@

ifeq ($(TARGET), unix)
$(DSTLIB): $(OBJS)
	$(AR) rcs $(DSTLIB) $(OBJS)
else
$(DSTLIB): $(OBJS)
	$(AR) rcs $(DSTLIB) $(OBJS)
endif


.PHONY: all clean

all: $(DSTLIB)

clean:
	-rm -f *.o *.a
