#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, num, M, pal;
	int max, min, cnt, fl = 0;

	scanf("%d", &N);
	while (N != 0) {

		num = N; pal = N;
		M = 0;
		while (num != 0) {
			pal *= 10;
			M *= 10;
			M += num % 10;
			num /= 10;	
		}
		pal += M; //��Ī���� ���ϱ�
 		
		num = pal; cnt = 0;
		while (num != 0) {
			if (num % 10 == 3)
				cnt++;	//��Ī���� �� 3�� ���� Ȯ��
			num /= 10;
		}

		printf("%d %d ", pal, cnt); //���
		
		//��Ī���� ���� �ִ� �ּҰ� �ʱ�ȭ
		if (fl == 0) { 
			max = pal;
			min = pal;
			fl = 1;
		}
		else {
			if (pal > max)
				max = pal;
			if (pal < min)
				min = pal;
		}
		
		scanf("%d", &N);
	}

	printf("\n%d %d", min, max); //���

	return 0;
}