#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argv,char **argc) {
	int x;
	long int y;
	x = -3;
	y = x;
	printf("y in decimal=%ld, y in hex=%x",y,y);	

/*printf(" x=%d=0x%02x andf0=%s, orf0=%s\n",x,x,andf0?"true":"false",or0f?"true":"false");
*/

	return(0);
}
