all: p1

p1 : p1.o
	gcc p1.o -o p1

p1.o : p1.c
	gcc -c p1.c

test : all
	./p1

clean :
	rm p1 *.o
