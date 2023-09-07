#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, num, M, R, B = 0;

	scanf("%d", &N);

	while (N >= B) {
		printf("%d ", N);
		num = N;

		M = 1, R = 0;

		while (num != 0) {
			M *= num % 10;
			num /= 10;
		}
		printf("%d ", M);

		while (M != 0) {
			R *= 10;
			R += M % 10;
			M /= 10;
		}
		printf("%d ", R);

		printf("%d\n", N - B);

		B = N;
		scanf("%d", &N);
	}

	printf("End");

	return 0;
}
//12 6547 7085 28796 58