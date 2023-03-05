PR = client
VPATH = . ../src
CXX = g++
CFLAGS = -Wall -Os -I../src
#CFLAGS+= -DDEBUG
MFLAGS = -o $(PR)
LFLAGS = -lasound

all: $(PR)

OBJECTS = main.o client.o alsa.o

$(PR): $(OBJECTS)
	$(CXX) $(MFLAGS) $(OBJECTS) $(LFLAGS)
clean:
	rm -f *.o *~ *.wav
%.o: %.cpp
	$(CXX) -std=c++14 -c $(CFLAGS) -o $@ $<
.PHONY: all clean
