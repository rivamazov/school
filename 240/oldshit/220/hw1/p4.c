#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argv,char **argc) {
	int x=0;
	int y=1;
	//int x=atoi(argc[2]);
	//int y=atoi(argc[3]);
	unsigned int v=x; unsigned int w=y;
	int s_sum; unsigned int u_sum;
	s_sum=x+y;
	u_sum=v+w;
	if (s_sum==u_sum) printf("Unsigned and signed are the same\n");
	else printf("Unsigned and signed are different\n");

/*printf(" x=%d=0x%02x andf0=%s, orf0=%s\n",x,x,andf0?"true":"false",or0f?"true":"false");
*/

	return(0);
}
