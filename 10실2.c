#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int n, num;	//정수형
	char ar[10], *p = ar; //문자형 (널 문자 고려)
	
	scanf("%d", &n);	//정수 입력

	while (n != 0) {
		num = n % 10;	//한 자리씩

		if (num == 0)	//맨앞이 0이면 안된다는 조건 없으므로
			*p = '0';
		else if (num == 1)
			*p = '1';
		else if (num == 2)
			*p = '2';
		else if (num == 3)
			*p = '3';
		else if (num == 4)
			*p = '4';
		else if (num == 5)
			*p = '5';
		else if (num == 6)
			*p = '6';
		else if (num == 7)
			*p = '7';
		else if (num == 8)
			*p = '8';
		else
			*p = '9';

		p++;	//포인터 이동
		n /= 10;		//자리수 분리
	}

	*p = '\0';	//문자열임을 표기 (인덱스 증가에 유의)

	printf("%s", ar);	//문자열 출력

	return 0;
}