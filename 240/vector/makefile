all:main

main: main.o generator.o
	g++ -g -std=c++11 generator.o main.o -o main

main.o: main.cpp vector.h generator.h
	g++ -g -std=c++11 -c main.cpp

generator.o: generator.cpp generator.h
	g++ -std=c++11 -c generator.cpp

clean:
	rm *.o *~ main
