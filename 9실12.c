#pragma warning(disable:4996)
#include <stdio.h>

//�Լ� ����
void addArray(int *, int *, int *, int);

int main(void) {

	//���� ����
	int N, ar[20] = { 0 }, br[20] = { 0 }, cr[20] = { 0 };
	int *p = ar, *q = br, *r = cr;

	//���� �� �Է�
	scanf("%d", &N);

	for (; p < ar + N; p++)	//ù��° �迭 �� ����
		scanf("%d", p);

	for (; q < br + N; q++)	//�ι�° �迭 �� ����
		scanf("%d", q);

	//�Լ� ȣ��
	addArray(ar, br, cr, N);
	
	//���� �� ���
	for (; r < cr + N; r++)
		printf(" %d", *r);

	return 0;
}

//�Լ� ����
void addArray(int* a, int* b, int* c, int s) {

	//���� ����
	int *p = a, *q = b + s - 1, *r = c;

	for (; r < c + s; p++, q--, r++) //������ (�ּ� ��) ����� �迭�� �� ����
		*r = *p + *q;
}