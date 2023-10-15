#pragma warning(disable:4996)
#include <stdio.h>

typedef struct taxi_info {	//����ü ���� �� typedef ���
	char start[11];		//����� �� ����
	char target[11];	//������ �� ����
	double distance;	//�̵��Ÿ� km
	int t_time;			//��ü�ð� sec
	char late_night;	//�ɾ߿��� ���� Y Ȥ�� N
	int tot;			//���� �ýÿ�� 
} TAXI;	//����� �ڷ��� ����

int main(void) {

	TAXI ar[20];		//����ü �迭 ����
	int N, dis, tim;	//������ ���� ����

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

	for (int i = 0; i < N; i++) {	//N���� ���� ���
		printf("%s %s %d\n", ar[i].start, ar[i].target, ar[i].tot);	
	}	//�����, ������, ��� ���

	return 0;
}
/*
4
aaa bbb 2 180 N
ccc ddd 2.25 135 Y
eee fff 5 0 Y
ggg hhh 7.5 60 N
*/