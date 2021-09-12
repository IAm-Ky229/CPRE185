/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

int numButtons(int TRI,int CIR,int X, int SQUA) {
	return TRI + CIR + X + SQUA;
}

int main(void) {
	int TRIANGLE;
	int CIRCLE;
	int X;
	int SQUARE;

	while (1) {
		scanf("%d,%d,%d,%d", &TRIANGLE, &CIRCLE, &X, &SQUARE);

		printf("The number of buttons being pressed is currently %d.\n", numButtons(TRIANGLE, CIRCLE, X, SQUARE));
		fflush(stdout);
	}

	return 0;
}

