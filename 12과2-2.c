#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 관련 함수 포함
#include <stdlib.h>	//동적할당 관련 함수 포함

int main(void) {

	int len, blen, N = 0, M = 0, wlen, i = 0, k = 0, idx;	//정수형 변수 선언
	char tmp[101], *t, **p, wmp[101];						//문자형 변수 선언
	char bmp[101], **q, res[100][101] = { 0 };

	gets_s(tmp, 100);	//공백을 포함하는 임시 문자열A 입력
	gets_s(bmp, 100);	//공백을 포함하는 임시 문자열B 입력

	len = strlen(tmp);	//임시 문자열A 길이 구하기
	for (t = tmp; t < tmp + len; t++)	//임시 문자열A 접근하여
		if (*t == ' ') {		//공백 문자를 널 문자로 교체
			*t = '\0';
			N++;			//단어 개수 카운트
		}
	N++;	//단어 개수 정정

	blen = strlen(bmp);	//임시 문자열B 길이 구하기
	for (t = bmp; t < bmp + blen; t++)	//임시 문자열B 접근하여
		if (*t == ' ') {		//공백 문자를 널 문자로 교체
			*t = '\0';
			M++;			//단어 개수 카운트
		}
	M++;	//단어 개수 정정

	//임시 문자열 A에 대하여
	p = (char**)malloc(N * sizeof(char*));	//포인터 배열 동적할당

	if (p == NULL) {					//동적할당 검사
		printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
		return -1;
	}

	strcpy(wmp, tmp);	//첫 임시 단어 저장
	wlen = strlen(wmp);	//첫 임시 단어의 길이 저장

	for (t = tmp; t < tmp + len; t++) {	//임시 문자열 훑어
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

	//임시 문자열 B에 대하여
	q = (char**)malloc(M * sizeof(char*));	//포인터 배열 동적할당

	if (q == NULL) {					//동적할당 검사
		printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
		return -1;
	}

	strcpy(wmp, bmp);	//첫 임시 단어 저장
	wlen = strlen(wmp);	//첫 임시 단어의 길이 저장
	i = 0;				//인덱스 초기화

	for (t = bmp; t < bmp + blen; t++) {	//임시 문자열 훑어
		if (*t == '\0') {			//널 문자 만날 때마다
			strcpy(wmp, t + 1);		//다음 단어 저장
			wlen = strlen(wmp);		//다음 단어 길이 저장
			i++;	//인덱스 증가
		}
		q[i] = (char*)malloc((wlen + 1) * sizeof(char));	//문자 배열 동적할당

		if (q[i] == NULL) {					//동적할당 검사
			printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
			return -1;
		}

		strcpy(q[i], wmp);	//각 단어 저장
	}

	for (int i = 0; i < N; i++)			//동적할당된 두 문자열에 대해 비교하며
		for (int j = 0; j < M; j++)	
			if (strcmp(p[i], q[j]) == 0) 	//공통으로 나타나는 단어 등장 시
				strcpy(res[k++], p[i]);		//해당 단어 res 배열에 저장

	idx = k;	//인덱스 저장
	for (int i = 0; i < idx - 1; i++)		//공통 단어 배열 버블 정렬하기
		for (int j = 0; j < idx - 1; j++)
			if (strlen(res[j]) <= strlen(res[j + 1])) {		//길이 기준으로
				if (strlen(res[j]) < strlen(res[j + 1])) {	//후자가 긴 경우 내림차순 정렬
					strcpy(tmp, res[j]);
					strcpy(res[j], res[j + 1]);			//단어 문자 배열 간 교환
					strcpy(res[j + 1], tmp);
				}
				else {										//길이가 같은 경우
					if (strcmp(res[j], res[j + 1]) > 0) {	//후자가 사전 순 빠른 경우 정렬
						strcpy(tmp, res[j]);
						strcpy(res[j], res[j + 1]);		//단어 문자 배열 간 교환
						strcpy(res[j + 1], tmp);
					}
				}
			}

	for (int i = 0; i < idx; i++)	//정렬된 결과 출력
		printf("%s\n", res[i]);

	for (int i = 0; i < N; i++) //문자열 A에 대하여
		free(p[i]);		//문자 배열 동적할당 각각 해제
	free(p);			//포인터 배열 해제

	for (int i = 0; i < M; i++)	//문자열 B에 대하여
		free(q[i]);		//문자 배열 동적할당 각각 해제
	free(q);			//포인터 배열 해제

	return 0;
}
/*
red orange yellow green blue purple
pink red yellow black white purple

red
red

getchar()는 
gets()나 scanf("%c")앞에 쓰이나,
gets()가 그 앞에 온 경우 쓰일 필요X
*/