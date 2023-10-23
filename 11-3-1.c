#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct hotel_info {
	char name[31], food;
	int grade;
	double rate, dist;
};

int in_hotel_info(struct hotel_info *);
void out_hotel_info(struct hotel_info *, int, int, double);

int main(void) {

	struct hotel_info st[100];
	int N, G;
	double D;

	N = in_hotel_info(st);

	scanf("%d %lf", &G, &D);

	out_hotel_info(st, N, G, D);

	return 0;
}

int in_hotel_info(struct hotel_info *p) {

	struct hotel_info* ps;
	char tmp[31], zer[2] = "0";
	int N = 0;

	for (ps = p; ps < p + 100; ps++) {
		scanf("%s", tmp);
		if (strcmp(tmp, zer) == 0)
			break;

		strcpy(ps->name, tmp);
		scanf("%d %lf %lf %c", &ps->grade, &ps->rate, &ps->dist, &ps->food);
		N++;
	}

	return N;
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D) {

	struct hotel_info *ps, *r = p;	//연결 필요
	double max = -1;

	for (ps = p; ps < p + N; ps++)
		if (ps->grade >= G && ps->dist <= D) {
			if (ps->rate >= max){	//같거나 큰 경우,
				if (ps->rate == max) {
					if (strcmp(ps->name, r->name) < 0) {	//이름이 사전 순 빠를 때만 갱신
						max = ps->rate;
						r = ps;
					}
				}
				else {	//큰 경우,
					max = ps->rate;
					r = ps;
				}
			}
		}

	printf("%s %d %.1f %.1f %c", r->name, r->grade, r->rate, r->dist, r->food);
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