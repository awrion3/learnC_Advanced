#pragma warning(disable:4996)
#include <stdio.h>

typedef struct taxi_info {
	char start[11];
	char target[11];
	double distance;
	int t_time;
	char late_night;
	int tot;
} TAXI;

int main(void) {

	TAXI st[20];
	int dis, over;

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
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

	for (int i = 0; i < N; i++)
		printf("%s %s %d\n", st[i].start, st[i].target, st[i].tot);

	return 0;
}
/*
4
aaa bbb 2 180 N
ccc ddd 2.25 135 Y
eee fff 5 0 Y
ggg hhh 7.5 60 N
*/