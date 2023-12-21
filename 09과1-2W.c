#pragma warning(disable:4996)
#include <stdio.h>

int* MAX(int[]);
int* MIN(int[]);

int main(void) {

	int N, ar[100], *p, *max, *min;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (p = ar; p < ar + 100; p++){
			scanf("%d", p);
			if (*p == 0)
				break;
		}

		max = MAX(ar);
		min = MIN(ar);

		if (max < min){
			for (p = max + 1; p < min; p++)
				printf("%d ", *p);
			printf("\n");
		}
		else if (max > min) {
			for (p = min + 1; p < max; p++)
				printf("%d ", *p);
			printf("\n");
		}
		else
			printf("none\n");
	}

	return 0;
}

int* MAX(int ar[]) {

	int *p, *mp = ar;

	for (p = ar; p < ar + 100; p++){
		if (*p == 0)
			break;
		if (*p > *mp)
			mp = p;
	}

	return mp;
}

int* MIN(int ar[]) {

	int *p, *mp = ar;

	for (p = ar; p < ar + 100; p++) {
		if (*p == 0)
			break;
		if (*p < *mp)
			mp = p;
	}

	return mp;
}
