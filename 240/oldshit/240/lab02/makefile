all:main

vector.o: vector.cpp vector.h
	g++ -c -std=c++11 vector.cpp

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

main: vector.o main.o
	g++ -std=c++11 vector.o main.o -o main

clean:
	rm *.o *~ main
