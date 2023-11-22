#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	char x[101] = { 0 }, **y, *t, *q;
	int N, len, wlen, i;

	gets_s(x, 100);
	len = strlen(x);

	N = 1;
	for (t = x; t < x + len; t++)
		if (*t == ' '){
			*t = '\0';
			N++;
		}

	y = (char**)malloc(N * sizeof(char*));

	if (y == NULL) {
		printf("Not enough memory");
		return -1;
	}

	q = x, i = 0;
	for (t = x; t <= x + len; t++) {
		if (*t == '\0'){
			wlen = strlen(q);
			y[i] = (char*)malloc((wlen + 1) * sizeof(char));

			if (y[i] == NULL) {
				printf("Not enough memory");
				return -1;
			}

			strcpy(y[i++], q);
			q = t + 1;
		}
	}

	for (i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			if (strcmp(y[j], y[j + 1]) > 0) {
				q = y[j];
				y[j] = y[j + 1];
				y[j + 1] = q;
			}

	for (i = 0; i < N; i++)
		printf("%s\n", y[i]);

	for (i = 0; i < N; i++)
		free(y[i]);
	free(y);

	return 0;
}
/*
cat banana apricot
*/