#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 표준 함수 포함

int main(void) {

	char str1[101], str2[101], *p = str1, *q = str2; //널 문자 고려
	int fl, cnt = 0;

	gets_s(str1, 100);	//공백 포함 //gcc에서는 gets(str1);를 쓰도록 한다//
	scanf("%s", str2);  //공백 등등 포함하지 않는 문자열 입력 //따라서 이전에 getchar();쓰지 않아도 된다//

	for (; *p; p++) {	//str1을 훑으며
		if (*p == *q) {	//str2에 같은 문자 있으면
			fl = 1;		//같은 문자 있음을 표기
			q++;	//str2 포인터 이동 (즉 다음 계산에 포함시키지 않음)

			if (!*q){	//str2 끝인 경우
				cnt++;	//횟수 계산 카운트//
				q = str2;	//str2 포인터 다시 처음으로 이동
			}
		}
		else {			//str2에 같은 문자 없으면
			if (fl == 1)	//이전까지 같은 문자였으면
				p--;		//포인터 이동 되감아서 다음번부터 그 지점에서 비교하게 하기

			fl = 0;		 //같은 문자 없음을 표기
			q = str2;	 //str2를 다시 처음부터 비교하게 포인터 이동
		}
	}

	printf("%d", cnt);	//횟수 출력하기

	return 0;
}