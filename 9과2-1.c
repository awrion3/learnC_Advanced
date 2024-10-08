#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	//변수 선언 및 초기화
	int N, ar[21], *p, *q;
	int dp[21] = { 0 }, *r = dp, fl = 0, *s, al = 0;

	//승객 수 N 입력
	scanf("%d", &N); 

	for (p = ar; p < ar + N; p++) //승객 N명이 각자 좌석 번호 입력
		scanf("%d", p);

	//중복 예약 확인
	for (p = ar; p < ar + N; p++, r++) {//한 승객이 입력한 좌석 번호에 대해
		for (q = ar; q < ar + N; q++)	
			if (*p == *q)		 //본인 및 다른 승객들의 좌석 번호 비교하여
				++*r;			 //중복 횟수 카운트하며 저장
	}

	//중복 예약 확인 결과 출력
	if (N < 5)			//승객수가 5보다 작은 경우,
		printf("-1\n");	//-1 출력
	else {
		for (r = dp, p = ar; r < dp + N; r++, p++) //좌석번호 ar와 중복횟수 dp 배열에 접근해
			if (*r > 1) {	//중복예약이 존재하는지 확인
				fl = 1;		//중복예약이 배열 dp에 존재할 시 표기

				al = 0; //중복예약 내역을 한번씩만 출력하기 위한 표기 초기화
				for (s = ar; s < p; s++) 
					if (*s == *p)	//이전에 같은 좌석번호가 존재한다면
						al = 1;		//중복예약 내역을 이미 출력했음을 표기

				if (al == 0)	//이전에 출력하지 않은 경우에 한해
					printf("%d %d\n", *p, *r); //해당 좌석번호와 중복횟수 내역 출력하기
			}

		if (fl == 0)  //중복 예약이 존재하지 않을 시 0 출력
			printf("0\n"); 
	}

	return 0;
}

/*
8
7 2 5 5 20 5 8 7

7
21 15 20 9 16 1 3

3
10 5 5
*/