#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

typedef struct student {
	char name1[21], name2[21];
	int score, flag;
} student;

int main(void) {

	student st[10], *p;
	int N, cnt = 0, fl = 0, sc;
	char key[21], n1[21], n2[21];
	double avg = 0, gap, min;

	scanf("%d", &N);

	for (p = st; p < st + N; p++)
		scanf("%s %s %d", p->name1, p->name2, &p->score);

	scanf("%s", key);

	for (p = st; p < st + N; p++)
		if (strcmp(p->name1, key) == 0 || strcmp(p->name2, key) == 0) {
			p->flag = 1;
			avg += p->score;
			cnt++;
		}
		else
			p->flag = 0;

	avg = (double)avg / cnt;

	printf("average = %.2f\n", avg);

	for (p = st; p < st + N; p++) {
		gap = (double)p->score - avg > 0 ? (double)p->score - avg : -((double)p->score - avg);
		
		if (fl == 0) {
			min = gap;
			strcpy(n1, p->name1);
			strcpy(n2, p->name2);
			sc = p->score;
			fl = 1;
		}
		else {
			if (min > gap) {
				min = gap;
				strcpy(n1, p->name1);
				strcpy(n2, p->name2);
				sc = p->score;
			}
		}
	}

	printf("%s %s %d", n1, n2, sc);

	return 0;
}
/*
6
gildong hong 70
gildong kim 82
kim jack 65
gill kim 93
elvis kim 94
park lena 89
kim
*/