#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//���ڿ� ó�� ǥ�� �Լ� ����

int main(void) {

	char str[101], *p, *w = str, *fw = str;	//�� ���� ����
	int len;								//������ ���� ����

	gets_s(str, 100);		//���� ���� �Է�
	len = strlen(str);		//���ڿ� ���� ���ϱ�

	for (p = str; p <= str + len; p++) {	//���� ���ڿ��� �� ���ڷ� ��ü
		if (*p == ' ') 			
			*p = '\0';
	}

	for (p = str; p < str + len; p++) {		//������ �� ���ڸ� �����ϰ� �Ⱦ�
		if (*p == '\0') {			//���̻��� �� ���� ���� ������
			w = p + 1;				//�ܾ� ������ �� ���� �������� ���� ����

			if (strcmp(w, fw) < 0)	//�� �ܾ ���� ���� �ܾ�� �� ���� ���
				fw = w;				//���� ���� �ܾ�� ����
		}
	}

	printf("%s", fw);	//������ ���� ���� �ܾ� ���

	return 0;
}
/*
why so happy
icecream makes everything better

����:
���� \0�� ���� ��� �߰� ���ߴٸ� ���� ���ϴ� ��������
�����Ͱ� ����Ű�� �������� �� ���� ���� ������ �� �����ϰ� �� 
*/