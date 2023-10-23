#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int a[11], b[11], num, *p, max = -1, min = 101, ant = 0, bnt = 0;

	for (p = a; p < a + 11; p++){
		scanf("%d", &num);

		if (num == -1)
			break;
		
		*p = num;
		ant++;
	}
	
	for (p = b; p < b + 11; p++) {
		scanf("%d", &num);
		
		if (num == -1)
			break;
		
		*p = num;
		bnt++;
	}

	for (p = a; p < a + ant; p++) {
		if (max < *p)
			max = *p;
		if (min > *p)
			min = *p;
	}

	for (p = b; p < b + bnt; p++) {
		if (max < *p)
			max = *p;
		if (min > *p)
			min = *p;
	}

	printf("%d %d\n", ant, bnt);
	printf("%d %d", max, min);

	return 0;
}
/*
5 20 23 80 80 -1
70 50 50 45 5 15 28 46 76 11 -1
*/