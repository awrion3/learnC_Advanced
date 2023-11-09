#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� ���� �Լ� ����
#include <stdlib.h>	//�����Ҵ� ���� �Լ� ����

//����ü ����
struct student {
	char *name;		// �л� �̸�
	char id[5];		// �л� �й�
	int numSubject; // ���� ����
	struct subject *psub;	// ���� ����ü ������
	double avg;				// ��� ������ ��� ����
};

struct subject {
	char *name;		// ���� �̸�
	double score;	// ���� ����
};

int main(void) {

	struct student *p, smp;			//����ü ������ ����	
	int N, len, M, wlen, wnt, sl, idx, num, cl, K;	//������ ���� ����
	char tmp[101], *t, wmp[101], *sub = NULL;	//������ ���� ����
	double sum, max = -1;							//�Ǽ��� ���� ����

	scanf("%d", &N);	//�л� �� �Է�
	getchar();			//���� Ű ����

	//����ü �迭 �����Ҵ�1
	p = (struct student*)malloc(N * sizeof(struct student));	

	if (p == NULL) {					//�����Ҵ� �˻�1
		printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
		return -1;
	}

	for (int i = 0; i < N; i++) {	//�л� �� ��ŭ �Է¹ޱ�
		gets_s(tmp, 100);	//������ �ִ� �ӽ� ���ڿ� �Է�
		len = strlen(tmp);	//�ӽ� ���ڿ� ���� ���ϱ�

		M = 0;	//���� �� �ʱ�ȭ
		for (t = tmp; t < tmp + len; t++) {	//�ӽ� ���ڿ� �����Ͽ�
			if (*t == ' ') {	//���� ���ڸ� �� ���ڷ� ��ü
				*t = '\0';
				M++;		//���� �� ���� ���
			}
		}
		M = (M - 1) / 2;	//���� �� ����

		strcpy(wmp, tmp);	//ù �ܾ� ����
		wlen = strlen(wmp);	//ù �ܾ� ���� ���ϱ�
		wnt = 0, sl = 0, idx = 0, cl = 0, sum = 0;	//ī���� �ʱ�ȭ

		for (t = tmp; t < tmp + len; t++) {	//�ӽ� ���ڿ� �����Ͽ�
			if (*t == '\0') {	//�� ���� ������
				strcpy(wmp, t + 1);	//���� �ܾ� ����
				wlen = strlen(wmp);	//���� �ܾ� ���� ���ϱ�
				wnt++;

				if (cl == 2)	//���� �������� ������ ���
					idx++;		//���� ���� �ε��� ����
			}
			cl = 0;		//���� ���� �ε��� �ʱ�ȭ

			if (wnt == 0) {			//�л� �̸� �κ�
				//���ڿ� �����Ҵ�2
				p[i].name = (char*)malloc((wlen + 1) * sizeof(char));

				if (p[i].name == NULL) {	//�����Ҵ� �˻�2
					printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
					return -1;
				}
				strcpy(p[i].name, wmp);		//�л� �̸� �����Ҵ�� ���ڿ��� ����
			}
			else if (wnt == 1) {	//�л� �й� �κ�
				strcpy(p[i].id, wmp);		//�л� �й� ���ڿ��� ����
			}
			else {					//���� ���� �κ�
				if (sl == 0) {	//�л� �� ó�� ���� �ÿ��� �ǽ�
					//��ø ����ü �迭 �����Ҵ�3 
					p[i].psub = (struct subject*)malloc(M * sizeof(struct subject));

					if (p[i].psub == NULL) {			//�����Ҵ� �˻�3
						printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
						return -1;
					}
					sl = 1;		//�л� �� ���ĺ��ʹ� ����
				}

				if (*t >= 'A' && *t <= 'Z' || *t >= 'a' && *t <= 'z') {	//���� �̸� �κ�
					//��ø ����ü ���ڿ� �����Ҵ�4
					p[i].psub[idx].name = (char*)malloc((wlen + 1) * sizeof(char));

					if (p[i].psub[idx].name == NULL) {	//�����Ҵ� �˻�4
						printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
						return -1;
					}
					strcpy(p[i].psub[idx].name, wmp);		//���� �̸� �����Ҵ�� ���ڿ��� ����

					cl = 1;		//���� �̸����� ǥ��
				}
				else {								//���� ���� �κ�
					num = atoi(wmp);	//���ڿ� ������ ��ȯ
					p[i].psub[idx].score = (double)num;		//�Ǽ��� ��ȯ�Ͽ� ���� ���� ����

					cl = 2;		//���� �������� ǥ��
				}
			}
		}
		
		p[i].numSubject = M;			//���� �� ����

		for (int j = 0; j < M; j++)		//�ش� �л��� ��� ���� ���ϱ�
			sum += p[i].psub[j].score;
		p[i].avg = sum / M;				//��� ���� ����
	}

	for (int i = 0; i < N - 1; i++)			//����ü �迭 ���� �����ϱ�
		for (int j = 0; j < N - 1; j++) 
			if (p[j].avg <= p[j + 1].avg) {	//��� ���� Ȯ���Ͽ�
				if (p[j].avg < p[j + 1].avg) {			//�������� ����
					smp = p[j];
					p[j] = p[j + 1];			//����ü �� �����Ͽ� ��ȯ
					p[j + 1] = smp;
				}
				else {
					if (strcmp(p[j].id, p[j + 1].id) > 0) {	//�й� �� ����
						smp = p[j];
						p[j] = p[j + 1];		//����ü �� �����Ͽ� ��ȯ
						p[j + 1] = smp;
					}
				}
			}

	scanf("%d", &K);	//K��° �л� �Է¹ޱ�
	K--;	//�ε��� ����

	printf("%s %s %.2lf ", p[K].name, p[K].id, p[K].avg);	//�ش� �л��� �̸�, �й�, ��� ���� ���

	for (int i = 0; i < p[K].numSubject; i++) {	//�ش� �л��� ���� ����ü �����Ͽ�
		if (max < p[K].psub[i].score) {		//���� ������ ���� ���� ���� ����
			max = p[K].psub[i].score;
			sub = p[K].psub[i].name;		//���� ������ ���� ���� �̸� ����
		}
	}

	printf("%s %.2lf", sub, max);	//�ش� �л��� �ְ���� ���� �̸��� ���� ���

	// �����Ҵ� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < p[i].numSubject; j++)
			free(p[i].psub[j].name);	//��ø ����ü ���ڿ� �����Ҵ� ����4
		free(p[i].name);			//���ڿ� �����Ҵ� ����2
		free(p[i].psub);				//��ø ����ü �迭 �����Ҵ� ����3
	}
	free(p);						//����ü �迭 �����Ҵ� ����1
	
	return 0;
}
/*
5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
4
*/