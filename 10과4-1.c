#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//���ڿ� ó�� ǥ�� �Լ� ����

//�Լ� ����
int check_u(char*, char*);

int main(void) {

	char str[101], mstr[101];			//�� ���� ����
	int N, max = 0, len, cnt, fl = 0;	//������ ���� ���� �� �ʱ�ȭ

	scanf("%d", &N);	//���ڿ� �� �� �Է�
	getchar();			//����Ű ���� ����

	for (int i = 0; i < N; i++) { //N���� ���ڿ� �Է�
		gets_s(str, 100);		  //������ �����Ͽ� ���ڿ� �Է�

		if (fl == 0) {			  //ù ���ڿ� �Է��� ���
			strcpy(mstr, str);	  //���ĺ��� ���� ���� ���ڰ� �ִ��� ���ڿ��� ����  
			fl = 1;
		}

		len = strlen(str);					//���ڿ� ���� ����
		cnt = check_u(str, str + len - 1);	//�Լ� ȣ���Ͽ� ���� ��ȯ

		if (max < cnt) {		//���ĺ��� ���� ���� ���ڰ� �ִ��� ���
			max = cnt;			//�ش� ������ ����
			strcpy(mstr, str);	//�ش� ���ڿ��� ����
		}
	}
	
	printf("%s", mstr);		//���ĺ��� ���� ���� ���� �ִ� ������ ���ڿ� ���

	return 0;
}

//�Լ� ����
int check_u(char *p, char *q) {

	char *t;		//������ ����
	int cnt = 0;	

	for (t = p; t <= q; t++) {	//���ڿ��� ó������ ������ ���ڱ��� �Ⱦ�
		if (!(*t >= 'A' && *t <= 'Z') && 
			!(*t >= 'a' && *t <= 'z') &&	//���� ���ĺ���
			!(*t == ' '))					//������ �ƴ� ������ ���
			cnt++;	//���� ī��Ʈ
	}	

	return cnt;		//���� ��ȯ
}
/*
5
1 year is 365 days.
How are you doing?
**Notice**
Winter is coming.
1 + 1 = 2

getchar();����ؾ� ��

���� ��� ������ 0������,
fl = 0���� �ϴ� ù��° �������� �ʱ�ȭ��
*/