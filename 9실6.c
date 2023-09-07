#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	
	//변수 선언 및 초기화
	char ch[10], *p = ch, *q, mch;
	int fr[10], *f = fr, max = 1;

	//변수 값 입력
	for (; p < ch + 10; p++) 
		scanf("%c", p);

	//변수 값 연산
	for (p = ch; p < ch + 10; p++) {
		*f = 0;	//빈도수 초기화
		for (q = ch; q < ch + 10; q++)
			if (*p == *q)	//중복되면	
				++*f;		//빈도수 값 증가
		f++;	//빈도수 배열 원소의 인덱스 증가(포인터 활용)//
	}

	p = ch;	mch = *p;	//가장 빈도수가 높은 문자를 첫 문자로 초기화//
	for (f = fr; f < fr + 10; p++, f++)	//포인터 활용하여 빈도수 배열 원소 내 비교를 통해
		if (max < *f) {
			max = *f;	//가장 높은 빈도수 및
			mch = *p;	//가장 빈도수가 높은 문자 갱신
		}

	//변수 값 출력
	printf("%c %d", mch, max);

	return 0;
}