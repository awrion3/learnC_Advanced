#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char A[21], B[21], *p, *q, C[201]; //
	int aen, ben, num, N, i = 0, fl = 0;

	gets_s(A, 20);
	gets_s(B, 20);

	aen = strlen(A);
	ben = strlen(B);

	p = A, q = B;
	N = *p - *q > 0 ? *p - *q : -(*p - *q); //

	for (p = A; p < A + aen; p++)
		if (*p >= 'A' && *p <= 'Z') {
			C[i++] = *p + N > 'Z' ? 'A' + (*p + N - 'Z' - 1) : *p + N;
		}
		else if (*p >= 'a' && *p <= 'z') {
			C[i++] = *p - N < 'a' ? 'Z' + (*p - N - 'a' + 1) : *p - N; //
		}
		else if (*p >= '1' && *p <= '9') {
			if (*(p + 1) >= '0' && *(p + 1) <= '7') {
				num = *p - '0';
				num *= 10;
				num += *(p + 1) - '0';

				p++;
			}
			else
				num = *p - '0';
			num--;

			for (int j = 0; j < N; j++) //
				C[i++] = 'A' + num;
		}
		else
			C[i++] = ' ';
	C[i++] = '\0'; //

	if (strcmp(C, B) == 0)
		fl = 1;
	
	i = 0; //
	for (p = B; p < B + ben; p++)
		if (*p >= 'A' && *p <= 'Z') {
			C[i++] = *p + N > 'Z' ? 'A' + (*p + N - 'Z' - 1) : *p + N;
		}
		else if (*p >= 'a' && *p <= 'z') {
			C[i++] = *p - N < 'a' ? 'A' + (*p - N - 'z' + 1) : *p - N;
		}
		else if (*p >= '1' && *p <= '9') { //
			if (*(p + 1) >= '0' && *(p + 1) <= '7') {
				num = *p - '0';
				num *= 10;
				num += *(p + 1) - '0';

				p++; //
			}
			else
				num = *p - '0';
			num--; //

			for (int j = 0; j < N; j++)
				C[i++] = 'A' + num;
		}
		else
			C[i++] = ' ';
	C[i++] = '\0';

	if (strcmp(C, A) == 0)
		fl = 2;

	printf("%d", fl);

	return 0;
}
/*
Qej15J
SchOOL
*/