#include "my_func.h"

int main(void) {

	FILE* fp; 		//파일 구조체 포인터 선언
	TEL** tel_list;	//이중 포인터 선언
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
		if (N == 6) {
			fp = fopen("PHONE_BOOK.txt", "w");	//쓰기 모드로 파일 열기
			if (fp == NULL)	//파일 열기 확인
				return -1;

			for (int i = 0; i < count; i++)	//파일로 구조체 포인터 배열에 저장된 데이터를 출력
				fprintf(fp, "%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth);

			fclose(fp);	//파일 닫기
			break;
		}

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
		case 5:	//파일 관련 함수 호출
			count = reg_from_file(tel_list, count, max_num);//인덱스 반환
		}
	}

	//구조체 관련 동적할당 해제
	for (int i = 0; i < count; i++) {
		//구조체 내부 멤버 동적할당3 해제
		free(tel_list[i]->name); free(tel_list[i]->tel_no); free(tel_list[i]->birth);
		free(tel_list[i]); //구조체 원소 동적할당2 해제
	}
	free(tel_list);	//구조체 포인터 배열 동적할당1 해제

	return 0;
}