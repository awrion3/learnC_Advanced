#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char *p, wst[101], wli[10][101] = { 0 }, tmp[101];
	int len, i = 0, idx;

	gets_s(wst, 100);

	len = strlen(wst);

	for (p = wst; p < wst + len; p++)
		if (*p == ' ')
			*p = '\0';

	strcpy(wli[i++], wst);
	for (p = wst; p < wst + len; p++)
		if (*p == '\0') {
			strcpy(wli[i++], p + 1);
		}

	idx = i;
	for (int i = 0; i < idx  - 1; i++)
		for (int j = 0; j < idx - 1; j++) 
			if (strlen(wli[j]) < strlen(wli[j + 1])) {
				strcpy(tmp, wli[j]);
				strcpy(wli[j], wli[j + 1]);
				strcpy(wli[j + 1], tmp);
			}
	
	for (int i = 0; i < idx; i++)
		printf("%s\n", wli[i]);

	return 0;
}
/*
aa bbb cccc ddddd
*/