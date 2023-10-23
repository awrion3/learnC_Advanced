#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N, ar[21], *p, *q, dp[21] = {0}, *d = dp, dup, is = 0;

	scanf("%d", &N);

	for (p = ar; p < ar + N; p++)
		scanf("%d", p);

	for (p = ar; p < ar + N; p++, d++)
		for (q = ar; q < ar + N; q++)
			if (*p == *q)
				++*d;

	if (N < 5)
		printf("%d", -1);
	else {
		d = dp;
		for (p = ar; p < ar + N; p++, d++) {
			dup = 0;
			for (q = ar; q < p; q++)
				if (*p == *q) {
					dup = 1;
					is = 1;
				}

			if (dup == 0 && *d > 1)
				printf("%d %d\n", *p, *d);
		}
	}

	if (is == 0)
		printf("%d", 0);

	return 0;
}
/*
8
7 2 5 5 20 5 8 7

7
21 15 20 9 16 1 3
*/