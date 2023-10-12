#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 함수 포함

//함수 선언
int check(char*);

int main(void) {

	char str[31], *p = str;	//널 문자 포함
	int len, res;

	scanf("%s", str);	//문자열 입력

	len = strlen(str);
	printf("%d ", len);	//길이 출력

	res = check(str);
	printf("%d", res);  //회문 판단 결과 출력

	return 0;
}

//함수 정의
int check(char *str) {

	char *p = str, rst[31], *q = rst;
	int len, res;

	len = strlen(str); //길이 측정

	for (p = str + len - 1; p >= str; p--, q++)
		*q = *p;	//뒤집은 rst 생성
	*q = '\0';		//널 문자 추가(인덱스 유의)

	res = strcmp(str, rst);	//대소문자까지 비교함

	if (res == 0)	//뒤집어도 같은 경우에만 1 반환
		return 1;
	return 0;		//그외 항상 0 반환
}
/*
Hello

aibohpphobia
*/