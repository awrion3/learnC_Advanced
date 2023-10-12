#pragma warning(disable:4996)
#include <stdio.h>

//구조체 정의
struct student {
	int gender, weight, height;
};

int main(void) {

	//구조체 배열 선언
	struct student st[10];
	int N, g1 = 0, g2 = 0, g3 = 0;

	scanf("%d", &N);

	//구조체 배열의 구조체 원소 멤버값 입력 후 분류
	for (int i = 0; i < N; i++){
		scanf("%d %d %d", &st[i].gender, &st[i].weight, &st[i].height);

		//성별, 체중, 키에 따라 세부 분류
		if (st[i].gender == 1) {
			if (st[i].weight >= 70) {
				if (st[i].height >= 175)
					g1 += 1;
				else if (st[i].height >= 165)
					g3 += 1;
				else
					g2 += 1;
			}
			else if (st[i].weight >= 60) {
				if (st[i].height >= 175)
					g2 += 1;
				else if (st[i].height >= 165)
					g1 += 1;
				else 
					g3 += 1;
			}
			else {
				if (st[i].height >= 175)
					g3 += 1;
				else if (st[i].height >= 165)
					g2 += 1;
				else
					g1 += 1;
			}
		}
		else if (st[i].gender == 2) {
			if (st[i].weight >= 60) {
				if (st[i].height >= 175) 
					g1 += 1;
				else if (st[i].height >= 165)
					g3 += 1;
				else 
					g2 += 1;
			}
			else if (st[i].weight >= 50) {
				if (st[i].height >= 175) 
					g2 += 1;
				else if (st[i].height >= 165) 
					g1 += 1;
				else
					g3 += 1;
			}
			else {
				if (st[i].height >= 175) 
					g3 += 1;
				else if (st[i].height >= 165) 
					g2 += 1;
				else
					g1 += 1;
			}
		}
	}

	//구조체 관련하여 카운트한 값 출력
	printf("%d %d %d", g1, g2, g3);

	return 0;
}

/*
2
1 66 170
2 48 155
*/