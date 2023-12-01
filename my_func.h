#ifndef __MY_FUNC_H__
#define __MY_FUNC_H__ //정의되어 있지않으면 컴파일

//전처리기 
#pragma warning(disable:4996)

//컴파일러 헤더파일
#include <stdio.h>
#include <stdlib.h> //동적할당 관련
#include <string.h> //문자열 처리 관련

//사용자 헤더파일
#include "my_struct.h"	//구조체 정의 관련
#include "my_define.h"	//사용자 형정의 관련

//함수 원형 선언
void menu(void);				    //메뉴
int reg_insert(TEL**, int, int);    //등록
void show_all(TEL**, int);			//보기
int delete_tel(TEL**, int);			//삭제
void find_by_birth(TEL**, int);		//검색
int reg_from_file(TEL**, int, int);	//파일

#endif