#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N, H, T, O, r = 1;
	scanf("%d", &N);

	H = N / 100;
	T = N / 10 % 10;
	O = N % 10;

	r += (H == T || T == O || H == O);
	r += (H == T && T == O);

	printf("%d", r);

	return 0;
}