#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, x[20], max, min, fl;
	int mx[20], mn[20], idx;
	int y[20];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x[i]);
		y[i] = x[i]; //
	}

	for (int i = 0; i < N; i++)
		printf(" %d", x[N - 1 - i]);
	printf("\n");

	//
	while (N > 1) {
		idx = 0; fl = 0; //

		for (int i = 0; i < N; i++) {
			if (fl == 0) {
				max = x[i];
				min = y[i];
				fl = 1;
			}
			else {
				if (max < x[i])
					max = x[i];
				if (min > y[i])
					min = y[i];
			}

			if ((i + 1) % 3 == 0 || i + 1 == N) {
				mx[idx] = max;
				mn[idx] = min;
				fl = 0;
				idx++;
			}
		}

		//
		for (int i = 0; i < idx; i++)
			printf(" %d", mx[i]);
		printf("\n");
		for (int i = 0; i < idx; i++)
			printf(" %d", mn[i]);
		printf("\n");

		//
		for (int i = 0; i < idx; i++) {
			x[i] = mx[i];
			y[i] = mn[i];
		}
		N = idx;
	}
	
	return 0;
}
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20