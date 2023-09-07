#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, x[20], max, min, fl = 0;
	int mx[20], mn[20], idx = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);

	for (int i = 0; i < N; i++)
		printf(" %d", x[N - 1 - i]);
	printf("\n");

	//
	for (int i = 0; i < N; i++) {
		if (fl == 0) {
			max = x[i];
			min = x[i];
			fl = 1;
		}
		else {
			if (max < x[i])
				max = x[i];
			if (min > x[i])
				min = x[i];
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

	return 0;
}