#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
int* MAX(int[]);
int* MIN(int[]);

int main(void) {

	int N, ar[100], *p, *pmax, *pmin, is;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		//
		is = 0;
		//
		for (p = ar; p < ar + 100; p++){
			scanf("%d", p);
			if (*p == 0)
				break;
		}
		//
		pmax = MAX(ar);
		pmin = MIN(ar);

		//
		if (pmax < pmin) {
			for (p = pmax + 1; p < pmin; p++)
				printf("%d ", *p);
			is = 1;
		}
		else if (pmax > pmin) {
			for (p = pmin + 1; p < pmax; p++) 
				printf("%d ", *p);
			is = 1;
		}
		
		//
		if (is == 1)
			printf("\n");
		else
			printf("none\n");
	}

	return 0;
}

//함수 정의
int* MAX(int ar[]) {

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
3 7 6 5 5 -2 0
1 7 6 2 3 13 2 0
2 0
*/