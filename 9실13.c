#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
int arrsum(int *, int *);

int main(void) {

	//변수 선언
	int N, ar[100], S, E, *p = ar;

	//변수 값 입력
	scanf("%d%d%d", &N, &S, &E);

	for (; p < ar + N; p++)	//배열을 포인터 사용하여 접근
		scanf("%d", p);

	//함수 호출 및 반환값 출력
	printf("%d", arrsum(ar + S, ar + E));

	return 0;
}

//함수 정의
int arrsum(int* a, int* b) {

	//변수 선언
	int sum = 0, *p = a;

	//해당 범위 내 배열 원소의 합 구하기
	for (; p <= b; p++)
		sum += *p;

	return sum;	//합 반환
}
