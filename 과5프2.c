#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	 //문자열 처리 함수 관련 헤더 파일 포함
#include <stdlib.h>	 //동적할당 관련 헤더 파일 포함

//구조체 정의
struct tel {
	char *name;		//이름
	char *tel_no;	//전화번호
	char *birth;	//생일
};
//구조체 사용자 형정의
typedef struct tel TEL;	

//함수 원형 선언
void menu(void);				    //메뉴
int reg_insert(TEL**, int, int);    //등록
void show_all(TEL**, int);			//보기
int delete_tel(TEL**, int);			//삭제
void find_by_birth(TEL**, int);		//검색

int main(void) {

	TEL **tel_list;	//이중 포인터 선언
	int max_num;	//최대 회원수 (사용자로부터 입력)
	int count = 0, N;	//카운터: 현재 연락처 개수

	//max_num 입력
	printf("Max_num:");
	scanf("%d", &max_num);

	//구조체 포인터 배열 동적할당1
	tel_list = (TEL**)malloc(max_num * sizeof(TEL*));
	if (tel_list == NULL)	//동적할당1 확인
		return -1;

	while (1) {	//종료 조건 만족 시 무한 반복 중지//	

		//메뉴 출력
		menu();

		//원하는 메뉴 선택 입력
		scanf("%d", &N);

		//종료 메뉴 선택 시 프로그램 종료
		if (N == 5)
			break;

		//해당하는 메뉴 기능을 하는 함수 호출 
		switch (N) {
		case 1:	//등록 관련 함수 호출
			count = reg_insert(tel_list, count, max_num);	//인덱스 반환
			break;
		case 2:	//보기 관련 함수 호출
			show_all(tel_list, count);
			break;
		case 3:	//삭제 관련 함수 호출
			count = delete_tel(tel_list, count);			//인덱스 반환
			break;
		case 4: //검색 관련 함수 호출
			find_by_birth(tel_list, count);
			break;
		}
	}

	//구조체 관련 동적할당 해제
	for (int i = 0; i < count; i++) {
		//구조체 내부 멤버 동적할당3 해제
		free(tel_list[i]->name); free(tel_list[i]->tel_no); free(tel_list[i]->birth);
		free(tel_list[i]); //구조체 원소 동적할당2 해제
	}
	free(tel_list);	//구조체 포인터 배열 동적할당1 해제

	return 0;	//프로그램 종료
}

//함수 정의
void menu(void) { //메뉴 출력//
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");	//유저 인터페이스 관련 출력
}

int reg_insert(TEL **p, int cnt, int max) { //등록 함수//

	TEL smp;		//구조체 관련 변수 선언
	char tmp[101];	//최대 100글자 임시 문자열
	int len;		//임시 문자열 길이 관련 변수
	
	if (cnt >= max)					//점검//
		printf("OVERFLOW\n");
	else {							//입력//
		//구조체 원소 하나당 동적할당2
		p[cnt] = (TEL*)malloc(sizeof(TEL));	
		if (p[cnt] == NULL)	//동적할당2 확인
			return -1;

		//이름 입력
		printf("Name:");
		scanf("%s", tmp);

		//문자열 동적할당3-1
		len = strlen(tmp);
		p[cnt]->name = (char*)malloc((len + 1) * sizeof(char));	
		strcpy(p[cnt]->name, tmp);		//할당된 공간에 이름 문자열 저장

		//전화번호 입력
		printf("Phone_number:");
		scanf("%s", tmp);	

		//문자열 동적할당3-2
		len = strlen(tmp);
		p[cnt]->tel_no = (char*)malloc((len + 1) * sizeof(char)); 
		strcpy(p[cnt]->tel_no, tmp);	//할당된 공간에 전화번호 문자열 저장

		//생일 문자열 입력
		printf("Birth:");
		scanf("%s", tmp);	

		//문자열 동적할당3-3
		len = strlen(tmp);
		p[cnt]->birth = (char*)malloc((len + 1) * sizeof(char)); 
		strcpy(p[cnt]->birth, tmp);	//할당된 공간에 생일 문자열 저장

		for (int i = 0; i < cnt; i++) {	//정렬//
			if (strcmp(p[i]->name, p[cnt]->name) > 0) {	//기존 이름보다 새 이름이 앞설 경우
				smp = *(p[i]);
				*(p[i]) = *(p[cnt]);			   //구조체 간 대입을 통해 삽입 위치로 이동
				*(p[cnt]) = smp;
			}
		}
	
		cnt++;	//구조체 배열 크기 조정
		
		//현재 저장된 연락처 개수 출력
		printf("<<%d>>\n", cnt);
	}

	return cnt;	//인덱스 반환
}

void show_all(TEL **p, int cnt) {	//보기 함수//

	if (cnt != 0) {		//구조체 배열 크기 0이 아닌 경우
		for (int i = 0; i < cnt; i++)	//구조체 원소의 정보 출력
			printf("%s %s %s\n", p[i]->name, p[i]->tel_no, p[i]->birth);
	}
}

int delete_tel(TEL **p, int cnt) { //삭제 함수//

	char tmp[101];		//임시 문자열
	int del = 0, idx;	//플래그 및 인덱스 관련 변수

	if (cnt == 0)					//점검//
		printf("NO MEMBER\n");
	else {							//삭제//
		printf("Name:");
		scanf("%s", tmp);				//이름 입력

		for (int i = 0; i < cnt; i++)	//이름 일치시
			if (strcmp(p[i]->name, tmp) == 0) {
				idx = i;	//해당 구조체 원소 위치 저장
				del = 1;	//일치 여부 확인
			}
	}

	if (del == 1) {			//이름 일치 존재 시
		
		//삭제 대상 관련 구조체 동적할당 해제
		free(p[idx]->name);
		free(p[idx]->tel_no);	//구조체 내부 멤버 메모리 정리
		free(p[idx]->birth);
		
		for (int i = idx; i < cnt - 1; i++)
			*(p[i]) = *(p[i + 1]);	//구조체 간 대입을 통해 해당 구조체 원소 삭제

		cnt--;	//구조체 배열 크기 변동 반영

		free(p[cnt]);			//구조체 메모리 정리
	}

	return cnt;	//인덱스 반환
}

void find_by_birth(TEL **p, int cnt) { //검색 함수//

	char bday[5], *q;	//찾으려는 생일 관련 변수
	int key, mon;		//생일 달 관련 변수

	printf("Birth:");	//입력//
	scanf("%d", &key);

	for (int i = 0; i < cnt; i++) {	//구조체 배열 접근하여
		strcpy(bday, p[i]->birth + 4);	//생일 월일 임시 문자열로 저장

		mon = 0;		//값 초기화
		for (q = bday; q < bday + 2; q++) {	//임시 문자열의 생일 월에 대하여
			mon *= 10;
			mon += *q - '0';				//정수형 값으로 변환
		}

		if (key == mon)	//찾으려는 생일 달인 경우 해당자 정보 출력
			printf("%s %s %s\n", p[i]->name, p[i]->tel_no, p[i]->birth);
	}
}