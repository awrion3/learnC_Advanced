#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	char ch, x[100], idx = 0;
	int M, isdup;
	char y[100], jdx = 0;
	int f = 0, al, bl, cnt = 1, max = 1, mdx;

	scanf("%c", &ch);
	while (ch != '!') {
		x[idx++] = ch;
		scanf("%c", &ch);
	}

	scanf("%d", &M); //int형 서식지정자 (자료형이 char이면 손상됨)
	
	//
	for (int i = 0; i < idx; i++) {
		isdup = 0;
		for (int j = 0; j < i; j++)
			if (x[i] == x[j])
				isdup = 1;

		if (isdup == 0)
			y[jdx++] = x[i];
	}

	for (int i = 0; i < jdx; i++)
		printf("%c", y[i]);
	printf("\n");

	//
	for (int i = 0; i < jdx; i++) {
		M %= 26;
		if (y[i] >= 'A' && y[i] <= 'Z') {
			y[i] = y[i] + M > 'Z' ? 'A' + (y[i] - 'Z' + M - 1) : y[i] + M;
			y[i] += ('a' - 'A');
		}
		else if (y[i] >= 'a' && y[i] <= 'z') {
			y[i] = y[i] + M > 'z' ? 'a' + (y[i] - 'z' + M - 1) : y[i] + M;
			y[i] -= ('a' - 'A');
		}
	}

	for (int i = 0; i < jdx; i++)
		printf("%c", y[i]);
	printf("\n");
	
	//
	for (int i = 0; i < jdx; i++) {
		if (y[i] >= 'A' && y[i] <= 'Z') {
			if (f == 0) {
				al = 1;
				f = 1;
			}
			bl = al;
			al = 1;
		}
		else if (y[i] >= 'a' && y[i] <= 'z') {
			if (f == 0) {
				al = 0;
				f = 1;
			}
			bl = al;
			al = 0;
		}
		if (al != bl) {
			cnt++;
			if (max < cnt) {
				max = cnt;
				mdx = i;
			}
		}
		else
			cnt = 1;
	}

	if (max == 1) //부분배열은 최소길이 1
		printf("none");
	else {
		for (int i = mdx - max + 1; i <= mdx; i++)
			printf("%c", y[i]);
	}

	return 0;
}
//aZaBcXyZxYzStp!
//5