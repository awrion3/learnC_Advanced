#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char x[101] = { 0 }, y[50][101] = { 0 }, tmp[101] = { 0 }, *p, *q;
	int i = 0;

	gets_s(x, 100);
	
	q = x;
	for (p = x; ;p++) {
		if (*p == ' ') {
			*p = '\0';
			strcpy(y[i++], q);
			q = p + 1;
		}
		else if (*p == '\0') {
			strcpy(y[i++], q);
			break;
		}
	}

	for (int j = 0; j < i - 1; j++) 
		for (int k = 0; k < i - 1; k++)
			if (strcmp(y[k], y[k + 1]) > 0) {
				strcpy(tmp, y[k]);
				strcpy(y[k], y[k + 1]);
				strcpy(y[k + 1], tmp);
			}

	for (int j = 0; j < i; j++)
		printf("%s\n", y[j]);

	return 0;
}
/*
cat banana apricot
*/