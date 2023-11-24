#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int n, *arr, *p, *q, sum = 0, max, fl = 0, mp, mq;
	
	scanf("%d", &n);
	
	arr = (int*)malloc(sizeof(int) * n);
	
	if (arr == NULL) 
		return -1;
	
	for (p = arr; p < arr + n; p++) {   // p로 배열 훑어보기
		scanf("%d", p);
	}

	for (p = arr; p < arr + n; p++) {
		for (q = arr; q < arr + n; q++) {
			if (p != q) {
				sum = *p + *q;

				if (fl == 0) {
					max = sum;
					mp = *p;
					mq = *q;
					fl = 1;
				}
				else {
					if (max < sum) {
						max = sum;
						mp = *p;
						mq = *q;
					}
				}
			}
		}
	}

	printf("%d %d", mp, mq);

	free(arr);

	return 0;
}
/*
5
2 3 8 2 4
*/