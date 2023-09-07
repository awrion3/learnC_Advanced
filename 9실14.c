#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
int add_to_k(int *, int *);

int main(void) {

	//변수 선언	
	int N, d[100], *p = d, res = 0;
	
	//변수 값 입력
	scanf("%d", &N);

	for (; p < d + N; p++)	//포인터 활용해 배열 원소 값 입력
		scanf("%d", p);

	//함수 호출
	p = d;	//포인터 주소 연결 초기화//
	for (; p < d + N; p++)
		res += add_to_k(d, p);	//해당 주소 범위 내 합 누적하기

	//변수 값 출력
	printf("%d\n", res);

	return 0;
}

//함수 정의
int add_to_k(int* a, int* b) {

	//변수 선언
	int sum = 0, *p = a;

	for (; p <= b; p++)	//포인터 활용해 배열 구간 내 합 구하기
		sum += *p;

	//합 반환
	return sum;
}
