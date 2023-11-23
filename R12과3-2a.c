#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct subject {
	char* name;
	double score;
};

struct student {
	char* studentName;
	char id[5];
	int numSubject;
	struct subject* psub;
	double avg;
};

int main(void) {

	struct student *p, smp;
	char tmp[101], *t, *q, msub[101];
	int N, tlen, cnt, wlen, fl, M, K, j;
	double sum, max = -1;

	scanf("%d", &N);
	getchar();

	p = (struct student*)malloc(N * sizeof(struct student));

	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++) {
		gets_s(tmp, 100);
		tlen = strlen(tmp);

		cnt = 1, M;
		for (t = tmp; t < tmp + tlen; t++) 
			if (*t == ' '){
				*t = '\0';
				cnt++;
			}
		M = (cnt - 2)/2;
		p[i].numSubject = M;

		cnt = 0, q = tmp, fl = 0, j = 0;
		for (t = tmp; t <= tmp + tlen; t++) {
			if (*t == '\0') {
				
				if (cnt == 0) {
					wlen = strlen(q);

					p[i].studentName = (char*)malloc((wlen + 1) * sizeof(char));

					if (p[i].studentName == NULL) {
						printf("Not enough memory");
						return -1;
					}

					strcpy(p[i].studentName, q);
				}
				else if (cnt == 1) {
					strcpy(p[i].id, q);
				}
				else {
					if (fl == 0) {
						p[i].psub = (struct subject*)malloc(M * sizeof(struct subject));
					
						if (p[i].psub == NULL) {
							printf("Not enough memory");
							return -1;
						}

						sum = 0;
						fl = 1;
					}

					if (cnt % 2 == 0) {
						wlen = strlen(q);

						p[i].psub[j].name = (char*)malloc((wlen + 1) * sizeof(char));

						if (p[i].psub[j].name == NULL) {
							printf("Not enough memory");
							return -1;
						}

						strcpy(p[i].psub[j].name, q);
					}
					else {
						p[i].psub[j].score = atof(q);
						
						sum += p[i].psub[j].score;
						j++;
					}
				}

				cnt++;
				q = t + 1;
			}
		}
		p[i].avg = sum / M;
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
	
	printf("%s %s %.2lf ", p[K].studentName, p[K].id, p[K].avg);

	for (int j = 0; j < p[K].numSubject; j++) {
		if (max < p[K].psub[j].score) {
			max = p[K].psub[j].score;
			strcpy(msub, p[K].psub[j].name);
		}
	}

	printf("%s %.2lf", msub, max);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < p[i].numSubject; j++)
			free(p[i].psub[j].name);
		free(p[i].studentName);
		free(p[i].psub);
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