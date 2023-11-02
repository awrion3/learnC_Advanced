#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int N, len, min = 101;
	char **p, tmp[101], *q = NULL;

	scanf("%d", &N);
	getchar();	//gets 고려

	p = (char**)malloc(N * sizeof(char*));	//이중 포인터 사용
	
	if (p == NULL) {	//동적할당 및 확인
		printf("Not enough Memory");
		return -1;
	}

	for (int i = 0; i < N; i++){
		gets_s(tmp, 100);	
		len = strlen(tmp);	//임시 문자열 길이 재기

		p[i] = (char*)malloc((len + 1) * sizeof(char));	//널 문자 포함해서 맞추어 재단

		if (p[i] == NULL) {	//동적할당 및 확인
			printf("Not enough Memory");
			return -1;
		}

		strcpy(p[i], tmp);	//재단한 문자열에 저장

		if (len < min) {	//최소 길이 문자열 구하기
			min = len;
			q = p[i];
		}
	}

	printf("%s", q);	//최소 길이 문자열 출력

	for (int i = 0; i < N; i++)	//차례대로 동적할당 해제
		free(p[i]);
	free(p);

	return 0;
}
/*
4
Program
Good
This is string
language
*/