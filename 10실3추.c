#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>			//문자열 처리 표준 함수 포함

int main(void) {

	char str[201], wlist[20][200], *p, tmp[200];	//널 문자 포함
	int len, i = 0, j = 0, idx;

	gets_s(str, 200);	//공백을 포함하는 문자열 입력

	len = strlen(str);	//문자열 길이 구하기

	for (p = str; p <= str + len; p++) { //널 문자까지 훑어
		if (*p == ' ' || *p == '\0') {		//공백이나 널 문자 만나면
			wlist[i][j] = '\0';				//해당 배열의 마지막에 널 문자 삽입
			wlist[i++];					//다음 배열로 인덱스 증가//
			j = 0;						//각 배열별 인덱스 초기화//
		}
		else {
			wlist[i][j++] = *p;			//값 하나하나 카피
		}
	}

	idx = i;	//총 배열 개수 인덱스 저장// 
	for (int i = 0; i < idx; i++)	//각 배열 접근하여 출력
		printf("%s\n", wlist[i]);

	for (int k = 0; k < idx - 1; k++) {		//버블 정렬 방식으로 idx - 1 회 반복
		for (int i = 0; i < idx - 1; i++)				//아래 인덱스에 유의
			if (strcmp(wlist[i], wlist[i + 1]) > 0) {	//더 빠른 단어를 보관한 배열을 
				strcpy(tmp, wlist[i]);					 
				strcpy(wlist[i], wlist[i + 1]);		 	//앞 배열로 복사하며 교환하기
				strcpy(wlist[i + 1], tmp);				 
			}
	}

	for (int i = 0; i < idx; i++)	//각 배열 접근하여 출력
		printf("%s ", wlist[i]);

	return 0;
}

/*
simple is best
i am a boy
*/