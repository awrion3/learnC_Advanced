#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char ar[101], *p = ar, *q = ar, tmp; //�� ���� ���
	int len = 0;

	scanf("%s", ar);	//���ڿ� �Է�

	for (; *p; p++)
		len++;	//���� ���� (�� ���� ����)

	for (int i = 0; i < len; i++) {	//���ڿ� ���̸�ŭ �ݺ�
		printf("%s\n", ar);

		tmp = *q;	//�Ǿ� ĭ�� ���� ����
		for (p = ar; p < ar + len - 1; p++)	//�ι�° ĭ���� ��ĭ�� ������ ����
			*p = *(p + 1);	//+1�̹Ƿ� ������ -1�Ͽ� �ε��� ����
		p = ar + len - 1;	 //������ ĭ���� ���� ��
		*p = tmp;			 //tmp�� ����� �Ǿ� ĭ�� ���� ����
	}
	
	return 0;
}