#pragma warning(disable:4996)
#include <stdio.h>

//구조체 정의
struct result {
	int high, low, limit, gap;
	char porf;
};

//함수 선언
void passorfail(struct result *);

int main(void) {

	//구조체 선언
	struct result st;

	scanf("%d %d %d", &st.high, &st.low, &st.limit);

	//함수 호출(주소 연결)
	passorfail(&st);

	printf("%d %c", st.gap, st.porf);

	return 0;
}

//함수 정의
void passorfail(struct result *p) {

	//간접 접근하여 멤버값 저장
	p->gap = p->high - p->low;

	if (p->gap <= p->limit)
		p->porf = 'P';
	else
		p->porf = 'F';
}
/*
100 95 10
*/