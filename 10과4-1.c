#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//문자열 처리 표준 함수 포함

//함수 선언
int check_u(char*, char*);

int main(void) {

	char str[101], mstr[101];			//널 문자 포함
	int N, max = 0, len, cnt, fl = 0;	//정수형 변수 선언 및 초기화

	scanf("%d", &N);	//문자열 줄 수 입력
	getchar();			//엔터키 남김 제거

	for (int i = 0; i < N; i++) { //N개의 문자열 입력
		gets_s(str, 100);		  //공백을 포함하여 문자열 입력

		if (fl == 0) {			  //첫 문자열 입력인 경우
			strcpy(mstr, str);	  //알파벳과 공백 제외 문자가 최대인 문자열로 저장  
			fl = 1;
		}

		len = strlen(str);					//문자열 길이 저장
		cnt = check_u(str, str + len - 1);	//함수 호출하여 개수 반환

		if (max < cnt) {		//알파벳과 공백 제외 문자가 최대인 경우
			max = cnt;			//해당 개수로 갱신
			strcpy(mstr, str);	//해당 문자열로 갱신
		}
	}
	
	printf("%s", mstr);		//알파벳과 공백 제외 문자 최대 개수의 문자열 출력

	return 0;
}

//함수 정의
int check_u(char *p, char *q) {

	char *t;		//포인터 선언
	int cnt = 0;	

	for (t = p; t <= q; t++) {	//문자열의 처음부터 마지막 문자까지 훑어
		if (!(*t >= 'A' && *t <= 'Z') && 
			!(*t >= 'a' && *t <= 'z') &&	//영어 알파벳과
			!(*t == ' '))					//공백이 아닌 문자인 경우
			cnt++;	//개수 카운트
	}	

	return cnt;		//개수 반환
}
/*
5
1 year is 365 days.
How are you doing?
**Notice**
Winter is coming.
1 + 1 = 2

getchar();사용해야 함

만약 모든 문장이 0개더라도,
fl = 0에서 일단 첫번째 문장으로 초기화됨
*/