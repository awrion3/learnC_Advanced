#pragma warning(disable:4996)
#include <stdio.h>

//�Լ� ����
void swap(int*, int*);

int main(void) {

	//���� ����
	int N, id1, id2, ar[50], *p = ar;

	//���� �� �Է�
	scanf("%d", &N);

	for (; p < ar + N; p++)	//������ �ּ� �� ����Ͽ� �迭 ���� ����
		scanf("%d", p);

	scanf("%d%d", &id1, &id2);

	//�Լ� ȣ��
	p = ar;	//������ �ּ� ���� �ʱ�ȭ//
	swap(p + id1, p + id2);

	//���� �� ���
	for (; p < ar + N; p++)
		printf(" %d", *p);

	return 0;
}

//�Լ� ����
void swap(int* a, int* b) {

	int tmp;	//���� ���� ����

	tmp = *a;	//tmp�� Ȱ���Ͽ� �� ��ȯ
	*a = *b;
	*b = tmp;	//������ ���� ������ ����Ͽ� ���� ����
}