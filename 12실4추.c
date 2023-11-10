#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string {
	char* str;
	int words;
};

int main(void) {

	int N, tlen, cnt;
	struct string *p, smp;
	char tmp[101], *t;

	scanf("%d", &N);
	getchar();

	p = (struct string*)malloc(N * sizeof(struct string));

	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++) {
		gets_s(tmp, 100);
		tlen = strlen(tmp);

		p[i].str = (char*)malloc((tlen + 1) * sizeof(char));

		if (p[i].str == NULL) {
			printf("Not enough memory");
			return -1;
		}

		strcpy(p[i].str, tmp);

		cnt = 1;
		for (t = tmp; t < tmp + tlen; t++) {
			if (*t == ' ')
				cnt++;
		}

		p[i].words = cnt;
	}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++){
			if (p[j].words < p[j + 1].words) {
				smp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = smp;
			}
		}

	for (int i = 0; i < N; i++)
		printf("%s %d\n", p[i].str, p[i].words);

	for (int i = 0; i < N; i++)
		free(p[i].str);
	free(p);

	return 0;
}
/*
5
why so serious
icecream makes everything better
you make me smile
c language midterm and final
see you
*/