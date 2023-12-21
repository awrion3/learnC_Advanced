#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

typedef struct parking {
	int num;
	int pho;
	char opt;
	char mem;
	int type;
	int min;
	double fee;
} park;

void input(park*, int);
void compute(park*);
void display(park*, int);
void sort(park*, int);

int main(void) {

	park st[100], *t;
	int N;

	scanf("%d", &N);

	input(st, N);

	for (t = st; t < st + N; t++)
		compute(t);

	sort(st, N);

	display(st, N);

	return 0;
}

void input(park *p, int N) {

	park* t;

	for (t = p; t < p + N; t++){
		scanf("%d %d %c", &t->num, &t->pho, &t->opt);

		if (t->opt == 'S') {
			getchar();
			scanf("%c %d %d", &t->mem, &t->type, &t->min);
		}
		else
			scanf("%d", &t->min);
	}
}

void compute(park *p) {
	
	if (p->opt == 'S') {
		if (p->mem == 'N') {
			if (p->type == 7)
				p->fee = 30000;
			else if (p->type == 30)
				p->fee = 100000;
			else
				p->fee = 500000;
		}
		else
			p->fee = 0;
	}
	else
		p->fee = 5000;
	
	if (p->min >= 240) {
		p->min -= 240;

		p->fee += (int)(p->min / 10) * 200;
	}
}

void display(park *p, int N) {

	park* t;
	double sfee = 0, dfee = 0;

	for (t = p; t < p + N; t++){
		printf("%d %d %c %.0f\n", t->num, t->pho, t->opt, t->fee);
		
		if (t->opt == 'S')
			sfee += t->fee;
		else
			dfee += t->fee;
	}

	printf("%.0f %.0f %.0f\n", dfee, sfee, dfee + sfee);
}

void sort(park *p, int N) {

	park *t, smp;

	for (int i = 0; i < N - 1; i++)
		for (t = p; t < p + N - 1; t++)
			if (t->opt >= (t + 1)->opt) {
				if (t->opt > (t + 1)->opt) {
					smp = *t;
					*t = *(t + 1);
					*(t + 1) = smp;
				}
				else if (t->num > (t + 1)->num) {
					smp = *t;
					*t = *(t + 1);
					*(t + 1) = smp;
				}
			}
}
/*
4
1111 12345678 S N 7 230
2222 22223333 D 240
3333 44445555 D 255
4444 66667777 S Y 30 200
*/