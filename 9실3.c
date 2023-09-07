#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//변수 선언 및 초기화
	int ar[50] = { 0 }, N;
	int *pa = ar, cnt = 0;

	//변수 값 입력
	scanf("%d", &N);

	for (; pa < ar + N; pa++)	//주소 비교를 이용하여 배열 원소 접근
		scanf("%d", pa);

	//변수 값 연산
	for (pa = ar; pa < ar + N; pa++, cnt++) {
		if (*pa == 0)	//0이 나오기 전까지의 정수 개수 계산
			break;
	}

	//변수 값 출력
	printf("%d\n", cnt);

	return 0;
}