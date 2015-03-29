#include <stdio.h>
int recurse(int n)
{
	return recurse(n+1);
}

int main()
{
	recurse(43);
	return 0;
}
