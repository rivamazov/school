all:main

main: bst.o main.o
	g++ -std=c++11 -g bst.o main.o -o main

main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp

bst.o: bst.h bst.cpp
	g++ -std=c++11 -g -c bst.cpp

clean:
	rm *.o *~ main