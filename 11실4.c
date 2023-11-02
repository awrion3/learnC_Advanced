#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

struct student {	//구조체 정의

	char name[8];
	int kor, eng, math;
	int score;
	double avg;

};

int main(void) {

	int N;
	struct student *p;	//구조체 선언

	scanf("%d", &N);

	p = (struct student*)malloc(N * sizeof(struct student)); //동적할당...및 확인

	for (int i = 0; i < N; i++) {	//구조체 배열 + 구조체 포인터 사용 접근
		scanf("%s %d %d %d", p[i].name, &p[i].kor, &p[i].eng, &p[i].math);
		p[i].avg = (double)(p[i].kor + p[i].eng + p[i].math) / 3;
	}

	for (int i = 0; i < N; i++) {
		printf("%s %.1f ", p[i].name, p[i].avg);	//결과 출력

		if (p[i].kor >= 90 || p[i].eng >= 90 || p[i].math >= 90)	//등급 추가로 매겨 출력
			printf("GREAT ");
		if (p[i].kor < 70 || p[i].eng < 70 || p[i].math < 70)
			printf("BAD ");
		
		printf("\n");
	}
	
	free(p);	//동적할당 해제

	return 0;
}
/*
2
Kim 100 82 34
Young 90 100 99
*/