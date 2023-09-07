#pragma warning(disable:4996)
#include <stdio.h>

int add_digits(int);

int main(void) {

	int num, N, min, fl = 0, mium;

	scanf("%d", &num);
	while (num >= 0) {

		N = add_digits(num);
		while (N >= 10) {
			N = add_digits(N);
		}

		if (fl == 0) {
			min = N;
			mium = num;
			fl = 1;
		}
		else {
			if (min > N) {
				min = N;
				mium = num;
			}
		}
		scanf("%d", &num);
	}
	//
	printf("%d %d", mium, min);

	return 0;
}

int add_digits(int N) {

	int sum = 0;

	while (N != 0) {
		sum += N % 10;
		N /= 10;
	}

	return sum;
}