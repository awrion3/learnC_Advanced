#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� �Լ� ����

//�Լ� ����
int check(char*);

int main(void) {

	char str[31], *p = str;	//�� ���� ����
	int len, res;

	scanf("%s", str);	//���ڿ� �Է�

	len = strlen(str);
	printf("%d ", len);	//���� ���

	res = check(str);
	printf("%d", res);  //ȸ�� �Ǵ� ��� ���

	return 0;
}

//�Լ� ����
int check(char *str) {

	char *p = str, rst[31], *q = rst;
	int len, res;

	len = strlen(str); //���� ����

	for (p = str + len - 1; p >= str; p--, q++)
		*q = *p;	//������ rst ����
	*q = '\0';		//�� ���� �߰�(�ε��� ����)

	res = strcmp(str, rst);	//��ҹ��ڱ��� ����

	if (res == 0)	//����� ���� ��쿡�� 1 ��ȯ
		return 1;
	return 0;		//�׿� �׻� 0 ��ȯ
}
/*
Hello

aibohpphobia
*/