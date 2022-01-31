CFLAGS = -O2
CLIBS=-lsfml-window -lsfml-graphics -lsfml-system

all: bunnymark-sfml

bunnymark-sfml: main.o Bunny.o
	$(CXX) -o $@ $^ $(CLIBS)

main.o: main.cpp
Bunny.o: Bunny.cpp

clear:
	$(RM) *.o