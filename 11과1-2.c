#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//���ڿ� ó�� ǥ�� �Լ� ����

typedef struct taxi_info {	//����ü ���� �� typedef ���
	char start[11];		//����� �� ����
	char target[11];	//������ �� ����
	double distance;	//�̵��Ÿ� km
	int t_time;			//��ü�ð� sec
	char late_night;	//�ɾ߿��� ���� Y Ȥ�� N
	int tot;			//���� �ýÿ�� 
} TAXI;	//����� �ڷ��� ����

//�Լ� ���� ����
TAXI* sel_max(TAXI*, int, char*, char*);

int main(void) {

	TAXI ar[20], *p;	//����ü �迭 �� ������ ����
	int N, dis, tim;	//������ ���� ����
	char sta[11], des[11];	//����� �� ������ ���ڿ� �Է� �� ���� ����

	scanf("%d", &N);	//N �Է�

	for (int i = 0; i < N; i++) {	//N���� ���� �Է�
		scanf("%s", ar[i].start);		//������ ���� ���ڿ� �Է�
		scanf("%s", ar[i].target);
		scanf("%lf", &ar[i].distance);	//�̵��Ÿ� �Է�
		scanf("%d", &ar[i].t_time);		//��ü�ð� �Է�
		getchar();						//����Ű ���� ����//
		scanf("%c", &ar[i].late_night);	//�ɾ߿��� ���� �Է�

		ar[i].tot = 0;	//���� ��� �ʱ�ȭ
		if (ar[i].late_night == 'N') {	//�ְ� ���
			ar[i].tot += 3800;	//�⺻���

			//�߰� �̵��Ÿ� ���� ��� (�Ҽ��� ���� ����)
			dis = (int)((ar[i].distance - 2) * 1000 / 100);
			ar[i].tot += dis * 100;	//�ʰ��� �̵��Ÿ� ��� �߰�

			//��ü�ð� ���� ��� (�Ҽ��� ���� ����)
			tim = (int)(ar[i].t_time / 30);
			ar[i].tot += tim * 100;	//��ü�ð� ��� �߰�	
		}
		else {	//�ɾ� ���� ���
			ar[i].tot += 4800;	//�⺻���

			//�߰� �̵��Ÿ� ���� ��� (�Ҽ��� ���� ����)
			dis = (int)((ar[i].distance - 2) * 1000 / 100);
			ar[i].tot += dis * 120;	//�ʰ��� �̵��Ÿ� ��� �߰�

			//��ü�ð� ���� ��� (�Ҽ��� ���� ����)
			tim = (int)(ar[i].t_time / 30);
			ar[i].tot += tim * 120;	//��ü�ð� ��� �߰�
		}
	}
	
	scanf("%s", sta);	//����� �� ������ �Է�
	scanf("%s", des);

	//�Լ� ȣ�� (����ü �迭�� �����ּ� �� ���Ұ���, ����� �� ������ ���ڿ� �����ּ� ����)
	p = sel_max(ar, N, sta, des);	

	//�ش� ��������� ���������� �̵� ���� �ִ� �ýÿ���� ��츦 ��� (�Ÿ�, ��ü�ð�, �ɾ�, ���)
	printf("%.2f %d %c %d", p->distance, p->t_time, p->late_night, p->tot);

	return 0;
}

//�Լ� ����
TAXI* sel_max(TAXI *p, int N, char *s, char *d) {

	TAXI *q, *m = p;	//����ü ������ ���� ���� �� �ʱ�ȭ
	int max = -1;

	for (q = p; q < p + N; q++) {//����ü �迭 �����ͷ� ����
		//������� �������� ������
		if (strcmp(q->start, s) == 0 && strcmp(q->target, d) == 0) {
			//����� ���� ū ��� ã��
			if (max < q->tot) {
				max = q->tot;	//�ִ� �ý� ��� ����
				m = q;			//����ü �迭�� �ش� ����ü ���� �ּ� ����
			}
		}
	}

	return m;	//�ش� ����ü ���� �ּ� ��ȯ
}

/*
8
aaa bbb 2.25 480 N
ccc ddd 10 300 Y
eee fff 10 180 Y
aaa bbb 3 180 N
ccc ddd 12 180 Y
ggg hhh 13 60 Y
aaa bbb 4 0 N
aaa bbb 3.2 60 N
aaa bbb
*/