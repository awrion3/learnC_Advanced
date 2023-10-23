#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
int* MAX(int[]);
int* MIN(int[]);

int main(void) {

	int N, ar[100], *p, *pmax, *pmin;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		//
		for (p = ar; p < ar + 100; p++) {
			scanf("%d", p);
			if (*p == 0)
				break;
		}
		//
		pmax = MAX(ar);
		pmin = MIN(ar);

		printf("%d %d\n", *pmax, *pmin);
	}

	return 0;
}

//함수 정의
int* MAX(int ar[]) {
	//
	int *p, *pmax = ar;

	for (p = ar; p < ar + 100; p++) {
		if (*p == 0)
			break;

		if (*pmax < *p)
			pmax = p;
	}

	return pmax;
}

int* MIN(int ar[]) {
	//
	int *p, *pmin = ar;

	for (p = ar; p < ar + 100; p++) {
		if (*p == 0)
			break;

		if (*pmin > *p)
			pmin = p;
	}

	return pmin;
}
/*
3
3 7 6 -2 0
1 7 6 13 2 0
2 0
*/