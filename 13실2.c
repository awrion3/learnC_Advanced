#pragma warning(disable:4996)
#include <stdio.h>

int factorial(int);

int main(void) {

	int n;
	double e = 0;

	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
		e += (double)1/factorial(i);

	printf("%.6f", e);

	return 0;
}

int factorial(int n) {

	if (n == 0)
		return 1;
	
	return factorial(n - 1) * n;
}
/*
30
*/