#pragma warning(disable:4996)
#include <stdio.h>

//student 구조체 정의
struct student {	
	char name[21];	//문자열 널 문자 포함
	int kor, eng, math;	//int형 성적 저장
	double avg;		 //double형 평균 저장
};

//함수 원형 선언
void read_data(struct student*, int);
void sort_score(struct student*, int);
struct student* select_out(struct student*, struct student*, int);

int main(void) {

	//구조체 배열 선언 및 구조체 포인터 선언
	struct student st1[49], st2[49], *st, *p;	
	int N;		//정수형 변수 선언

	scanf("%d", &N);	//정수 N 입력
	
	//함수 호출하여 구조체 배열값 입력
	read_data(st1, N);
	read_data(st2, N);	

	//함수 호출하여 구조체 배열값 정렬
	sort_score(st1, N);
	sort_score(st2, N);

	//함수 호출하여 반환된 구조체 배열의 시작주소 저장
	st = select_out(st1, st2, N);

	//중간값이 더 큰 배열에 저장된 학생들의 이름과 국영수 성적, 평균 점수 출력
	for (p = st; p < st + N; p++)
		printf("%s %d %d %d %.1f\n", p->name, p->kor, p->eng, p->math, p->avg);

	return 0;
}

//함수 정의
void read_data(struct student *st, int N) {

	struct student *p;	//구조체 포인터 선언

	for (p = st; p < st + N; p++){	//구조체 배열을 포인터로 접근하여 값 입력
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
		
		//세 과목의 평균 점수를 계산하여 저장
		p->avg = (double)(p->kor + p->eng + p->math) / 3;	
	}
}

void sort_score(struct student *st, int N) {

	struct student *q, dmp;	//구조체 관련 선언

	for (int i = 0; i < N - 1; i++)			//버블 정렬 방식으로
		for (q = st; q < st + N - 1; q++)	//구조체 배열을 포인터로 접근하여
			if (q->avg <= (q + 1)->avg) {	//내림차순 정렬
				//평균 점수가 같은 경우
				if (q->avg == (q + 1)->avg) {
					//국어 성적도 같은 경우
					if (q->kor == (q + 1)->kor) {
						//영어 성적으로 비교
						if (q->eng < (q + 1)->eng) {
							dmp = *q;		//dmp를 활용하여 구조체 간 대입을 통해
							*q = *(q + 1);	//큰 값을 앞으로 이동
							*(q + 1) = dmp;
						}
					}
					//국어 성적으로 비교
					else if (q->kor < (q + 1)->kor) {
						dmp = *q;		//dmp를 활용하여 구조체 간 대입을 통해
						*q = *(q + 1);	//큰 값을 앞으로 이동
						*(q + 1) = dmp;
					}
				}
				//큰 평균값이 뒤에 있는 경우
				else {
					dmp = *q;		//dmp를 활용하여 구조체 간 대입을 통해
					*q = *(q + 1);	//큰 값을 앞으로 이동
					*(q + 1) = dmp;
				}
			}
}

struct student* select_out(struct student *st1, struct student *st2, int N) {

	int M = N / 2;								  //중간 등수 인덱스 저장
	struct student *p1 = st1 + M, *p2 = st2 + M;  //중간 평균값 위치 저장

	//중간값이 더 큰 구조체 배열의 시작 주소 반환
	if (p1->avg > p2->avg)	//st1구조체의 중간값이 더 큰 경우
		return st1;
	return st2;				//st2구조체의 중간값이 더 큰 경우
}
/*
5
Kim 100 85 80
Lee 88 94 92
Park 92 100 100
Hong 84 82 85
Nam 80 84 72
Song 100 90 97
Lee 92 82 93
Park 80 84 72
Choi 97 80 90
Chung 100 94 93
*/