#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char ar[101], *p = ar, *q = ar, tmp; //널 문자 고려
	int len = 0;

	scanf("%s", ar);	//문자열 입력

	for (; *p; p++)
		len++;	//길이 측정 (널 문자 제외)

	for (int i = 0; i < len; i++) {	//문자열 길이만큼 반복
		printf("%s\n", ar);

		tmp = *q;	//맨앞 칸의 문자 저장
		for (p = ar; p < ar + len - 1; p++)	//두번째 칸부터 한칸씩 앞으로 당기기
			*p = *(p + 1);	//+1이므로 위에서 -1하여 인덱스 조정
		p = ar + len - 1;	 //마지막 칸으로 연결 후
		*p = tmp;			 //tmp에 저장된 맨앞 칸의 문자 대입
	}
	
	return 0;
}