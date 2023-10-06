#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//���ڿ� ó�� ǥ�� �Լ� ����

int main(void) {

	char str[101], mins[101], maxs[101], *p, *fw, *lw, *w;	//�� ���� ����
	int N, len, minlen = 101, maxlen = -1;	//���� min,maxlen �񱳿��� < �̹Ƿ�, +1 -1 ������ ����
	
	scanf("%d", &N);	//���� �Է�
	getchar();			//����Ű ���� ����

	for (int i = 0; i < N; i++) {	//Nȸ �ݺ�
		gets_s(str, 100);		//������ �����ϴ� ���ڿ� �Է�
		len = strlen(str);		//���ڿ� ���� ���ϱ�

		if (len < minlen) {	
			minlen = len;		//�ּ� ���ڿ� ���� ����
			strcpy(mins, str);	//�ּ� ���� ���ڿ� ����
		}
		
		if (len > maxlen) {	
			maxlen = len;		//�ִ� ���ڿ� ���� ����
			strcpy(maxs, str);	//�ִ� ���� ���ڿ� ����
		}
	}

	//����� �ּ� �� �ִ� ���ڿ��� ����//
	for (p = mins; p < mins + minlen; p++)	//�� ���� ������ �Ⱦ�
		if (*p == ' ')				//���� ���� �� ���ڷ� ��� ��ü
			*p = '\0';			

	for (p = maxs; p < maxs + maxlen; p++)	//�� ���� ������ �Ⱦ�
		if (*p == ' ')				//���� ���� �� ���ڷ� ��� ��ü
			*p = '\0';

	//�ּ� ���� ���ڿ� ��, ���� ���� �ܾ� ã��
	w = mins, fw = mins;	//ù �ܾ�� ���� ���� �ܾ� ��� ó�� �ܾ�� �ʱ�ȭ
	for (p = mins; p < mins + minlen; p++) {	//���� ������ �� ���ڴ� �ȱ� ����
		if (*p == '\0') {	//�� ���� ������
			w = p + 1;		//�� ������ �ܾ� ù ���ڷ� ������ ����
		
			if (strcmp(w, fw) < 0)	//�� ���� �ܾ� ������
				fw = w;		//���� ���� �ܾ� ������ ����
		}
	}

	//�ִ� ���� ���ڿ� ��, ���� ���� �ܾ� ã��
	w = maxs, lw = maxs; 	//ù �ܾ�� ���� ���� �ܾ� ��� ó�� �ܾ�� �ʱ�ȭ
	for (p = maxs; p < maxs + maxlen; p++) {	//���� ������ �� ���ڴ� �ȱ� ����
		if (*p == '\0') {	//�� ���� ������
			w = p + 1;		//�� ������ �ܾ� ù ���ڷ� ������ ����

			if (strcmp(w, lw) > 0)	//�� ���� �ܾ� ������
				lw = w;		//���� ���� �ܾ� ������ ����
		}
	}

	printf("%s\n", fw);	//���� ���� �ܾ ����� ������ �������� �� ���� ������ ���
	printf("%s\n", lw);	//���� ���� �ܾ ���������� ���

	return 0;
}
/*
2
why so happy
icecream makes everything better
*/