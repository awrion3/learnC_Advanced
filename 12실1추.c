#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int N, tlen, cnt, xlen, max = 0;
	char X[101], tmp[101], **Y, *t, M[101] = { 0 };

	scanf("%d", &N);
	scanf("%s", X);
	getchar();

	xlen = strlen(X);

	Y = (char**)malloc(N * sizeof(char *));

	if (Y == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++) {
		gets_s(tmp, 100);
		tlen = strlen(tmp);

		Y[i] = (char*)malloc((tlen + 1) * sizeof(char));
		
		if (Y[i] == NULL) {
			printf("Not enough memory");
			return -1;
		}

		strcpy(Y[i], tmp);
		
		cnt = 0;
		for (t = tmp; t < tmp + tlen; t++)
			if (strncmp(X, t, xlen) == 0) {
				cnt++;
				t += (xlen - 1);
			}

		if (cnt > max) {
			max = cnt;
			strcpy(M, tmp);
		}
	}

	if (max == 0)
		printf("NONE");
	else
		printf("%s", M);

	for (int i = 0; i < N; i++)
		free(Y[i]);
	free(Y);

	return 0;
}
/*
3 abc
abcabc abcabc
ABCabc ABCabc
abc abc abc abcd
*/