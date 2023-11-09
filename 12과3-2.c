#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 관련 함수 포함
#include <stdlib.h>	//동적할당 관련 함수 포함

//구조체 정의
struct student {
	char *name;		// 학생 이름
	char id[5];		// 학생 학번
	int numSubject; // 과목 개수
	struct subject *psub;	// 과목 구조체 포인터
	double avg;				// 모든 과목의 평균 점수
};

struct subject {
	char *name;		// 과목 이름
	double score;	// 과목 점수
};

int main(void) {

	struct student *p, smp;			//구조체 포인터 선언	
	int N, len, M, wlen, wnt, sl, idx, num, cl, K;	//정수형 변수 선언
	char tmp[101], *t, wmp[101], *sub = NULL;	//문자형 변수 선언
	double sum, max = -1;							//실수형 변수 선언

	scanf("%d", &N);	//학생 수 입력
	getchar();			//엔터 키 제거

	//구조체 배열 동적할당1
	p = (struct student*)malloc(N * sizeof(struct student));	

	if (p == NULL) {					//동적할당 검사1
		printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
		return -1;
	}

	for (int i = 0; i < N; i++) {	//학생 수 만큼 입력받기
		gets_s(tmp, 100);	//공백이 있는 임시 문자열 입력
		len = strlen(tmp);	//임시 문자열 길이 구하기

		M = 0;	//과목 수 초기화
		for (t = tmp; t < tmp + len; t++) {	//임시 문자열 접근하여
			if (*t == ' ') {	//공백 문자를 널 문자로 교체
				*t = '\0';
				M++;		//과목 수 관련 계산
			}
		}
		M = (M - 1) / 2;	//과목 수 정정

		strcpy(wmp, tmp);	//첫 단어 저장
		wlen = strlen(wmp);	//첫 단어 길이 구하기
		wnt = 0, sl = 0, idx = 0, cl = 0, sum = 0;	//카운터 초기화

		for (t = tmp; t < tmp + len; t++) {	//임시 문자열 접근하여
			if (*t == '\0') {	//널 문자 만나면
				strcpy(wmp, t + 1);	//다음 단어 저장
				wlen = strlen(wmp);	//다음 단어 길이 구하기
				wnt++;

				if (cl == 2)	//과목 점수까지 저장한 경우
					idx++;		//과목 관련 인덱스 증가
			}
			cl = 0;		//과목 관련 인덱스 초기화

			if (wnt == 0) {			//학생 이름 부분
				//문자열 동적할당2
				p[i].name = (char*)malloc((wlen + 1) * sizeof(char));

				if (p[i].name == NULL) {	//동적할당 검사2
					printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
					return -1;
				}
				strcpy(p[i].name, wmp);		//학생 이름 동적할당된 문자열에 저장
			}
			else if (wnt == 1) {	//학생 학번 부분
				strcpy(p[i].id, wmp);		//학생 학번 문자열에 저장
			}
			else {					//과목 관련 부분
				if (sl == 0) {	//학생 당 처음 진입 시에만 실시
					//중첩 구조체 배열 동적할당3 
					p[i].psub = (struct subject*)malloc(M * sizeof(struct subject));

					if (p[i].psub == NULL) {			//동적할당 검사3
						printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
						return -1;
					}
					sl = 1;		//학생 당 이후부터는 제외
				}

				if (*t >= 'A' && *t <= 'Z' || *t >= 'a' && *t <= 'z') {	//과목 이름 부분
					//중첩 구조체 문자열 동적할당4
					p[i].psub[idx].name = (char*)malloc((wlen + 1) * sizeof(char));

					if (p[i].psub[idx].name == NULL) {	//동적할당 검사4
						printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
						return -1;
					}
					strcpy(p[i].psub[idx].name, wmp);		//과목 이름 동적할당된 문자열에 저장

					cl = 1;		//과목 이름임을 표기
				}
				else {								//과목 점수 부분
					num = atoi(wmp);	//문자열 정수로 변환
					p[i].psub[idx].score = (double)num;		//실수로 변환하여 과목 점수 저장

					cl = 2;		//과목 점수임을 표기
				}
			}
		}
		
		p[i].numSubject = M;			//과목 수 저장

		for (int j = 0; j < M; j++)		//해당 학생의 평균 점수 구하기
			sum += p[i].psub[j].score;
		p[i].avg = sum / M;				//평균 점수 저장
	}

	for (int i = 0; i < N - 1; i++)			//구조체 배열 버블 정렬하기
		for (int j = 0; j < N - 1; j++) 
			if (p[j].avg <= p[j + 1].avg) {	//평균 점수 확인하여
				if (p[j].avg < p[j + 1].avg) {			//내림차순 정렬
					smp = p[j];
					p[j] = p[j + 1];			//구조체 간 대입하여 교환
					p[j + 1] = smp;
				}
				else {
					if (strcmp(p[j].id, p[j + 1].id) > 0) {	//학번 순 정렬
						smp = p[j];
						p[j] = p[j + 1];		//구조체 간 대입하여 교환
						p[j + 1] = smp;
					}
				}
			}

	scanf("%d", &K);	//K번째 학생 입력받기
	K--;	//인덱스 정정

	printf("%s %s %.2lf ", p[K].name, p[K].id, p[K].avg);	//해당 학생의 이름, 학번, 평균 점수 출력

	for (int i = 0; i < p[K].numSubject; i++) {	//해당 학생의 과목 구조체 접근하여
		if (max < p[K].psub[i].score) {		//가장 점수가 높은 과목 점수 저장
			max = p[K].psub[i].score;
			sub = p[K].psub[i].name;		//가장 점수가 높은 과목 이름 저장
		}
	}

	printf("%s %.2lf", sub, max);	//해당 학생의 최고득점 과목 이름과 점수 출력

	// 동적할당 해제
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < p[i].numSubject; j++)
			free(p[i].psub[j].name);	//중첩 구조체 문자열 동적할당 해제4
		free(p[i].name);			//문자열 동적할당 해제2
		free(p[i].psub);				//중첩 구조체 배열 동적할당 해제3
	}
	free(p);						//구조체 배열 동적할당 해제1
	
	return 0;
}
/*
5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
4
*/