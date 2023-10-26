#pragma warning(disable:4996)
#include <stdio.h>

void input(int*, int);
int* diff(int*, int);

int main(void) {

	int N, ar[100], *p;

	scanf("%d", &N);

	input(ar, N);

	p = diff(ar, N);

	printf("%d %d", *(p - 1), *p);

	return 0;
}

void input(int* ar, int N) {

	int *p;

	for (p = ar; p < ar + N; p++)
		scanf("%d", p);
}

int* diff(int* ar, int N) {

	int *p, gap, max = -1, *r = ar;

	for (p = ar + 1; p < ar + N; p++) {
		gap = *p - *(p - 1) > 0 ? *p - *(p - 1) : -(*p - *(p - 1));

		if (gap > max) {
			max = gap;
			r = p;
		}
	}

	return r;
}
/*
5
3 7 2 4 3 
*/