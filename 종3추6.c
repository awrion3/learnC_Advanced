#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char *name;
	int kor, prime;
}student;

void prime(student *);

int main(void) {

	student *p, *t;
	char tmp[21];
	int N, len;

	scanf("%d", &N);

	p = (student*)malloc(N * sizeof(student));

	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++) {
		scanf("%s", tmp);
		
		len = strlen(tmp);

		p[i].name = (char*)malloc((len + 1) * sizeof(char));

		if (p[i].name == NULL) {
			printf("Not enough memory");
			return -1;
		}

		strcpy(p[i].name, tmp);

		scanf("%d", &p[i].kor);
	}

	for (t = p; t < p + N; t++)
		prime(t);

	for (int i = 0; i < N; i++)
		if (p[i].prime)
			printf("%s %d\n", p[i].name, p[i].kor);

	for (int i = 0; i < N; i++)
		free(p[i].name);
	free(p);

	return 0;
}

void prime(student *p) {
	
	int isp = 1;

	for (int i = 2; i < p->kor; i++)
		if (p->kor % i == 0) {
			isp = 0;
			break;
		}

	p->prime = isp;
}
/*
5
jacob 31
kim 41
lee 51
park 61
jane 71
*/