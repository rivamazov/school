all: main

main: main.o
	g++ -std=c++11 -g main.o -o main

main.o: main.cpp queue.h dlinklist.h node.h
	g++ -std=c++11 -g -c main.cpp

clean:
	rm *.o *~ main