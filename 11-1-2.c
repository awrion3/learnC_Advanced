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
	int N, dis, over;
	char sta[11], des[11];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s %s %lf %d %c", st[i].start, st[i].target, &st[i].distance, &st[i].t_time, &st[i].late_night);

		st[i].tot = 0;
		if (st[i].late_night == 'N')
			st[i].tot += 3800;
		else
			st[i].tot += 4800;

		if (st[i].distance > 2) {
			dis = (int)((st[i].distance - 2) * 1000 / 100);

			if (st[i].late_night == 'N')
				st[i].tot += dis * 100;
			else
				st[i].tot += dis * 120;
		}

		over = st[i].t_time / 30;
		if (st[i].late_night == 'N')
			st[i].tot += over * 100;
		else
			st[i].tot += over * 120;
	}

	scanf("%s %s", sta, des);

	p = sel_max(st, N, sta, des);

	printf("%.2f %d %c %d\n", p->distance, p->t_time, p->late_night, p->tot);

	return 0;
}

TAXI* sel_max(TAXI *p, int N, char *s, char *d) {

	TAXI *ps, *pmax = p;
	int max = -1;

	for (ps = p; ps < p + N; ps++) {
		if (strcmp(ps->start, s) == 0 && strcmp(ps->target, d) == 0) {
			if (max < ps->tot) {
				max = ps->tot;
				pmax = ps;
			}
		}
	}

	return pmax;
}
/*
8
aaa bbb 2.25 480 N
ccc ddd 10 300 Y
eee fff 10 180 Y
aaa bbb 3 180 N
ccc ddd 12 180 Y
ggg hhh 13 60 Y
aaa bbb 4 0 N
aaa bbb 3.2 60 N
aaa bbb
*/