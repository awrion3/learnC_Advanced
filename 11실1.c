#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>	//�����Ҵ� ���� ��� ����

int main(void) {

	int N, *p, sum = 0;

	scanf("%d", &N);

	p = (int*)malloc(N * sizeof(int));
	if (p == NULL)
		return -1;	//�����Ҵ� �� Ȯ��

	for (int i = 0; i < N; i++){
		scanf("%d", &p[i]);	//�迭 ���·� ������ ���
		sum += p[i];
	}

	printf("%d", sum);

	free(p);	//�����Ҵ� ����

	return 0;
}
/*
6
3 2 0 1 4 6
*/