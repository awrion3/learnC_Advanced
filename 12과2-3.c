#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 관련 함수 포함
#include <stdlib.h>	//동적할당 관련 함수 포함

int main(void) {

	int len, blen, N = 0, M = 0, wlen, i, k = 0;		//정수형 변수 선언
	int d = 0, fl = 0, dl = 0;
	char tmp[101], *t, **p, wmp[101];					//문자형 변수 선언
	char bmp[101], **q, res[200][201] = { 0 }, cmp[101], hit[100][101] = { 0 };

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

	//임시 문자열 B에 대하여
	q = (char**)malloc(M * sizeof(char*));	//포인터 배열 동적할당

	if (q == NULL) {					//동적할당 검사
		printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
		return -1;
	}

	strcpy(wmp, bmp);	//첫 임시 단어 저장
	wlen = strlen(wmp);	//첫 임시 단어의 길이 저장

	for (t = bmp, i = 0; t < bmp + blen; t++) {	//임시 문자열 훑어
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

	//동적할당한 같은 문자열 A끼리 비교하여
	for (i = 0; i < N; i++)			
		for (int j = 0; j < N; j++)		
			if (strcmp(p[i], p[j])) {	//문자열 내 다른 두 개의 단어인 경우
				strcpy(cmp, p[i]);	//두 단어를 합성하기
				strcat(cmp, p[j]);
				strcpy(res[k++], cmp);	//합성한 단어 배열 res에 저장

				strcpy(cmp, p[j]);	//역순으로 두 단어를 합성하기
				strcat(cmp, p[i]);
				strcpy(res[k++], cmp);	//역순으로 합성한 단어 배열 res에 저장
			}
	
	for (int j = 0; j < M; j++)	{			//문자열 B에 대해서
		fl = 0;
		for (i = 0; i < k; i++) 			//문자열 A로 합성한 단어가
			if (strcmp(res[i], q[j]) == 0) 	//문자열 B에 있는 경우 표기하기
				fl = 1;	

		if (fl == 1) {						//문자열 B에 있는 경우,
			dl = 0;
			for (int w = 0; w < d; w++)		//합성 단어 배열 hit에 이미 저장한 경우
				if (strcmp(hit[w], q[j]) == 0)
					dl = 1;					//중복 표기하기

			if (dl == 0)					//중복되지 않으면
				strcpy(hit[d++], q[j]);		//해당 단어 합성 단어 배열 hit에 저장
		}
	}
	
	for (i = 0; i < d - 1; i++)			//합성 단어 배열을 버블 정렬하기
		for (int j = 0; j < d - 1; j++)
			if (strlen(hit[j]) <= strlen(hit[j + 1])) {		//단어 길이 확인하여
				if (strlen(hit[j]) < strlen(hit[j + 1])) {	//길이 순 내림차순 정렬
					strcpy(cmp, hit[j]);
					strcpy(hit[j], hit[j + 1]);		//단어 서로 교환
					strcpy(hit[j + 1], cmp);
				}
				else {	//단어 길이 같은 경우
					if (strcmp(hit[j], hit[j + 1]) > 0) {	//사전 순 빠른 단어 앞에 정렬
						strcpy(cmp, hit[j]);
						strcpy(hit[j], hit[j + 1]);	//단어 서로 교환
						strcpy(hit[j + 1], cmp);
					}
				}
			}

	for (i = 0; i < d; i++)		//정렬된 문자열 B에 있는 합성 단어 리스트 출력
		printf("%s\n", hit[i]);

	for (i = 0; i < N; i++) //문자열 A에 대하여
		free(p[i]);		//문자 배열 동적할당 각각 해제
	free(p);			//포인터 배열 해제

	for (i = 0; i < M; i++)	//문자열 B에 대하여
		free(q[i]);		//문자 배열 동적할당 각각 해제
	free(q);			//포인터 배열 해제

	return 0;
}
/*
red orange yellow green blue purple
pink red redorange orangered yellow black bluegreen white purple

apple or ange pineapple coconuts lemons ora nge
appleapple orange orlemons

합성 단어 리스트 res 배열의 크기 잘 고려하기
(일단 앞의 [200]은 역순 조합도 있으므로, 
최대 단어 생성 개수 * 2배 가능성 존재)
(그리고 [200][101]도 runtime error 발생.
왜냐하면 문자열 A에 한 단어 길이가 100이면,
그리고 또 다른 단어 길이도 100이면, 둘을 조합하면
길이는 200 + 1이 된다)
*/