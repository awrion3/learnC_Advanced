#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//문자열 처리 표준 함수 포함

int main(void) {

	char str[101], mins[101], maxs[101], *p, *fw, *lw, *w;	//널 문자 포함
	int N, len, minlen = 101, maxlen = -1;	//이후 min,maxlen 비교에서 < 이므로, +1 -1 값으로 설정
	
	scanf("%d", &N);	//정수 입력
	getchar();			//엔터키 남김 제거

	for (int i = 0; i < N; i++) {	//N회 반복
		gets_s(str, 100);		//공백을 포함하는 문자열 입력
		len = strlen(str);		//문자열 길이 구하기

		if (len < minlen) {	
			minlen = len;		//최소 문자열 길이 갱신
			strcpy(mins, str);	//최소 길이 문자열 저장
		}
		
		if (len > maxlen) {	
			maxlen = len;		//최대 문자열 길이 갱신
			strcpy(maxs, str);	//최대 길이 문자열 저장
		}
	}

	//저장된 최소 및 최대 문자열에 대해//
	for (p = mins; p < mins + minlen; p++)	//널 문자 전까지 훑어
		if (*p == ' ')				//공백 문자 널 문자로 모두 대체
			*p = '\0';			

	for (p = maxs; p < maxs + maxlen; p++)	//널 문자 전까지 훑어
		if (*p == ' ')				//공백 문자 널 문자로 모두 대체
			*p = '\0';

	//최소 길이 문자열 내, 가장 빠른 단어 찾기
	w = mins, fw = mins;	//첫 단어와 가장 빠른 단어 모두 처음 단어로 초기화
	for (p = mins; p < mins + minlen; p++) {	//가장 마지막 널 문자는 훑기 제외
		if (*p == '\0') {	//널 문자 만나면
			w = p + 1;		//그 다음의 단어 첫 문자로 포인터 연결
		
			if (strcmp(w, fw) < 0)	//더 빠른 단어 만나면
				fw = w;		//가장 빠른 단어 포인터 갱신
		}
	}

	//최대 길이 문자열 내, 가장 늦은 단어 찾기
	w = maxs, lw = maxs; 	//첫 단어와 가장 늦은 단어 모두 처음 단어로 초기화
	for (p = maxs; p < maxs + maxlen; p++) {	//가장 마지막 널 문자는 훑기 제외
		if (*p == '\0') {	//널 문자 만나면
			w = p + 1;		//그 다음의 단어 첫 문자로 포인터 연결

			if (strcmp(w, lw) > 0)	//더 늦은 단어 만나면
				lw = w;		//가장 늦은 단어 포인터 갱신
		}
	}

	printf("%s\n", fw);	//가장 빠른 단어를 저장된 포인터 지점부터 널 문자 전까지 출력
	printf("%s\n", lw);	//가장 늦은 단어도 마찬가지로 출력

	return 0;
}
/*
2
why so happy
icecream makes everything better
*/