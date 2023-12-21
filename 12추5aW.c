#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string {
	char *str;
	int words;
};

int main(void) {

	int N, len, num, wlen, kdx, wnt, max;
	struct string *p, smp;
	char tmp[101], *t, **q = NULL, *r, word[101];

	scanf("%d", &N);
	getchar();

	p = (struct string*)malloc(N * sizeof(struct string));
	if (p == NULL)
		return -1;

	for (int i = 0; i < N; i++) {
		gets_s(tmp, 100);

		len = strlen(tmp);

		p[i].str = (char*)malloc((len + 1) * sizeof(char));
		if (p[i].str == NULL)
			return -1;

		strcpy(p[i].str, tmp);

		num = 1;
		for (t = tmp; t < tmp + len; t++)
			if (*t == ' '){
				num++;
			}

		p[i].words = num;
	}

	for (int i = 0; i < N -1; i++)
		for (int j = 0; j < N - 1; j++)
			if (p[j].words < p[j + 1].words) {
				smp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = smp;
			}

	for (int i = 0; i < N; i++) {
	
		printf("%s %d ", p[i].str, p[i].words);

		q = (char**)malloc(p[i].words * sizeof(char*));
		if (q == NULL)
			return -1;

		len = strlen(p[i].str);
		
		for (t = p[i].str; t < p[i].str + len; t++) {
			if (*t == ' ')
				*t = '\0';
		}

		r = p[i].str; kdx = 0;
		for (t = p[i].str; t <= p[i].str + len; t++) {
			if (*t == '\0'){
				wlen = strlen(r);

				q[kdx] = (char*)malloc((wlen + 1) * sizeof(char));
				if (q[kdx] == NULL)
					return -1;

				strcpy(q[kdx++], r);

				r = t + 1;
			}
		}

		max = -1;
		for (int u = 0; u < kdx; u++){
			wnt = 0;
			for (int v = 0; v < kdx; v++)
				if (strcmp(q[u], q[v]) == 0)
					wnt++;

			if (max <= wnt) {
				if (max < wnt) {
					max = wnt;
					strcpy(word, q[u]);
				}
				else if (strcmp(word, q[u]) > 0) {
					max = wnt;
					strcpy(word, q[u]);
				}
			}
		}

		printf("%s %d\n", word, max);

		for (int j = 0; j < p[i].words; j++) //
			free(q[j]);
		free(q);	//
	}

	//
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