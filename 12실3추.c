#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct reserve {
	int id; // 고객 id
	char grade[4]; // 구매한 티켓의 등급
	int price; // 구매한 티켓의 가격
};

void input(struct reserve*, int);
int cal_sum(struct reserve*, int, int);

int main(void) {

	int N, cus = 0, tot;
	struct reserve *p, *ps;
	
	scanf("%d", &N);

	p = (struct reserve*)malloc(N * sizeof(struct reserve));

	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	input(p, N);

	scanf("%d", &cus);

	for (ps = p; ps < p + N; ps++) {
		if (ps->id == cus)
			printf("%s %d\n", ps->grade, ps->price);
	}

	tot = cal_sum(p, N, cus);
	printf("%d", tot);

	free(p);

	return 0;
}


void input(struct reserve* p, int N) {

	struct reserve* ps;
	char g1[4] = "VIP", g2[2] = "R", g3[2] = "S", g4[2] = "A";

	for (ps = p; ps < p + N; ps++)	{
		scanf("%d %s", &ps->id, ps->grade);
		if (strcmp(ps->grade, g1) == 0)
			ps->price = 140000;
		else if (strcmp(ps->grade, g2) == 0)
			ps->price = 110000;
		else if (strcmp(ps->grade, g3) == 0)
			ps->price = 85000;
		else
			ps->price = 55000;
	}
}

int cal_sum(struct reserve *p, int N, int id) {

	struct reserve* q;
	int sum = 0;

	for (q = p; q < p + N; q++) 
		if (q->id == id) {
			sum += q->price;
		}

	return sum;
}

/*
10
123 A
210 VIP
123 A
123 R
210 S
210 VIP
123 A
523 A
123 R
523 VIP
123
*/