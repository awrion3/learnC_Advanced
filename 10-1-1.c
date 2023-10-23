#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char str[201], *p, news[201] = { 0 }, *q = news;	//길이 계산 및 널 문자 삽입
	int N, len, num;

	scanf("%s", str);
	scanf("%d", &N);

	len = strlen(str);

	for (p = str; p < str + len; p++) {
		//아스키 코드표 순서 (대소문자 관계없이 가장 첫 문자 A부터로 생각한다)
		if (*p >= 'A' && *p <= 'Z') {	
			*q = *p + N > 'Z' ? 'A' + (*p + N - 'Z' - 1) : *p + N;
			q++;
		}
		else if (*p >= 'a' && *p <= 'z') {
			*q = *p - N < 'A' ? 'Z' + (*p - N - 'A' + 1) : *p - N;
			q++;
		}
		else if (*p >= '1' && *p <= '9') {
			if (*(p + 1) >= '0' && *(p + 1) < '7') {
				num = *p - '0';	//문자이므로 atoi 사용 불가
				num *= 10;
				num += *(p + 1) - '0';
				p++; //포인터 추가 이동 유의
			}
			else
				num = *p - '0';

			for (int i = 0; i < N; i++, q++)	//포인터 이동 유의
				*q = 'A' + num - 1;	//0번째가 아닌 1번째 문자는 A임
		}
		else {
			*q = ' ';
			q++;
		}
	}
	strcpy(str, news);

	printf("%s", str);

	return 0;
}
/*
CLikp5tGLE?Qej15J
2
*/