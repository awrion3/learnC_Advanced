#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N, cnt1 = 0, cnt2 = 0;
	char *p, ch1, ch2;

	scanf("%d", &N);

	p = (char*)malloc((N + 1) * sizeof(char));	//�� ���� ���

	scanf("%s", p);

	getchar();	//���� %c ���
	scanf("%c %c", &ch1, &ch2);

	for (int i = 0; i < N; i++) 
		if (p[i] == ch1)
			cnt1++;
	
	for (int i = 0; i < N; i++)
		if (p[i] == ch2)
			cnt2++;

	printf("%d %d", cnt1, cnt2);	//��ġ ���� �� ���� ���

	free(p);

	return 0;
}
/*
5
apple
a x
*/