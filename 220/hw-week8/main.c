#include "stdio.h"
typedef enum color {
	RED,
	WHITE,
	BLUE,
	GREEN,
	YELLOW,
	ORANGE
};


int getRed(enum color qc) {
	int redPart=0;
	switch(qc) {
		case RED:
		case WHITE: redPart=255; break;
		case BLUE:
		case GREEN: redPart=0; break;
		case YELLOW: redPart=32; break;
		case ORANGE: redPart=128; break;
	}
	return redPart;
}
int main() {
	printf("%d\n", getRed(RED));
	printf("%i", (0x4030dc%0x4));
	return 0;
}



