#pragma warning(disable:4996)
#include <stdio.h>

//student ����ü ����
struct student {	
	char name[21];	//���ڿ� �� ���� ����
	int kor, eng, math;	//int�� ���� ����
	double avg;		 //double�� ��� ����
};

//�Լ� ���� ����
void read_data(struct student*, int);
void sort_score(struct student*, int);
struct student* select_out(struct student*, struct student*, int);

int main(void) {

	//����ü �迭 ���� �� ����ü ������ ����
	struct student st1[49], st2[49], *st, *p;	
	int N;		//������ ���� ����

	scanf("%d", &N);	//���� N �Է�
	
	//�Լ� ȣ���Ͽ� ����ü �迭�� �Է�
	read_data(st1, N);
	read_data(st2, N);	

	//�Լ� ȣ���Ͽ� ����ü �迭�� ����
	sort_score(st1, N);
	sort_score(st2, N);

	//�Լ� ȣ���Ͽ� ��ȯ�� ����ü �迭�� �����ּ� ����
	st = select_out(st1, st2, N);

	//�߰����� �� ū �迭�� ����� �л����� �̸��� ������ ����, ��� ���� ���
	for (p = st; p < st + N; p++)
		printf("%s %d %d %d %.1f\n", p->name, p->kor, p->eng, p->math, p->avg);

	return 0;
}

//�Լ� ����
void read_data(struct student *st, int N) {

	struct student *p;	//����ü ������ ����

	for (p = st; p < st + N; p++){	//����ü �迭�� �����ͷ� �����Ͽ� �� �Է�
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
		
		//�� ������ ��� ������ ����Ͽ� ����
		p->avg = (double)(p->kor + p->eng + p->math) / 3;	
	}
}

void sort_score(struct student *st, int N) {

	struct student *q, dmp;	//����ü ���� ����

	for (int i = 0; i < N - 1; i++)			//���� ���� �������
		for (q = st; q < st + N - 1; q++)	//����ü �迭�� �����ͷ� �����Ͽ�
			if (q->avg <= (q + 1)->avg) {	//�������� ����
				//��� ������ ���� ���
				if (q->avg == (q + 1)->avg) {
					//���� ������ ���� ���
					if (q->kor == (q + 1)->kor) {
						//���� �������� ��
						if (q->eng < (q + 1)->eng) {
							dmp = *q;		//dmp�� Ȱ���Ͽ� ����ü �� ������ ����
							*q = *(q + 1);	//ū ���� ������ �̵�
							*(q + 1) = dmp;
						}
					}
					//���� �������� ��
					else if (q->kor < (q + 1)->kor) {
						dmp = *q;		//dmp�� Ȱ���Ͽ� ����ü �� ������ ����
						*q = *(q + 1);	//ū ���� ������ �̵�
						*(q + 1) = dmp;
					}
				}
				//ū ��հ��� �ڿ� �ִ� ���
				else {
					dmp = *q;		//dmp�� Ȱ���Ͽ� ����ü �� ������ ����
					*q = *(q + 1);	//ū ���� ������ �̵�
					*(q + 1) = dmp;
				}
			}
}

struct student* select_out(struct student *st1, struct student *st2, int N) {

	int M = N / 2;								  //�߰� ��� �ε��� ����
	struct student *p1 = st1 + M, *p2 = st2 + M;  //�߰� ��հ� ��ġ ����

	//�߰����� �� ū ����ü �迭�� ���� �ּ� ��ȯ
	if (p1->avg > p2->avg)	//st1����ü�� �߰����� �� ū ���
		return st1;
	return st2;				//st2����ü�� �߰����� �� ū ���
}
/*
5
Kim 100 85 80
Lee 88 94 92
Park 92 100 100
Hong 84 82 85
Nam 80 84 72
Song 100 90 97
Lee 92 82 93
Park 80 84 72
Choi 97 80 90
Chung 100 94 93
*/