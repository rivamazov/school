#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argv,char **argc) {
	unsigned int x;
	int y;
	x = INT_MAX+1;
	y = INT_MIN;
	printf("y in decimal=%x, y in hex=%x\n",x,(y));	
	printf("%d",(x==y));

/*printf(" x=%d=0x%02x andf0=%s, orf0=%s\n",x,x,andf0?"true":"false",or0f?"true":"false");
*/

	return(0);
}
