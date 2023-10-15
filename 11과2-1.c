#pragma warning(disable:4996)
#include <stdio.h>

struct student {	//����ü ����
	char name[21];	//���ڿ� �� ���� ����
	int kor, eng, math;	//int�� ���� ����
};

struct average {	//����ü ����
	double kor, eng, math;	//double�� ��� ����
};

//�Լ� ���� ����
struct average calculate_avg(struct student*, int);	

int main(void) {

	struct student ar[50];	//����ü �迭 ����
	struct average stav;	//����ü ���� ����
	int N, k = 0, e = 0, m = 0;		//������ ���� ���� �� �ʱ�ȭ

	scanf("%d", &N);	//���� N �Է�

	for (int i = 0; i < N; i++) {	//N���� ���� ����ü �迭�� ����
		scanf("%s %d %d %d", ar[i].name, &ar[i].kor, &ar[i].eng, &ar[i].math);
	}

	//�Լ� ȣ�� �� N���� ���� ��� ��ȯ�� ����ü�� ����
	stav = calculate_avg(ar, N);	

	//���� ��� ���
	printf("%.1f %.1f %.1f\n", stav.kor, stav.eng, stav.math);

	//����ü �迭�� �����Ͽ�
	for (int i = 0; i < N; i++) {
		if (stav.kor > ar[i].kor)	//���� ��� �̴� �л� �� ���
			k++;
		if (stav.eng > ar[i].eng)	//���� ��� �̴� �л� �� ���
			e++;
		if (stav.math > ar[i].math)	//���� ��� �̴� �л� �� ���
			m++;
	}

	//�� ������ ��� �������� ���� ������ ���� �л� �� ���� ���
	printf("%d %d %d", k, e, m);

	return 0;
}

//�Լ� ����
struct average calculate_avg(struct student* st, int N) {

	struct student *p;			//����ü ������ ����
	struct average sav = { 0 };	//����ü ���� ���� �� �ʱ�ȭ

	//����ü �迭�� �����ͷ� �����Ͽ�
	for (p = st; p < st + N; p++) {	
		sav.kor += p->kor;		//����ü �迭�� ����� ���� ���� ���� ����ü ������ ����
		sav.eng += p->eng;		//����ü �迭�� ����� ���� ���� ���� ����ü ������ ����
		sav.math += p->math;	//����ü �迭�� ����� ���� ���� ���� ����ü ������ ����
	}

	sav.kor = (double)sav.kor / N;		//����ü ������ ���� ��� ����
	sav.eng = (double)sav.eng / N;		//����ü ������ ���� ��� ����
	sav.math = (double)sav.math / N;	//����ü ������ ���� ��� ����

	return sav;		//����ü ������ ��ȯ
}
/*
5
Kim 100 90 80
Lee 88 94 92
Park 92 100 100
Hong 84 82 85
Nam 80 84 72
*/