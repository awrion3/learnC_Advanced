#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char ar[201], wd[20][200], *p, tm[200];
	char nw[200], str[201] = { 0 }, sp[2] = " ";	//널 문자 초기화
	int n, i = 0, idx, is = 0;

	gets_s(ar, 200);
	scanf("%s", nw);	//단어 입력

	n = strlen(ar);

	//이차원 배열 생성
	for (p = ar; p < ar + n; p++)
		if (*p == ' ')
			*p = '\0';

	p = ar;
	strcpy(wd[i], p);	//첫 단어 저장
	for (p = ar; p <= ar + n; p++) {	//널 문자까지 훑기
		if (*p == '\0') {
			i++;
			strcpy(wd[i], p + 1);
		}
	}

	//이차원 배열과 단어 비교
	idx = i;
	for (int i = 0; i < idx; i++) 
		if (strcmp(wd[i], nw) == 0) {
			is = 1;
			break;
		}
	
	//이차원 배열에 단어 추가
	if (is == 0) {
		strcpy(wd[i], nw);
		i++;	//인덱스 조정 및 갱신
		idx = i;
	}

	//단어별 출력
	for (int i = 0; i < idx; i++)
		printf("%s\n", wd[i]);

	//정렬
	for (int i = 0; i < idx - 1; i++)
		for (int j = 0; j < idx - 1; j++)	//버블 정렬
			if (strcmp(wd[j], wd[j + 1]) > 0) {	//이차원 배열 오름차순 정렬
				strcpy(tm, wd[j]);
				strcpy(wd[j], wd[j + 1]);
				strcpy(wd[j + 1], tm);
			}

	//정렬후 결합
	for (int i = 0; i < idx; i++) {
		strcat(str, wd[i]);
		strcat(str, sp);
	}

	printf("%s", str);

	return 0;
}
/*
ant apple ace ape
arch

bag bat back bean box
back
*/