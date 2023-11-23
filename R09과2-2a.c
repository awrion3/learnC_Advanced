#pragma warning(disable:4996)
#include <stdio.h>

int passengerN(int);
void rebooking(int*);
int changeseat(int*);

int main(void) {

	int N, ar[21] = { 0 }, * p;

	scanf("%d", &N);

	for (p = ar; p < ar + N; p++)
		scanf("%d", p);

	if (!passengerN(N)) {
		printf("%d\n", passengerN(N));

		rebooking(ar);

		for (p = ar; p < ar + N; p++)
			printf("%d ", *p);
	}
	else 
		printf("%d\n", passengerN(N));

	return 0;
}

int passengerN(int N) {

	if (N >= 5)
		return 0;
	return -1;
}

void rebooking(int* ar) {

	int *p, *q, *r;

	for (p = ar; p < ar + 21; p++) {
		if (*p == 0)
			break;

		for (q = ar; q < ar + 21; q++)
			if (*p == *q) 
				for (r = p + 1; r < ar + 21; r++)
					if (*p == *r)
						*r = changeseat(ar);
	}
}

int changeseat(int* ar) {

	int num = 1, *p, fl = 0;

	while (num < 21) {
		for (p = ar; p < ar + 21; p++) {
			if (*p == 0)
				break;

			if (*p == num){
				fl = 1;
				break;
			}
		}

		if (fl == 0)
			break;
		else {
			num++;
			fl = 0;
		}
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