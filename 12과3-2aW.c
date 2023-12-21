#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct subject {
	char* name;
	double score;
};

struct student {
	char* name;
	char id[5];
	int numSub;
	struct subject* psub;
	double avg;
};

int main(void) {

	int N, len, M, cnt, wlen, idx, K;
	double max = -1;
	char tmp[101], *t, *q, mst[101];
	struct student *p, smp;

	scanf("%d", &N);

	p = (struct student*)malloc(N * sizeof(struct student));
	if (p == NULL)
		return -1;

	getchar();

	for (int i = 0; i < N; i++) {
		
		gets_s(tmp, 100);

		len = strlen(tmp);

		M = 1;
		for (t = tmp; t < tmp + len; t++)
			if (*t == ' '){
				*t = '\0';
				M++;
			}
		M = (M - 2) / 2;
		p[i].numSub = M;

		p[i].psub = (struct subject*)malloc(M * sizeof(struct subject));
		if (p[i].psub == NULL)
			return -1;

		p[i].avg = 0;
		cnt = 0; q = tmp; idx = 0;
		for (t = tmp; t <= tmp + len; t++)
			if (*t == '\0'){

				if (cnt == 0) {
					wlen = strlen(q);

					p[i].name = (char*)malloc((wlen + 1) * sizeof(char));
					if (p[i].name == NULL)
						return -1;

					strcpy(p[i].name, q);
				}
				else if (cnt == 1) {
					strcpy(p[i].id, q);
				}
				else {
					if (cnt % 2 == 0) {
						wlen = strlen(q);

						p[i].psub[idx].name = (char*)malloc((wlen + 1) * sizeof(char));
						if (p[i].psub[idx].name == NULL)
							return -1;

						strcpy(p[i].psub[idx].name, q);
					}
					else {
						p[i].psub[idx++].score = atof(q);
						p[i].avg += atof(q);
					}
				}

				cnt++;
				q = t + 1;
			}

		p[i].avg = (double)p[i].avg / p[i].numSub;
	}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			if (p[j].avg <= p[j + 1].avg) {
				if (p[j].avg < p[j + 1].avg) {
					smp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = smp;
				}
				else if (strcmp(p[j].id, p[j + 1].id) > 0) {
					smp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = smp;
				}
			}
	scanf("%d", &K);
	K--;

	printf("%s %s %.2f", p[K].name, p[K].id, p[K].avg);

	for (int i = 0; i < p[K].numSub; i++)
		if (max < p[K].psub[i].score){
			max = p[K].psub[i].score;
			strcpy(mst, p[K].psub[i].name);
		}
	
	printf(" %s %.2f", mst, max);
	
	//
	for (int i = 0; i < N; i++){
		for (int j = 0; j < p[i].numSub; j++)
			free(p[i].psub[j].name);
		free(p[i].psub);
		free(p[i].name);
	}
	free(p);

	return 0;
}
/*
5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
2
*/