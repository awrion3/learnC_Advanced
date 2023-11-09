#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 관련 함수 포함
#include <stdlib.h>	//동적할당 관련 함수 포함

//구조체 정의
struct student {	
	char *studentName;	 // 학생 이름
	char id[5];			 // 학생 학번
	char *subjectName;	 // 과목 이름
	double subjectScore; // 과목 점수
};

int main(void) {

	struct student *p, smp;			//구조체 포인터 선언
	char tmp[101], *t, wmp[101];	//문자열 변수 선언
	int N, len, wlen, cnt, num, K;	//정수형 변수 선언

	scanf("%d", &N);	//학생 수 입력 받기
	getchar();			//엔터키 제거

	p = (struct student*)malloc(N * sizeof(struct student));	//구조체 배열 동적할당1

	if (p == NULL) {					//동적할당 검사1
		printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
		return -1;
	}

	for (int i = 0; i < N; i++){	//N명의 정보 입력
		gets_s(tmp, 100);			//공백 포함 임시 문자열 입력
		len = strlen(tmp);			//임시 문자열 길이 구하기

		for (t = tmp; t < tmp + len; t++)	//해당 문자열 포인터로 접근하여
			if (*t == ' ')   				//공백 문자를 널 문자로 대체
				*t = '\0';
		
		strcpy(wmp, tmp);		//첫 단어 저장하기
		wlen = strlen(wmp);		//첫 단어 길이 구하기
		cnt = 0;				//카운터 초기화

		for (t = tmp; t < tmp + len; t++) {	//해당 문자열 포인터로 접근하여
			if (*t == '\0') {	//널 문자 만나면
				strcpy(wmp, t + 1);		//다음 단어 저장하기
				wlen = strlen(wmp);		//다음 단어 길이 구하기
				cnt++;			//카운터 증가
			}

			if (cnt == 0) {			//학생 이름 부분
				p[i].studentName = (char*)malloc((wlen + 1) * sizeof(char));	//문자열 동적 할당2

				if (p[i].studentName == NULL) {		//동적할당 검사2
					printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
					return -1;
				}
				strcpy(p[i].studentName, wmp);		//학생 이름 동적할당된 문자열에 저장
			}
			else if (cnt == 1) {	//학생 학번 부분
				strcpy(p[i].id, wmp);	//학생 학번 저장
			}
			else if (cnt == 2) {	//과목 이름 부분
				p[i].subjectName = (char*)malloc((wlen + 1) * sizeof(char));	//문자열 동적 할당3

				if (p[i].subjectName == NULL) {		//동적할당 검사3
					printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
					return -1;
				}
				strcpy(p[i].subjectName, wmp);		//과목 이름 동적할당된 문자열에 저장
			}
			else {					//과목 점수 부분
				num = atoi(wmp);					//해당 단어 정수로 변환
				p[i].subjectScore = (double)num;	//실수로 변환하여 저장
			}
		}
	}

	for (int i = 0; i < N - 1; i++)		//구조체 배열 버블 정렬
		for (int j = 0; j < N - 1; j++)
			if (p[j].subjectScore < p[j + 1].subjectScore) {	//과목 점수 내림차순 정렬
				smp = p[j];
				p[j] = p[j + 1];		//구조체 간 대입
				p[j + 1] = smp;
			}

	scanf("%d", &K);	//K번째 학생 입력
	K--;				

	//K번째 학생의 학생 이름, 학번, 과목 이름, 과목 점수 출력하기
	printf("%s %s %s %.2lf", p[K].studentName, p[K].id, p[K].subjectName, p[K].subjectScore);

	//동적할당 해제
	for (int i = 0; i < N; i++) {
		free(p[i].studentName);		//학생 이름 동적할당 각각 해제2
		free(p[i].subjectName);		//과목 이름 동적할당 각각 해제3
	}
	free(p);	//구조체 배열 동적할당 해제1

	return 0;
}
/*
5
HongGilDong 1003 Math 78
JeonWooChi 1001 English 60
HeungBoo 1002 Economics 80
NolBoo 1004 Ethics 50
Euler 1005 Math 100
2
*/