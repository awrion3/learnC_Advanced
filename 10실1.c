#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char ar[21], *p = ar; //문자열 선언 (널 문자 포함)

	scanf("%s", ar); //공백 포함하지 않는 입력

	for (; *p; p++) //문자열 원소 값이 NULL이면 반복 중지
		if (*p >= 'a' && *p <= 'z')
			printf("%c", *p);	//소문자만 출력

	return 0;
}

/*
for (int i = 0; ar[i]; i++)	//배열 형태
*/