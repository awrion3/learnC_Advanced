#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
void strcopy(char [], char []);

int main(void) {

	//변수 선언
	char a[6], b[6], *p = a, *q = b;

	//변수 값 입력(배열 a[6])
	for (; p < a + 6; p++)
		scanf("%c", p);

	//함수 호출
	strcopy(a, b); //(배열 이름은 0번 원소의) 주소 실인자 전달

	//변수 값 출력(배열 b[6])
	for (; q < b + 6; q++)
		printf("%c", *q);

	return 0;
}

//함수 정의
void strcopy(char a[], char b[]) {	//배열 형태의 형식 인자 사용

	//변수 선언
	char *p = a, *q = b;

	//변수 값 입력
	for (; p < a + 6; p++, q++)
		*q = *p; //포인터를 활용하여 배열 간의 문자 복사
}