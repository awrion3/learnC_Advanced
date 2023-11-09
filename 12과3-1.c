#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� ���� �Լ� ����
#include <stdlib.h>	//�����Ҵ� ���� �Լ� ����

//����ü ����
struct student {	
	char *studentName;	 // �л� �̸�
	char id[5];			 // �л� �й�
	char *subjectName;	 // ���� �̸�
	double subjectScore; // ���� ����
};

int main(void) {

	struct student *p, smp;			//����ü ������ ����
	char tmp[101], *t, wmp[101];	//���ڿ� ���� ����
	int N, len, wlen, cnt, num, K;	//������ ���� ����

	scanf("%d", &N);	//�л� �� �Է� �ޱ�
	getchar();			//����Ű ����

	p = (struct student*)malloc(N * sizeof(struct student));	//����ü �迭 �����Ҵ�1

	if (p == NULL) {					//�����Ҵ� �˻�1
		printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
		return -1;
	}

	for (int i = 0; i < N; i++){	//N���� ���� �Է�
		gets_s(tmp, 100);			//���� ���� �ӽ� ���ڿ� �Է�
		len = strlen(tmp);			//�ӽ� ���ڿ� ���� ���ϱ�

		for (t = tmp; t < tmp + len; t++)	//�ش� ���ڿ� �����ͷ� �����Ͽ�
			if (*t == ' ')   				//���� ���ڸ� �� ���ڷ� ��ü
				*t = '\0';
		
		strcpy(wmp, tmp);		//ù �ܾ� �����ϱ�
		wlen = strlen(wmp);		//ù �ܾ� ���� ���ϱ�
		cnt = 0;				//ī���� �ʱ�ȭ

		for (t = tmp; t < tmp + len; t++) {	//�ش� ���ڿ� �����ͷ� �����Ͽ�
			if (*t == '\0') {	//�� ���� ������
				strcpy(wmp, t + 1);		//���� �ܾ� �����ϱ�
				wlen = strlen(wmp);		//���� �ܾ� ���� ���ϱ�
				cnt++;			//ī���� ����
			}

			if (cnt == 0) {			//�л� �̸� �κ�
				p[i].studentName = (char*)malloc((wlen + 1) * sizeof(char));	//���ڿ� ���� �Ҵ�2

				if (p[i].studentName == NULL) {		//�����Ҵ� �˻�2
					printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
					return -1;
				}
				strcpy(p[i].studentName, wmp);		//�л� �̸� �����Ҵ�� ���ڿ��� ����
			}
			else if (cnt == 1) {	//�л� �й� �κ�
				strcpy(p[i].id, wmp);	//�л� �й� ����
			}
			else if (cnt == 2) {	//���� �̸� �κ�
				p[i].subjectName = (char*)malloc((wlen + 1) * sizeof(char));	//���ڿ� ���� �Ҵ�3

				if (p[i].subjectName == NULL) {		//�����Ҵ� �˻�3
					printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
					return -1;
				}
				strcpy(p[i].subjectName, wmp);		//���� �̸� �����Ҵ�� ���ڿ��� ����
			}
			else {					//���� ���� �κ�
				num = atoi(wmp);					//�ش� �ܾ� ������ ��ȯ
				p[i].subjectScore = (double)num;	//�Ǽ��� ��ȯ�Ͽ� ����
			}
		}
	}

	for (int i = 0; i < N - 1; i++)		//����ü �迭 ���� ����
		for (int j = 0; j < N - 1; j++)
			if (p[j].subjectScore < p[j + 1].subjectScore) {	//���� ���� �������� ����
				smp = p[j];
				p[j] = p[j + 1];		//����ü �� ����
				p[j + 1] = smp;
			}

	scanf("%d", &K);	//K��° �л� �Է�
	K--;				

	//K��° �л��� �л� �̸�, �й�, ���� �̸�, ���� ���� ����ϱ�
	printf("%s %s %s %.2lf", p[K].studentName, p[K].id, p[K].subjectName, p[K].subjectScore);

	//�����Ҵ� ����
	for (int i = 0; i < N; i++) {
		free(p[i].studentName);		//�л� �̸� �����Ҵ� ���� ����2
		free(p[i].subjectName);		//���� �̸� �����Ҵ� ���� ����3
	}
	free(p);	//����ü �迭 �����Ҵ� ����1

	return 0;
}
/*
5
HongGilDong 1003 Math 78
JeonWooChi 1001 English 60
HeungBoo 1002 Economics 80
NolBoo 1004 Ethics 50
Euler 1005 Math 100
2
*/