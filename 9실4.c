#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//변수 선언 및 초기화
	int ar[3] = { 0 }, *p = ar, *q, tmp;

	//변수 값 입력
	for (; p < ar + 3; p++)
		scanf("%d", p);

	//변수 값 연산
	for (p = ar; p < ar + 2; p++) //주소 비교를 통해 배열 원소 접근
		for (q = p + 1; q < ar + 3; q++) //선택 정렬의 방식으로
			if (*p > *q) {				 //오름차순 정렬
				tmp = *p;	
				*p = *q;
				*q = tmp;	//tmp를 활용하여 값 교환
			}

	//변수 값 출력
	printf("%d", *(ar + 1));	//배열 오름차순 정렬했을 때 중앙값 출력

	return 0;
}