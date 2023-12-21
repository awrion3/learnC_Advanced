#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int a[11], b[11], *p, num, n = 0, m = 0, *q, tmp;

	for (p = a; p < a + 11; p++) {
		scanf("%d", &num);
		if (num == -1)
			break;
		*p = num;
		n++;
	}

	for (p = b; p < b + 11; p++) {
		scanf("%d", &num);
		if (num == -1)
			break;
		*p = num;
		m++;
	}

	for (p = a; p < a + n; p++)
		for (q = b; q < b + m; q++)
			if (*p <= *q) {
				tmp = *p;
				*p = *q;
				*q = tmp;
			}

	for (int i = 0; i < n - 1; i++)
		for (p = a; p < a + n - 1; p++)
			if (*p < *(p + 1)) {
				tmp = *p;
				*p = *(p + 1);
				*(p + 1) = tmp;
			}

	for (int i = 0; i < m - 1; i++)
		for (q = b; q < b + m - 1; q++)
			if (*q > *(q + 1)) {
				tmp = *q;
				*q = *(q + 1);
				*(q + 1) = tmp;
			}

	for (p = a; p < a + n; p++)
		printf("%d ", *p);
	printf("\n");
	for (q = b; q < b + m; q++)
		printf("%d ", *q);

	return 0;
}