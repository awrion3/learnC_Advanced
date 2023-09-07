#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N;
	char year;

	scanf("%d", &N);

	year = N % 4 == 0 && N % 100 != 0 || N % 400 == 0 ? 'L' : 'C';

	printf("%c", year);

	return 0;
}