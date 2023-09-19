#pragma warning (disable:4996)
#include <stdio.h>

//함수 선언
int* MAX(int []); //인자 int형 배열, 반환 int형 포인터
int* MIN(int []); //인자 int형 배열, 반환 int형 포인터

int main(void) {

	//변수 선언
	int N, num, ar[100], *p, *pmax, *pmin;	

	//사용자로부터 정수형 변수 N 입력
	scanf("%d", &N); 

	//N회 반복
	for (int i = 0; i < N; i++) {

		for (p = ar; p < ar + 100; p++) { //주소를 이용하여 배열 접근
			scanf("%d", &num); //사용자로부터 정수 입력받아
			*p = num; //포인터 사용하여 배열 ar에 원소 값 저장
			if (num == 0) //입력받은 정수가 0이면 반복 종료//
				break;
		}  

		pmax = MAX(ar); //이번 배열의 최대값 주소 반환
		pmin = MIN(ar);	//이번 배열의 최소값 주소 반환
		
		printf("%d %d\n", *pmax, *pmin); //간접 접근한 값 출력
	}

	return 0;
}

//함수 정의
int* MAX(int ar[]) {

	int *p = ar, *pmax = ar; //포인터 선언 및 연결

	for (; p < ar + 100; p++) {
		if (*p == 0) //0은 최대값에서 제외
			break;

		if (*p > *pmax) //해당 배열 내 최대값 찾아
			pmax = p;	//해당 최대값의 주소로 갱신
	}

	return pmax; //해당 배열내 최대값의 주소 반환
}

int* MIN(int ar[]) {

	int *p = ar, *pmin = ar; //포인터 선언 및 연결

	for (; p < ar + 100; p++) {
		if (*p == 0) //0은 최소값에서 제외
			break;

		if (*p < *pmin)	//해당 배열 내 최소값 찾아
			pmin = p;	//해당 최소값의 주소로 갱신
	}

	return pmin; //해당 배열내 최소값의 주소 반환
}
/*
3
3 7 6 -2 0
1 7 6 13 2 0
2 0

2
13 7 6 6 2 0
7 3 4 5 6 10 4 0
*/