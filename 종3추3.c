#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int len, N, i, wlen, tnt[100] = { 0 }, cnt, imp;
	char tmp[100], **p, *t, *q;

	gets_s(tmp, 99);
	len = strlen(tmp);

	N = 1;
	for (t = tmp; t < tmp + len; t++)
		if (*t == ' ') {
			*t = '\0';
			N++;
		}

	p = (char**)malloc(N * sizeof(char*));

	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	q = tmp, i = 0, cnt = 0;
	for (t = tmp; t <= tmp + len; t++) {
		if (*t == '\0') {
			tnt[i] = cnt;
			cnt = 0;

			wlen = strlen(q);

			p[i] = (char*)malloc((wlen + 1) * sizeof(char));

			if (p[i] == NULL) {
				printf("Not enough memory");
				return -1;
			}

			strcpy(p[i++], q);
			q = t + 1;
		}

		if (*t == 'a' || *t == 'e' || *t == 'i' || *t == 'o' || *t == 'u')
			cnt++;
	}

	for (int j = 0; j < N - 1; j++)
		for (int k = 0; k < N - 1; k++)
			if (tnt[k] < tnt[k + 1]) {
				t = p[k];
				p[k] = p[k + 1];
				p[k + 1] = t;

				imp = tnt[k];
				tnt[k] = tnt[k + 1];
				tnt[k + 1] = imp;
			}

	for (int j = 0; j < N; j++)
		printf("%s %d\n", p[j], tnt[j]);

	for (int j = 0; j < N; j++)
		free(p[j]);
	free(p);

	return 0;
}
/*
happy good onion
*/