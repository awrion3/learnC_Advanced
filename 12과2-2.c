#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� ���� �Լ� ����
#include <stdlib.h>	//�����Ҵ� ���� �Լ� ����

int main(void) {

	int len, blen, N = 0, M = 0, wlen, i = 0, k = 0, idx;	//������ ���� ����
	char tmp[101], *t, **p, wmp[101];						//������ ���� ����
	char bmp[101], **q, res[100][101] = { 0 };

	gets_s(tmp, 100);	//������ �����ϴ� �ӽ� ���ڿ�A �Է�
	gets_s(bmp, 100);	//������ �����ϴ� �ӽ� ���ڿ�B �Է�

	len = strlen(tmp);	//�ӽ� ���ڿ�A ���� ���ϱ�
	for (t = tmp; t < tmp + len; t++)	//�ӽ� ���ڿ�A �����Ͽ�
		if (*t == ' ') {		//���� ���ڸ� �� ���ڷ� ��ü
			*t = '\0';
			N++;			//�ܾ� ���� ī��Ʈ
		}
	N++;	//�ܾ� ���� ����

	blen = strlen(bmp);	//�ӽ� ���ڿ�B ���� ���ϱ�
	for (t = bmp; t < bmp + blen; t++)	//�ӽ� ���ڿ�B �����Ͽ�
		if (*t == ' ') {		//���� ���ڸ� �� ���ڷ� ��ü
			*t = '\0';
			M++;			//�ܾ� ���� ī��Ʈ
		}
	M++;	//�ܾ� ���� ����

	//�ӽ� ���ڿ� A�� ���Ͽ�
	p = (char**)malloc(N * sizeof(char*));	//������ �迭 �����Ҵ�

	if (p == NULL) {					//�����Ҵ� �˻�
		printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
		return -1;
	}

	strcpy(wmp, tmp);	//ù �ӽ� �ܾ� ����
	wlen = strlen(wmp);	//ù �ӽ� �ܾ��� ���� ����

	for (t = tmp; t < tmp + len; t++) {	//�ӽ� ���ڿ� �Ⱦ�
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

	//�ӽ� ���ڿ� B�� ���Ͽ�
	q = (char**)malloc(M * sizeof(char*));	//������ �迭 �����Ҵ�

	if (q == NULL) {					//�����Ҵ� �˻�
		printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
		return -1;
	}

	strcpy(wmp, bmp);	//ù �ӽ� �ܾ� ����
	wlen = strlen(wmp);	//ù �ӽ� �ܾ��� ���� ����
	i = 0;				//�ε��� �ʱ�ȭ

	for (t = bmp; t < bmp + blen; t++) {	//�ӽ� ���ڿ� �Ⱦ�
		if (*t == '\0') {			//�� ���� ���� ������
			strcpy(wmp, t + 1);		//���� �ܾ� ����
			wlen = strlen(wmp);		//���� �ܾ� ���� ����
			i++;	//�ε��� ����
		}
		q[i] = (char*)malloc((wlen + 1) * sizeof(char));	//���� �迭 �����Ҵ�

		if (q[i] == NULL) {					//�����Ҵ� �˻�
			printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
			return -1;
		}

		strcpy(q[i], wmp);	//�� �ܾ� ����
	}

	for (int i = 0; i < N; i++)			//�����Ҵ�� �� ���ڿ��� ���� ���ϸ�
		for (int j = 0; j < M; j++)	
			if (strcmp(p[i], q[j]) == 0) 	//�������� ��Ÿ���� �ܾ� ���� ��
				strcpy(res[k++], p[i]);		//�ش� �ܾ� res �迭�� ����

	idx = k;	//�ε��� ����
	for (int i = 0; i < idx - 1; i++)		//���� �ܾ� �迭 ���� �����ϱ�
		for (int j = 0; j < idx - 1; j++)
			if (strlen(res[j]) <= strlen(res[j + 1])) {		//���� ��������
				if (strlen(res[j]) < strlen(res[j + 1])) {	//���ڰ� �� ��� �������� ����
					strcpy(tmp, res[j]);
					strcpy(res[j], res[j + 1]);			//�ܾ� ���� �迭 �� ��ȯ
					strcpy(res[j + 1], tmp);
				}
				else {										//���̰� ���� ���
					if (strcmp(res[j], res[j + 1]) > 0) {	//���ڰ� ���� �� ���� ��� ����
						strcpy(tmp, res[j]);
						strcpy(res[j], res[j + 1]);		//�ܾ� ���� �迭 �� ��ȯ
						strcpy(res[j + 1], tmp);
					}
				}
			}

	for (int i = 0; i < idx; i++)	//���ĵ� ��� ���
		printf("%s\n", res[i]);

	for (int i = 0; i < N; i++) //���ڿ� A�� ���Ͽ�
		free(p[i]);		//���� �迭 �����Ҵ� ���� ����
	free(p);			//������ �迭 ����

	for (int i = 0; i < M; i++)	//���ڿ� B�� ���Ͽ�
		free(q[i]);		//���� �迭 �����Ҵ� ���� ����
	free(q);			//������ �迭 ����

	return 0;
}
/*
red orange yellow green blue purple
pink red yellow black white purple

red
red

getchar()�� 
gets()�� scanf("%c")�տ� ���̳�,
gets()�� �� �տ� �� ��� ���� �ʿ�X
*/