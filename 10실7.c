#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N, V = 0, cnt = 0, num;
	char ar[50], *par = ar, *pstr = NULL, *q;
	//널 문자1 + 최대 공백6 + 최대 자리수 표기9 + 최대 숫자 표기20 보다 크게 설정
	
	scanf("%d", &N);	//정수 입력

	while (N != 0) {
		V *= 10;	//수 뒤집기
		V += (N % 10); //한자리씩 더하기

		cnt++;		//전체 자리수 계산
		N /= 10;
	}

	while (V != 0) {
		num = V % 10;	//한 자리씩 검사

		if (num == 1) 		
			pstr = "one ";
		else if (num == 2)
			pstr = "two ";
		else if (num == 3)
			pstr = "three ";
		else if (num == 4)
			pstr = "four ";
		else if (num == 5)
			pstr = "five ";
		else if (num == 6)
			pstr = "six ";
		else if (num == 7)
			pstr = "seven ";
		else if (num == 8)
			pstr = "eight ";
		else if (num == 9)
			pstr = "nine ";
		else
			pstr = ""; //0은 숫자 출력하지 않음

		for (q = pstr; *q; q++, par++)  //par를 이어받아 붙여넣기
			*par = *q;
		
		if (num != 0) {	//0인 경우 자리수 표기도 안함에 유의//
			if (cnt == 4)
				pstr = "THO ";
			else if (cnt == 3)
				pstr = "HUN ";
			else if (cnt == 2)
				pstr = "TEN ";
			else
				pstr = "";	//일의 자리에는 아무것도 붙이지 않음
		}					//(이 초기화를 거쳐야 아래서 마지막 자리수가 한번더 붙는 일이 없어짐)
	
		for (q = pstr; *q; q++, par++)	//par를 이어받아 붙여넣기
			*par = *q;

		V /= 10;		//자리수 떼기
		cnt--;	//카운터 감소
	}

	*par = '\0';	//(붙여넣기 할 때 항상 널 문자는 제외였으므로)널 문자 추가 (인덱스 증가 고려)
	printf("%s", ar);

	return 0;
}