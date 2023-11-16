#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char* name;
	int kor;
}STUDENT;

STUDENT* center(STUDENT*, int);

int main(void) {
	
	STUDENT *p, *t, *r;
	int N, len;
	char tmp[31];

	scanf("%d", &N);

	p = (STUDENT*)malloc(N * sizeof(STUDENT));

	if (p == NULL){
		printf("Not enough memory");
		return -1;
	}

	for (t = p; t < p + N; t++){
		scanf("%s", tmp);
		len = strlen(tmp);

		t->name = (char*)malloc((len + 1) * sizeof(char));

		if (t->name == NULL) {
			printf("Not enough memory");
			return -1;
		}

		strcpy(t->name, tmp);

		scanf("%d", &t->kor);
	}

	r = center(p, N);

	printf("%s %d", r->name, r->kor);

	for (t = p; t < p + N; t++)
		free(t->name);
	free(p);

	return 0;
}

STUDENT* center(STUDENT* p, int N) {
	
	STUDENT *t, *r = NULL;
	double avg = 0, gap, min;
	int fl = 0;

	for (t = p; t < p + N; t++)
		avg += t->kor;

	avg = (double)avg / N;

	for (t = p; t < p + N; t++){
		gap = avg - t->kor;
		gap = gap > 0 ? gap : -gap;

		if (fl == 0) {
			min = gap;
			r = t;
			fl = 1;
		}
		if (min > gap) {
			min = gap;
			r = t;
		}
	}

	return r;
}
/*
3
John 70
Smith 80
Ann 90
*/