#pragma warning(disable:4996)
#include <stdio.h>

//����ü ����
struct parking_info {
	int num, tel;	//������ȣ, ��ȭ��ȣ 
	char opt, mem;	//��ǰ, ����� ��������
	int day, min;	//����� ��������, �����ð�
	double fee;		//���
};

//�Լ� ���� ����
void input(struct parking_info*, int);
void compute(struct parking_info*);
void display(struct parking_info*, int);
void parking_info_sort(struct parking_info*, int);	//������ ���� sort �Լ�

int main(void) {

	struct parking_info st[100], *p;	//����ü �迭 �� ������ ����
	int N;

	scanf("%d", &N);	//���� N �Է�

	//�Լ� ȣ���Ͽ� ����ü �迭�� ����
	input(st, N);

	//�Լ� ȣ���Ͽ� 1�뾿 ������� ����Ͽ� ����
	for (p = st; p < st + N; p++)
		compute(p);

	//�Լ� ȣ���Ͽ� ����ü �迭 ����
	parking_info_sort(st, N);

	//�Լ� ȣ���Ͽ� ��� ����Ʈ �� ��� �Ѿ� ���
	display(st, N);

	return 0;
}

//�Լ� ����
void input(struct parking_info *p, int N) {

	struct parking_info *ps;	//����ü ������ ����

	for (ps = p; ps < p + N; ps++) {	//����ü �迭�� �����ͷ� �����Ͽ�
		//������ȣ �� ��ȭ��ȣ, ��ǰ �Է�
		scanf("%d %d %c", &ps->num, &ps->tel, &ps->opt);	
		//��ǰ�� ������� ���
		if (ps->opt == 'S') {	
			getchar();		//����Ű ���� ����//
			//����� ��������, �������� �Է�
			scanf("%c %d", &ps->mem, &ps->day);			
		}		
		//�뿩�ð� �Է�
		scanf("%d", &ps->min);						
	}
}

void compute(struct parking_info *p) {

	p->fee = 0;	//��� �ʱ�ȭ

	//��ǰ�� S��,
	if (p->opt == 'S') {	
		if (p->mem == 'N') {	//����ǿ� ���� ������ �� �� ���,
			if (p->day == 7)		//���������� ���� ���Ժ���� 
				p->fee = 30000;		//3����
			else if (p->day == 30)
				p->fee = 100000;	//10����
			else if (p->day == 180)
				p->fee = 500000;	//50���� �ΰ�
		}
	}
	//��ǰ�� D��,
	else {	
		p->fee = 5000;	//�⺻��� 5000�� �ΰ�
	}

	//��ǰ �ɼǿ� ������� �뿩�ð��� 4�ð��� �ʰ��� ��,
	if (p->min > 240) {
		//�ʰ��� ���� ��� (�Ҽ��� ���� ����)
		p->min = (int)((p->min - 240) / 10);	
		//�ʰ� �ݾ� ����Ͽ� �߰�
		p->fee += p->min * 200;			
	}
}

void parking_info_sort(struct parking_info *p, int N) {
	
	struct parking_info *q, smp;	//����ü ���� ����

	//��ǰ �ɼ� �� ���� ��ȣ�� �������� �������� ����
	for (int i = 0; i < N - 1; i++)			//���� ���� �������
		for (q = p; q < p + N - 1; q++) {	//����ü �迭�� �����ͷ� �����Ͽ�
				//��ǰ �ɼ��� ���ų� ���ڰ� ���� ��쿡 ���Ͽ�
				if (q->opt >= (q + 1)->opt) {	
					//��ǰ �ɼ��� ������
					if (q->opt == (q + 1)->opt) {	
						//���� ��ȣ�� �������� ���ڰ� ������
						if (q->num > (q + 1)->num) {
							smp = *q;
							*q = *(q + 1);	//����ü �� �����Ͽ� ����
							*(q + 1) = smp;
						}
					}
					//��ǰ �ɼǿ��� ���ڰ� ������
					else {
						smp = *q;
						*q = *(q + 1);		//����ü �� �����Ͽ� ����
						*(q + 1) = smp;
					}
				}
		}
}

void display(struct parking_info *p, int N) {

	struct parking_info *ps;	//����ü ������ ����
	double fees = 0, feed = 0;	//��� �Ѿ� ���� double�� ���� ����

	for (ps = p; ps < p + N; ps++) {	//����ü �迭�� �����ͷ� �����Ͽ�
		//���� ��ȣ, ��ȭ ��ȣ, ��ǰ �ɼ�, ���� ��� ����ϱ� 
		printf("%d %d %c %.0f\n", ps->num, ps->tel, ps->opt, ps->fee);
	}

	for (ps = p; ps < p + N; ps++) {	//����ü �迭�� �����ͷ� ����
		if (ps->opt == 'D') {	//��ǰ �ɼ��� D�� ���
			feed += ps->fee;	//D ��ǰ ������ ���� ����
		}
		else {					//��ǰ �ɼ��� S�� ���
			fees += ps->fee;	//S ��ǰ ������ ���� ����
		}
	}
	//D�� �Ѿ�, S�� �Ѿ�, ��ü �Ѿ� ���
	printf("%.0f %.0f %.0f", feed, fees, feed + fees);
}

/*
4
1111 12345678 S N 7 230
2222 22223333 D 240
3333 44445555 D 255
4444 66667777 S Y 30 200

6
3777 28171652 S Y 30 348
1989 97027706 D 429
7757 25158262 S Y 30 392
2714 15392245 D 560
8506 12389677 D 47
5113 59262609 S N 30 967
*/