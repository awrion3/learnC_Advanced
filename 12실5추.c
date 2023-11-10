#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string {
	char* str;
	int words;
	//
	int wmax;
	char mst[101];
};

int main(void) {

	struct string *p, smp;
	int N, tlen, k, wlen, cnt, max, num;
	char tmp[101], *t, **q = NULL;

	scanf("%d", &N);
	getchar();

	//����ü �迭 �����Ҵ�1
	p = (struct string*)malloc(N * sizeof(struct string));

	if (p == NULL) {	//����ü �迭 �����Ҵ� Ȯ��1
		printf("Not enough memory!");
		return -1;
	}

	for (int i = 0; i < N; i++) {	//N���� ���ڿ� �Է¹ޱ�
		gets_s(tmp, 100);
		tlen = strlen(tmp);

		//����ü ��� ���ڿ� �����Ҵ�2
		p[i].str = (char*)malloc((tlen + 1) * sizeof(char));

		if (p[i].str == NULL) {	//����ü ��� ���ڿ� �����Ҵ� Ȯ��2
			printf("Not enough memory!");
			return -1;
		}

		strcpy(p[i].str, tmp);
		//
		num = 1;
		for (t = tmp; t < tmp + tlen; t++)
			if (*t == ' ') {
				*t = '\0';
				num++;
			}

		p[i].words = num;

		//���� ������ �迭 �����Ҵ�3
		q = (char**)malloc(num * sizeof(char*));

		if (q == NULL) {	//���� ������ �迭 �����Ҵ� Ȯ��3
			printf("Not enough memory!");
			return -1;
		}

		k = 0;
		wlen = strlen(tmp);

		//�ܾ� ���� �迭 �����Ҵ�4
		q[k] = (char*)malloc((wlen + 1) * sizeof(char));

		if (q[k] == NULL) {		//�ܾ� ���� �迭 �����Ҵ� Ȯ��4
			printf("Not enough memory!");
			return -1;
		}

		strcpy(q[k], tmp);

		for (t = tmp; t < tmp + tlen; t++) {
			if (*t == '\0') {
				k++;
				wlen = strlen(t + 1);

				//�ܾ� ���� �迭 �����Ҵ�4
				q[k] = (char*)malloc((wlen + 1) * sizeof(char));

				if (q[k] == NULL) {		//�ܾ� ���� �迭 �����Ҵ� Ȯ��4
					printf("Not enough memory!");
					return -1;
				}

				strcpy(q[k], t + 1);
			}
		}

		max = -1;
		for (int j = 0; j < p[i].words; j++) {
			cnt = 0;
			for (int l = 0; l < p[i].words; l++)
				if (strcmp(q[j], q[l]) == 0) {
					cnt++;
					if (cnt >= max) {
						if (cnt > max) {
							max = cnt;
							p[i].wmax = max;
							strcpy(p[i].mst, q[j]);
						}
						else {
							if (strcmp(p[i].mst, q[j]) > 0) {
								max = cnt;
								p[i].wmax = max;
								strcpy(p[i].mst, q[j]);
							}
						}
					}
				}
		}
		//�ܾ� ���� �迭 �����Ҵ� ����4
		for (k = 0; k < num; k++)
			free(q[k]);
		//���� ������ �迭 �����Ҵ� ����3
		free(q);
	}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			if (p[j].words < p[j + 1].words) {
				smp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = smp;
			}

	for (int i = 0; i < N; i++)
		printf("%s %d %s %d\n", p[i].str, p[i].words, p[i].mst, p[i].wmax);

	//����ü ��� ���ڿ� �����Ҵ� ����2
	for (int i = 0; i < N; i++)
		free(p[i].str);
	//����ü �迭 �����Ҵ� ����1
	free(p);

	return 0;
}
/*
5
why why why so so so serious
icecream makes everything better and better
you make me smile
c language exam and exam and exam and exam
see you later later later later
*/