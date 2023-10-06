#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>			//문자열 처리 함수 포함

//함수 선언
void StringAdd(char [], char, int);	
int Convertor(char);				

int main(void) {

	char str[20], *p = str, ch;	//널 문자 포함1 + 최대 입력8 + 최대 삽입7 = 16
	int len, even = 0, fl = -1;

	scanf("%s", str);	//공백 미포함 문자열 입력
	len = strlen(str);	//문자열 길이 구하기

	for (int i = 0; i < len; i++) {		//널 문자 전까지 훑어
		if (Convertor(*(p + i)) % 2 == 0) {	//변환된 문자가 짝수인 경우
			even = 1;	//짝수임을 표기
			ch = '*';	//삽입 특수문자 지정

			if (fl == even) {	//이전에도 짝수였다면
				StringAdd(str, ch, i);	//연속되는 경우에 함수 호출하여 삽입 문자 사이에 추가
				i++;	//문자 삽입으로 인한 배열 인덱스 +1	
				len++;	//문자열 길이도 +1
			}
			fl = even;	//이전 표기 저장
		}
		else {								//변환된 문자가 홀수인 경우
			even = 0;	//홀수임을 표기
			ch = '+';	//삽입 특수문자 지정

			if (fl == even) {	//이전에도 홀수였다면
				StringAdd(str, ch, i);	//연속되는 경우에 함수 호출하여 삽입 문자 사이에 추가
				i++;	//문자 삽입으로 인한 배열 인덱스 +1	
				len++;	//문자열 길이도 +1
			}
			fl = even;	//이전 표기 저장
		}
	}

	printf("%s", str);	//삽입 추가된 문자열 출력

	return 0;
}

//함수 정의
void StringAdd(char arr[], char ch, int index) {

	char *p;	//지역변수 선언
	int len;

	len = strlen(arr);	//문자열 길이 구하기

	for (p = arr + len; p >= arr + index; p--)	//배열의 널문자부터 접근하여 인덱스까지 훑어
		*(p + 1) = *p;	//한칸씩 뒤로 이동시키기

	p = arr + index;	//해당 배열의 인덱스 위치에 
	*p = ch;			//해당 특수문자 삽입
}

int Convertor(char x) {

	int n = 0;	//지역변수 선언 및 초기화

	n = x - '0';	//문자를 숫자로 변환(문자는 모두 한자리 양의 정수 == 1 ~ 9 사이 )

	return n;	//변환된 숫자 반환
}
/*
132456
33332222
*/