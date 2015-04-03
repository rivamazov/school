all:main

main: avl.o main.o stopWatch.o generator.o
	g++ -g -std=c++11 avl.o main.o -o main

main.o: main.cpp 
	g++ -g -std=c++11 -c main.cpp

avl.o: avl.cpp avl.h
	g++ -g -std=c++11 -c avl.cpp

stopWatch.o: stopWatch.cpp stopWatch.h
	g++ -std=c++11 -c stopWatch.cpp

generator.o: generator.cpp generator.h
	g++ -std=c++11 -c generator.cpp

clean:
	rm *.o *~ main