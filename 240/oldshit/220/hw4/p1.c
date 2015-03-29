#include <stdio.h>

int main()
{
	int myfunc(int a, int * b) 
	{
		(*b)=a+1; a ++;
		return (*b);
	}
	int x=3; int y=10;
	int z = myfunc(x,&y);
	printf("%i\n%i\n%i\n",x,y,z);
	return 0;
}
