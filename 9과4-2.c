#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//변수 선언 및 초기화
	int a[11], b[11], *p, *q, n = 0, m = 0, num, tmp;

	for (p = a; p < a + 11; p++){ //101호에서 응시한 시험 점수 입력
		scanf("%d", &num);
		if (num == -1)	//-1 입력 시 반복 중지
			break;
		else {
			*p = num;	//배열 a에 시험점수 저장
			n++;	//입력 횟수 카운트
		}
	}

	for (q = b; q < b + 11; q++){ //102호에서 응시한 시험 점수 입력
		scanf("%d", &num);
		if (num == -1)	//-1 입력 시 반복 중지
			break;
		else {
			*q = num;	//배열 b에 시험점수 저장
			m++;	//입력 횟수 카운트
		}
	}

	for (p = a; p < a + n; p++)		//두 배열을 비교하며 시험점수 분류하기
		for (q = b; q < b + m; q++) //한 배열에 대해 다른 배열의 값들을 비교하며
			if (*p <= *q) {	//크거나 같은 값은 배열 a로, 작은 값은 배열 b로 교환//
				tmp = *p;
				*p = *q;	//tmp를 활용하여 두 값을 서로 교환
				*q = tmp;
			}

	//전체 점수들 중 비교적 큰 값들로 분류된 배열 a를 접근하여
	for (p = a; p < a + n - 1; p++)
		for (q = a; q < a + n - 1; q++)	//버블정렬 방식으로
			if (*q < *(q + 1)) {	//내림차순 정렬하기
				tmp = *q;
				*q = *(q + 1);	//tmp를 활용하여 값 교환
				*(q + 1) = tmp;
			}

	//전체 점수들 중 비교적 작은 값들로 분류된 배열 b를 접근하여
	for (p = b; p < b + m - 1; p++)
		for (q = b; q < b + m - 1; q++)	//버블정렬 방식으로
			if (*q > *(q + 1)) {	//오름차순 정렬하기
				tmp = *q;
				*q = *(q + 1);	//tmp를 활용하여 값 교환
				*(q + 1) = tmp;
			}

	for (p = a; p < a + n; p++) //가장 높은 n개의 점수 출력
		printf("%d ", *p);
	printf("\n");	//줄바꿈 출력

	for (q = b; q < b + m; q++)	//가장 낮은 m개의 점수 출력
		printf("%d ", *q);

	return 0;
}
/*
10 50 70 -1
20 100 -1

10 20 40 5 10 -1
100 100 50 20 5 90 80 75 75 60 -1
*/