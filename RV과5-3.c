#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char ch;
	int M;

	scanf("%c", &ch);
	scanf("%d", &M); //자료형 서식지정자 일치에 유의
	//char와 int는 같은 정수형이나, double과의 계산에는 유의해야.
	//기본적으로 int 이하의 변수 타입은 연산시 int로 자동변환
	//따라서 서식지정자 말고, 자료형 char에 다시 char와 int의 계산값을 대입할 시, (char) 필요하게 됨.

	M %= 26;

	//..넘어가서 'A'부터 시작, +M할 때, 이전-'Z' 간격-1을 고려
	if (ch >= 'A' && ch <= 'Z')
		ch = ch + M > 'Z' ? 'A' + (ch - 'Z' + M - 1) : ch + M;
	else if (ch >= 'a' && ch <= 'z') 
		ch = ch + M > 'z' ? 'a' + (ch - 'z' + M - 1) : ch + M;
	else
		ch;

	printf("%c", ch);

	return 0;
}