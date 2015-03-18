#include "stdio.h"
int main()
{
	int myvar = 25;
	int foo = &myvar;
	int bar = myvar;
	int *shit=&myvar;
	shit=*foo;
	printf("%i, %i, %i, %i",myvar, foo, bar, shit);
	return 0;
}
