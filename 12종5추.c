#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char* name;
	int kor, eng, math, diff;
}student;

student* difference(student*, int);

int main(void) {

	student *p, *q;
	int N, len;
	char tmp[101];

	scanf("%d", &N);

	p = (student*)malloc(N * sizeof(student));

	if (p == NULL) {
		printf("not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++){
		scanf("%s", tmp);
		len = strlen(tmp);

		p[i].name = (char*)malloc((len + 1) * sizeof(char));

		if (p[i].name == NULL) {
			printf("not enough memory");
			return -1;
		}

		strcpy(p[i].name, tmp);

		scanf("%d %d %d", &p[i].kor, &p[i].eng, &p[i].math);
	}

	q = difference(p, N);

	printf("%s %d", q->name, q->diff);

	for (int i = 0; i < N; i++)
		free(p[i].name);
	free(p);

	return 0;
}

student* difference(student *p, int N) {

	student *q, *r = p;
	int gap = -1, max, min;

	for (q = p; q < p + N; q++){
		max = -1, min = 101;

		if (q->kor > max)
			max = q->kor;
		if (q->eng > max)
			max = q->eng;
		if (q->math > max)
			max = q->math;

		if (q->kor < min)
			min = q->kor;
		if (q->eng < min)
			min = q->eng;
		if (q->math < min)
			min = q->math;

		if (gap < max - min){
			gap = max - min;
			q->diff = gap;

			r = q;
		}
	}

	return r;
}
/*
4
jacob 31 32 41
cathy 41 51 52
park 61 51 41
jane 71 81 31
*/