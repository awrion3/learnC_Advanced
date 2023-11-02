#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N, *p, D, R;

	scanf("%d", &N);

	//�����Ҵ� �� Ȯ��
	p = (int*)malloc(N * sizeof(int));
	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++)
		scanf("%d", &p[i]);

	scanf("%d", &D);

	R = N - D;
	
	//�����Ҵ� �޸� ũ�� ���� �� Ȯ��
	p = (int*)realloc(p, R * sizeof(int));	//�ణ�� ������ �ٸ��� sizeof ������ ��� ����
	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	//����� �����Ҵ� ������ ���� ���
	for (int i = 0; i < R; i++)
		printf("%d\n", p[i]); //�ڿ������� �߸�

	free(p);	//�����Ҵ� ����

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