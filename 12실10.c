#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N, *p, num = 0, *q, k = 0;
	
	scanf("%d", &N);
	
	//�����Ҵ� �� Ȯ��
	p = (int*)malloc(N * sizeof(int));

	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++) //�� ����
		p[i] = num++;

	//�����Ҵ� �� Ȯ��
	q = (int*)malloc((N - 1) * sizeof(int));

	if (q == NULL) {
		printf("Not enough memory");
		return -1;
	}

	//���ο� �����Ҵ�� �迭�� ���Ӱ� �迭�� ����
	for (int i = 0; i < N; i++) {
		if (p[i] == N / 2)	//�߾Ӱ��� �����ϰ�
			continue;
		q[k++] = p[i];
	}

	for (int i = 0; i < N - 1; i++)	//�迭 ũ�� �ϳ� �پ�꿡 ����
		printf(" %d", q[i]);

	//���ʴ�� �����Ҵ� ����
	free(p);
	free(q);

	return 0;
}
/*
11
*/