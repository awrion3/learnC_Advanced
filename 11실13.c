#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N, *p, D, R;

	scanf("%d", &N);

	//동적할당 및 확인
	p = (int*)malloc(N * sizeof(int));
	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++)
		scanf("%d", &p[i]);

	scanf("%d", &D);

	R = N - D;
	
	//동적할당 메모리 크기 변경 및 확인
	p = (int*)realloc(p, R * sizeof(int));	//약간의 형식은 다르나 sizeof 여전히 사용 권장
	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	//변경된 동적할당 공간의 값들 출력
	for (int i = 0; i < R; i++)
		printf("%d\n", p[i]); //뒤에서부터 잘림

	free(p);	//동적할당 해제

	return 0;
}
/*
3
16011111
16011123
16011145
2

4
120111
15011123
16011145
16011300
1
*/