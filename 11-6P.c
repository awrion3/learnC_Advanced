#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[11];
	int kor, eng, math;
	int sum;
} student;

typedef struct subject {
	double koravg, engavg, mathavg;
	char top[11];
} subject;

struct subject average(struct student*, int);

int main(void) {

	student st[10], *p;
	subject sb;
	int N;

	scanf("%d", &N);

	for (p = st; p < st + N; p++) 
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
	
	sb = average(st, N);

	printf("kor=%.1f\n", sb.koravg);
	printf("eng=%.1f\n", sb.engavg);
	printf("math=%.1f\n", sb.mathavg);
	printf("top=%s", sb.top);

	return 0;
}

struct subject average(struct student *pst, int N) {

	student *p;
	subject sa = { 0 };
	int max = -1;
	char tmp[11] = { 0 };

	for (p = pst; p < pst + N; p++) {
		sa.koravg += p->kor;
		sa.engavg += p->eng;
		sa.mathavg += p->math;

		p->sum = p->kor + p->eng + p->math;
		if (p->sum > max) {
			max = p->sum;
			strcpy(tmp, p->name);
		}
	}

	sa.koravg = (double)sa.koravg / N;
	sa.engavg = (double)sa.engavg / N;
	sa.mathavg = (double)sa.mathavg / N;
	strcpy(sa.top, tmp);

	return sa;
}
/*
3
kim 90 95 90
tom 80 85 80
john 70 75 75
*/