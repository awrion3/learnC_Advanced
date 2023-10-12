#pragma warning(disable:4996)
#include <stdio.h>

//구조체 정의
struct student {
	char name[10];
	int score;
};

//함수 선언
struct student* select_min(struct student *);

int main(void) {

	//구조체 배열 선언 및 포인터 선언과 연결
	struct student st[5], *p = NULL;

	//포인터 주소 비교를 통해 구조체 배열 접근하여 구조체 원소별 멤버값 입력
	for (p = st; p < st + 5; p++)
		scanf("%s %d", p->name, &p->score);

	//함수 호출 및 구조체 배열의 특정 구조체 원소의 주소 반환받기
	p = select_min(st);
	
	//포인터를 활용하여 해당 구조체 원소의 멤버값 간접접근하여 출력
	printf("%s %d", p->name, p->score);

	return 0;
}

//함수 정의
struct student* select_min(struct student *ps) {

	struct student *p, *mp = ps;	//반복문 진입 안했을 때 고려해 포인터 주소값 초기화하기
	double mavg = 101;		

	for (p = ps; p < ps + 5; p++)	//포인터로 구조체 배열 접근하여 구조체 원소들의 멤버값 비교하며 갱신
		if (mavg > p->score) {
			mavg = p->score;
			mp = p;
		}

	//구조체 배열의 특정 구조체 원소를 가리키는 주소 반환
	return mp;
}

/*
akim 75
bkim 85
ckim 65
dkim 95
ekim 100
*/