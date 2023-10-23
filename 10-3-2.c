#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char A[101], B[101], R[251] = {0}, *p, W[100][101];
	char WB[100][101], sp[2] = " ";
	int al, bl, i = 0, k = 0, idx, dup, j = 0;
	
	gets_s(A, 100);
	gets_s(B, 100);

	//
	al = strlen(A);
	for (p = A; p <= A + al; p++)
		if (*p == ' ')
			*p = '\0';

	strcpy(W[i++], A);	//첫 단어 저장
	for (p = A; p < A + al; p++)
		if (*p == '\0') 
			strcpy(W[i++], p + 1);
	//

	idx = i;
	for (int i = 0; i < idx; i++) {			//한 단어 기준
		dup = 0;
		for (int k = 0; k < i; k++) {
			if (strcmp(W[i], W[k]) == 0) 	//이전 단어 리스트에 비교하여 중복 확인
				dup = 1;
		}
		if (dup == 1)
			W[i][0] = '*';		//해당 중복 단어 표기
	}

	//
	bl = strlen(B);
	for (p = B; p < B + bl; p++)
		if (*p == ' ')
			*p = '\0';

	k = 0;
	strcpy(WB[k++], B);	//첫 단어 저장
	for (p = B; p < B + bl; p++)
		if (*p == '\0')
			strcpy(WB[k++], p + 1);
	//

	j = 0, k = 0;
	for (int i = 0; i < idx; i++) {
		if (W[i][0] == '*') {	//중복 단어의 경우 B에서 접합
			strcat(R, WB[j++]);
			strcat(R, sp);
		}
		else {	//중복하지 않는 단어는 A에서 접합 (접합 관계없이 인덱스는 계속 이동)
			strcat(R, W[k]);
			strcat(R, sp);
		}
		k++;
	}

	printf("%s", R);

	return 0;
}
/*
red orange red yellow green red blue purple yellow
white black gray pink brown blush crimson garnet vermilion indigo 
*/