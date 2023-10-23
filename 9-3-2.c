#pragma warning(disable:4996)
#include <stdio.h>

void PRT(int, char*);

int main(void) {

	char ar[100], *p, *pmax = NULL, *pword = NULL;
	int m = 0, fl = 0, max = -1, len = 0;

	for (p = ar; p < ar + 100; p++) {
		scanf("%c", p);
		m++;
		if (*p == '#')
			break;
	}

	for (p = ar; p < ar + m; p++) {	//'#'까지 훑어 마지막 단어까지 읽게 함
		if (*p >= 'a' && *p <= 'z') {
			printf("%c", *p);

			if (fl == 0) {	//단어의 첫 글자마다 저장
				pword = p;
			}
			fl = 1;
			len++;
		}
		else {
			if (max < len){
				max = len;
				pmax = pword;
			}
			len = 0;

			if (fl == 1)
				printf("\n");
			fl = 0;
		}
	}

	printf("%d %c\n", max, *pmax);

	PRT(max, pmax);

	return 0;
}

void PRT(int n, char* p) {

	char *q;

	for (q = p; q < p + n; q++)
		printf("%c", *q);
}
/*
roll out electric334car334#
*/