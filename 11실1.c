#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>	//동적할당 관련 헤더 파일

int main(void) {

	int N, *p, sum = 0;

	scanf("%d", &N);

	p = (int*)malloc(N * sizeof(int));
	if (p == NULL)
		return -1;	//동적할당 및 확인

	for (int i = 0; i < N; i++){
		scanf("%d", &p[i]);	//배열 형태로 포인터 사용
		sum += p[i];
	}

	printf("%d", sum);

	free(p);	//동적할당 해제

	return 0;
}
/*
6
3 2 0 1 4 6
*/