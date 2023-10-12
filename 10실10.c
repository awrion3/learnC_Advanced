#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 표준 함수 포함

int main(void) {

	int N, len, min, fl = 0;
	char ar[101], mn[101];	//문자열 선언 (널 문자 고려)

	scanf("%d", &N);
	getchar();	//아래 gets 고려하여 필요(여기 엔터키부터 포함시킨 후, 다음 엔터키 입력 전까지 저장해버림)//

	for (int i = 0; i < N; i++) {
		gets_s(ar, 100); //gcc에서는 gets(ar);를 쓰도록 한다//
		//공백을 포함하는 문자열 == 문자열 입출력 표준 함수 == <stdio.h>
		
		len = strlen(ar);
		
		if (fl == 0) {	//처음 초기화
			min = len;
			strcpy(mn, ar);
			fl = 1;
		}
		else if (min > len){ //이후 min 갱신 및 배열 저장 갱신
			min = len;
			strcpy(mn, ar);
		}
	}

	//최소 길이의 문자열 출력
	printf("%s", mn);

	return 0;
}