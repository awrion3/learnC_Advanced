#pragma warning(disable:4996)
#include <stdio.h>

//�Լ� ����
int arrsum(int *, int *);

int main(void) {

	//���� ����
	int N, ar[100], S, E, *p = ar;

	//���� �� �Է�
	scanf("%d%d%d", &N, &S, &E);

	for (; p < ar + N; p++)	//�迭�� ������ ����Ͽ� ����
		scanf("%d", p);

	//�Լ� ȣ�� �� ��ȯ�� ���
	printf("%d", arrsum(ar + S, ar + E));

	return 0;
}

//�Լ� ����
int arrsum(int* a, int* b) {

	//���� ����
	int sum = 0, *p = a;

	//�ش� ���� �� �迭 ������ �� ���ϱ�
	for (; p <= b; p++)
		sum += *p;

	return sum;	//�� ��ȯ
}
