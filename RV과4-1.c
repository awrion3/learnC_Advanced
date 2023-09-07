#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N, v;

	scanf("%d", &N);
	
	v = 3 * !(N % 3) + 5 * !(N % 5) + 7 * !(N % 15);
	v += N * !(v != 0);

	printf("%d is multiple of %d.", N, v);

	return 0;
}