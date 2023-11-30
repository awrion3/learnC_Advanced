#pragma warning(disable:4996)
#include <stdio.h>

int euclidean(int, int);

int main(void) {

	int A, B, C;

	scanf("%d %d", &A, &B);

	C = euclidean(A, B);

	printf("%d", C);

	return 0;
}

int euclidean(int A, int B) {

	int a, b;

	a = B;
	b = A % B;
	
	if (b == 0)
		return a;
	
	return euclidean(a, b);
}
/*
366 60
*/