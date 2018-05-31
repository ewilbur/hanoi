COMPILE = g++
OBJS = tower.o hanoi.o
FLAGS = -W -Wall -Werror -pedantic -ansi -O2 -std=c++11

all: main.cpp $(OBJS)
	$(COMPILE) -o hanoi.out main.cpp $(OBJS)

clean:
	rm *.out *.o
