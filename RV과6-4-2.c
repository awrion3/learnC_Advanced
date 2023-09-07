#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int T, num, big = 0, sma = 0, equ = 0;
	int N, v;

	scanf("%d", &T);

	scanf("%d", &num);
	while(num != 0) {

		N = num;
		while (N != 0) {
			v = N % 10;

			if (v > T)
				big++;
			else if (v < T)
				sma++;
			else
				equ++;

			N /= 10;
		}
		scanf("%d", &num);
	}

	printf("%d %d %d", equ, sma, big);

	return 0;
}