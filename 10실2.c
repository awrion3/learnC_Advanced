#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int n, num;	//������
	char ar[10], *p = ar; //������ (�� ���� ���)
	
	scanf("%d", &n);	//���� �Է�

	while (n != 0) {
		num = n % 10;	//�� �ڸ���

		if (num == 0)	//�Ǿ��� 0�̸� �ȵȴٴ� ���� �����Ƿ�
			*p = '0';
		else if (num == 1)
			*p = '1';
		else if (num == 2)
			*p = '2';
		else if (num == 3)
			*p = '3';
		else if (num == 4)
			*p = '4';
		else if (num == 5)
			*p = '5';
		else if (num == 6)
			*p = '6';
		else if (num == 7)
			*p = '7';
		else if (num == 8)
			*p = '8';
		else
			*p = '9';

		p++;	//������ �̵�
		n /= 10;		//�ڸ��� �и�
	}

	*p = '\0';	//���ڿ����� ǥ�� (�ε��� ������ ����)

	printf("%s", ar);	//���ڿ� ���

	return 0;
}