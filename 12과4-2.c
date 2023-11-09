#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� ���� �Լ� ����
#include <stdlib.h>	//�����Ҵ� ���� �Լ� ����

//����ü ����
struct student {
	char* name; // �̸� ����
	int firstStage; // 1�ܰ� ���� ����
	int interview;	// ���� ���� ����
	double sum; // ���� ����
};

int main(void) {

	struct student *p, smp;	//����ü ���� ����
	int N, M, tlen, fir, cut = 0;	//������ ���� ����
	char tmp[11];			//������ ���� ����
	double tot;				//�Ǽ��� ���� ����

	scanf("%d %d", &N, &M);	//1�ܰ� �հ����� ��, ���� �հ��� ���� �Է�

	//����ü �迭 �����Ҵ�1
	p = (struct student*)malloc(N * sizeof(struct student));

	if (p == NULL) {				//�����Ҵ� ���� �˻�1
		printf("Not enough Memory");		//�����Ҵ� ���� �� ����
		return -1;
	}

	for (int i = 0; i < N; i++) {	//N���� ������ ���� �Է��ϱ�
		scanf("%s %d %d", tmp, &p[i].firstStage, &p[i].interview);
		tlen = strlen(tmp);		//�ӽ� ���ڿ� ���� ���ϱ�

		//���ڿ� �����Ҵ�2
		p[i].name = (char*)malloc((tlen + 1) * sizeof(char));

		if (p[i].name == NULL) {	//�����Ҵ� ���� �˻�2
			printf("Not enough Memory");	//�����Ҵ� ���� �� ����
			return -1;
		}

		strcpy(p[i].name, tmp);	//�����Ҵ�� ���ڿ��� �̸� ����

		p[i].sum = 7 * p[i].firstStage + 3 * p[i].interview;	//�ӽ� ���� ���ϱ�
	}

	for (int i = 0; i < N - 1; i++)			//����ü �迭 ���� ����
		for (int j = 0; j < N - 1; j++)
			if (p[j].sum <= p[j + 1].sum) {	//���� Ȯ���Ͽ�
				if (p[j].sum < p[j + 1].sum) {	//���� �������� ����
					smp = p[j];
					p[j] = p[j + 1];		//����ü �� �����Ͽ� ��ȯ
					p[j + 1] = smp;
				}
				else {						//���� ���� ���
					if (p[j].firstStage <= p[j + 1].firstStage) {	//1�ܰ� ���� Ȯ���Ͽ�
						if (p[j].firstStage < p[j + 1].firstStage) {	//1�ܰ� ���� �������� ����
							smp = p[j];
							p[j] = p[j + 1];	//����ü �� �����Ͽ� ��ȯ
							p[j + 1] = smp;
						}
						else {				//1�ܰ� ���� ���� ���
							if (strcmp(p[j].name, p[j + 1].name) > 0) {	//�̸� ���� �� ���� �� ����
								smp = p[j];
								p[j] = p[j + 1];	//����ü �� �����Ͽ� ��ȯ
								p[j + 1] = smp;
							}
						}
					}
				}
			}

	fir = p[M - 1].firstStage; //1�ܰ� �հ����� �����뼱 ����
	tot = p[M - 1].sum;		   //���� �հ����� �����뼱 ����

	for (int i = 0; i < M; i++) {	//���� �� �հ��� ���
		p[i].sum /= 10;			//���� �����ϱ�
		printf("%s %d %d %.1f\n", p[i].name, p[i].firstStage, p[i].interview, p[i].sum);
	}

	for (int i = M; i < N; i++)	//�߰� �հ��� ���
		if (p[i].sum == tot && p[i].firstStage == fir) {	//�����뼱 ������ 1�ܰ� ������ ���
			p[i].sum /= 10;			//���� �����ϱ�
			printf("%s %d %d %.1f\n", p[i].name, p[i].firstStage, p[i].interview, p[i].sum);
			cut++;	//���� �հ����� �� ���
		}
	//���� �հ����� �� ���
	printf("%d", M + cut);
	
	for (int i = 0; i < N; i++)	 //���ڿ� �����Ҵ� ����2
		free(p[i].name);
	free(p);				//����ü �迭 �����Ҵ� ����1

	return 0;
}
/*
7 3
Kim 75 85
Lee 93 63
Park 94 82
Choi 78 70
Jung 65 85
Kang 83 90
Cho 90 70

7 3
Kim 75 85
Lee 96 56
Park 94 82
Choi 78 70
Jung 65 85
Kang 93 63
Cho 93 63
*/