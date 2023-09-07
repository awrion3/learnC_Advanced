#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int A[20], F, R, M, tmp;

	scanf("%d%d%d", &F, &R, &M);

	for (int i = 0; i < 20; i++)
		A[i] = i + 1;

	//
	tmp = A[R];
	for (int i = R; i > R - M + 1; i--)
		A[i] = A[i - 1];
	A[R - M + 1] = tmp;

	//
	for (int i = 0; i < 20; i++)
		printf("%d ", A[i]);

	return 0;
}