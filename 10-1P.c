#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	int N, idx[10], cnt = 1, order[10];
	char wlist[10][101], wstr[1200] = { 0 }, sp[2] = " ";

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s", wlist[i]);
		idx[i] = cnt++;
	}

	for (int i = 0; i < N; i++)
		scanf("%d", &order[i]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (order[i] == idx[j]) {
				strcat(wstr, wlist[j]);
				strcat(wstr, sp);
			}
	}

	printf("%s", wstr);

	return 0;
}
/*
3
white
black
and
2 3 1
*/