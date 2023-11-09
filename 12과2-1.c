#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� ���� �Լ� ����
#include <stdlib.h>	//�����Ҵ� ���� �Լ� ����

int main(void) {

	int len, N = 0, wlen, i;			//������ ���� ����
	char tmp[101], *t, **p, wmp[101];	//������ ���� ����

	gets_s(tmp, 100);	//������ �����ϴ� �ӽ� ���ڿ� �Է�
	len = strlen(tmp);	//�ӽ� ���ڿ� ���� ���ϱ�

	for (t = tmp; t < tmp + len; t++)	//�ӽ� ���ڿ� �����Ͽ�
		if (*t == ' '){		//���� ���ڸ� �� ���ڷ� ��ü
			*t = '\0';
			N++;			//�ܾ� ���� ī��Ʈ
		}
	N++;	//�ܾ� ���� ����

	p = (char**)malloc(N * sizeof(char*));	//������ �迭 �����Ҵ�

	if (p == NULL) {					//�����Ҵ� �˻�
		printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
		return -1;
	}

	strcpy(wmp, tmp);	//ù �ӽ� �ܾ� ����
	wlen = strlen(wmp);	//ù �ӽ� �ܾ��� ���� ����
	for (t = tmp, i = 0; t < tmp + len; t++) {	//�ӽ� ���ڿ� �Ⱦ�
		if (*t == '\0') {			//�� ���� ���� ������
			strcpy(wmp, t + 1);		//���� �ܾ� ����
			wlen = strlen(wmp);		//���� �ܾ� ���� ����
			i++;	//�ε��� ����
		}

		p[i] = (char*)malloc((wlen + 1) * sizeof(char));	//���� �迭 �����Ҵ�

		if (p[i] == NULL) {					//�����Ҵ� �˻�
			printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
			return -1;
		}

		strcpy(p[i], wmp);	//�� �ܾ� ����
	}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)		//2���� �迭 ���� ���� 
			if (strlen(p[j]) <= strlen(p[j + 1])) {	//�ܾ� ���� �迭 ���� Ȯ���Ͽ�
				if (strlen(p[j]) < strlen(p[j + 1])) {	//���ڰ� �� �� ���
					t = p[j];
					p[j] = p[j + 1];	//�� ���� �迭 ������ ��ü
					p[j + 1] = t;
				}
				else {	//���̰� ���� ���
					if (strcmp(p[j], p[j + 1]) > 0) {	//���ڰ� ���� �� ���� ���
						t = p[j];
						p[j] = p[j + 1];	//�� ���� �迭 ������ ��ü
						p[j + 1] = t;
					}
				}
			}
		
	for (int i = 0; i < N; i++)	//���ĵ� ��� ���
		printf("%s\n", p[i]);

	for (int i = 0; i < N; i++)	
		free(p[i]);		//���� �迭 �����Ҵ� ���� ����
	free(p);			//������ �迭 ����

	return 0;
}
/*
red orange yellow green blue purple
*/