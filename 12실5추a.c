#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string {
	char* str;
	int words;
};

int main(void) {

	struct string *p, smp;
	int N, tlen, k, wlen, cnt, max, num;
	char tmp[101], *t, **q = NULL, mmp[101];

	scanf("%d", &N);
	getchar();

	p = (struct string*)malloc(N * sizeof(struct string));

	if (p == NULL) {
		printf("Not enough memory!");
		return -1;
	}

	for (int i = 0; i < N; i++) {
		gets_s(tmp, 100);
		tlen = strlen(tmp);

		p[i].str = (char*)malloc((tlen + 1) * sizeof(char));

		if (p[i].str == NULL) {	
			printf("Not enough memory!");
			return -1;
		}
		strcpy(p[i].str, tmp);
		
		num = 1;
		for (t = tmp; t < tmp + tlen; t++)
			if (*t == ' ') 
				num++;

		p[i].words = num;
	}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			if (p[j].words < p[j + 1].words) {
				smp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = smp;
			}
	//
	for (int i = 0; i < N; i++) {
		num = p[i].words;
		q = (char**)malloc(num * sizeof(char*));

		if (q == NULL) {	
			printf("Not enough memory!");
			return -1;
		}

		strcpy(tmp, p[i].str);
		tlen = strlen(tmp);
		for (t = tmp; t < tmp + tlen; t++)
			if (*t == ' ')
				*t = '\0';

		k = 0;
		wlen = strlen(tmp);
		q[k] = (char*)malloc((wlen + 1) * sizeof(char));
		
		if (q[k] == NULL) {	
			printf("Not enough memory!");
			return -1;
		}
		strcpy(q[k], tmp);

		for (t = tmp; t < tmp + tlen; t++) {
			if (*t == '\0') {
				k++;
				wlen = strlen(t + 1);

				q[k] = (char*)malloc((wlen + 1) * sizeof(char));

				if (q[k] == NULL) {		
					printf("Not enough memory!");
					return -1;
				}
				strcpy(q[k], t + 1);
			}
		}
		
		max = -1;
		for (int j = 0; j < p[i].words; j++){
			cnt = 0;
			for (int l = 0; l < p[i].words; l++)
				if (strcmp(q[j], q[l]) == 0) {
					cnt++;
					if (cnt >= max) {
						if (cnt > max) {
							max = cnt;
							strcpy(mmp, q[j]);
						}
						else {
							if (strcmp(mmp, q[j]) > 0) {
								max = cnt;
								strcpy(mmp, q[j]);
							}
						}
					}
				}
		}		
		printf("%s %d %s %d\n", p[i].str, p[i].words, mmp, max);	

		for (k = 0; k < p[i].words; k++)
			free(q[k]);
		free(q);
	}

	for (int i = 0; i < N; i++)
		free(p[i].str);
	free(p);

	return 0;
}
/*
5
why why why so so so serious
icecream makes everything better and better
you make me smile
c language exam and exam and exam and exam
see you later later later later
*/