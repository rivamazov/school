all:main

main: avl.o main.o stopWatch.o generator.o bst.o
	g++ -g -std=c++11 stopWatch.o generator.o bst.o avl.o main.o -o main

main.o: main.cpp 
	g++ -g -std=c++11 -c main.cpp

avl.o: avl.cpp avl.h
	g++ -g -std=c++11 -c avl.cpp

stopWatch.o: stopWatch.cpp stopWatch.h
	g++ -std=c++11 -c stopWatch.cpp

generator.o: generator.cpp generator.h
	g++ -std=c++11 -c generator.cpp

bst.o: bst.cpp bst.h
	g++ -std=c++11 -c bst.cpp

clean:
	rm *.o *~ main
