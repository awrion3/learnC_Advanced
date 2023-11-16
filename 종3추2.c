#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int len, N, i, wlen, fl, S, E, cnt, M;
	char tmp[100], **p, *t, *q;

	gets_s(tmp, 99);
	len = strlen(tmp);

	N = 1;
	for (t = tmp; t < tmp + len; t++)
		if (*t == ' '){
			*t = '\0';
			N++;
		}

	p = (char**)malloc(N * sizeof(char*));

	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	q = tmp, i = 0;
	for (t = tmp; t <= tmp + len; t++) {
		if (*t == '\0') {
			wlen = strlen(q);
			
			p[i] = (char*)malloc((wlen + 1) * sizeof(char));

			if (p[i] == NULL) {
				printf("Not enough memory");
				return -1;
			}

			strcpy(p[i++], q);
			q = t + 1;
		}
	}

	S = 0, E = N - 1, M = N / 2; fl = 0;
	while (S <= M) {
		cnt = 0;
		while (fl == 0) {
			if (cnt == 2 || S > M || E == M - 1) {
				fl = 1;
				break;
			}

			printf("%s\n", p[S++]);
			cnt++;
		}

		cnt = 0;
		while (fl == 1) {
			if (cnt == 2 || E == M - 1 || S > M) {
				fl = 0;
				break;
			}

			printf("%s\n", p[E--]);
			cnt++;
		}
	}

	for (int j = 0; j < N; j++)
		free(p[j]);
	free(p);

	return 0;
}
/*
lion cat tiger snake bear
5 | 2
S0 1 E4 3 S2 / S3 E2

lion cat tiger dog snake bear
6 | 3
S0 1 E5 4 S2 3 / S4 E3

one two three four five six seven eight
*/