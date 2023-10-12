#pragma warning(disable:4996)
#include <stdio.h>

//구조체 정의
struct student {
	char name[9];
	int kor, eng, mat;
	double avg;
	char result;
};

int main(void) {

	//구조체 배열 선언
	struct student st[50], *p = NULL;
	int N;

	scanf("%d", &N);

	//구조체 포인터 활용하여 구조체 배열의 원소별 멤버 간접 접근
	for (p = st; p < st + N; p++) 
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->mat);
	
	for (p = st; p < st + N; p++) {
		p->avg = 0;
		p->avg = (double)(p->kor + p->eng + p->mat)/3;	//형 변환에 유의

		//구조체 포인터를 통해 접근한 구조체 배열의 각 구조체 원소의 멤버인 학점 매기기
		if (p->avg >= 90 && p->avg <= 100)
			p->result = 'A';
		else if (p->avg >= 80 && p->avg <= 90)
			p->result = 'B';
		else if (p->avg >= 70 && p->avg <= 80)
			p->result = 'C';
		else
			p->result = 'D';
	}

	//구조체 포인터를 통해 구조체 배열 접근하여 간접 참조한 값 출력
	for (p = st; p < st + N; p++)
		printf("%s %.1f %c\n", p->name, p->avg, p->result);

	return 0;
}
/*
2
Kim 82 72 58
Young 90 100 99
*/