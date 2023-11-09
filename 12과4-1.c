#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 관련 함수 포함
#include <stdlib.h>	//동적할당 관련 함수 포함

//구조체 정의
struct student {
	char* name; // 이름 저장
	int firstStage; // 1단계 점수 저장
	int interview;	// 면접 점수 저장
	double sum; // 총점 저장
};

int main(void) {

	struct student *p, smp;	//구조체 변수 선언
	int N, M, tlen;	//정수형 변수 선언
	char tmp[11];		//문자형 변수 선언

	scanf("%d %d", &N, &M);	//1단계 합격자의 수, 최종 합격자 정원 입력

	//구조체 배열 동적할당1
	p = (struct student*)malloc(N * sizeof(struct student));

	if (p == NULL) {				//동적할당 오류 검사1
		printf("Not enough Memory");		//동적할당 실패 시 종료
		return -1;
	}

	for (int i = 0; i < N; i++) {	//N명의 지원자 정보 입력하기
		scanf("%s %d %d", tmp, &p[i].firstStage, &p[i].interview);
		tlen = strlen(tmp);		//임시 문자열 길이 구하기

		//문자열 동적할당2
		p[i].name = (char*)malloc((tlen + 1) * sizeof(char));

		if (p[i].name == NULL) {	//동적할당 오류 검사2
			printf("Not enough Memory");	//동적할당 실패 시 종료
			return -1;
		}

		strcpy(p[i].name, tmp);	//동적할당된 문자열에 이름 저장

		p[i].sum = 0.7 * p[i].firstStage + 0.3 * p[i].interview;	//총점 구하기
	}

	for (int i = 0; i < N - 1; i++)			//구조체 배열 버블 정렬
		for (int j = 0; j < N - 1; j++)
			if (p[j].sum < p[j + 1].sum) {	//총점 내림차순 정렬
				smp = p[j];
				p[j] = p[j + 1];	//구조체 간 대입하여 교환
				p[j + 1] = smp;
			}

	for (int i = 0; i < M; i++)		//최종 합격자의 이름과 총점 출력
		printf("%s %.1f\n", p[i].name, p[i].sum);

	for (int i = 0; i < N; i++)	 //문자열 동적할당 해제2
		free(p[i].name);
	free(p);				//구조체 배열 동적할당 해제1

	return 0;
}