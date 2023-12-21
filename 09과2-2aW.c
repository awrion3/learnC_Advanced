#pragma warning(disable:4996)
#include <stdio.h>

int passengerN(int);
void rebooking(int*);
int changeseat(int*);

int main(void) {

	int N, ar[21] = {0}, *p;

	scanf("%d", &N);

	for (p = ar; p < ar + N; p++) 
		scanf("%d", p);

	if (passengerN(N) == 0) {
		printf("%d\n", passengerN(N));

		rebooking(ar);

		for (p = ar; p < ar + N; p++)
			printf("%d ", *p);
	}
	else {
		printf("%d\n", passengerN(N));
	}

	return 0;
}

int passengerN(int n) {
	
	if (n >= 5)
		return 0;
	else
		return -1;
}

void rebooking(int *ar) {

	int *p, n = 0, *q, *ddx = NULL, dal, dup;

	for (p = ar; *p != 0; p++)
		n++;

	for (p = ar; p < ar + n; p++) {

		for (q = ar; q < ar + n; q++) {
			dup = 0;
			if (*p == *q && p != q) { //8" 8 6 8 6 1 //8 8' 6 8 6 1
				ddx = q;
				dal = *q;
				dup = 1;
				break;
			}
		}

		if (dup == 1) {
			for (q = ddx; q < ar + n; q++)	//8 8' 6 8' 6 1
				if (*q == dal)
					*q = changeseat(ar);
		}
	}
}

int changeseat(int *ar) {
	
	int *p, num = 1, is = 0;

	while (num < 21) {

		is = 0;
		for (p = ar; *p != 0; p++)
			if (num == *p){
				is = 1;
				break;
			}

		if (is == 0)
			break;
		else
			num++;
	}

	return num;
}