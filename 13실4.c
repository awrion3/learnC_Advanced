#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int a, b, c, d;
	unsigned int r;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	a <<= 24;
	b <<= 16;
	c <<= 8;

	r = a | b | c | d;

	printf("%d", r);

	return 0;
}
/*
15 4 20 3
*/