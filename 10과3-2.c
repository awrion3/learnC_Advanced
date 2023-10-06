#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 표준 함수 포함

int main(void) {

	char A[101], B[101], rA[251] = { "" }, sp[2] = { " " };	//널 문자 포함
	char wA[101], mA[101], wB[101], *w, * m;
	int alen, blen, wlen, mlen, fl = 0;		  //정수형 변수 선언 및 초기화

	gets(A);	//공백을 포함하는 문자열 입력
	gets(B);

	alen = strlen(A);	//문자열 A 길이 계산

	strcpy(wA, A);		//문자열 A복사하여 wA생성
	for (w = wA; w <= wA + alen; w++) {
		if (*w == ' ')	//공백 대신 널 문자 추가
			*w = '\0';
	}

	strcpy(mA, A);	    //문자열 A복사하여 mA생성
	for (m = mA; m <= mA + alen; m++) {
		if (*m == ' ')	//공백 대신 널 문자 추가
			*m = '\0';
	}

	for (w = wA; w <= wA + alen; w++) {		//널 문자 다음의 단어 첫 문자로 포인터 이동

		fl = 0;				//해당 단어 처음 등장 여부 플래그 초기화
		wlen = strlen(w);	//해당 단어 길이 계산

		for (m = mA; m <= mA + alen; m++) {	//널 문자 다음의 단어 첫 문자로 포인터 이동

			mlen = strlen(m);			//문자열 내의 단어 길이 계산

			if (strcmp(m, w) == 0) {	//문자열 내의 단어와 해당 단어가 같은지 널 문자까지 비교
				if (fl == 1) {	//해당 단어가 문자열 내 중복으로 등장하는 경우부터 
					*m = '*';	//mA에 표기
				}
				fl = 1;			//해당 단어 중복 등장을 표기
			}
			m += mlen;	//널 문자로 포인터 이동
		}
		w += wlen;		//널 문자로 포인터 이동
	}

	blen = strlen(B);	//문자열 B 길이 계산

	strcpy(wB, B);		//문자열 B복사하여 wB생성
	for (w = wB; w <= wB + blen; w++) {
		if (*w == ' ')  //공백 대신 널 문자 추가
			*w = '\0';
	}

	w = wB;				//문자열 wB에 연결 초기화
	for (m = mA; m <= mA + alen; ) {	//중복되는 단어 표기한 문자열 참조하여
		wlen = strlen(w);	//해당 단어 길이 계산
		mlen = strlen(m);	//문자열 내의 단어 길이 계산

		if (*m == '*') {	//중복되는 단어는
			strcat(rA, w);	//문자열 B의 단어로 치환해 접합
			strcat(rA, sp);	//공백 추가

			w += wlen;	//널 문자로 포인터 이동
			w++;		//널 문자 다음의 단어 첫 문자로 포인터 이동
		}
		else {				//중복되지 않는 단어는
			strcat(rA, m);	//문자열 A의 단어로 접합
			strcat(rA, sp);	//공백 추가
		}

		m += mlen;		//널 문자로 포인터 이동 (위의 접합 여부에 관계없이 다음 단어로 이동함에 유의)
		m++;			//널 문자 다음의 단어 첫 문자로 포인터 이동
	}

	printf("%s", rA);	//최종 문자열 출력

	return 0;
}
/*
red orange red yellow green red blue purple yellow
white black gray pink brown blush crimson garnet vermilion indigo

팁)
strcat( ,sp);로 무엇이 되었든 마지막에 공백은 하나씩 추가된다
오류는 없었으나 혹시나 출력이 다를 경우 이러한 차이에 유의

n이 들어간 문자열 처리 함수를 제외하면
다들 널 문자까지를 기준으로 처리함에 유의
*/