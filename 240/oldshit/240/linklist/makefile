all:main

node.o: node.h node.cpp
	g++ -c -g -std=c++11 node.cpp

linklist.o: linklist.h linklist.cpp
	g++ -c -g -std=c++11 linklist.cpp

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

main: node.o linklist.o main.o
	g++ -g -std=c++11 node.o linklist.o main.o -o main

clean:
	rm *.o *~ main
