#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N, *p, tmp;

	scanf("%d", &N);

	p = (int*)malloc(N * sizeof(int));	//동적할당 및...확인

	for (int i = 0; i < N; i++)
		scanf("%d", &p[i]);		//동적할당한 배열에 값 저장

	for (int i = 0; i < N - 1; i++)
		if (p[i] > p[i + 1]){	//배열의 가장 큰 값 맨 뒤로 옮기기
			tmp = p[i];
			p[i] = p[i + 1];
			p[i + 1] = tmp;
		}

	for (int i = 0; i < N; i++)
		printf("%d\n", p[i]);

	free(p);		//동적할당 해제

	return 0;
}
/*
5
5 4 3 2 1
*/