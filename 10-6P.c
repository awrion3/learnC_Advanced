#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int front(char *, int);
int back(char *, int);

int main(void) {

	char ar[101];
	int len, fr, bk;

	scanf("%s", ar);
	len = strlen(ar);

	for (int i = 0; i < len; i++) {

		fr = front(ar, i);
		bk = back(ar, i);
		
		if (fr == 1 && bk == 1) 
			if (ar + i != ar && ar + i != ar + len - 1)
				*(ar + i) -= ('a' - 'A');
	}
	
	printf("%s", ar);

	return 0;
}

int front(char* p, int idx) {

	char *q, *r = p + idx;
	int dup = 0;

	for (q = p; q < p + idx; q++)
		if (*q == *r)
			dup = 1;

	return dup;
}

int back(char* p, int idx) {

	char *q, *r = p + idx;
	int dup = 0, len;
	
	len = strlen(p);

	for (q = p + idx + 1; q < p + len; q++)
		if (*q == *r)
			dup = 1;
	
	return dup;
}
/*
abcdabdacd
*/