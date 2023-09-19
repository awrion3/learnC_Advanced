#pragma warning (disable:4996)
#include <stdio.h>

//함수 선언
int passengerN(int);	//인자 int형, 반환값 int형
void rebooking(int*);	//인자 int형 포인터, 반환값 없음
int changeseat(int*);	//인자 int형 포인터, 반환값 int형

int main(void) {

	//변수 선언 및 초기화
	int ar[21] = {0}, *p, N;

	scanf("%d", &N);	//승객 수 입력

	for (p = ar; p < ar + N; p++)	//버스 좌석번호 예약
		scanf("%d", p);

	if (passengerN(N) == 0) {	//승객 수가 충분하면
		printf("%d\n", passengerN(N)); //0을 출력하고

		rebooking(ar); //중복 좌석번호 확인 및 변경

		//승객들이 예약한 좌석번호를 순서대로 출력
		for (p = ar; p < ar + N; p++)
			printf("%d ", *p);
	}
	else
		printf("%d\n", passengerN(N)); //승객 수가 부족하면 -1만을 출력

	return 0;
}

//함수 정의
int passengerN(int n) { //인자 승객 수, 반환값 0 또는 -1

	if (n >= 5)	//승객 수가 5명 이상인 경우 0을 반환
		return 0;
	else		//5명 미만이면 -1을 반환
		return -1;
}

void rebooking(int *ar) { //인자 입력된 배열의 이름, 반환값 없음
	
	//변수 선언 및 초기화
	int *p, len = 0, *q, dup, dum, *dex = ar, fl;

	//배열의 크기 구하기
	for (p = ar; p < ar + 21; p++) {
		if (*p != 0)	//예약한 좌석번호가 있는 원소까지 계산
			len++;
	}

	for (p = ar; p < ar + len; p++) { //예약된 버스 좌석번호가 저장된 배열에 접근해
		dup = 0; fl = 0;	//중복값 표기 및 초기값 표기 초기화

		for (q = ar; q < p; q++)	  //이전의 좌석번호들과 비교하며 중복되는지 확인
			if (*p == *q) {		    
				dup = 1;		//중복값임을 표기//
				if (fl == 0) {	//처음만 초기값으로 설정//
					dum = *p;		//중복되는 좌석번호 숫자 기록
					dex = p;		//중복되는 좌석번호 위치 기록
					fl = 1;		
				}
			}

		if (dup == 1) {	//해당 좌석번호가 중복 예약된 번호일 시
			for (q = dex; q < ar + len; q++)	//해당 위치 이후의 모든 같은 중복 좌석번호들을
				if (*q == dum)
					*q = changeseat(ar);		//changeseat 함수 호출하여 빠른 빈 좌석 번호로 대체
		}	
	}
}

int changeseat(int *ar) { //인자 입력된 배열의 이름, 반환값 배열에 존재하지 않는 가장 작은 숫자

	//변수 선언
	int *p, len = 0, num = 1, fl = 0;

	//배열의 크기 구하기
	for (p = ar; p < ar + 21; p++) {
		if (*p != 0)	//예약한 좌석번호가 있는 원소까지 계산
			len++;
	}

	while (num < 21) { //num은 1부터 21 사이의 숫자//
		for (p = ar; p < ar + len; p++) //예약된 좌석번호가 저장된 배열을 훑으며
			if (*p == num)	//배열에 존재하는 숫자인지 확인
				fl = 1;

		if (fl == 0)	//배열에 존재하지 않으면 반복 중지
			break;
		else {			//배열에 존재하면 값 증가시켜서 다시 반복
			num++;
			fl = 0;		    //배열에 존재하지 않는 숫자로 가정 초기화
		}
	}
	
	return num; //배열에 존재하지 않는 가장 작은 숫자 반환
}
/*
7
1 2 3 3 4 5 6

6
8 8 6 8 6 1

3
1 2 2

10
8 3 1 6 4 11 21 13 5 2
*/