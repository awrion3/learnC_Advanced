#pragma warning(disable:4996)
#include <stdio.h>

//�Լ� ����
void sort(int, int[], double[]);

int main(void) {

	//���� ���� �� �� �Է�
	int N, *p, *q, *r, id[100], kor[100], mat[100];
	double avg[100], *s = avg;

	scanf("%d", &N);

	//������ �ּ� �񱳷� �迭 �� �Է�
	p = id, q = kor, r = mat;

	for (; p < id + N; p++, q++, r++, s++) {
		scanf("%d%d%d", p, q, r);

		//�Է¹޴� ���ÿ� ��հ� ����
		*s = (double)(*q + *r) / 2;	
	}

	//�Լ� ȣ��
	sort(N, id, avg);

	//���� �� ���
	for (p = id, s = avg; p < id + N; p++, s++)
		printf("%d %.1f\n", *p, *s);

	return 0;
}

//�Լ� ����
void sort(int N, int id[], double avg[]) {

	int *p, *q, imp;
	double *s, *t, tmp;

	//�������� ��������
	for (p = id, s = avg; s < avg + N - 1; s++, p++) {
		for (q = p + 1, t = s + 1; t < avg + N; t++, q++)

			//avg �������� ����
			if (*s < *t) {
				tmp = *s;
				*s = *t;
				*t = tmp;

				//id�� �Բ� ����
				imp = *p;
				*p = *q;
				*q = imp;
			}
	}
}
/*
3
1 90 90
2 70 70
3 80 80
*/