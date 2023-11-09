#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 관련 함수 포함
#include <stdlib.h>	//동적할당 관련 함수 포함

int main(void) {

	int len, N = 0, wlen, i;			//정수형 변수 선언
	char tmp[101], *t, **p, wmp[101];	//문자형 변수 선언

	gets_s(tmp, 100);	//공백을 포함하는 임시 문자열 입력
	len = strlen(tmp);	//임시 문자열 길이 구하기

	for (t = tmp; t < tmp + len; t++)	//임시 문자열 접근하여
		if (*t == ' '){		//공백 문자를 널 문자로 교체
			*t = '\0';
			N++;			//단어 개수 카운트
		}
	N++;	//단어 개수 정정

	p = (char**)malloc(N * sizeof(char*));	//포인터 배열 동적할당

	if (p == NULL) {					//동적할당 검사
		printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
		return -1;
	}

	strcpy(wmp, tmp);	//첫 임시 단어 저장
	wlen = strlen(wmp);	//첫 임시 단어의 길이 저장
	for (t = tmp, i = 0; t < tmp + len; t++) {	//임시 문자열 훑어
		if (*t == '\0') {			//널 문자 만날 때마다
			strcpy(wmp, t + 1);		//다음 단어 저장
			wlen = strlen(wmp);		//다음 단어 길이 저장
			i++;	//인덱스 증가
		}

		p[i] = (char*)malloc((wlen + 1) * sizeof(char));	//문자 배열 동적할당

		if (p[i] == NULL) {					//동적할당 검사
			printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
			return -1;
		}

		strcpy(p[i], wmp);	//각 단어 저장
	}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)		//2차원 배열 버블 정렬 
			if (strlen(p[j]) <= strlen(p[j + 1])) {	//단어 문자 배열 길이 확인하여
				if (strlen(p[j]) < strlen(p[j + 1])) {	//후자가 더 긴 경우
					t = p[j];
					p[j] = p[j + 1];	//두 문자 배열 포인터 교체
					p[j + 1] = t;
				}
				else {	//길이가 같은 경우
					if (strcmp(p[j], p[j + 1]) > 0) {	//후자가 사전 순 빠른 경우
						t = p[j];
						p[j] = p[j + 1];	//두 문자 배열 포인터 교체
						p[j + 1] = t;
					}
				}
			}
		
	for (int i = 0; i < N; i++)	//정렬된 결과 출력
		printf("%s\n", p[i]);

	for (int i = 0; i < N; i++)	
		free(p[i]);		//문자 배열 동적할당 각각 해제
	free(p);			//포인터 배열 해제

	return 0;
}
/*
red orange yellow green blue purple
*/