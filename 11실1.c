#pragma warning(disable:4996)
#include <stdio.h>

//구조체 정의
struct vector {
	int ar[3];
};

int main(void) {

	//구조체 선언
	struct vector v1, v2, v3;
	int dot = 0;

	//구조체 변수1 입력
	for (int i = 0; i < 3; i++)
		scanf("%d", &v1.ar[i]);

	//구조체 변수2 입력
	for (int i = 0; i < 3; i++)
		scanf("%d", &v2.ar[i]);

	//구조체 변수3 계산
	for (int i = 0; i < 3; i++) {
		v3.ar[i] = v1.ar[i] * v2.ar[i];
		printf("%d ", v3.ar[i]);
	}
	printf("\n");

	//구조체 변수3 사용
	for (int i = 0; i < 3; i++)
		dot += v3.ar[i];

	//결과값 출력
	printf("%d", dot);

	return 0;
}
/*
1 2 3
-1 5 5
*/