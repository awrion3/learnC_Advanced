#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct student {
	char name[21];
	int kor, eng, math;
	double avg;
};

void read_data(struct student *, int);
void sort_score(struct student *, int);
struct student* select_out(struct student*, struct student*, int);

int main(void) {

	int N;
	struct student st1[49], st2[49], *p, *t;

	scanf("%d", &N);

	read_data(st1, N);
	read_data(st2, N);

	sort_score(st1, N);
	sort_score(st2, N);

	p = select_out(st1, st2, N);

	for (t = p; t < p + N; t++)
		printf("%s %d %d %d %.1f\n", t->name, t->kor, t->eng, t->math, t->avg);

	return 0;
}

void read_data(struct student *p, int N) {

	struct student* t;

	for (t = p; t < p + N; t++){
		scanf("%s %d %d %d", t->name, &t->kor, &t->eng, &t->math);
		t->avg = (double)(t->kor + t->eng + t->math) / 3;
	}
}

void sort_score(struct student *p, int N) {

	struct student *t, smp;

	for (int i = 0; i < N - 1; i++)
		for (t = p; t < p + N - 1; t++)
			if (t->avg <= (t + 1)->avg) {
				if (t->avg < (t + 1)->avg) {
					smp = *t;
					*t = *(t + 1);
					*(t + 1) = smp;
				}
				else if (t->kor <= (t + 1)->kor) {
					if (t->kor <= (t + 1)->kor) {
						smp = *t;
						*t = *(t + 1);
						*(t + 1) = smp;
					}
					else if (t->eng < (t + 1)->eng) {
						smp = *t;
						*t = *(t + 1);
						*(t + 1) = smp;
					}
				}
			}
}

struct student* select_out(struct student *p, struct student *q, int N) {

	struct student* r;

	N = N / 2 + 1;

	r = (p + N)->avg > (q + N)->avg ? p : q;

	return r;
}
/*
5
Kim 100 85 80
Lee 88 94 92
Park 92 100 100
Hong 84 82 85
Nam 80 84 72
Song 100 90 97
Lee 92 82 93
Park 80 84 72
Choi 97 80 90
Chung 100 94 93
*/