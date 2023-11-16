#pragma warning(disable:4996)
#include <stdio.h>

int* center(int*, int);

int main(void) {

	int N, p[100], *t, *r, i = 0;

	scanf("%d", &N);

	for (t = p; t < p + N; t++)
		scanf("%d", t);

	r = center(p, N);

	printf("%d\n", *r);

	for (t = p; t < p + N; t++, i++)
		if (*t == *r)
			break;

	printf("%d", i);

	return 0;
}

int* center(int* p, int N) {

	int *t, *r = NULL, fl = 0;
	double avg = 0, gap, min;

	for (t = p; t < p + N; t++)
		avg += *t;

	avg = (double)avg / N;

	printf("%.1f\n", avg);

	for (t = p; t < p + N; t++) {
		gap = avg - *t > 0 ? avg - *t : -(avg - *t);

		if (fl == 0) {
			min = gap;
			r = t;
			fl = 1;
		}

		if (min > gap){
			min = gap;
			r = t;
		}
	}

	return r;
}
/*
5
2 5 6 12 18
*/