#pragma warning(disable:4996)
#include <stdio.h>

//�Լ� ����
void strcopy(char [], char []);

int main(void) {

	//���� ����
	char a[6], b[6], *p = a, *q = b;

	//���� �� �Է�(�迭 a[6])
	for (; p < a + 6; p++)
		scanf("%c", p);

	//�Լ� ȣ��
	strcopy(a, b); //(�迭 �̸��� 0�� ������) �ּ� ������ ����

	//���� �� ���(�迭 b[6])
	for (; q < b + 6; q++)
		printf("%c", *q);

	return 0;
}

//�Լ� ����
void strcopy(char a[], char b[]) {	//�迭 ������ ���� ���� ���

	//���� ����
	char *p = a, *q = b;

	//���� �� �Է�
	for (; p < a + 6; p++, q++)
		*q = *p; //�����͸� Ȱ���Ͽ� �迭 ���� ���� ����
}