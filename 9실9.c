#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
int* mid(int[]);

int main(void) {

	//지역 변수 선언
	int ar[3], *p = ar, *r;

	//변수 값 입력
	for (; p < ar + 3; p++)
		scanf("%d", p);

	//함수 호출 및 반환값 연결
	r = mid(ar);

	//변수 값 출력
	printf("%d", *r);

	return 0;
}

//함수 정의
int* mid(int x[]) {	//포인터 사용에 있어 배열 형태의 인자 사용

	//지역 변수 선언 (포인터 연결)
	int* p = x, *m;

	if (*p <= *(p + 1) && *p >= *(p + 2))				//첫번째 원소가 중앙값인 경우
		m = p;
	else if (*p <= *(p + 2) && *p >= *(p + 1))			 //값의 크기 순에 따라 비교
		m = p;
	else if (*(p + 1) <= *p && *(p + 1) >= *(p + 2))	//두번째 원소가 중앙값인 경우
		m = p + 1;
	else if (*(p + 1) <= *(p + 2) && *(p + 1) >= *p)	 //값의 크기 순에 따라 비교
		m = p + 1;
	else if (*(p + 2) <= *p && *(p + 2) >= *(p + 1))	//세번째 원소가 중앙값인 경우
		m = p + 2;
	else if (*(p + 2) <= *(p + 1) && *(p + 2) >= *p)	 //값의 크기 순에 따라 비교
		m = p + 2;

	return m; //주소 반환
}