#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
void input(int*, int);
int* sel_max(int*, int);
void output(int*, int);

int main(void) {

	int in[100], out[100], * max, i, N, M;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) { //해당 작업 N번 반복
		input(in, M);			//함수 호출하여 M개의 정수 입력
		max = sel_max(in, M);	//그 중 가장 높은 중복 입력 횟수를 지닌 원소의 주소로 max값 갱신
		out[i] = *max;			//해당 입력에 대한 중복 입력 횟수 *max값 저장
	}

	output(out, N); //함수 호출하여 출력 

	return 0;
}

//함수 정의
void input(int *p, int M) {//입력 구현

	int *pa = p;

	for (; pa < p + M; pa++)
		scanf("%d", pa);
}

int* sel_max(int* p, int M) {

	int* pa = p, * qa = p;
	int dup, max = -1, * mdx = p;
	//중복 횟수 = 자기자신을 제외한 상태에서 계산, 따라서 모든 수가 중복되지 않을 시,
	//최대 중복 횟수는 0이 되며, 이를 반영하기 위해서는 max를 -1로 지정한다
	//또한 반복문 진입하지 않을 시까지 고려해 주소 mdx는 p로 초기화한다

	for (; pa < p + M; pa++) {
		dup = 0;
		for (qa = p; qa < p + M; qa++) //qa = p 초기화 식을 빼놓지 않도록 한다//
			if (*pa == *qa && pa != qa)	//같은 주소는 제외 == 자기 자신 제외
				dup++;

		//=을 넣지 않았다는 것 = 중복 횟수가 동일할 시, (그것이 자기 자신이든, 다른 수든 처음 원소의 주소로 고정)
		if (dup > max) {//만약 처음 수가 중복 횟수가 0이어도 일단 그 첫 주소로 갱신될 것임
			max = dup;
			mdx = pa; //해당 원소 주소 저장
		}
	}

	return mdx;
}

void output(int *p, int N) {//출력 구현

	int *pa = p;

	for (; pa < p + N; pa++)
		printf(" %d", *pa);
}

/*
3 5
1 2 2 1 3
2 4 2 4 3
1 2 3 4 5

2 3
2 1 1
0 1 0
*/