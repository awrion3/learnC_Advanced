#pragma warning(disable:4996)
#include <stdio.h>

struct parking_info {
	int num, tel, day, min;
	char opt, mem;
	double fee;
};

void input(struct parking_info*, int);
void compute(struct parking_info*);
void display(struct parking_info*, int);

int main(void) {

	struct parking_info ar[100], *p;
	int N;

	scanf("%d", &N);
	
	input(ar, N);

	for (p = ar; p < ar + N; p++)
		compute(p);

	display(ar, N);

	return 0;
}

void input(struct parking_info *p, int N) {

	struct parking_info *r;

	for (r = p; r < p + N; r++) {
		scanf("%d %d %c", &r->num, &r->tel, &r->opt);
		if (r->opt == 'S') {
			getchar();	//%c가 뒤에 오므로
			scanf("%c %d", &r->mem, &r->day);
		}
		scanf("%d", &r->min);
	}
}

void compute(struct parking_info *p) {

	p->fee = 0;						//요금 초기화

	if (p->opt == 'S') {
		if (p->mem == 'N') {		//정기권 아직 안 가입된 경우에 추가 가입요금 부과
			if (p->day == 7)
				p->fee += 30000;
			else if (p->day == 30)
				p->fee += 100000;
			else
				p->fee += 500000;
		}
	}
	else {							//일일권은 기본 요금 부과
		p->fee += 5000;
	}

	if (p->min > 240) {			//추가 요금은 정기권/일일권 상관없이 부과
		p->fee += (int)((p->min - 240) / 10) * 200;
	}
}

void display(struct parking_info *p, int N) {

	struct parking_info *r;
	
	for (r = p; r < p + N; r++) {	//소수점 이하 출력 안함
		printf("%d %d %c %.0f\n", r->num, r->tel, r->opt, r->fee);
	}
}
/*
4
1111 12345678 S N 7 230
2222 22223333 D 240
3333 44445555 D 255
4444 66667777 S Y 30 200

6
3777 28171652 S Y 30 348
1989 97027706 D 429
7757 25158262 S Y 30 392
2714 15392245 D 560
8506 12389677 D 47
5113 59262609 S N 30 967
*/