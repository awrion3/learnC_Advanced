#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 함수 포함

int main(void) {

	char ar[51], br[51], cr[101], *p, *q = cr; //cr의 경우 50 + 50 + 1널문자
	int res;

	//문자열 입력
	scanf("%s", ar);
	scanf("%s", br);

	//문자열 비교
	res = strcmp(ar, br);

	if (res < 0) {	//ar < br 사전상 br가 뒤에 있는 경우,
		strcpy(cr, br);	//사전의 역순으로 br 먼저 복사 후
		strcat(cr, ar);	//ar 접합하기
	}
	else {			//사전상 ar가 뒤에 있는 경우,
		strcpy(cr, ar);	//ar 먼저 복사 후
		strcat(cr, br);	//br 접합하기
	}

	//문자열 출력
	printf("%s\n", cr);
	
	return 0;
}