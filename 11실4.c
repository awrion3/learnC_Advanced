#pragma warning(disable:4996)
#include <stdio.h>

//구조체 정의
struct student {
	char name[20];
	int score[3];
	double avg;
	char result;
};

int main(void) {

	//구조체 배열 선언
	struct student st[20];
	int N;

	scanf("%d", &N);

	//N명의 학생 구조체 배열 접근
	for (int i = 0; i < N; i++) {
		scanf("%s", st[i].name);
		
		//구조체 배열의 구조체 원소별 멤버값 초기화
		st[i].avg = 0;
		for (int j = 0; j < 3; j++){
			scanf("%d", &st[i].score[j]);	//구조체 배열의 구조체 원소별 배열 멤버값 활용

			st[i].avg += st[i].score[j];
		}
		st[i].avg = (double)st[i].avg / 3;	//형 변환에 유의

		//구조체 배열의 구조체 원소별 멤버값 저장
		if (st[i].avg >= 90)
			st[i].result = 'A';
		else if (st[i].avg >= 80)
			st[i].result = 'B';
		else if (st[i].avg >= 70)
			st[i].result = 'C';
		else
			st[i].result = 'F';
	}

	//구조체 배열의 구조체 원소별 멤버값 출력(소수점 한 자리 수까지임에 유의)
	for (int i = 0; i < N; i++)
		printf("%s %.1f %c\n", st[i].name, st[i].avg, st[i].result);

	return 0;
}
/*
1
Hongildong 95 80 75
*/