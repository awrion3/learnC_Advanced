#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//변수 선언 및 값 입력
	int N, ar[100], * p = ar, * q;
	int num, cnt = 0, tmp, odd = 0, max = 1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) { //N개의 정수 입력하되,
		scanf("%d", &num);

		if (num > 0) { //0보다 큰 정수만 배열에 저장
			*p++ = num;
			cnt++;	//실제로 배열에 저장된 정수의 개수
		}
	}
	//정수의 개수 출력//
	printf("%d\n", cnt);

	if (cnt % 2 != 0) { //배열에 저장된 정수의 개수가 홀수인 경우
		for (p = ar; p < ar + cnt - 1; p++)
			for (q = p + 1; q < ar + cnt; q++)	//선택정렬
				if (*p > *q) {//오름차순
					tmp = *p;
					*p = *q;
					*q = tmp;
				}
	}
	else {//배열에 저장된 정수의 개수가 짝수인 경우
		for (p = ar; p < ar + cnt - 1; p++)
			for (q = p + 1; q < ar + cnt; q++)	//선택정렬
				if (*p < *q) {//내림차순
					tmp = *p;
					*p = *q;
					*q = tmp;
				}
	}
	//정렬한 배열 출력//
	for (p = ar; p < ar + cnt; p++)
		printf("%d ", *p);
	printf("\n");

	//누적 횟수 계산
	for (p = ar; p < ar + cnt; p++)
		if (*p % 2 != 0) { //연속해서 홀수가 나오는 횟수 누적
			odd++;
			if (max < odd) //최대 누적 횟수 갱신 (참고: max의 초기값은 1. 조건에 따라)
				max = odd;
		}
		else
			odd = 0;	//아니면 처음부터 다시 초기화
	//연속하여 홀수 등장 최대 횟수 출력//
	printf("%d\n", max);

	return 0;
}
/*
16
5 1 -2 3 19 6 7 8 17 -4 9 11 -6 16 13 15

12
5 11 -1 -14 9 7 -5 6 2 1 3 -7
*/