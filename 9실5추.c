#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
int input(int*);
int* sel_next(int*);
int number(int*, int*);

int main(void) {

	int x[100], N, *r = x, *s, R; //배열, 배열 크기, 두 포인터, 하나의 정수 결과값

	N = input(x); //배열 크기 계산(-1 입력 포함하되, 길이 계산에는 포함 안함)

	for (; r < x + N;) { //범위 설정1 (r 포인터가 전체 배열 인덱스 벗어나지 않도록 유의)//
		s = sel_next(r); //함수 호출 및 주소 반환

		R = number(r, s); //함수 호출 및 해당 구간 내 값들로 하나의 정수 만들어 반환

		printf("%d*\n", R); //하나의 정수 값 출력//

		r = s + 1;	//새로운 시작점 갱신하되, 그 다음 주소부터로 설정//
	}

	return 0;
}

//함수 정의
int input(int *p) {

	int *pa = p, cnt = 0;

	for (; pa < p + 100; pa++) {
		scanf("%d", pa);

		if (*pa == -1) //배열 길이에 -1은 포함 안함
			break;
		else
			cnt++;
	}

	return cnt;
}

int* sel_next(int *p) { //이전 주소의 다음 위치에서부터 받아 시작

	int *pa, sum = 0, *q = NULL; //이 경우 q는 아래서 어떤 경우든 갱신되므로 NULL로 초기화

	for (pa = p; *pa != -1; pa++) { //범위 설정2: 배열 크기 인자로 못 받고, 계속 변동되는 주소 p만 받고 있으므로,
		sum += *pa;					//배열 인덱스 범위 내에서만 지정하고자, 마지막 구간 때 -1 전까지만 훑게 설정

		if (sum > 10) //10 초과시 반복 중지하여 아래서 원소 주소 위치 q가 갱신되지 않게끔
			break;

		q = pa; //10 초과 직전의 원소 위치 저장
	}

	return q;
}

int number(int *p, int *q) { // x[m] 인덱스 및 위 함수 반환 인덱스 까지 구간

	int *r = p, sum = 0; //해당 구간 내

	for (; r <= q; r++) {	//값들로 하나의 정수 만들어 반환
		sum *= 10;
		sum += *r;
	}

	return sum;
}
