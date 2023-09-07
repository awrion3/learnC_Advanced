#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, num, x[100], idx = 0;
	int tmp, cnt = 0, max = 0;

	//
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &num);
		if (num > 0)
			x[idx++] = num;
	}

	//
	if (idx % 2 != 0) {
		for (int i = 0; i < idx - 1; i++)
			for (int j = i + 1; j < idx; j++)
				if (x[i] > x[j]) {
					tmp = x[i];
					x[i] = x[j];
					x[j] = tmp;
				}
	}
	else {
		for (int i = 0; i < idx - 1; i++)
			for (int j = i + 1; j < idx; j++)
				if (x[i] < x[j]) {
					tmp = x[i];
					x[i] = x[j];
					x[j] = tmp;
				}
	}

	printf("%d\n", idx);
	for (int i = 0; i < idx; i++)
		printf("%d ", x[i]);

	//
	for (int i = 0; i < idx; i++)
		if (x[i] % 2 != 0) {
			cnt++;
			if (max < cnt)
				max = cnt;
		}
		else
			cnt = 0;

	printf("\n%d", max);

	return 0;
}
//5 1 -2 3 19 6 7 8 17 -4 9 11 -6 16 13 15
//5 11 -1 -14 9 7 -5 6 2 1 3 -7