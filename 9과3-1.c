#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	//변수 선언 및 초기화
	char ch, ar[100], *p = ar;
	int N = 0, len = 0, max = 0, fl = 0; //int형 변수 선언 및 초기화

	do {
		scanf("%c", &ch);	//문자를 입력받아
		*p = ch;			//포인터로 접근한 배열에 저장
		N++;				 //배열 크기 카운트
		p++;				 //포인터 이동
	} while (ch != '#');	//'#' 문자가 입력될 때까지 반복
	
	for (p = ar; p < ar + N; p++) {
		if (*p >= 'a' && *p <= 'z') { //입력된 문자가 소문자인 경우
			fl = 1; //소문자임을 표기

			printf("%c", *p);	//소문자 출력//
			len++;	//길이 계산
		}
		else {	//소문자가 아닌 문자인 경우
			if (fl == 1)	//바로 전에 소문자가 나타났던 경우에만
				printf("\n");		//줄바꿈 출력//
			fl = 0;	//소문자가 아닌 문자임을 표기

			if (max < len)  //여태 계산한 단어의 길이를 최대 길이와 비교하여
				max = len;	//최대 길이 갱신
			len = 0; //길이 계산 초기화
		}
	}

	//가장 긴 단어의 길이 출력
	printf("%d", max);

	return 0;
}
/*
banana25apple#
roll out electric334car334#
*/