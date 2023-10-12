#pragma warning(disable:4996)
#include <stdio.h>

//구조체 정의
struct numbers {
	int num;
	int rank;
};

int main(void) {

	//구조체 배열 선언
	struct numbers rk[10];

	//구조체 배열의 구조체 원소별 멤버값 입력
	for (int i = 0; i < 10; i++)
		scanf("%d", &rk[i].num);

	//구조체 배열의 구조체 원소별 멤버값 활용하여 다른 멤버값(등수) 구하기
	for (int i = 0; i < 10; i++) {
		rk[i].rank = 1;	//구조체 배열의 구조체 원소별 멤버값 초기화

		for (int j = 0; j < 10; j++)
			if (rk[i].num < rk[j].num) {
				++rk[i].rank;
			}
	}
	
	//3순위와 7순위 등수를 가지는 멤버값(정수) 출력하기
	for (int i = 0; i < 10; i++)
		if (rk[i].rank == 3)
			printf("%d ", rk[i].num);
	
	for (int i = 0; i < 10; i++)
		if (rk[i].rank == 7)
			printf("%d", rk[i].num);

	return 0;
}
/*
78 65 23 43 82 95 31 15 8 54
*/