#pragma warning(disable:4996)
#include <stdio.h>

struct student {
	char name[21];
	int kor, eng, math;
	double avg;
};

//
void read_data(struct student*, int);
void sort_score(struct student*, int);
struct student* select_out(struct student*, struct student*, int);

int main(void) {

	struct student st1[50], st2[50], *p, *st;	
	int N;

	scanf("%d", &N);
	
	read_data(st1, N);
	read_data(st2, N);

	sort_score(st1, N);
	sort_score(st2, N);

	st = select_out(st1, st2, N);

	for (p = st; p < st + N; p++)
		printf("%s %d %d %d %.1f\n", p->name, p->kor, p->eng, p->math, p->avg);

	return 0;
}

//
void read_data(struct student* st, int N) {

	struct student* p;

	for (p = st; p < st + N; p++){
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);

		p->avg = (double)(p->kor + p->eng + p->math) / 3;
	}
}

void sort_score(struct student* st, int N) {

	struct student *p, smp;

	for (int i = 0; i < N - 1; i++)
		for (p = st; p < st + N - 1; p++)
			if (p->avg <= (p + 1)->avg) {
				if (p->avg == (p + 1)->avg) {
					//
					if (p->kor <= (p + 1)->kor) {
						if (p->kor == (p + 1)->kor) {
							//
							if (p->eng < (p + 1)->eng) {
								smp = *p;
								*p = *(p + 1);
								*(p + 1) = smp;
							}
						}
						else {
							smp = *p;
							*p = *(p + 1);
							*(p + 1) = smp;
						}
					}
				}
				else {
					smp = *p;
					*p = *(p + 1);
					*(p + 1) = smp;
				}
			}
}

struct student* select_out(struct student* st1, struct student* st2, int N) {

	int M = N / 2;	//

	if ((st1 + M)->avg > (st2 + M)->avg)
		return st1;
	return st2;
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