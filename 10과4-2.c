#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//문자열 처리 표준 함수 포함

//함수 선언
int check_w(char*, char*);

int main(void) {

	char str[101], wlist[10][101], wnt[10], tstr[101];		//널 문자 포함 선언
	int N, M, i = 0, idx, tmp;	   //정수형 변수 선언 및 초기화
	
	scanf("%d%d", &N, &M);	//문자열 N줄 수과 M번째 수 입력
	getchar();				//엔터키 남김 제거

	for (int k = 0; k < N; k++) {	//문자열 N줄 입력받기
		gets_s(str, 100);	//공백 포함된 문자열 입력

		//처음부터 M번째 문자까지 알파벳 공백 제외 문자 개수 확인한 반환값 저장
		wnt[i] = check_w(str, str + M - 1); 

		strcpy(wlist[i], str); //문자열을 이차원 배열에 저장
		
		i++;	//인덱스 증가
	}

	idx = i;	//인덱스 저장
	for (int i = 0; i < idx - 1; i++) {		//버블 정렬 방식으로
		for (int j = 0; j < idx - 1; j++)
			if (wnt[j] < wnt[j + 1]) {	//가장 많은 문자의 개수를
				tmp = wnt[j];
				wnt[j] = wnt[j + 1];	//배열의 앞쪽으로 이동
				wnt[j + 1] = tmp;

				strcpy(tstr, wlist[j]);			//문자열도 문자의 개수에 따라
				strcpy(wlist[j], wlist[j + 1]);	
				strcpy(wlist[j + 1], tstr);		//이차원 배열 내에서 교환하며 이동
			}
	}

	for (int i = 0; i < idx; i++)		//이차원 배열에 인덱스로 접근하여
		if (wnt[i] != 0)				//알파벳 공백 제외 문자의 개수가 0인 경우를 제하고
			printf("%s\n", wlist[i]);	//정렬된 문자열 출력

	return 0;
}

//함수 정의
int check_w(char *p, char *q) {

	char *t;
	int len, cnt = 0;	//변수 선언 및 초기화

	len = strlen(p);	//문자열 길이 구하기

	if (p + len - 1 < q) {	//q의 값이 문자열의 마지막 원소 주소보다 더 큰 경우
		for (t = p; t < p + len; t++) {	//문자열 끝까지만 검사하여
			if (!(*t >= 'A' && *t <= 'Z') &&
				!(*t >= 'a' && *t <= 'z') &&	//영어 알파벳과
				!(*t == ' '))					//공백이 아닌 문자인 경우
				cnt++;	//문자 개수 카운트
		}
	}
	else {					//q의 값이 문자열의 마지막 원소 주소 내에 있는 경우
		for (t = p; t <= q; t++) {		//M번째 문자까지 검사하여
			if (!(*t >= 'A' && *t <= 'Z') &&
				!(*t >= 'a' && *t <= 'z') &&	//영어 알파벳과
				!(*t == ' '))					//공백이 아닌 문자인 경우
				cnt++;	//문자 개수 카운트
		}
	}

	return cnt;		//문자 개수 카운트 반환
}
/*
5 15
1 year is 365 days.
How are you doing?
**Notice**
Winter is coming
1+1=2
*/