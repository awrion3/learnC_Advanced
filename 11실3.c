#pragma warning(disable:4996)
#include <stdio.h>

//구조체 정의
struct student {
	char name[10];
	int score;
};

int main(void) {

	//구조체 배열 선언
	struct student st[5];
	double avg = 0;

	//구조체 배열의 구조체 원소별 멤버값 입력
	for (int i = 0; i < 5; i++){
		scanf("%s", st[i].name);
		scanf("%d", &st[i].score);
		avg += st[i].score;
	}

	avg = (double)avg / 5;	//형 변환에 유의

	//구조체 배열의 구조체 원소별 멤버값 출력
	for (int i = 0; i < 5; i++)
		if (st[i].score <= avg)
			printf("%s\n", st[i].name);

	return 0;
}

/*
akim 75
bkim 85
ckim 65
dkim 95
ekim 100
*/