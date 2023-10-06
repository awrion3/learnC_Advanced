#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 표준 함수 포함

int main(void) {

	char A[101], B[11], C[11], *p;	//널 문자 포함
	char R[250] = { "" }, *r = R;	//새 배열 관련 변수 선언
	int blen, clen;				//정수형 변수 선언

	gets_s(A, 100);	//공백 포함 문자열 A 입력

	scanf("%s", B);	//공백 미포함 문자열 B 입력 
	scanf("%s", C);	//공백 미포함 문자열 C 입력 
	
	blen = strlen(B);	//문자열 B 길이 구하기
	clen = strlen(C);	//문자열 C 길이 구하기

	for (p = A; *p; p++) {	//널 문자 전까지 문자열 A 훑으며 
		//해당 지점부터 B 길이만큼 비교하였을 때 
		if (strncmp(p, B, blen) == 0) {	//문자열 B가 문자열 A에 포함된 경우
			strcat(R, C);	//문자열 C로 치환해 R에 저장

			p += (blen - 1);	//인덱스 B 길이 -1만큼 이동
			r += clen;			//인덱스 C 길이만큼 이동
		}
		else {				//포함되지 않은 경우
			*r = *p;		//기존 문자열 A를 R에 저장
			r++;				//인덱스 한칸씩 이동	
		}
	}

	//치환이 완료된 하나의 문자열 출력
	printf("%s", R);

	return 0;
}
/*
I have a pen. I have an applepen. PPAP.
pen
mouse

Sequence GTCGTCG
GTCG
CAGC
*/