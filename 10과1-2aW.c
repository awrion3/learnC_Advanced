#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char A[21], B[21], *p, NA[201], NB[201], *t;
	int alen, blen, N, num, fl;

	gets_s(A, 20);
	gets_s(B, 20);

	alen = strlen(A);
	blen = strlen(B);

	p = A; t = B;
	N = *p - *t > 0 ? *p - *t : -(*p - *t);

	t = NA;
	for (p = A; p < A + alen; p++){
		if (*p >= 'A' && *p <= 'Z') {
			*t = *p + N > 'Z' ? 'A' + (*p + N - 'Z' - 1) : *p + N;
			t++;
		}
		else if (*p >= 'a' && *p <= 'z') {
			*t = *p - N < 'a' ? 'Z' + (*p + N - 'a' + 1) : *p - N;
			t++;
		}
		else if (*p >= '1' && *p <= '9') {
			num = *p - '0';

			if (*(p + 1) >= '0' && *(p + 1) < '7'){	
				num *= 10;
				num += *(p + 1) - '0';

				p++;
			}
			
			for (int i = 0; i < N; i++, t++){
				*t = 'A' + num - 1;
			}
		}
		else {
			*t = ' ';
			t++;
		}
	}
	*t = '\0';

	//
	t = NB;
	for (p = B; p < B + blen; p++) {
		if (*p >= 'A' && *p <= 'Z') {
			*t = *p + N > 'Z' ? 'A' + (*p + N - 'Z' - 1) : *p + N;
			t++;
		}
		else if (*p >= 'a' && *p <= 'z') {
			*t = *p - N < 'a' ? 'Z' + (*p + N - 'a' + 1) : *p - N;
			t++;
		}
		else if (*p >= '1' && *p <= '9') {
			num = *p - '0';

			if (*(p + 1) >= '0' && *(p + 1) < '7') {
				num *= 10;
				num += *(p + 1) - '0';

				p++;
			}

			for (int i = 0; i < N; i++, t++) {
				*t = 'A' + num - 1;
			}
		}
		else {
			*t = ' ';
			t++;
		}
	}
	*t = '\0';

	fl = 0;
	if (strcmp(NA, B) == 0)
		fl = 1;
	if (strcmp(NB, A) == 0)
		fl = 2;

	printf("%d\n", fl);

	return 0;
}