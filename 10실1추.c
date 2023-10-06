#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//문자열 처리 표준 함수 포함

int main(void) {

	char str[101], *p, *w = str, *fw = str;	//널 문자 포함
	int len;								//정수형 변수 선언

	gets_s(str, 100);		//공백 포함 입력
	len = strlen(str);		//문자열 길이 구하기

	for (p = str; p <= str + len; p++) {	//공백 문자에서 널 문자로 교체
		if (*p == ' ') 			
			*p = '\0';
	}

	for (p = str; p < str + len; p++) {		//마지막 널 문자를 제외하고 훑어
		if (*p == '\0') {			//사이사이 널 문자 만날 때마다
			w = p + 1;				//단어 포인터 널 문자 다음으로 새로 연결

			if (strcmp(w, fw) < 0)	//새 단어가 가장 빠른 단어보다 더 빠른 경우
				fw = w;				//가장 빠른 단어로 갱신
		}
	}

	printf("%s", fw);	//사전상 가장 빠른 단어 출력

	return 0;
}
/*
why so happy
icecream makes everything better

주의:
만약 \0을 공백 대신 추가 안했다면 이후 비교하는 과정에서
포인터가 가리키는 지점부터 널 문자 만날 때까지 쭉 포함하게 됨 
*/