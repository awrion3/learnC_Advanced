#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N;
	scanf("%d", &N);

	switch (N / 10000) {
	case 1:
		switch (N / 1000 % 10) {
		case 0:
			switch (N / 100 % 10) {
			case 0: case 1: case 2:
				printf("Seoul");
				break; //아래까지 안내려가게 차단
			case 3: case 4:
				printf("Busan");
				break;
			case 5: //case별로는 {} 사용안함에 유의
				printf("Gwangju");
				break;
			default:
				printf("none");
			}
			break;
		default:
			printf("none");
		}
		break;
	default:
		printf("none");
	}
	
	return 0;
}