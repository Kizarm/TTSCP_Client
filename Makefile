PR = client
VPATH = . ./src
CXX = g++
CFLAGS = -Wall -Os -I./src
#CFLAGS+= -DDEBUG
MFLAGS = -o $(PR)
LFLAGS =

all: $(PR)

OBJECTS = main.o client.o

$(PR): $(OBJECTS)
	$(CXX) $(MFLAGS) $(OBJECTS) $(LFLAGS)
clean:
	rm -f *.o *~
%.o: %.cpp
	$(CXX) -std=c++14 -c $(CFLAGS) -o $@ $<
.PHONY: all clean
