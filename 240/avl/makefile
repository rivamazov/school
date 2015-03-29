all:main

main: avl.o main.o
	g++ -std=c++11 avl.o main.o -o main

main.o: main.cpp 
	g++ -std=c++11 -c main.cpp

avl.o: avl.cpp avl.h
	g++ -std=c++11 -c avl.cpp

clean:
	rm *.o *~ main