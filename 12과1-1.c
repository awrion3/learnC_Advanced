#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 관련 함수 포함
#include <stdlib.h>	//동적할당 관련 함수 포함

//구조체 정의
struct st {
	char *str;	//문자열 저장
	int cnt1;	//자음 수 저장
	int cnt2;	//총 문자 수 저장
};

int main(void) {

	int N, len;			//정수형 변수 선언
	char tmp[101], *q;	//문자형 변수 선언 (널 문자 포함)
	struct st *sp, smp;	//구조체 포인터 및 변수 선언

	scanf("%d", &N);	//정수 N 입력

	sp = (struct st*)malloc(N * sizeof(struct st));	//구조체 배열 동적할당

	if (sp == NULL) {					//동적할당 검사1
		printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
		return -1;
	}
		
	for (int i = 0; i < N; i++) {	//N개의 문자열 입력
		scanf("%s", tmp);	//공백 포함하지 않은 문자열 입력

		len = strlen(tmp);	//문자열 길이 확인

		sp[i].str = (char*)malloc((len + 1) * sizeof(char));	//구조체 멤버 문자열 동적할당 (널 문자 포함)

		if (sp[i].str == NULL) {			//동적할당 검사2
			printf("Not enough memory");	//메모리 공간 확보 실패 시 종료
			return -1;
		}

		strcpy(sp[i].str, tmp);		//동적할당된 구조체 멤버 문자열에 저장

		sp[i].cnt1 = 0, sp[i].cnt2 = 0;		//누적값 초기화
		for (q = sp[i].str; q < sp[i].str + len; q++) {		//해당 문자열 포인터로 접근하여
			//대문자 및 소음자 모음이 아닌 경우,
			if (*q != 'A' && *q != 'E' && *q != 'I' && *q != 'O' && *q != 'U'
				&& *q != 'a' && *q != 'e' && *q != 'i' && *q != 'o' && *q != 'u')
				sp[i].cnt1++;	//자음의 수 세기
			
			sp[i].cnt2++;		//총 문자 수 저장
		}
	}

	for (int i = 0; i < N - 1; i++)			//구조체 배열 버블 정렬 사용
		for (int j = 0; j < N - 1; j++)
			if (sp[j].cnt1 <= sp[j + 1].cnt1) {		//자음의 수부터 확인하여
				if (sp[j].cnt1 < sp[j + 1].cnt1) {	//후자가 많은 경우 내림차순 정렬
					smp = sp[j];
					sp[j] = sp[j + 1];		//구조체 간 대입을 통해 교환
					sp[j + 1] = smp;
				}
				else {	//자음의 수가 같은 경우, 총 문자의 수를 확인하여
					if (sp[j].cnt2 < sp[j + 1].cnt2) {	//후자가 많은 경우 내림차순 정렬
						smp = sp[j];
						sp[j] = sp[j + 1];	//구조체 간 대입을 통해 교환
						sp[j + 1] = smp;
					}
				}
			}

	for (int i = 0; i < N; i++)	//정렬된 구조체의 멤버 문자열 출력
		printf("%s\n", sp[i].str);	

	for (int i = 0; i < N; i++)	//구조체 멤버 문자열 동적할당 각각 해제
		free(sp[i].str);
	free(sp);					//구조체 배열 동적할당 해제

	return 0;
}
/*
5
History
Politics
DonQuixote
LaPeste
Chaos
*/