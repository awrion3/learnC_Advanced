#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void change(char*, char*, int, int);

int main(void) {

	char A[201], B[201], newA[201] = { 0 }, newB[201] = { 0 };	//길이 계산 및 널 문자 삽입
	char *p = A, *q = B;
	int N, lenA, lenB, fl = 0;

	gets_s(A, 200);
	gets_s(B, 200);
	
	N = *p > *q ? *p - *q : -(*p - *q);

	lenA = strlen(A);
	lenB = strlen(B);

	change(A, newA, lenA, N);
	change(B, newB, lenB, N);

	if (strcmp(newA, B) == 0)
		fl = 1;
	if (strcmp(A, newB) == 0)
		fl = 2;

	printf("%d", fl);

	return 0;
}

void change(char* str, char* news, int len, int N) {

	char *p, *q = news;
	int num;

	for (p = str; p < str + len; p++) {
		//아스키 코드표 순서 (대소문자 관계없이 가장 첫 문자 A부터로, 즉 대문자 내로 변경된다는 뜻)
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
}
/*
Qej15J
SchOOL
*/