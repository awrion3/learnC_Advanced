#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//���ڿ� ó�� ǥ�� �Լ� ����

//����ü hotel_info ����
struct hotel_info {
	char name[31];		//�̸� ���ڿ�
	int grade;			//��� ����
	double rate, dis;	//���ǵ� �Ǽ�, �Ÿ� �Ǽ�
	char food;			//�������� ���� ����
};

//�Լ� ���� ����
int in_hotel_info(struct hotel_info*);
void out_hotel_info(struct hotel_info*, int, int, double);

int main(void) {

	struct hotel_info ar[100];	//����ü �迭 ����
	int N, G;	//������ ���� ����
	double D;	//�Ǽ��� ���� ����

	//�Լ� ȣ�� �� ȣ�� �� ��ȯ
	N = in_hotel_info(ar);

	//���ϴ� ȣ���� ��ް� �Ÿ� �Է�
	scanf("%d %lf", &G, &D);

	//�Լ� ȣ���Ͽ� ���ϴ� ȣ���� ������ ���
	out_hotel_info(ar, N, G, D);

	return 0;
}

//�Լ� ����
int in_hotel_info(struct hotel_info *st) {

	struct hotel_info *p; //����ü ������ ����
	int N = 0;					//������ ���� ���� �� �ʱ�ȭ
	char tmp[31], end[2] = "0";	//���ڿ� ����

	for (p = st; p < st + 100; p++) {	//����ü �迭�� �����ͷ� ����
		//ȣ���� �̸� �Է�
		scanf("%s", tmp);
		if (strcmp(tmp, end) == 0)	//ȣ�� �̸����� "0" �Է½� ����
			break;
		else						//�Է¹��� ȣ�� �̸� ����
			strcpy(p->name, tmp);
		//ȣ���� ���, ���ǵ�, �Ÿ�, �������� ���� �Է¹޾� ����
		scanf("%d %lf %lf %c", &p->grade, &p->rate, &p->dis, &p->food);
		N++;	//ȣ�� �� ���
	}

	return N;	//ȣ�� �� ��ȯ
}

void out_hotel_info(struct hotel_info *st, int N, int G, double D) {

	struct hotel_info *p, res[100], *q = res, smp;	//����ü ������ ���� �� �ʱ�ȭ
	int M = 0;				//������ ���� ����
	
	for (p = st; p < st + N; p++) {	//����ü �迭�� �����ͷ� �����Ͽ�
		if (p->grade >= G && p->dis <= D) {	//G �̻� ���, D ������ �Ÿ� ȣ���̸�
			*q = *p;	//����ü �迭 ���ҷ� ����ü �����Ͽ� ����
			q++;	//����ü �迭 �ε��� �̵�
			M++;	//����ü �迭 ���� ���� ����
		}
	}

	for (int i = 0; i < M - 1; i++) {	//���� ���� �������
		for (q = res; q < res + M - 1; q++) {	//����ü �迭�� �����ͷ� �����Ͽ�
			if (q->rate <= (q + 1)->rate) {		//������ ���ǵ��� ���ų� ���� ���
				if (q->rate < (q + 1)->rate) {		//���ڰ� ���ǵ��� ���� ���
					smp = *q;
					*q = *(q + 1);	//����ü �� ������ ���� ����ü �迭 �������� ����
					*(q + 1) = smp;
				}
				else {								//�� ���ǵ��� ���� ���
					if (strcmp(q->name, (q + 1)->name) > 0) { //���ڰ� ������ ȣ�� �̸��� ���� ���
						smp = *q;
						*q = *(q + 1);	//����ü �� ������ ���� ����ü �迭 ����
						*(q + 1) = smp;
					}
				}
			}
		}
	}
	//������ �����ϴ� ȣ�ڵ��� ���ĵ� ��� ���
	for (p = res; p < res + M; p++)	  //�̸�, ���, ���ǵ�, �Ÿ�, �������� ���� ���
		printf("%s %d %.1f %.1f %c\n", p->name, p->grade, p->rate, p->dis, p->food);	
}
/*
marriott 4 4.7 12.5 Y
ibis 2 3.5 5.6 N
novotel 3 3.0 2.7 N
renaissance 3 3.5 4.8 N
hyatt 5 3.5 7.4 Y
bestwestern 2 2.5 3.8 Y
0
3 7.5

��)
*p�� ����� ���� p�� �� �� ����
tmp�� � �ڷ��������� ����
*/