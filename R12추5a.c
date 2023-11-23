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
	char tmp[101], *t;
	int N, tlen, cnt, k, wlen, max;
	char **q, *r, mwd[101];

	scanf("%d", &N);
	getchar();

	p = (struct string*)malloc(N * sizeof(struct string));

	if (p == NULL) {
		printf("not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++) {
		gets_s(tmp, 100);

		tlen = strlen(tmp);

		p[i].str = (char*)malloc((tlen + 1) * sizeof(char));

		if (p[i].str == NULL) {
			printf("not enough memory");
			return -1;
		}

		strcpy(p[i].str, tmp);

		cnt = 1;
		for (t = tmp; t < tmp + tlen; t++)
			if (*t == ' ')
				cnt++;

		p[i].words = cnt;
	}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			if (p[j].words < p[j + 1].words) {
				smp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = smp;
			}

	for (int i = 0; i < N; i++) {
		strcpy(tmp, p[i].str);
		tlen = strlen(p[i].str);

		for (t = tmp; t < tmp + tlen; t++)
			if (*t == ' ')
				*t = '\0';

		q = (char**)malloc(p[i].words * sizeof(char*));

		if (q == NULL) {
			printf("not enough memory");
			return -1;
		}

		r = tmp, k = 0;
		for (t = tmp; t <= tmp + tlen; t++)
			if (*t == '\0') {
				wlen = strlen(r);

				q[k] = (char*)malloc((wlen + 1) * sizeof(char));

				if (q[k] == NULL) {
					printf("not enough memory");
					return -1;
				}

				strcpy(q[k++], r);

				r = t + 1;
			}

		max = -1;
		for (int j = 0; j < k; j++){
			cnt = 0;
			for (int m = 0; m < k; m++)
				if (strcmp(q[j], q[m]) == 0)
					cnt++;

			if (max <= cnt) {
				if (max < cnt) {
					max = cnt;
					strcpy(mwd, q[j]);
				}
				else if (strcmp(mwd, q[j]) > 0) {
					max = cnt;
					strcpy(mwd, q[j]);
				}
			}
		}

		printf("%s %d %s %d\n", p[i].str, p[i].words, mwd, max);

		for (int j = 0; j < p[i].words; j++)	//한 문장 속 단어마다 각 문자열 할당 해제
			free(q[j]);
		free(q);	//한 문장 관련 이차원 배열 할당 해제
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