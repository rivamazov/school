all:main

main: bst.o main.o
	g++ -std=c++11 bst.o main.o -o main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

bst.o: bst.h bst.cpp
	g++ -std=c++11 -c bst.cpp

clean:
	rm *.o *~ main