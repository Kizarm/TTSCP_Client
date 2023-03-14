PR = generate
VPATH = . ..
CXX = g++
CC  = gcc
CFLAGS = -Wall -Os
#CFLAGS+= -DDEBUG
MFLAGS = -o $(PR)
LFLAGS = -lsndfile -L.. -lgsm

all: $(PR)

OBJECTS = main.o texts.o

$(PR): ../libgsm.a $(OBJECTS)
	$(CXX) $(MFLAGS) $(OBJECTS) $(LFLAGS)
clean:
	rm -f *.o *~ $(PR)
%.o: %.cpp
	$(CXX) -std=c++14 -c $(CFLAGS) -o $@ $<
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
../libgsm.a:
	cd ../gsm/src && $(MAKE) all && $(MAKE) clean
.PHONY: all clean
