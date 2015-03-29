#include <stdio.h>

int main()
{
	int x=-3;
	int y=x/2;
	int z=x>>1;
	
	printf("%x\n%x\n%x\n%i\n",x,y,z,(y==z));
	return 0;
}
