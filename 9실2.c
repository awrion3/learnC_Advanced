#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//변수 선언(배열 및 포인터 포함)
	char ch[20], ca, *pch = ch;
	int idx = 0;

	//변수 값 입력(포인터 주소 비교하며 배열 접근)
	for (; pch < ch + 20; pch++) {
		scanf("%c", &ca);
		if (ca == '\n')	//엔터키 입력시 반복 종료
			break;	
		else 
			*pch = ca; //포인터로 배열 원소 접근하여 값 저장
	}

	//변수 값 연산
	for (pch = ch; pch < ch + 20; pch++, idx++) {
		if (*pch == '#') //첫번째 문자 #의 위치 확인
			break;
	}

	//변수 값 출력
	for (pch = ch + idx - 1; pch >= ch; pch--)
		printf("%c", *pch); //첫번째 # 전의 문자부터 역순으로 출력

	return 0;
}