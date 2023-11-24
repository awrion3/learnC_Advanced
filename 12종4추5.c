#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct word {
	char spell[20];
	int L; 
	int V; 
};

int main(void) {

	char temp[100], *t, *q = NULL, *r = NULL;
	int tlen, M = 0, fl = 0, cnt = 0;
	struct word sp[100], cp[100], smp;

	gets_s(temp, 99);
	tlen = strlen(temp);

	for (t = temp; t < temp + tlen; t++)
		if (*t == ' ') 
			*t = '\0';

	for (t = temp; t < temp + tlen; t++)
		if (*t != '\0'){
			q = t;
			break;
		}

	fl = 0; r = q;
	for (t = temp; t <= temp + tlen; t++)
		if (*t == '\0' && t >= r) {
			if (fl == 0) {
				strcpy(sp[M].spell, q);
				sp[M].L = strlen(sp[M].spell);
				sp[M++].V = cnt;

				cnt = 0;
			}
			q = t + 1;
			
			fl = 1;
		}
		else {
			if (*t == 'a' || *t == 'e' || *t == 'i' || *t == 'o' || *t == 'u')
				cnt++;

			fl = 0;
		}

	for (int i = 0; i < M; i++)
		cp[i] = sp[i];

	for (int i = 0; i < M - 1; i++)
		for (int j = 0; j < M - 1; j++)
			if (sp[j].L < sp[j + 1].L) {
				smp = sp[j];
				sp[j] = sp[j + 1];
				sp[j + 1] = smp;
			}

	for (int i = 0; i < M; i++)
		printf("%s %d\n", sp[i].spell, sp[i].L);
	printf("*****\n");

	for (int i = 0; i < M - 1; i++)
		for (int j = 0; j < M - 1; j++)
			if (cp[j].V < cp[j + 1].V) {
				smp = cp[j];
				cp[j] = cp[j + 1];
				cp[j + 1] = smp;
			}

	for (int i = 0; i < M; i++)
		printf("%s %d\n", cp[i].spell, cp[i].V);

	return 0;
}
/*
  ripe   three  banana   

ripe  three    banana
tell us  about   doing
*/