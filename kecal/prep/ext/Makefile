PR = test
VPATH = . ..
CXX = g++
CC  = gcc
CFLAGS = -Wall -Os -I../..
#CFLAGS+= -DDEBUG
MFLAGS = -o $(PR)
LFLAGS =
#arm-none-eabi-

all: data.elf $(PR)

OBJECTS = main.o gsmdata.o texts.o

$(PR): $(OBJECTS)
	$(CXX) $(MFLAGS) $(OBJECTS) $(LFLAGS)
clean:
	rm -f *.o *~ data.elf data.map data.bin data.hex
%.o: %.cpp
	$(CXX) -std=c++14 -c $(CFLAGS) -o $@ $<
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
data.elf: gsmdata.c
	gcc -Wall -Os -I../.. -Wl,-Map=data.map,--gc-sections -nostdlib -nostartfiles -o data.elf gsmdata.c -L. -T script.ld
	objcopy -O binary data.elf data.bin
	#objcopy -O ihex data.elf data.hex
.PHONY: all clean
