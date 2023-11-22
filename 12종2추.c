#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	char str[101], key[101], *t, keys[2][101], *s, **p;
	int tlen, klen, i, cnt, wlen;

	gets_s(str, 100);
	gets_s(key, 100);

	tlen = strlen(str);
	for (t = str; t < str + tlen; t++)
		if (*t == ' ')
			*t = '\0';

	klen = strlen(key);
	s = key, i = 0;
	for (t = key; t <= key + klen; t++)
		if (*t == ' ' || *t == '\0') {
			*t = '\0';
			strcpy(keys[i++], s);
			s = t + 1;
		}

	s = str, cnt = 0;
	for (t = str; t <= str + tlen; t++)
		if (*t == '\0') {
			if (strcmp(keys[0], s) <= 0 && strcmp(keys[1], s) >= 0) 
				cnt++;

			s = t + 1;
		}

	p = (char**)malloc(cnt * sizeof(char*));
	
	if (p == NULL) {
		printf("not enough memory");
		return -1;
	}

	s = str, i = 0;
	for (t = str; t <= str + tlen; t++)
		if (*t == '\0') {
			if (strcmp(keys[0], s) <= 0 && strcmp(keys[1], s) >= 0){

				wlen = strlen(s);

				p[i] = (char*)malloc((wlen + 1) * sizeof(char));

				if (p[i] == NULL) {
					printf("not enough memory");
					return -1;
				}

				strcpy(p[i++], s);
			}
			s = t + 1;
		}
	
	for (i = 0; i < cnt; i++)
		printf("%s\n", p[i]);

	for (i = 0; i < cnt; i++)
		free(p[i]);
	free(p);

	return 0;
}
/*
lion cat tiger snake bear
caa szz
*/