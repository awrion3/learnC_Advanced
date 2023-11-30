#pragma warning(disable:4996)
#include <stdio.h>

int fib(int);

int main(void) {

	int n, r;

	scanf("%d", &n);

	r = fib(n);

	printf("%d", r);

	return 0;
}

int fib(int n) {

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n > 1)
		return fib(n - 1) + fib(n - 2);
}
/*
6
*/