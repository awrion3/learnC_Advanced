#pragma warning(disable:4996)
#include <stdio.h>

int reverse_num(int);
int del_dupnum(int);

int main(void) {

	int N, R, max = 0, gap, mnum;

	scanf("%d", &N);
	while (N >= 0) {

		R = del_dupnum(reverse_num(N));
		printf(" %d", R);
		
		//���밪 ���ϱ�
		gap = N - R > 0 ? N - R : -(N - R);
		if (gap > max) {
			max = gap;
			mnum = N;
		}

		scanf("%d", &N);
	}

	printf("\n%d %d", mnum, max);

	return 0;
}

int reverse_num(int num) {

	int val = 0;

	while (num != 0) {
		val *= 10;
		val += num % 10;
		num /= 10;
	}

	return val;
}

int del_dupnum(int num) {

	int x[9], idx = 0, isdup, tmp;
	int y[9], jdx = 0, val = 0;

	while (num != 0) {
		x[idx++] = num % 10;
		num /= 10;
	} //���⼭ �ٽ� �������� ��

	for (int i = 0, j = idx - 1; i < j; i++, j--) {
		tmp = x[i];	//�����ϱ�
		x[i] = x[j];
		x[j] = tmp;
	}

	for (int i = 0; i < idx; i++) {
		isdup = 0;
		for (int j = 0; j < i; j++)
			if (x[i] == x[j])
				isdup = 1;

		if (isdup == 0)
			y[jdx++] = x[i];
	}

	for (int i = 0; i < jdx; i++) {
		val *= 10;
		val += y[i];
	}

	return val;
}
//34830332 912715 1983 101224 1357 -5