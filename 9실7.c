#pragma warning(disable:4996)
#include <stdio.h>

//�Լ� ���� ����
void input(int *, int *, int *);
void output(int *, int *, int *);

int main(void) {

	//���� ����
	int x, y, z;

	//�Լ� ȣ��
	input(&x, &y, &z);
	output(&x, &y, &z);

	return 0;
}

//�Լ� ����
void input(int* a, int* b, int* c) {

	scanf("%d%d%d", a, b, c);	//�Է�(������ ���)
}

void output(int* a, int* b, int* c) {

	printf("%d %d %d", *a, *b, *c);	//���(������ ���)
}