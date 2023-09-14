#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
int input(int*);
int* sel_next(int*, int, int);
int number(int*, int*);

int main(void) {

	int x[100], N, M, *q, R; //배열, 크기, 인덱스, 포인터, 정수 결과값

	N = input(x); //함수 호출 및 배열 크기 반환 (-1을 입력 포함하되, 길이에는 포함 안함)

	scanf("%d", &M); //인덱스 입력

	q = sel_next(x, N, M); //배열 x의 시작 주소, 배열의 크기 N, 지정된 시작점 인덱스 M
							//함수 호출 및 원소 값의 증가가 끝나는 마지막 원소의 주소 반환
	R = number(x + M, q); //함수 호출 및 인덱스 M과 위 함수에서 반환된 주소 범위 내로 만든 하나의 정수 반환

	printf("%d\n", R); //만들어진 하나의 정수 결과값 출력

	return 0;
}

//함수 정의
int input(int *p) {

	int *pa = p, cnt = 0;

	for (; pa < p + 100; pa++) {
		scanf("%d", pa);

		if (*pa == -1) //-1인 경우 배열 입력에는 포함하되, 길이 계산에는 포함 안함
			break;
		else
			cnt++;
	}

	return cnt;
}

int* sel_next(int *p, int N, int M) { //배열x의 시작주소, 배열크기 N, 시작 지정점 M 인덱스

	int *pa = p + (M + 1), *q = p + M; 
	//아래서 비교를 위해 +1 변동 
	//q의 경우 반복문 진입안할 시 대비해서, 
	//(또 여기서는 작거나 같은 경우에 해당; x[m]의 주소 반환하기 위한 초기값 지정)

	for (; pa < p + N; pa++) {
		if (*(pa - 1) < *pa) //이전 값과 비교하여 연속적 증가시, q 구간 내 마지막 원소 주소로 갱신
			q = pa;
		else
			break; //증가하지 않으면 반복 중지하여 q 값 갱신되지 않게 함
	}
	
	return q;
}

int number(int *p, int *q) { //x[m] 인덱스 위치 및 위에서 반환된 q 주소값 범위 내로 하나의 정수 구성

	int *r = p, sum = 0;

	for (; r <= q; r++) {
		sum *= 10;
		sum += *r;
	}

	return sum;
}

/*
1 2 4 6 7 4 3 -1
1
*/