#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
	char* name;
	int first;
	int inter;
	double sum;
};

int main(void) {

	int N, M, len, cut = 0;
	struct student *p, smp;
	char tmp[11];

	scanf("%d %d", &N, &M);

	p = (struct student*)malloc(N * sizeof(struct student));
	if (p == NULL)
		return -1;

	for (int i = 0; i < N; i++){
		scanf("%s %d %d", tmp, &p[i].first, &p[i].inter);
		len = strlen(tmp);

		p[i].name = (char*)malloc((len + 1) * sizeof(char));
		if (p[i].name == NULL)
			return -1;

		strcpy(p[i].name, tmp);

		p[i].sum = p[i].first * 7 + p[i].inter * 3;
	}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			if (p[j].sum <= p[j + 1].sum) {
				if (p[j].sum < p[j + 1].sum) {
					smp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = smp;
				}
				else if (p[j].first <= p[j + 1].first) {
					if (p[j].first < p[j + 1].first) {
						smp = p[j];
						p[j] = p[j + 1];
						p[j + 1] = smp;
					}
					else if (strcmp(p[j].name, p[j + 1].name) > 0) {
						smp = p[j];
						p[j] = p[j + 1];
						p[j + 1] = smp;
					}
				}
			}

	for (int i = 0; i < M; i++)
		printf("%s %d %d %.1f\n", p[i].name, p[i].first, p[i].inter, p[i].sum / 10);

	for (int i = M; i < N; i++)
		if (p[M - 1].sum == p[i].sum && p[M - 1].first == p[i].first) {
			printf("%s %d %d %.1f\n", p[i].name, p[i].first, p[i].inter, p[i].sum / 10);
			cut++;
		}

	printf("%d", M + cut);

	for (int i = 0; i < N; i++)
		free(p[i].name);
	free(p);

	return 0;
}
/*
7 3
Kim 75 85
Lee 96 56
Park 94 82
Choi 78 70
Jung 65 85
Kang 93 63
Cho 93 63
*/