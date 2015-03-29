all:main

main: generator.o main.o
	g++ -std=c++11 generator.o main.o -o main

main.o: main.cpp array.h generator.h
	g++ -std=c++11 -c main.cpp 

generator.o: generator.cpp generator.h
	g++ -std=c++11 -c generator.cpp

clean:
	rm *.o *~ main