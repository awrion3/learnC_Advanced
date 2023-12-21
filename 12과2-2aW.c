#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	char A[101], B[101], **p, **q;
	char *t, *r, C[200][201] = { 0 }, D[200][201] = { 0 }, tmp[201];
	int alen, blen, N = 1, M = 1, wlen, idx = 0, jdx = 0, kdx = 0, udx = 0, dup;

	gets_s(A, 100);
	gets_s(B, 100);

	alen = strlen(A);
	blen = strlen(B);

	for (t = A; t < A + alen; t++)
		if (*t == ' '){
			*t = '\0';
			N++;
		}

	for (t = B; t < B + blen; t++)
		if (*t == ' '){
			*t = '\0';
			M++;
		}

	p = (char**)malloc(N * sizeof(char*));
	if (p == NULL)
		return -1;

	q = (char**)malloc(M * sizeof(char*));
	if (q == NULL)
		return -1;

	r = A;
	for (t = A; t <= A + alen; t++)
		if (*t == '\0'){
			wlen = strlen(r);
			
			p[idx] = (char*)malloc((wlen + 1) * sizeof(char));
			if (p[idx] == NULL)
				return -1;
			
			strcpy(p[idx++], r);
			r = t + 1;
		}

	r = B;
	for (t = B; t <= B + blen; t++)
		if (*t == '\0') {
			wlen = strlen(r);

			q[jdx] = (char*)malloc((wlen + 1) * sizeof(char));
			if (q[jdx] == NULL)
				return -1;

			strcpy(q[jdx++], r);
			r = t + 1;
		}

	for (int i = 0; i < idx; i++)
		for (int j = 0; j < idx; j++)
			if (strcmp(p[i], p[j])) {
				strcat(C[kdx], p[i]);
				strcat(C[kdx++], p[j]);

				strcat(C[kdx], p[j]);
				strcat(C[kdx++], p[i]);
			}


	for (int i = 0; i < jdx; i++)
		for (int j = 0; j < kdx; j++)
			if (strcmp(q[i], C[j]) == 0) {
				dup = 0;
				for (int k = 0; k < udx; k++)
					if (strcmp(q[i], D[k]) == 0)
						dup = 1;

				if (dup == 0)
					strcpy(D[udx++], q[i]);
			}

	for (int i = 0; i < udx - 1; i++)
		for (int j = 0; j < udx - 1; j++)
			if (strlen(D[j]) <= strlen(D[j + 1])) {
				if (strlen(D[j]) < strlen(D[j + 1])) {
					strcpy(tmp, D[j]);
					strcpy(D[j], D[j + 1]);
					strcpy(D[j + 1], tmp);
				}
			}
			else if (strcmp(D[j], D[j + 1]) > 0) {
				strcpy(tmp, D[j]);
				strcpy(D[j], D[j + 1]);
				strcpy(D[j + 1], tmp);
			}

	for (int i = 0; i < udx; i++)
		printf("%s\n", D[i]);
	//
	for (int i = 0; i < idx; i++)
		free(p[i]);
	for (int i = 0; i > jdx; i++)
		free(q[i]);
	free(p);
	free(q);

	return 0;
}
/*
red orange yellow green blue purple
pink red redorange orangered yellow black bluegreen white purple
*/