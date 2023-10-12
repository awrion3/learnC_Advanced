#pragma warning(disable:4996)
#include <stdio.h>

//구조체 정의
struct date {
	int year, month, day;
};

//함수 선언
struct date* select_min(struct date*, struct date*);

int main(void) {

	//구조체 선언 및 포인터 선언
	struct date dt1, dt2, *pd;

	scanf("%d/%d/%d", &dt1.year, &dt1.month, &dt1.day);
	scanf("%d/%d/%d", &dt2.year, &dt2.month, &dt2.day);

	//함수 호출(구조체 주소 넘기고 반환 받기)
	pd = select_min(&dt1, &dt2);

	//구조체 포인터 활용하여 출력
	printf("%d/%d/%d", pd->year, pd->month, pd->day);

	return 0;
}

//함수 정의
struct date* select_min(struct date *p1, struct date *p2) {

	//간접 참조한 구조체 멤버값 간 비교하여 특정 구조체 주소값으로 반환
	if (p1->year < p2->year) {
		return p1;
	}
	else if (p1->year > p2->year) {
		return p2;
	}
	else {
		if (p1->month < p2->month) {
			return p1;
		}
		else if (p1->month > p2->month) {
			return p2;
		}
		else {
			if (p1->day < p2->day) {
				return p1;
			}
			else
				return p2;
		}
	}
}
/*
2016/10/9
2016/8/6

2014/10/9
2016/8/6
*/