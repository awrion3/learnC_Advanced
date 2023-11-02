#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//각 헤더 파일 포함시키기
#include <stdlib.h>

int main(void) {

	char tmp[101], **p, *qmp;
	int N, len;
	
	scanf("%d", &N);
	getchar();	//이후의 gets 고려

	//동적할당 및 확인
	p = (char**)malloc(N * sizeof(char*));	//이중 포인터 
	
	if (p == NULL) {
		printf("not enough memory!");
		return -1;
	}
	
	for (int i = 0; i < N; i++) {
		gets_s(tmp, 100);
		len = strlen(tmp);

		//동적할당 및 확인
		p[i] = (char*)malloc((len + 1) * sizeof(char));
		
		if (p[i] == NULL) {
			printf("not enough memory!");
			return -1;
		}
		
		strcpy(p[i], tmp);	//재단된 문자열 공간에 임시 문자열 저장하기
	}

	//이번엔 사전순으로 내림차순 정렬(빠른 단어 앞에 위치)
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			if (strcmp(p[j], p[j + 1]) > 0) {
				qmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = qmp;
			}

	for (int i = 0; i < N; i++)	//정렬 결과 출력
		printf("%s\n", p[i]);

	for (int i = 0; i < N; i++)	//차례대로 동적할당 해제
		free(p[i]);
	free(p);

	return 0;
}
/*
4
apricot
peach
willow
birch
*/