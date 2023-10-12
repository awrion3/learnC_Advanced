#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int len = 0, fl = 1;
	char ar[101], br[101], *p = ar, *q = br;  //널 문자 고려

	scanf("%s", ar);	//문자열 입력(공백, 엔터 제외)
	scanf("%s", br);	//문자열 입력

	for (; *p; p++)
		len++;	//첫번째 문자열 길이 계산

	printf("%d ", len);

	for (p = ar; *p; p++, q++) 
		if (*p != *q) {
			fl = 0;	//같지 않으면 표기하고 반복 중지
			break;
		}

	printf("%d", fl); //일치 여부 출력

	return 0;
}