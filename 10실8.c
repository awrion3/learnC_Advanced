#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� �Լ� ����

int main(void) {

	char ar[51], br[51], cr[101], *p, *q = cr; //cr�� ��� 50 + 50 + 1�ι���
	int res;

	//���ڿ� �Է�
	scanf("%s", ar);
	scanf("%s", br);

	//���ڿ� ��
	res = strcmp(ar, br);

	if (res < 0) {	//ar < br ������ br�� �ڿ� �ִ� ���,
		strcpy(cr, br);	//������ �������� br ���� ���� ��
		strcat(cr, ar);	//ar �����ϱ�
	}
	else {			//������ ar�� �ڿ� �ִ� ���,
		strcpy(cr, ar);	//ar ���� ���� ��
		strcat(cr, br);	//br �����ϱ�
	}

	//���ڿ� ���
	printf("%s\n", cr);
	
	return 0;
}