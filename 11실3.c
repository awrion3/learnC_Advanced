#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N, cnt1 = 0, cnt2 = 0;
	char *p, ch1, ch2;

	scanf("%d", &N);

	p = (char*)malloc((N + 1) * sizeof(char));	//널 문자 고려

	scanf("%s", p);

	getchar();	//다음 %c 고려
	scanf("%c %c", &ch1, &ch2);

	for (int i = 0; i < N; i++) 
		if (p[i] == ch1)
			cnt1++;
	
	for (int i = 0; i < N; i++)
		if (p[i] == ch2)
			cnt2++;

	printf("%d %d", cnt1, cnt2);	//일치 문자 수 각각 출력

	free(p);

	return 0;
}
/*
5
apple
a x
*/