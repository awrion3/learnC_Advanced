#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� ���� �Լ� ����
#include <stdlib.h>	//�����Ҵ� ���� �Լ� ����

int main(void) {

	int len, blen, N = 0, M = 0, wlen, i, k = 0;		//������ ���� ����
	int d = 0, fl = 0, dl = 0;
	char tmp[101], *t, **p, wmp[101];					//������ ���� ����
	char bmp[101], **q, res[200][201] = { 0 }, cmp[101], hit[100][101] = { 0 };

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

	//�ӽ� ���ڿ� B�� ���Ͽ�
	q = (char**)malloc(M * sizeof(char*));	//������ �迭 �����Ҵ�

	if (q == NULL) {					//�����Ҵ� �˻�
		printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
		return -1;
	}

	strcpy(wmp, bmp);	//ù �ӽ� �ܾ� ����
	wlen = strlen(wmp);	//ù �ӽ� �ܾ��� ���� ����

	for (t = bmp, i = 0; t < bmp + blen; t++) {	//�ӽ� ���ڿ� �Ⱦ�
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

	//�����Ҵ��� ���� ���ڿ� A���� ���Ͽ�
	for (i = 0; i < N; i++)			
		for (int j = 0; j < N; j++)		
			if (strcmp(p[i], p[j])) {	//���ڿ� �� �ٸ� �� ���� �ܾ��� ���
				strcpy(cmp, p[i]);	//�� �ܾ �ռ��ϱ�
				strcat(cmp, p[j]);
				strcpy(res[k++], cmp);	//�ռ��� �ܾ� �迭 res�� ����

				strcpy(cmp, p[j]);	//�������� �� �ܾ �ռ��ϱ�
				strcat(cmp, p[i]);
				strcpy(res[k++], cmp);	//�������� �ռ��� �ܾ� �迭 res�� ����
			}
	
	for (int j = 0; j < M; j++)	{			//���ڿ� B�� ���ؼ�
		fl = 0;
		for (i = 0; i < k; i++) 			//���ڿ� A�� �ռ��� �ܾ
			if (strcmp(res[i], q[j]) == 0) 	//���ڿ� B�� �ִ� ��� ǥ���ϱ�
				fl = 1;	

		if (fl == 1) {						//���ڿ� B�� �ִ� ���,
			dl = 0;
			for (int w = 0; w < d; w++)		//�ռ� �ܾ� �迭 hit�� �̹� ������ ���
				if (strcmp(hit[w], q[j]) == 0)
					dl = 1;					//�ߺ� ǥ���ϱ�

			if (dl == 0)					//�ߺ����� ������
				strcpy(hit[d++], q[j]);		//�ش� �ܾ� �ռ� �ܾ� �迭 hit�� ����
		}
	}
	
	for (i = 0; i < d - 1; i++)			//�ռ� �ܾ� �迭�� ���� �����ϱ�
		for (int j = 0; j < d - 1; j++)
			if (strlen(hit[j]) <= strlen(hit[j + 1])) {		//�ܾ� ���� Ȯ���Ͽ�
				if (strlen(hit[j]) < strlen(hit[j + 1])) {	//���� �� �������� ����
					strcpy(cmp, hit[j]);
					strcpy(hit[j], hit[j + 1]);		//�ܾ� ���� ��ȯ
					strcpy(hit[j + 1], cmp);
				}
				else {	//�ܾ� ���� ���� ���
					if (strcmp(hit[j], hit[j + 1]) > 0) {	//���� �� ���� �ܾ� �տ� ����
						strcpy(cmp, hit[j]);
						strcpy(hit[j], hit[j + 1]);	//�ܾ� ���� ��ȯ
						strcpy(hit[j + 1], cmp);
					}
				}
			}

	for (i = 0; i < d; i++)		//���ĵ� ���ڿ� B�� �ִ� �ռ� �ܾ� ����Ʈ ���
		printf("%s\n", hit[i]);

	for (i = 0; i < N; i++) //���ڿ� A�� ���Ͽ�
		free(p[i]);		//���� �迭 �����Ҵ� ���� ����
	free(p);			//������ �迭 ����

	for (i = 0; i < M; i++)	//���ڿ� B�� ���Ͽ�
		free(q[i]);		//���� �迭 �����Ҵ� ���� ����
	free(q);			//������ �迭 ����

	return 0;
}
/*
red orange yellow green blue purple
pink red redorange orangered yellow black bluegreen white purple

apple or ange pineapple coconuts lemons ora nge
appleapple orange orlemons

�ռ� �ܾ� ����Ʈ res �迭�� ũ�� �� ����ϱ�
(�ϴ� ���� [200]�� ���� ���յ� �����Ƿ�, 
�ִ� �ܾ� ���� ���� * 2�� ���ɼ� ����)
(�׸��� [200][101]�� runtime error �߻�.
�ֳ��ϸ� ���ڿ� A�� �� �ܾ� ���̰� 100�̸�,
�׸��� �� �ٸ� �ܾ� ���̵� 100�̸�, ���� �����ϸ�
���̴� 200 + 1�� �ȴ�)
*/