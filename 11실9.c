#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int N, len;
	char **p, tmp[101], *qmp;

	scanf("%d", &N);
	getchar();

	p = (char**)malloc(N * sizeof(char*));

	if (p == NULL) {
		printf("Not enough Memory");
		return -1;
	}

	for (int i = 0; i < N; i++) {
		gets_s(tmp, 100);
		len = strlen(tmp);

		p[i] = (char*)malloc((len + 1) * sizeof(char));
		
		if (p[i] == NULL) {
			printf("Not enough Memory");
			return -1;
		}

		strcpy(p[i], tmp);
	}

	for (int i = 0; i < N - 1; i++)	//이번에는 문자열 간 정렬
		for (int j = 0; j < N - 1; j++)
			if (strlen(p[j]) < strlen(p[j + 1])) {	//오름차순 정렬(긴 문자열 앞에 위치)
				qmp = p[j];
				p[j] = p[j + 1];	//문자열들 공간은 모두 재단되었기에, strcpy()가 아닌,
				p[j + 1] = qmp;		//가리키는 포인터만 교환해야 한다
			}

	for (int i = 0; i < N; i++)	//정렬된 문자열들 출력
		printf("%s\n", p[i]);

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