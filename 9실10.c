#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
void gcdlcm(int, int, int *, int *);

int main(void) {

	//변수 선언
	int a, b, *pg = &a, *pl = &b;

	//변수 값 입력
	scanf("%d%d", &a, &b);

	//함수 호출
	gcdlcm(a, b, pg, pl);

	//변수 값 출력
	printf("%d %d", *pg, *pl);

	return 0;
}

//함수 정의
void gcdlcm(int a, int b, int *x, int *y) {

	//변수 선언
	int gcd, lcm;

	//최대공약수 gcd 구하기
	for (int i = 1; i <= a && i <= b; i++)	//두 수 중 작은 수를 기준으로
		if (a % i == 0 && b % i == 0)	//i로 나누어떨어지는 최대 공약수 찾기
			gcd = i;

	//최소공배수 lcm 구하기
	lcm = a * b / gcd;

	//포인터로 간접 접근하여 변수 값 저장
	*x = gcd, *y = lcm;
}