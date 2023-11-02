#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 표준 처리 함수 포함

//구조체 정의
struct student {
	char name[10];
	int quiz[3];
	double avg;
};

//함수 선언
void read_data(struct student[]);
void cal_avg(struct student[]);
void sort(struct student[]);
void print_score(struct student[]);

int main(void) {

	//구조체 배열 선언
	struct student st[10];

	//함수 호출
	read_data(st);

	cal_avg(st);

	sort(st);

	print_score(st);

	return 0;
}

//함수 정의
//구조체 배열 값 입력
void read_data(struct student st[]) {

	struct student *p;

	//구조체 배열의 구조체 원소별 멤버 간접 접근하여 값 입력
	for (p = st; p < st + 10; p++) {
		scanf("%s", p->name);

		for (int i = 0; i < 3; i++)
			scanf("%d", &p->quiz[i]);
	}
}

//구조체 배열 값 구하기
void cal_avg(struct student st[]) {

	struct student *p;
	double ag;

	for (p = st; p < st + 10; p++) {

		ag = 0;		//평균값 관련 초기화
		
		//구조체 배열의 구조체 원소의 멤버(int형 배열) 간접 접근하여 계산
		for (int i = 0; i < 3; i++)	
			ag += p->quiz[i];

		ag = (double)ag / 3;	//형 변환

		p->avg = ag;
	}
}

//구조체 배열 정렬
void sort(struct student st[]) {

	struct student *p, *q;
	double dmp;			//자료형별 임시 변수 선언
	char cmp[10];
	int tmp;

	for (p = st; p < st + 10 - 1; p++)	//구조체(및 문자열)에서는 버블 정렬 활용
		for (q = st; q < st + 10 - 1; q++) {
			//포인터를 활용하여 구조체 배열의 구조체 원소별 멤버값 간접 접근하여 크기 비교
			if (q->avg < (q+1)->avg) {	
				dmp = q->avg;
				q->avg = (q+1)->avg;	//큰 값을 앞으로 이동시키기
				(q+1)->avg = dmp;

				//평균값 기준으로 내림차순 정렬할 때, 이름과 퀴주 점수들도 같이 정렬
				strcpy(cmp, q->name);
				strcpy(q->name, (q+1)->name);
				strcpy((q+1)->name, cmp);

				//구조체 배열의 구조체 원소별 멤버인 int형 배열의 원소 모두 정렬시키기
				for (int i = 0; i < 3; i++) {	
					tmp = q->quiz[i];
					q->quiz[i] = (q+1)->quiz[i];
					(q+1)->quiz[i] = tmp;
				}
			}
		}
}

//구조체 배열 값 출력
void print_score(struct student st[]) {

	struct student *p;
	int N = 10 * (1 - 0.3);	//내림차순 정렬된 구조체 배열에서 하위 30%이므로

	//구조체 포인터 연결하여 간접 접근한 구조체 배열의 구조체 원소의 멤버값들 출력
	p = st;
	printf("%s %.2f\n", p->name, p->avg);
	p = st + 9;
	printf("%s %.2f\n", p->name, p->avg);

	for (p = st + N; p < st + 10; p++)	//내림차순 정렬된 구조체 배열의 하위 30% 출력
		printf("%s %.2f\n", p->name, p->avg);
}
/*
AKim 80 80 80
BKim 90 90 90
CKim 81 81 81
ALee 82 82 82
BLee 83 83 83
CLee 84 84 84
APark 85 85 85
BPark 86 86 86
CPark 87 87 87
DPark 88 88 88
*/