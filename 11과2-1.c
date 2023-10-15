#pragma warning(disable:4996)
#include <stdio.h>

struct student {	//구조체 정의
	char name[21];	//문자열 널 문자 포함
	int kor, eng, math;	//int형 성적 저장
};

struct average {	//구조체 정의
	double kor, eng, math;	//double형 평균 저장
};

//함수 원형 선언
struct average calculate_avg(struct student*, int);	

int main(void) {

	struct student ar[50];	//구조체 배열 선언
	struct average stav;	//구조체 변수 선언
	int N, k = 0, e = 0, m = 0;		//정수형 변수 선언 및 초기화

	scanf("%d", &N);	//정수 N 입력

	for (int i = 0; i < N; i++) {	//N명의 정보 구조체 배열에 저장
		scanf("%s %d %d %d", ar[i].name, &ar[i].kor, &ar[i].eng, &ar[i].math);
	}

	//함수 호출 및 N명의 과목별 평균 반환값 구조체에 저장
	stav = calculate_avg(ar, N);	

	//과목별 평균 출력
	printf("%.1f %.1f %.1f\n", stav.kor, stav.eng, stav.math);

	//구조체 배열에 접근하여
	for (int i = 0; i < N; i++) {
		if (stav.kor > ar[i].kor)	//국어 평균 미달 학생 수 계산
			k++;
		if (stav.eng > ar[i].eng)	//영어 평균 미달 학생 수 계산
			e++;
		if (stav.math > ar[i].math)	//수학 평균 미달 학생 수 계산
			m++;
	}

	//각 과목의 평균 점수보다 낮은 점수를 받은 학생 수 과목별 출력
	printf("%d %d %d", k, e, m);

	return 0;
}

//함수 정의
struct average calculate_avg(struct student* st, int N) {

	struct student *p;			//구조체 포인터 선언
	struct average sav = { 0 };	//구조체 변수 선언 및 초기화

	//구조체 배열에 포인터로 접근하여
	for (p = st; p < st + N; p++) {	
		sav.kor += p->kor;		//구조체 배열에 저장된 국어 점수 더해 구조체 변수에 저장
		sav.eng += p->eng;		//구조체 배열에 저장된 영어 점수 더해 구조체 변수에 저장
		sav.math += p->math;	//구조체 배열에 저장된 수학 점수 더해 구조체 변수에 저장
	}

	sav.kor = (double)sav.kor / N;		//구조체 변수에 국어 평균 저장
	sav.eng = (double)sav.eng / N;		//구조체 변수에 영어 평균 저장
	sav.math = (double)sav.math / N;	//구조체 변수에 수학 평균 저장

	return sav;		//구조체 변수값 반환
}
/*
5
Kim 100 90 80
Lee 88 94 92
Park 92 100 100
Hong 84 82 85
Nam 80 84 72
*/