#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
void swap(int*, int*);

int main(void) {

	//변수 선언
	int N, id1, id2, ar[50], *p = ar;

	//변수 값 입력
	scanf("%d", &N);

	for (; p < ar + N; p++)	//포인터 주소 비교 사용하여 배열 원소 접근
		scanf("%d", p);

	scanf("%d%d", &id1, &id2);

	//함수 호출
	p = ar;	//포인터 주소 연결 초기화//
	swap(p + id1, p + id2);

	//변수 값 출력
	for (; p < ar + N; p++)
		printf(" %d", *p);

	return 0;
}

//함수 정의
void swap(int* a, int* b) {

	int tmp;	//지역 변수 선언

	tmp = *a;	//tmp를 활용하여 값 교환
	*a = *b;
	*b = tmp;	//포인터 참조 연산자 사용하여 간접 접근
}