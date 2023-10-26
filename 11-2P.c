#pragma warning(disable:4996)
#include <stdio.h>

typedef struct student {
	int num;
	int sub1, sub2, sub3;
	double avg;
} student;

void average(student *);

int main(void) {

	student st[10], *p, smp;
	int N;

	scanf("%d", &N);

	for (p = st; p < st + N; p++) {
		scanf("%d %d %d %d", &p->num, &p->sub1, &p->sub2, &p->sub3);
		average(p);	
	}

	for (int i = 0; i < N - 1; i++)
		for (p = st; p < st + N - 1; p++)
			if (p->num > (p + 1)->num) {
				smp = *p;
				*p = *(p + 1);
				*(p + 1) = smp;
			}

	for (p = st; p < st + N; p++) 
		printf("%04d %.1f\n", p->num, p->avg);

	return 0;
}

void average(student *p) {

	p->avg = (double)(p->sub1 + p->sub2 + p->sub3) / 3;
}
/*
3
0011 90 95 90
0005 80 85 80
0003 70 75 70
*/