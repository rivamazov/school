all:main

main: main.o generator.o
	g++ -std=c++11 -g main.o generator.o -o main

main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp 

generator.o: generator.h generator.cpp
	g++ -std=c++11 -g -c generator.cpp

clean:
	rm *.o *~ main