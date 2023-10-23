#pragma warning(disable:4996)
#include <stdio.h>

int passengerN(int);
void rebooking(int*);
int changeseat(int*);

int main(void) {

	int N, ar[21] = {0}, *p;	//0�� �־� ���� �Լ����� for�� ���� ����

	scanf("%d", &N);

	for (p = ar; p < ar + N; p++)
		scanf("%d", p);

	if (passengerN(N) == -1) {
		printf("%d\n", passengerN(N));
	}
	else {
		printf("%d\n", passengerN(N));
		rebooking(ar);
		
		for (p = ar; p < ar + N; p++)
			printf("%d ", *p);
	}

	return 0;
}

int passengerN(int n) {

	if (n < 5)
		return -1;
	return 0;
}

void rebooking(int *ar) {

	int *p, n = 0, *q, dup, snum, *r;

	for (p = ar; *p != 0; p++)			//���� ����
		n++;

	for (p = ar; p < ar + n; p++){	
		dup = 0;
		for (q = ar; q < p; q++)
			if (*p == *q)		//ó�� �����ϴ� ���� �ƴϸ� ǥ��
				dup = 1;
		
		snum = *p;
		if (dup == 1)			//�ش� �������� ������ ���� �ߺ� �¼���ȣ�� ��ü
			for (r = p; r < ar + n; r++) 
				if (*r == snum)	//*p���� �ٲ�Ƿ�, ������ ������ ���ؾ� ��
					*r = changeseat(ar);
	}
}

int changeseat(int *ar) {

	int *p, n = 0, num, fl;

	for (p = ar; *p != 0; p++)			//���� ����
		n++;

	for (num = 1; num < 21; num++) {	//21�̸� �ݺ� ����
		fl = 0;
		
		for (p = ar; p < ar + n; p++)
			if (num == *p) 
				fl = 1;

		if (fl == 0)
			break;
	}

	return num;
}
/*
7
1 2 3 3 4 5 6

6
8 8 6 8 6 1

10
8 3 8 3 8 11 21 13 5 2
*/