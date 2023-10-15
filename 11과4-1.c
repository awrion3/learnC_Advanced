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
void input(struct parking_info*, int);		//input �Լ�
void compute(struct parking_info*);			//compute �Լ�
void display(struct parking_info*, int);	//display �Լ�

int main(void) {

	struct parking_info st[100], *p;	//����ü �迭 �� ������ ����
	int N;
		
	scanf("%d", &N);	//���� N �Է�
	
	//�Լ� ȣ���Ͽ� ����ü �迭�� ����
	input(st, N);

	//�Լ� ȣ���Ͽ� 1�뾿 ������� ����Ͽ� ����
	for (p = st; p < st + N; p++)
		compute(p);

	//�Լ� ȣ���Ͽ� ����ü �迭�� ���
	display(st, N);

	return 0;
}

//�Լ� ����
void input(struct parking_info *p, int N) {

	struct parking_info *ps;	//����ü ������ ����

	for (ps = p; ps < p + N; ps++) {	//����ü �迭�� �����ͷ� �����Ͽ�
		scanf("%d %d %c", &ps->num, &ps->tel, &ps->opt);	//������ȣ �� ��ȭ��ȣ, ��ǰ �Է�
		
		if (ps->opt == 'S') {	//��ǰ�� ������� ���
			getchar();	//����Ű ���� ����//
			scanf("%c %d", &ps->mem, &ps->day);		//����� ��������, �������� �Է�	
		}
		
		scanf("%d", &ps->min);						//�뿩�ð� �Է�
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

void display(struct parking_info *p, int N) {

	struct parking_info *ps; //����ü ������ ����

	//����ü �迭�� �����ͷ� �����Ͽ�
	for (ps = p; ps < p + N; ps++) {	
		//���� ��ȣ, ��ȭ ��ȣ, ��ǰ �ɼ�, ���� ��� ����ϱ� 
		printf("%d %d %c %.0f\n", ps->num, ps->tel, ps->opt, ps->fee);	
	}	
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

��)
%.��f �ø��� ��� �ݿø� �ڵ� ����� 
(int) ���� ���� �ڵ� �����
*/