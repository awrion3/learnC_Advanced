#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N, num, X[100], idx = 0, val;

	scanf("%d", &N);
	while (N > 0) {
		
		num = N; val = 0;
		while (num > 0) {
			val *= 10;
			val += num % 10;
			num /= 10;
		}

		if (N == val)
			X[idx++] = N;

		scanf("%d", &N);
	}

	for (int i = 0; i < idx; i++)
		printf("%d ", X[idx - 1 - i]);

	return 0;
}
//101 3453 123 1001 7683 2334 7790 12321 3777 -1