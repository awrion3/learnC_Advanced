#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N, *p, tmp;

	scanf("%d", &N);

	p = (int*)malloc(N * sizeof(int));	//�����Ҵ� ��...Ȯ��

	for (int i = 0; i < N; i++)
		scanf("%d", &p[i]);		//�����Ҵ��� �迭�� �� ����

	for (int i = 0; i < N - 1; i++)
		if (p[i] > p[i + 1]){	//�迭�� ���� ū �� �� �ڷ� �ű��
			tmp = p[i];
			p[i] = p[i + 1];
			p[i + 1] = tmp;
		}

	for (int i = 0; i < N; i++)
		printf("%d\n", p[i]);

	free(p);		//�����Ҵ� ����

	return 0;
}
/*
5
5 4 3 2 1
*/