#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, M, x[100], idx = 0;
	int sum = 0, cnt = 0, jdx = 0;
	double avg[100];
	int max[100], min[100], fl = 0, kdx = 0;

	//값 입력
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);

	//M개 정수의 평균값 배열 구하기
	for (int i = 0; i < N; i++) {
		sum += x[i];
		cnt++;

		if ((i + 1) % M == 0 || i + 1 == N) {
			avg[idx++] = (double) sum / cnt;
			sum = 0; cnt = 0;
		}
	}

	//M개 정수의 평균값보다 크거나 같은 정수 출력하기
	for (int i = 0; i < N; i++) {
		if (avg[jdx] <= x[i])
			printf(" %d", x[i]);

		if ((i + 1) % M == 0)
			jdx++;
	}
	printf("\n");

	//M개 정수의 최대값 및 최소값 배열 구하기
	for (int i = 0; i < N; i++) {
		if (fl == 0) {
			max[kdx] = x[i];
			min[kdx] = x[i];
			fl = 1;
		}
		else {
			if (max[kdx] < x[i])
				max[kdx] = x[i];
			if (min[kdx] > x[i])
				min[kdx] = x[i];
		}
		if ((i + 1) % M == 0 || i + 1 == N) {
			kdx++;
			fl = 0;
		}
	}

	for (int i = 0; i < kdx; i++)
		printf(" %d", max[i]);
	printf("\n");
	for (int i = 0; i < kdx; i++)
		printf(" %d", min[i]);

	return 0;
}
//23 5
//12 13 14 7 6 5 15 15 15 3 3 9 11 5 5 20 1 15 3 7 17 5 8