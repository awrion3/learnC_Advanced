#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	 //문자열 처리 함수 관련 헤더 파일 포함
#define MAX_NUM 100  //전처리기에서 배울 내용 (상수값 선언)

//구조체 정의
struct tel {
	char name[21];		//이름 20 bytes
	char tel_no[16];	//전화번호 15 bytes
	char birth[9];		//생일 8 bytes
};

//함수 원형 선언
void menu(void);					  //메뉴
int reg_insert(struct tel *, int);	   //등록
void show_all(struct tel *, int);      //보기
int delete_tel(struct tel *, int);     //삭제
void find_by_birth(struct tel *, int); //검색

int main(void) {

	struct tel tel_list[MAX_NUM] = {0}, *p = tel_list;   //구조체 배열: 최대 100개 가능
	int count = 0, N;	//카운터: 현재 저장되어 있는 연락처 개수

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
			count = reg_insert(p, count);	//인덱스 반환
			break;	
		case 2:	//보기 관련 함수 호출
			show_all(p, count);
			break;
		case 3:	//삭제 관련 함수 호출
			count = delete_tel(p, count);	//인덱스 반환
			break;
		case 4: //검색 관련 함수 호출
			find_by_birth(p, count);
			break;
		}
	}

	return 0;	//프로그램 종료
}

//함수 정의
void menu(void) { //메뉴 출력//
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");	//유저 인터페이스 관련 출력
}

int reg_insert(struct tel *p, int cnt) { //등록 함수//
	
	struct tel *t = p + cnt, *q, smp;	//구조체 관련 변수 선언
	
	if (cnt >= MAX_NUM)					//점검//
		printf("OVERFLOW\n");
	else {								//입력//
		printf("Name:");
		scanf("%s", t->name);		//이름
		printf("Phone_number:");
		scanf("%s", t->tel_no);		//전화번호
		printf("Birth:");
		scanf("%s", t->birth);		//생일 문자열 입력

		for (q = p; q < p + cnt; q++)	//정렬//
			if (strcmp(q->name, t->name) > 0) {	//기존 이름보다 새 이름이 앞설 경우
				smp = *q;	
				*q = *t;				//구조체 간 대입을 통해 삽입 위치로 이동
				*t = smp;
			}

		cnt++;	//구조체 배열 크기 조정

		//현재 저장된 연락처 개수 출력
		printf("<<%d>>\n", cnt);	
	}

	return cnt;	//인덱스 반환
}

void show_all(struct tel *p, int cnt) {	//보기 함수//
	
	struct tel *t;		//구조체 관련 변수 선언

	if (cnt != 0) {		//구조체 배열 크기 0이 아닌 경우
		for (t = p; t < p + cnt; t++)	//구조체 원소의 정보 출력
			printf("%s %s %s\n", t->name, t->tel_no, t->birth);
	}
}

int delete_tel(struct tel *p, int cnt) { //삭제 함수//

	struct tel *t, *q = NULL;	//구조체 관련 변수 선언
	char tmp[21];	//임시 문자열
	int del = 0;	//플래그 관련 변수

	if (cnt == 0)					//점검//
		printf("NO MEMBER\n");
	else {							//삭제//
		printf("Name:");
		scanf("%s", tmp);				//이름 입력
		
		for (t = p; t < p + cnt; t++)	//이름 일치시
			if (strcmp(t->name, tmp) == 0){
				q = t;		//해당 구조체 원소 위치 저장
				del = 1;	//일치 여부 확인
			}
	}

	if (del == 1) {			//이름 일치 존재 시
		for (t = q; t < p + cnt; t++) 	
			*t = *(t + 1);	//해당 구조체 원소 삭제

		cnt--;	//구조체 배열 크기 변동 반영
	}

	return cnt;	//인덱스 반환
}

void find_by_birth(struct tel *p, int cnt) { //검색 함수//

	struct tel *t;		//구조체 관련 변수 선언
	char bday[5], *q;	//찾으려는 생일 관련 변수
	int key, mon;		//생일 달 관련 변수

	printf("Birth:");	//입력//
	scanf("%d", &key);

	for (t = p; t < p + cnt; t++) {	//구조체 배열 접근하여
		strcpy(bday, t->birth + 4);	//생일 월일 임시 문자열로 저장
		
		mon = 0;		//값 초기화
		for (q = bday; q < bday + 2; q++){	//임시 문자열의 생일 월에 대하여
			mon *= 10;
			mon += *q - '0';				//정수형 값으로 변환
		}

		if (key == mon)	//찾으려는 생일 달인 경우 해당자 정보 출력
			printf("%s %s %s\n", t->name, t->tel_no, t->birth);
	}
}