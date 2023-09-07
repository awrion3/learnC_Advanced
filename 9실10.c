#pragma warning(disable:4996)
#include <stdio.h>

//�Լ� ����
void gcdlcm(int, int, int *, int *);

int main(void) {

	//���� ����
	int a, b, *pg = &a, *pl = &b;

	//���� �� �Է�
	scanf("%d%d", &a, &b);

	//�Լ� ȣ��
	gcdlcm(a, b, pg, pl);

	//���� �� ���
	printf("%d %d", *pg, *pl);

	return 0;
}

//�Լ� ����
void gcdlcm(int a, int b, int *x, int *y) {

	//���� ����
	int gcd, lcm;

	//�ִ����� gcd ���ϱ�
	for (int i = 1; i <= a && i <= b; i++)	//�� �� �� ���� ���� ��������
		if (a % i == 0 && b % i == 0)	//i�� ����������� �ִ� ����� ã��
			gcd = i;

	//�ּҰ���� lcm ���ϱ�
	lcm = a * b / gcd;

	//�����ͷ� ���� �����Ͽ� ���� �� ����
	*x = gcd, *y = lcm;
}