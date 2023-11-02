#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N, fl = 0;
	float *p, max;

	scanf("%d", &N);

	p = (float*)malloc(N * sizeof(float));

	for (int i = 0; i < N; i++) {
		scanf("%f", p + i);	//float는 scanf할 때도 f 사용
		
		if (fl == 0) {
			max = *(p + i);	//초기값 max
			fl = 1;
		}
		if (max < *(p + i))	//포인터 형태로 포인터 사용
			max = *(p + i);
	}

	printf("%.2f", max);

	free(p);

	return 0;
}
/*
5
1.1 2.5 3.4 6.1 7.8
*/