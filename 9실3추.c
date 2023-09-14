#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
int input(int*);
int* sel_next(int*, int, int);
int number(int*, int*);

int main(void) {

	int x[100], N, M, *q, R;

	N = input(x); //함수 호출 및 배열 x의 원소 개수 반환 (입력에 포함한 -1 제외한 길이)

	scanf("%d", &M); //정수 M 인덱스 입력

	q = sel_next(x, N, M); //함수 호출 및 배열 원소 주소 저장

	R = number(x + M, q); //함수 호출 및 하나의 정수 반환값 저장

	//하나의 정수 결과 값 출력
	printf("%d\n", R); 

	return 0;
}

//함수 정의
int input(int *p) {

	int *pa = p, cnt = 0;

	for (; pa < p + 100; pa++) { //배열 최대 길이 제한
		scanf("%d", pa);

		if (*pa == -1)	//-1을 포함해 입력받으나,
			break;
		else			//실제 배열 길이에는 카운트 하지 않음(== -1 전까지의 배열 길이)
			cnt++;
	}

	return cnt;
}

int* sel_next(int *p, int N, int M) { //배열의 시작 주소, 배열의 크기, 인덱스 주소

	int *pa, sum = 0;
	int *q = p + (N - 1); //반복문에 들어가지 않는 경우, 마지막 원소의 주소 반환하게끔

	for (pa = p + M; pa < p + N; pa++){ //해당 인덱스부터 배열 끝 원소까지 훑으나,
		sum += *pa;

		if (sum > 10) //합이 10 초과할 시, 주소 갱신되지 않도록 반복문 빠져나옴
			break;

		q = pa; //그렇지 않은 경우 해당 구간 내 마지막의 주소로 갱신
	}

	return q; //주소값 반환
}

int number(int *p, int *q) { //주어진 인덱스 및 위 함수에서 반환된 주소를 인자로 받음

	int *r = p, sum = 0; //구간의 시작 주소

	for (; r <= q; r++) {	//구간의 끝 주소
		sum *= 10;
		sum += *r;
	}

	return sum; //주소 범위 내 원소 값 합쳐서 만든 하나의 정수 반환
}


/*
1 2 1 3 3 2 5 -1
1

팁1) 경계값
1 -1
1 등

팁2) 중간출력
printf("(q=%p, *q=%d)", pa, *pa);
printf("\n[q=%p, *q=%d]\n", q, *q); 등

팁3) 인덱스 범위
팁4) 초과 등 조건
*/