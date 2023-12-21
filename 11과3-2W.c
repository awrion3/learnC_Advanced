#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

typedef struct hotel {
	char name[31];
	int grade;
	double rate;
	double dist;
	char food;
} hotel;

int in_hotel(hotel *);
void out_hotel(hotel *, int, int, double);

int main(void) {

	hotel st[100];
	int N, G;
	double D;

	N = in_hotel(st);

	scanf("%d %lf", &G, &D);

	out_hotel(st, N, G, D);

	return 0;
}

int in_hotel(hotel *p) {

	hotel* t;
	char tmp[31], fin[2] = "0";
	int num = 0;

	for (t = p; t < p + 100; t++) {
		scanf("%s", tmp);

		if (strcmp(tmp, fin) == 0)
			break;
		else
			strcpy(t->name, tmp);

		scanf("%d %lf %lf %c", &t->grade, &t->rate, &t->dist, &t->food);
		num++;
	}

	return num;
}

void out_hotel(hotel *p, int N, int G, double D) {

	hotel *t, nst[100], *q = nst, smp;
	int M = 0;

	for (t = p; t < p + N; t++)
		if (t->grade >= G && t->dist <= D) {
			*q = *t;
			q++;
			M++;
		}

	for (int i = 0; i < M - 1; i++)
		for (t = nst; t < nst + M - 1; t++)
			if (t->rate <= (t + 1)->rate) {
				if (t->rate < (t + 1)->rate) {
					smp = *t;
					*t = *(t + 1);
					*(t + 1) = smp;
				}
				else if (strcmp(t->name, (t + 1)->name) > 0) {
					smp = *t;
					*t = *(t + 1);
					*(t + 1) = smp;
				}
			}

	for (t = nst; t < nst + M; t++)
		printf("%s %d %.1f %.1f %c\n", t->name, t->grade, t->rate, t->dist, t->food);
}
/*
marriott 4 4.7 12.5 Y
ibis 2 3.5 5.6 N
novotel 3 3.0 2.7 N
renaissance 3 3.5 4.8 N
hyatt 5 3.5 7.4 Y
bestwestern 2 2.5 3.8 Y
0
3 7.5
*/