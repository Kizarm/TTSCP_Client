PR = client
VPATH = . .. ./src
CXX = g++
CC = gcc
CFLAGS = -Wall -Os -I./src
#CFLAGS+= -DDEBUG
MFLAGS = -o $(PR)
LFLAGS = -lsndfile

all: $(PR)

OBJECTS = main.o client.o file.o texts.o

$(PR): $(OBJECTS)
	$(CXX) $(MFLAGS) $(OBJECTS) $(LFLAGS)
clean:
	rm -f *.o *~ *.wav $(PR)
%.o: %.cpp
	$(CXX) -std=c++14 -c $(CFLAGS) -o $@ $<
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
.PHONY: all clean
