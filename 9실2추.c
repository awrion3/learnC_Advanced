#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//���� ���� �� �� �Է�
	int N, ar[100], * p = ar, * q;
	int num, cnt = 0, tmp, odd = 0, max = 1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) { //N���� ���� �Է��ϵ�,
		scanf("%d", &num);

		if (num > 0) { //0���� ū ������ �迭�� ����
			*p++ = num;
			cnt++;	//������ �迭�� ����� ������ ����
		}
	}
	//������ ���� ���//
	printf("%d\n", cnt);

	if (cnt % 2 != 0) { //�迭�� ����� ������ ������ Ȧ���� ���
		for (p = ar; p < ar + cnt - 1; p++)
			for (q = p + 1; q < ar + cnt; q++)	//��������
				if (*p > *q) {//��������
					tmp = *p;
					*p = *q;
					*q = tmp;
				}
	}
	else {//�迭�� ����� ������ ������ ¦���� ���
		for (p = ar; p < ar + cnt - 1; p++)
			for (q = p + 1; q < ar + cnt; q++)	//��������
				if (*p < *q) {//��������
					tmp = *p;
					*p = *q;
					*q = tmp;
				}
	}
	//������ �迭 ���//
	for (p = ar; p < ar + cnt; p++)
		printf("%d ", *p);
	printf("\n");

	//���� Ƚ�� ���
	for (p = ar; p < ar + cnt; p++)
		if (*p % 2 != 0) { //�����ؼ� Ȧ���� ������ Ƚ�� ����
			odd++;
			if (max < odd) //�ִ� ���� Ƚ�� ���� (����: max�� �ʱⰪ�� 1. ���ǿ� ����)
				max = odd;
		}
		else
			odd = 0;	//�ƴϸ� ó������ �ٽ� �ʱ�ȭ
	//�����Ͽ� Ȧ�� ���� �ִ� Ƚ�� ���//
	printf("%d\n", max);

	return 0;
}
/*
16
5 1 -2 3 19 6 7 8 17 -4 9 11 -6 16 13 15

12
5 11 -1 -14 9 7 -5 6 2 1 3 -7
*/