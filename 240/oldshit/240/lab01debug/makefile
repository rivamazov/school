all:main

array.o: array.cpp array.h
	g++ -g -c -std=c++11 array.cpp

main.o: main.cpp
	g++ -g -c -std=c++11 main.cpp

main: array.o main.o
	g++ -std=c++11 array.o main.o -o main

clean:
	rm *.o *~ main
