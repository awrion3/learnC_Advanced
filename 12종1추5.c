#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char* depart;
	char id[8];
}student;

int main(void) {

	int N, len;
	char tmp[101];
	student *p, smp;

	scanf("%d", &N);

	p = (student*)malloc(N * sizeof(student));

	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++) {
		scanf("%s", tmp);

		len = strlen(tmp);
		p[i].depart = (char*)malloc((len + 1) * sizeof(char));

		if (p[i].depart == NULL) {
			printf("Not enough memory");
			return -1;
		}

		strcpy(p[i].depart, tmp);

		scanf("%s", p[i].id);
	}
	
	for (int i = 0; i < N - 1;i++)
		for (int j = 0; j < N - 1; j++)
			if (strcmp(p[j].depart, p[j + 1].depart) >= 0) {
				if (strcmp(p[j].depart, p[j + 1].depart) > 0) {
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

	for (int i = 0; i < N; i++)
		printf("%s %s\n", p[i].depart, p[i].id);

	for (int i = 0; i < N; i++)
		free(p[i].depart);
	free(p);

	return 0;
}

/*
5
english 003
korean 005
english 001
korean 004
korean 002
*/