#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char a[101], b[101], *p, *q, nstr[251] = "", sp[2] = " ";
	char wa[100][101] = { 0 }, wb[100][101] = { 0 };
	int alen, blen, adx = 0, bdx = 0, dup, k = 0;

	gets_s(a, 100);
	gets_s(b, 100);

	alen = strlen(a);
	blen = strlen(b);

	for (p = a; p < a + alen; p++)
		if (*p == ' ')
			*p = '\0';

	for (p = b; p < b + blen; p++)
		if (*p == ' ')
			*p = '\0';

	q = a;
	for (p = a; p <= a + alen; p++)
		if (*p == '\0'){
			strcpy(wa[adx++], q);
			q = p + 1;
		}
	
	q = b;
	for (p = b; p <= b + blen; p++)
		if (*p == '\0') {
			strcpy(wb[bdx++], q);
			q = p + 1;
		}

	for (int i = 0; i < adx; i++){
		dup = 0;
		for (int j = 0; j < i; j++)
			if (strcmp(wa[i], wa[j]) == 0)
				dup = 1;

		if (dup == 1){
			strcat(nstr, wb[k++]);
			strcat(nstr, sp);
		}
		else {
			strcat(nstr, wa[i]);
			strcat(nstr, sp);
		}
	}

	printf("%s", nstr);

	return 0;
}
/*
red orange red yellow green red blue purple yellow
white black gray pink brown blush crimson garnet vermilion indigo
*/