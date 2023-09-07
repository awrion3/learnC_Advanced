#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//변수 선언 및 초기화
	int ar[5], *p = ar, *q;
	int rank[5], *r = rank;

	//변수 값 입력
	for (; p < ar + 5; p++)
		scanf("%d", p);

	//변수 값 연산
	for (p = ar; p < ar + 5; p++) { //포인터 활용하여 배열에 저장된 정수들을 비교하며
		*r = 1;	//등수 초기화
		for (q = ar; q < ar + 5; q++)
			if (*p < *q)			//등수 매겨서 배열 rank에 저장 (포인터 활용)
				++*r;
		r++;	//등수 인덱스 조정
	}

	//변수 값 출력
	r = rank;	//포인터 연결 초기화//
	for (p = ar; p < ar + 5; p++, r++)
		printf("%d=r%d ", *p, *r);	//정수 및 등수 값 출력
	
	return 0;
}