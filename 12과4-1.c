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
	int N, M, tlen;	//������ ���� ����
	char tmp[11];		//������ ���� ����

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

		p[i].sum = 0.7 * p[i].firstStage + 0.3 * p[i].interview;	//���� ���ϱ�
	}

	for (int i = 0; i < N - 1; i++)			//����ü �迭 ���� ����
		for (int j = 0; j < N - 1; j++)
			if (p[j].sum < p[j + 1].sum) {	//���� �������� ����
				smp = p[j];
				p[j] = p[j + 1];	//����ü �� �����Ͽ� ��ȯ
				p[j + 1] = smp;
			}

	for (int i = 0; i < M; i++)		//���� �հ����� �̸��� ���� ���
		printf("%s %.1f\n", p[i].name, p[i].sum);

	for (int i = 0; i < N; i++)	 //���ڿ� �����Ҵ� ����2
		free(p[i].name);
	free(p);				//����ü �迭 �����Ҵ� ����1

	return 0;
}