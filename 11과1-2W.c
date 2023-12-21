#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

typedef struct taxi_info {
	char start[11];
	char target[11];
	double distance;
	int t_time;
	char late_night;
	int tot;
} TAXI;

TAXI* sel_max(TAXI*, int, char*, char*);

int main(void) {

	TAXI st[20], *p;
	int N;
	char start[11], target[11];

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s %s %lf %d %c", st[i].start, st[i].target, &st[i].distance, &st[i].t_time, &st[i].late_night);
	
		
		if (st[i].late_night == 'Y') {
			st[i].tot = 4800;
			st[i].tot += 120 * (int)((st[i].distance - 2) * 1000 / 100);
			st[i].tot += 120 * (int)(st[i].t_time / 30);
		}
		else {
			st[i].tot = 3800;
			st[i].tot += 100 * (int)((st[i].distance - 2) * 1000 / 100);
			st[i].tot += 100 * (int)(st[i].t_time / 30);
		}
	}

	scanf("%s %s", start, target);

	p = sel_max(st, N, start, target);

	printf("%.2f %d %c %d", p->distance, p->t_time, p->late_night, p->tot);

	return 0;
}

TAXI* sel_max(TAXI* p, int N, char* s, char* d) {

	TAXI *t, *q = p;
	int max = -1;

	for (t = p; t < p + N; t++)
		if (strcmp(t->start, s) == 0 && strcmp(t->target, d) == 0)
			if (max < t->tot){
				max = t->tot;
				q = t;
			}

	return q;
}