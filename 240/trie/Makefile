all:main


trie.o: trie.h trie.cpp
	g++ -g -c -std=c++11 trie.cpp

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

main: trie.o main.o
	g++ -g -std=c++11 trie.o main.o -o main

clean:
	rm *.o *~ main