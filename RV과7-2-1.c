#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char ch, X[100], idx = 0;
	char Y[100], jdx = 0, isdup;
	int C[100] = { 0 };

	scanf("%c", &ch);
	while (ch != '!') {
		X[idx++] = ch;
		scanf("%c", &ch);
	}

	for (int i = 0; i < idx; i++){
		isdup = 0;
		for (int j = 0; j < i; j++)
			if (X[i] == X[j])
				isdup = 1;

		if (isdup == 0)
			Y[jdx++] = X[i];
	}

	for (int j = 0; j < jdx; j++)	   //중복제거한 배열 Y 기준으로
		for (int i = 0; i < idx; i++)	
			if (X[i] == Y[j])		   //배열 X의 동일 문자 개수 확인 및 저장
				++C[j];

	for (int i = 0; i < jdx; i++)
		printf("%c %d\n", Y[jdx - 1 - i], C[jdx - 1 - i]);

	return 0;
}
//ccccaaaattttbbbbccccaaaattttdddd!