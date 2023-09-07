#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N, x[50], y[50], isdup, idx = 0, c[50] = { 0 };
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);

	//중복제거
	for (int i = 0; i < N; i++) {
		isdup = 0;
		for (int j = 0; j < i; j++)
			if (x[i] == x[j])
				isdup = 1;
		if (isdup == 0) {
			y[idx++] = x[i];
		}
	}

	//개수확인
	for (int i = 0; i < idx; i++)
		for (int j = 0; j < N; j++)
			if (y[i] == x[j])
				++c[i];

	for (int i = 0; i < idx; i++)
		printf("%d %d\n", y[i], c[i]);

	return 0;
}