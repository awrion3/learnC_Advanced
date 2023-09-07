#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N, x[100], max = 1, cnt = 1, mdx;

	//
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);

	//
	mdx = N - 1; //최대 부분배열 길이 1인 경우에 마지막 배열(원소) 인덱스
	for (int i = 0; i < N - 1; i++)
		if (x[i] * x[i + 1] < 0) {
			cnt++;
			if (max <= cnt) { //마지막 배열
				max = cnt;
				mdx = i + 1;
			}
		}
		else
			cnt = 1;

	//
	printf("%d\n", max);

	for (int i = mdx - max + 1; i <= mdx; i++)
		printf(" %d", x[i]);

	return 0;
}