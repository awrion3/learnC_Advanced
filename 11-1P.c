#pragma warning(disable:4996)
#include <stdio.h>

typedef struct record {
	int month;
	int day;
	int sale[20];
} record;

int main(void) {

	record st[10];
	int N, num, tmp[20], *p, rm, rd, rn, cnt = 0;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &num);
		st[i].month = num / 100;
		st[i].day = num % 100;

		for (int j = 0; j < 20; j++) {
			scanf("%d", &num);
			st[i].sale[j] = num;
			
			if (num == 0)
				break;
		}
	}

	scanf("%d %d %d", &rm, &rd, &rn);

	for (int i = 0; i < N; i++) {
		if (rm == st[i].month && rd == st[i].day) {
			for (int j = 0; st[i].sale[j] != 0; j++) {
				if (st[i].sale[j] == rn)
					cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}
/*
3
0901 2 3 2 1 4 0
0902 12 5 4 12 12 1 0
0903 2 3 5 6 0
9 2 12
*/