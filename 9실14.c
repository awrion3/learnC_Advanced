#pragma warning(disable:4996)
#include <stdio.h>

//�Լ� ����
int add_to_k(int *, int *);

int main(void) {

	//���� ����	
	int N, d[100], *p = d, res = 0;
	
	//���� �� �Է�
	scanf("%d", &N);

	for (; p < d + N; p++)	//������ Ȱ���� �迭 ���� �� �Է�
		scanf("%d", p);

	//�Լ� ȣ��
	p = d;	//������ �ּ� ���� �ʱ�ȭ//
	for (; p < d + N; p++)
		res += add_to_k(d, p);	//�ش� �ּ� ���� �� �� �����ϱ�

	//���� �� ���
	printf("%d\n", res);

	return 0;
}

//�Լ� ����
int add_to_k(int* a, int* b) {

	//���� ����
	int sum = 0, *p = a;

	for (; p <= b; p++)	//������ Ȱ���� �迭 ���� �� �� ���ϱ�
		sum += *p;

	//�� ��ȯ
	return sum;
}
