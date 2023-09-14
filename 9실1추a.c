#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
void input(int *, int);
int* diff(int*, int);

int main(void) {

	//변수 선언 및 값 입력
	int N, ar[100], *p; 

	scanf("%d", &N);

	//함수 호출
	input(ar, N);

	//함수 호출
	p = diff(ar, N);

	//변수 값 출력
	printf("%d %d\n", *(p - 1), *p);
		
	return 0;	
}	

//함수 정의
void input(int* ar, int N) {

	int* p;

	//포인터 주소 비교 사용하여 배열 값 저장
	for (p = ar; p < ar + N; p++) 
		scanf("%d", p);
}

int* diff(int* ar, int N) {

	int* p = ar, gap, max, *mp;

	//첫 번째 원소와 두 번째 원소의 절대값 차로 max 초기화
	max = *p - *(p + 1) < 0 ? -(*p - *(p + 1)) : *p - *(p + 1);

	//두 번째 원소의 주소값으로 초기화
	mp = p + 1;

	for (; p < ar + N - 1; p++) { 
		//배열 두 원소 간의 절대값 차 구하기
		gap = *p - *(p + 1) < 0 ? -(*p - *(p + 1)) : *p - *(p + 1);

		//조건 만족시 max 값 갱신 및 두 번째 주소값 갱신 
		if (max < gap) {
			max = gap;
			mp = p + 1;
		}
	}

	//주소값 반환
	return mp; 
}