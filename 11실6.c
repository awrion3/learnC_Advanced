#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N, cnt = 0;
	char *p;

	scanf("%d", &N);

	p = (char*)malloc((N + 1) * sizeof(char));	//널 문자 포함

	scanf("%s", p);

	for (int i = 1; i < N - 1; i++) 
		if (p[i - 1] == 'c' && p[i] == 'a' && p[i + 1] == 't')	//cat 단어 포함 횟수 확인
			cnt++;
	
	printf("%d", cnt);

	free(p);	//동적할당 해제

	return 0;
}
/*
7
catbcat
*/