#pragma warning(disable:4996)
#include <stdio.h>

typedef struct point {
	double x, y;
}point;

point center(point, point);

int main(void) {

	point p, q, r;
	
	scanf("%lf %lf", &p.x, &p.y);
	scanf("%lf %lf", &q.x, &q.y);
	
	r = center(p, q);

	printf("%.2f %.2f", r.x, r.y);

	return 0;
}

point center(point a, point b) {

	point c;

	c.x = (a.x + b.x) / 2;
	c.y = (a.y + b.y) / 2;

	return c;
}
/*
1.0 1.0
2.0 2.0
*/