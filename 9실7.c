#pragma warning(disable:4996)
#include <stdio.h>

//함수 원형 선언
void input(int *, int *, int *);
void output(int *, int *, int *);

int main(void) {

	//변수 선언
	int x, y, z;

	//함수 호출
	input(&x, &y, &z);
	output(&x, &y, &z);

	return 0;
}

//함수 정의
void input(int* a, int* b, int* c) {

	scanf("%d%d%d", a, b, c);	//입력(포인터 사용)
}

void output(int* a, int* b, int* c) {

	printf("%d %d %d", *a, *b, *c);	//출력(포인터 사용)
}