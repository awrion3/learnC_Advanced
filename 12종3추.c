#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int x[100], N, *p, *q, cnt, dup;

	scanf("%d", &N);

	for (p = x; p < x + N; p++)
		scanf("%d", p);

	for (p = x; p < x + N; p++){
		cnt = 0;
		for (q = x; q < x + N; q++)
			if (*p == *q)
				cnt++;

		dup = 0;
		for (q = x; q < p; q++)
			if (*p == *q)
				dup = 1;

		if (dup == 0)
			printf("%d %d\n", *p, cnt);
	}

	return 0;
}
/*
7
2 3 8 2 3 4 2
*/