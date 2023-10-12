#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 표준 함수 포함

int main(void) {

	char str1[81], str2[11], *p = str1, *q = str2;	//널 문자 고려
	int len1, fl = 1;

	scanf("%s", str1);
	scanf("%s", str2); //공백을 포함하지 않는 문자열 입력

	len1 = strlen(str1);
	printf("%d ", len1);	//첫번째 문자열의 길이 출력

	for (; *p; p++)	//첫번째 문자열을 기준으로 훑으며 
		if (*p == *q) {	//두번째 문자열의 문자와 같은 경우ㅡ
			fl = 1;		//같음을 표기

			q++;		//두번째 문자열 포인터 이동//
			if (!*q)	//만약 두번째 문자열의 끝(널문자)에 도달한 경우 검사 끝내기
				break;	
		}
		else {			//두번째 문자열의 문자와 다른 경우ㅡ
			if (fl == 1)	//만약 이전까지는 같았다면,
				p--;		//다시 이전으로 되감아서 다음 검사 때 그 지점부터 다시 체크하게 하기

			fl = 0;		//다름을 표기
			q = str2;	//두번째 문자열 처음부터 비교하게끔 포인터 이동//
		}

	printf("%d", fl);	//검사 결과 출력

	return 0;
}