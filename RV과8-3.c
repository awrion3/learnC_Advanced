#pragma warning(disable:4996)
#include <stdio.h>

int multiple(int, int);
int maximum(int, int);
int digit_maximum(int);

int main (void) {

	int N, M, K;
	int dax = 0, rax = 0;

	scanf("%d%d%d", &N, &M, &K);

	for (int i = N; i <= M; i++)
		if (multiple(i, K)) 
			dax = maximum(dax, digit_maximum(i));
		else 
			rax = maximum(rax, i % K);

	printf("%d", maximum(dax, rax));

	return 0;
}

int multiple(int x, int y) {

	return (x % y == 0);
}

int maximum(int x, int y) {

	if (x > y)
		return x;
	return y;
}

int digit_maximum(int x) {
	
	int max = 0;

	while (x != 0) {
		max = maximum(max, x % 10);
		x /= 10;
	}

	return max;
}