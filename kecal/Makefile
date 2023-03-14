PR = kecal
#VPATH = .
CXX = g++
CC  = gcc
CFLAGS = -Wall -Os -g
#CFLAGS+= -DDEBUG
MFLAGS = -o $(PR)
LFLAGS = -lasound -L./prep -lgsm

all: $(PR)

OBJECTS = main.o player.o gsmdata.o

$(PR): $(OBJECTS) ./prep/libgsm.a
	$(CXX) $(MFLAGS) $(OBJECTS) $(LFLAGS)
clean:
	rm -f *.o *~
	cd ./prep && $(MAKE) clean
distclean: clean
	rm -f $(PR) gsmdata.c gsmdata.h
	rm -f ./prep/libgsm.a
	rm -f ./prep/wav/*.wav
%.o: %.cpp
	$(CXX) -std=c++14 -c $(CFLAGS) -o $@ $<
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
player.o: player.cpp player.h
main.o: main.cpp player.h
player.h: gsmdata.h
./prep/libgsm.a:
	cd ./prep/gsm/src && $(MAKE) all && $(MAKE) clean
gsmdata.o: gsmdata.c gsmdata.h
gsmdata.c gsmdata.h:
	cd ./prep && $(MAKE) all
.PHONY: all clean
