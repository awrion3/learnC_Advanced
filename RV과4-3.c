#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int a, b, c;
	char r = 0;

	scanf("%d%d%d", &a, &b, &c);

	a = a / 100 % 10;
	b = b / 100 % 10;
	c = c / 100 % 10;

	r += 'T' * (a == b && b == c);

	r += 'D' * (r != 'T' && !(a != b && b != c && a != c));

	r += 'S' * (a != b && b != c && a != c);
	
	printf("%c", r);

	return 0;
}