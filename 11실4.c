#pragma warning(disable:4996)
#include <stdio.h>

//����ü ����
struct student {
	char name[20];
	int score[3];
	double avg;
	char result;
};

int main(void) {

	//����ü �迭 ����
	struct student st[20];
	int N;

	scanf("%d", &N);

	//N���� �л� ����ü �迭 ����
	for (int i = 0; i < N; i++) {
		scanf("%s", st[i].name);
		
		//����ü �迭�� ����ü ���Һ� ����� �ʱ�ȭ
		st[i].avg = 0;
		for (int j = 0; j < 3; j++){
			scanf("%d", &st[i].score[j]);	//����ü �迭�� ����ü ���Һ� �迭 ����� Ȱ��

			st[i].avg += st[i].score[j];
		}
		st[i].avg = (double)st[i].avg / 3;	//�� ��ȯ�� ����

		//����ü �迭�� ����ü ���Һ� ����� ����
		if (st[i].avg >= 90)
			st[i].result = 'A';
		else if (st[i].avg >= 80)
			st[i].result = 'B';
		else if (st[i].avg >= 70)
			st[i].result = 'C';
		else
			st[i].result = 'F';
	}

	//����ü �迭�� ����ü ���Һ� ����� ���(�Ҽ��� �� �ڸ� �������ӿ� ����)
	for (int i = 0; i < N; i++)
		printf("%s %.1f %c\n", st[i].name, st[i].avg, st[i].result);

	return 0;
}
/*
1
Hongildong 95 80 75
*/