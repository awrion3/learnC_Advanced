#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char ar[21], *p = ar; //���ڿ� ���� (�� ���� ����)

	scanf("%s", ar); //���� �������� �ʴ� �Է�

	for (; *p; p++) //���ڿ� ���� ���� NULL�̸� �ݺ� ����
		if (*p >= 'a' && *p <= 'z')
			printf("%c", *p);	//�ҹ��ڸ� ���

	return 0;
}

/*
for (int i = 0; ar[i]; i++)	//�迭 ����
*/