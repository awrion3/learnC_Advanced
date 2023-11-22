#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char *name;
	int kor;
} student;

int main(void) {

	student* p;
	int N, len, lm1, lm2;
	char tmp[21], nm1[21], nm2[21];

	scanf("%d", &N);

	p = (struct student*)malloc(N * sizeof(struct student));

	if (p == NULL) {
		printf("not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++) {
		scanf("%s", tmp);
		len = strlen(tmp);

		p[i].name = (char*)malloc((len + 1) * sizeof(char));

		if (p[i].name == NULL) {
			printf("not enough memory");
			return -1;
		}

		strcpy(p[i].name, tmp);

		scanf("%d", &p[i].kor);
	}

	scanf("%d %d", &lm1, &lm2);
	scanf("%s %s", nm1, nm2);

	for (int i = 0; i < N; i++)
		if (p[i].kor >= lm1 && p[i].kor <= lm2)
			printf("%s %d\n", p[i].name, p[i].kor);

	printf("*****\n");
	for (int i = 0; i < N; i++)
		if (strcmp(p[i].name, nm1) >= 0 && strcmp(p[i].name, nm2) <= 0)
			printf("%s %d\n", p[i].name, p[i].kor);

	for (int i = 0; i < N; i++)
		free(p[i].name);
	free(p);

	return 0;
}
/*
5
jacob 31
kim 41
lee 51
park 61
jane 71
60 75
ja lz
*/