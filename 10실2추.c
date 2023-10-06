#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>			//문자열 처리 함수 포함

int main(void) {

	char str1[101], str2[101], *p, rstr[201];	//널 문자 포함
	char *mp, *np, mw[101], nw[101];
	int M, N, mlen, nlen, mnt = 0, nnt = 0;		//정수형 변수 선언 및 초기화
	
	scanf("%d%d", &M, &N);		//M과 N 입력
	getchar();					//엔터키 남김 제거

	gets_s(str1, 100);			//공백을 포함하는 두 문자열 입력
	gets_s(str2, 100);

	mlen = strlen(str1);		//각 문자열의 길이 구하기
	nlen = strlen(str2);

	mp = str1;					//0번째의 첫 단어로 연결
	for (p = str1; p < str1 + mlen; p++) {
		if (*p == ' ') {		//공백 널 문자로 대체
			*p = '\0';
			
			mnt++;				//단어 개수 카운터//
			if (mnt == M) {		//단어 개수가 M번째이면
				mp = p + 1;		//공백 다음의 단어 첫 문자로 포인터 연결
			}
		}
	}

	np = str2;					//0번째의 첫 단어로 연결
	for (p = str2; p < str2 + nlen; p++) {
		if (*p == ' ') {		//공백 널 문자로 대체
			*p = '\0';

			nnt++;				//단어 개수 카운터//
			if (nnt == N) {		//단어 개수가 N번째이면
				np = p + 1;		//공백 다음의 단어 첫 문자로 포인터 연결
			}
		}
	}
	
	strcpy(mw, mp);	//포인터 지점부터 널 문자까지 복사
	strcpy(nw, np);	

	if (strcmp(mw, nw) < 0) {	//두 단어 중 사전 상 빠른 단어를
		strcpy(rstr, mw);		//먼저 복사하고
		strcat(rstr, nw);		//나머지 단어를 널 문자 지점부터 접합한다
	}
	else {						//반대의 경우도 마찬가지
		strcpy(rstr, nw);
		strcat(rstr, mw);
	}

	printf("%s", rstr);			//만들어진 하나의 단어를 한번에 출력

	return 0;
}
/*
2 4
book desk pencil paper
orange apple banana lemon grape
*/