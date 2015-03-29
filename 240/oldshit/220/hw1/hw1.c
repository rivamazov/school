#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argv,char **argc) {
	unsigned char x;
	unsigned char mask;
	x = 0x0;
	mask = 0x0;

	unsigned char m_and = x & mask;
	unsigned char m_or = x | mask;
	unsigned char m_land = x && mask;
	unsigned char m_lor = x || mask;

	printf("m_and=%x\nm_or=%x\nm_land=%d\nm_lor=%d\n",m_and,
		m_or,m_land,m_lor);
	

/*printf(" x=%d=0x%02x andf0=%s, orf0=%s\n",x,x,andf0?"true":"false",or0f?"true":"false");
*/

	return(0);
}
