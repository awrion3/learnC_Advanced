#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

typedef struct rest {
	char name[100];
	int breakfast, lunch, dinner;
} rest;

int main(void) {

	rest st[10], *p, *q, *r;
	int N, W, cost, max, fl = 0;
	char br[100], lu[100], di[100];

	scanf("%d", &N);

	for (p = st; p < st + N; p++)
		scanf("%s %d %d %d", p->name, &p->breakfast, &p->lunch, &p->dinner);
	
	scanf("%d", &W);

	for (p = st; p < st + N; p++)
		for (q = st; q < st + N; q++)
			for (r = st; r < st + N; r++) {
				if (strcmp(p->name, q->name) 
					&& strcmp(q->name, r->name)
					&& strcmp(p->name, r->name)) {
					
					cost = p->breakfast + q->lunch + r->dinner;
					
					if (cost <= 6000) {
						if (fl == 0) {
							max = cost;
							fl = 1;
						}
						
						if (max < cost) {
							max = cost;
							strcpy(br, p->name);
							strcpy(lu, q->name);
							strcpy(di, r->name);
						}
					}
				}
			}

	printf("%s\n%s\n%s\n", br, lu, di);
	printf("%d", W);

	return 0;
}
/*
4
korean 1500 1200 1500
japanese 1000 1500 1500
chinese 1000 1200 2500
italy 1000 1200 3500
6000
*/