#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ǥ�� ó�� �Լ� ����

//����ü ����
struct student {
	char name[10];
	int quiz[3];
	double avg;
};

//�Լ� ����
void read_data(struct student[]);
void cal_avg(struct student[]);
void sort(struct student[]);
void print_score(struct student[]);

int main(void) {

	//����ü �迭 ����
	struct student st[10];

	//�Լ� ȣ��
	read_data(st);

	cal_avg(st);

	sort(st);

	print_score(st);

	return 0;
}

//�Լ� ����
//����ü �迭 �� �Է�
void read_data(struct student st[]) {

	struct student *p;

	//����ü �迭�� ����ü ���Һ� ��� ���� �����Ͽ� �� �Է�
	for (p = st; p < st + 10; p++) {
		scanf("%s", p->name);

		for (int i = 0; i < 3; i++)
			scanf("%d", &p->quiz[i]);
	}
}

//����ü �迭 �� ���ϱ�
void cal_avg(struct student st[]) {

	struct student *p;
	double ag;

	for (p = st; p < st + 10; p++) {

		ag = 0;		//��հ� ���� �ʱ�ȭ
		
		//����ü �迭�� ����ü ������ ���(int�� �迭) ���� �����Ͽ� ���
		for (int i = 0; i < 3; i++)	
			ag += p->quiz[i];

		ag = (double)ag / 3;	//�� ��ȯ

		p->avg = ag;
	}
}

//����ü �迭 ����
void sort(struct student st[]) {

	struct student *p, *q;
	double dmp;			//�ڷ����� �ӽ� ���� ����
	char cmp[10];
	int tmp;

	for (p = st; p < st + 10 - 1; p++)	//����ü(�� ���ڿ�)������ ���� ���� Ȱ��
		for (q = st; q < st + 10 - 1; q++) {
			//�����͸� Ȱ���Ͽ� ����ü �迭�� ����ü ���Һ� ����� ���� �����Ͽ� ũ�� ��
			if (q->avg < (q+1)->avg) {	
				dmp = q->avg;
				q->avg = (q+1)->avg;	//ū ���� ������ �̵���Ű��
				(q+1)->avg = dmp;

				//��հ� �������� �������� ������ ��, �̸��� ���� �����鵵 ���� ����
				strcpy(cmp, q->name);
				strcpy(q->name, (q+1)->name);
				strcpy((q+1)->name, cmp);

				//����ü �迭�� ����ü ���Һ� ����� int�� �迭�� ���� ��� ���Ľ�Ű��
				for (int i = 0; i < 3; i++) {	
					tmp = q->quiz[i];
					q->quiz[i] = (q+1)->quiz[i];
					(q+1)->quiz[i] = tmp;
				}
			}
		}
}

//����ü �迭 �� ���
void print_score(struct student st[]) {

	struct student *p;
	int N = 10 * (1 - 0.3);	//�������� ���ĵ� ����ü �迭���� ���� 30%�̹Ƿ�

	//����ü ������ �����Ͽ� ���� ������ ����ü �迭�� ����ü ������ ������� ���
	p = st;
	printf("%s %.2f\n", p->name, p->avg);
	p = st + 9;
	printf("%s %.2f\n", p->name, p->avg);

	for (p = st + N; p < st + 10; p++)	//�������� ���ĵ� ����ü �迭�� ���� 30% ���
		printf("%s %.2f\n", p->name, p->avg);
}
/*
AKim 80 80 80
BKim 90 90 90
CKim 81 81 81
ALee 82 82 82
BLee 83 83 83
CLee 84 84 84
APark 85 85 85
BPark 86 86 86
CPark 87 87 87
DPark 88 88 88
*/