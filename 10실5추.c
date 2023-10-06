#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//문자열 처리 함수 포함

int main(void) {

	char str[101], mins[101], maxs[101], *p;	//널 문자 포함
	char maxw[101] = { "" }, minw[101] = { "" }, neww[201];			//합한 최대 길이에 유의
	int N, len, minlen = 101, maxlen = -1, M1, M2, mx = 0, mn = 0;	//정수형 변수 선언 및 초기환

	scanf("%d%d%d", &N, &M1, &M2);	//N줄, M1 및 M2번째 입력
	getchar();						//엔터키 남김 제거

	for (int i = 0; i < N; i++) {	//N줄의 문자열 입력받기
		gets_s(str, 100);		//공백을 포함하여 문자열 입력
		len = strlen(str);		//문자열 길이 재기

		if (len < minlen) {		//등호를 포함하지 않아, 길이 같을 시 먼저 입력된 문자열만 반영//
			minlen = len;		//가장 짧은 문자열 길이 갱신
			strcpy(mins, str);	//가장 짧은 문자열 갱신
		}

		if (len > maxlen) {		
			maxlen = len;		//가장 긴 문자열 길이 갱신
			strcpy(maxs, str);	//가장 긴 문자열 갱신
		}
	}
	
	printf("%s\n", maxs);	//가장 긴 문자열 출력
	printf("%s\n", mins);	//가장 짧은 문자열 출력

	for (p = maxs; p < maxs + maxlen; p++) {	//가장 긴 문자열의 
		if (*p == ' ')	//공백 문자를 널 문자로 대체
			*p = '\0';
	}

	for (p = mins; p < mins + minlen; p++) {	//가장 짧은 문자열의
		if (*p == ' ')	//공백 문자를 널 문자로 대체
			*p = '\0';
	}

	strcpy(maxw, maxs);	//첫 단어를 M1번째 단어라 가정하여 저장
	for (p = maxs; p < maxs + maxlen; p++) {
		if (*p == '\0') {	//널 문자 만나면
			mx++;				//카운터 증가
			if (mx == M1)	//카운터가 M1번째면
				strcpy(maxw, p + 1);	//널 문자 다음의 단어 첫 문자 지점부터 널 문자까지 복사
		}
	}

	strcpy(minw, mins);	//첫 단어를 M2번째 단어라 가정하여 저장
	for (p = mins; p < mins + minlen; p++) {
		if (*p == '\0') {	//널 문자 만나면
			mn++;				//카운터 증가
			if (mn == M2)	//카운터가 M2번째면
				strcpy(minw, p + 1);	//널 문자 다음의 단어 첫 문자 지점부터 널 문자까지 복사
		}
	}

	if (strcmp(maxw, minw) < 0) {	//M1번째 단어가 더 빠른 경우
		strcpy(neww, maxw);		//빠른 단어 먼저 복사
		strcat(neww, minw);		//늦은 단어 접합
	}
	else {							//M2번째 단어가 더 빠른 경우
		strcpy(neww, minw);		//빠른 단어 먼저 복사
		strcat(neww, maxw);		//늦은 단어 접합
	}

	printf("%s", neww);		//만들어진 하나의 단어를 출력

	return 0;
}
/*
5 4 2
book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
candy cake icecream
july august september october november december

만약 같은 길이의 문장들만 존재하는 경우,
첫 번째 문장이 가장 긴 및 가장 짧은 문자열로 동시에 지정되어
해당 문장 내 두 단어를 조합해 결과가 나옴.

반례)
5 0 2
book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
candy cake icecream
july august september october november december

예상 결과:
july august september october november december
candy cake icecream
icecreamjuly

잘못 결과: 
icecream만 나옴
즉 0번 단어 반영을 안함
-> 41, 50 추가
*/