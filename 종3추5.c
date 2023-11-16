#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct car {
	char num[5];
	int hour, min, payment;
}car;

int main(void) {

	int N, gap, fl, dp;
	car *p, *t, *s, *r;

	scanf("%d", &N);

	p = (car*)malloc(N * sizeof(car));

	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (t = p; t < p + N; t++)
		scanf("%s %d", t->num, &t->hour);

	for (t = p; t < p + N; t++)
		for (s = p; s < p + N; s++)
			if (t != s && strcmp(t->num, s->num) == 0) {
				gap = t->hour - s->hour > 0 ? t->hour - s->hour : -(t->hour - s->hour);

				if (gap >= 100) {
					t->min = (gap / 100) * 60;
					gap %= 100;
				}
				
				t->min += gap;

				t->payment = 100 * t->min;
			}

	for (t = p; t < p + N; t++) {
		fl = 0, dp = 0;

		for (s = p; s < p + N; s++)
			if (t != s && strcmp(t->num, s->num) == 0)
				fl = 1;

		for (r = p; r < t; r++)
			if (strcmp(t->num, r->num) == 0)
				dp = 1;

		if (fl == 1 && dp == 0)
			printf("%s %d\n", t->num, t->payment);
	}

	free(p);

	return 0;
}
/*
5
1234 1030
9000 1040
0800 1045
1234 1130
9000 1150
*/