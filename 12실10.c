#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N, *p, num = 0, *q, k = 0;
	
	scanf("%d", &N);
	
	//동적할당 및 확인
	p = (int*)malloc(N * sizeof(int));

	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++) //값 저장
		p[i] = num++;

	//동적할당 및 확인
	q = (int*)malloc((N - 1) * sizeof(int));

	if (q == NULL) {
		printf("Not enough memory");
		return -1;
	}

	//새로운 동적할당된 배열에 새롭게 배열값 저장
	for (int i = 0; i < N; i++) {
		if (p[i] == N / 2)	//중앙값을 제외하고
			continue;
		q[k++] = p[i];
	}

	for (int i = 0; i < N - 1; i++)	//배열 크기 하나 줄어듦에 유의
		printf(" %d", q[i]);

	//차례대로 동적할당 해제
	free(p);
	free(q);

	return 0;
}
/*
11
*/