#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, M, num, div, dnt, cal, sum;
	int max = 2, mnum, msum; //�ּ� ����� ������ 2��.

	scanf("%d%d", &N, &M);

	for (int i = N; i <= M; i++) {
		num = i; 
		div = 2; dnt = 0;
		cal = 1; sum = 0;
		
		while (num != 1) {
			while (num % div == 0) { //if�� �ƴ� while���� ����ؾ� �Կ� ����
				num /= div;
				dnt++;
			} 
			div++;
			cal *= (dnt + 1);   //����� ���� ���ϱ�
			sum += dnt;			//���μ��� ���� �� ���ϱ�
			dnt = 0;
		}
		
		if (max < cal) { //����� ������ ���� ū �� ã��
			mnum = i;
			max = cal;
			msum = sum;
		}
	}

	printf("%d %d %d", mnum, max, msum);

	return 0;
}
/*
	int N, M, num, j, pnt, div, sum, max = 0, mnum, msum;
	scanf("%d%d", &N, &M);

	for (int i = N; i <= M; i++) {
		num = i; j = 2;
		div = 1; sum = 0;

		while (num != 1) {
			pnt = 0;
			while (num % j == 0) {
				num /= j;
				pnt++;
			}
			div *= (pnt + 1);
			sum += pnt;

			j++;
		}

		if (max < div) {
			max = div;
			mnum = i;
			msum = sum;
		}
	}
	printf("%d %d %d", mnum, max, msum);
*/