#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct hotel_info {
	char name[31], food;
	int grade;
	double rate, dist;
};

int in_hotel_info(struct hotel_info*);
void out_hotel_info(struct hotel_info*, int, int, double);

int main(void) {

	struct hotel_info st[100];
	int N, G;
	double D;

	N = in_hotel_info(st);

	scanf("%d %lf", &G, &D);

	out_hotel_info(st, N, G, D);

	return 0;
}

int in_hotel_info(struct hotel_info* p) {

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

void out_hotel_info(struct hotel_info* p, int N, int G, double D) {

	struct hotel_info *ps, res[100], *qs = res, smp;
	int M = 0;

	for (ps = p; ps < p + N; ps++)
		if (ps->grade >= G && ps->dist <= D) {
			*qs = *ps;	//구조체 대입
			qs++;
			M++;
		}

	for (int i = 0; i < M - 1; i++)
		for (qs = res; qs < res + M - 1; qs++) 	//버블 정렬
			if (qs->rate <= (qs + 1)->rate) {	
				//평판도 높은 게 앞으로
				if (qs->rate < (qs + 1)->rate) {
					smp = *qs;
					*qs = *(qs + 1);
					*(qs + 1) = smp;
				}
				else {
					//사전순 빠른 게 앞으로
					if (strcmp(qs->name, (qs + 1)->name) > 0) {
						smp = *qs;
						*qs = *(qs + 1);
						*(qs + 1) = smp;
					}
				}
			}
		
	for (qs = res; qs < res + M; qs++)
		printf("%s %d %.1f %.1f %c\n", qs->name, qs->grade, qs->rate, qs->dist, qs->food);
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