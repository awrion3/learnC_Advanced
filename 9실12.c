#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
void addArray(int *, int *, int *, int);

int main(void) {

	//변수 선언
	int N, ar[20] = { 0 }, br[20] = { 0 }, cr[20] = { 0 };
	int *p = ar, *q = br, *r = cr;

	//변수 값 입력
	scanf("%d", &N);

	for (; p < ar + N; p++)	//첫번째 배열 값 저장
		scanf("%d", p);

	for (; q < br + N; q++)	//두번째 배열 값 저장
		scanf("%d", q);

	//함수 호출
	addArray(ar, br, cr, N);
	
	//변수 값 출력
	for (; r < cr + N; r++)
		printf(" %d", *r);

	return 0;
}

//함수 정의
void addArray(int* a, int* b, int* c, int s) {

	//변수 선언
	int *p = a, *q = b + s - 1, *r = c;

	for (; r < c + s; p++, q--, r++) //포인터 (주소 비교) 사용해 배열에 값 저장
		*r = *p + *q;
}