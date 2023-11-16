#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int x, y;
}point;

int main(void) {

	point *p, q, r;
	int N, xap, yap, max = -1;

	scanf("%d", &N);

	p = (point *)malloc(N * sizeof(point));
	
	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++) 
		scanf("%d %d", &p[i].x, &p[i].y);

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (i != j) {
				xap = p[i].x - p[j].x;
				xap= xap * xap;
				
				yap = p[i].y - p[j].y;
				yap = yap * yap;

				if (max < xap + yap) {
					max = xap + yap;
					q = p[i];
					r = p[j];
				}
			}
			
	printf("%d %d\n", q.x, q.y);
	printf("%d %d\n", r.x, r.y);

	free(p);

	return 0;
}
/*
4
1 1
2 2
4 4
3 3
*/