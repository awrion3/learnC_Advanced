#pragma warning(disable:4996)
#include <stdio.h>

struct person {
	char name[11];	//지원자 이름(널 문자 포함)
	int wt, it;		//필기시험, 면접시험 점수
	double res;		//총점
};

//함수 선언
void swap(struct person*, struct person*);

int main(void) {

	struct person sp[100], *p;	//구조체 배열 및 포인터 선언

	int N, M;	//지원자, 합격자 수 입력
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {	//지원자별 이름, 시험 점수들 입력
		scanf("%s %d %d", sp[i].name, &sp[i].wt, &sp[i].it);
		sp[i].res = sp[i].wt * 0.8 + sp[i].it * 0.2;	//총점도 저장
	}

	for (int i = 0; i < N - 1; i++) 	//버블 정렬 방식으로
		for (p = sp; p < sp + N - 1; p++) 	//구조체 배열을 포인터로 접근하여
			if (p->res < (p + 1)->res) 	//후자가 더 큰 총점인 경우, 오름차순 정렬
				swap(p, p + 1);			//swap 함수 호출하여 두 구조체 원소를 교환
	
	for (p = sp; p < sp + M; p++) 	//오름차순 정렬 결과: 첫 원소부터 가장 큰 값 순의 구조체 배열
		printf("%s %.1f\n", p->name, p->res);	//차례로 합격자 수만큼 출력
	
	return 0;
}

void swap(struct person *p, struct person *q) {

	struct person tmp;	//구조체 선언

	tmp = *p;	//구조체 간 대입을 통해 각 구조체 원소의 멤버값들 함께 교환
	*p = *q;
	*q = tmp;
}
/*
7 3
Aaaaa 75 85
Bbbbb 86 77
Ccccc 94 82
Ddddd 78 70
Eeeee 65 85
Fffff 83 90
Ggggg 90 70
*/