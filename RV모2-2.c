#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char ch, x[100], y[100], idx = 0, jdx = 0, xfir = 0;

	//
	scanf("%c", &ch);
	while (ch != '*') {
		x[idx++] = ch;
		scanf("%c", &ch);
	}

	scanf("%c", &ch);
	while (ch != '*') {
		y[jdx++] = ch;
		scanf("%c", &ch);
	}

	//
	for (int i = 0, j = 0; i < idx && j < jdx; i++, j++)
		if (x[i] < y[j]) {
			xfir = 1;
			break;
		}
		else if (x[i] > y[j]) {
			xfir = 0;
			break;
		}
		else {
			if (idx < jdx)
				xfir = 1;
			else
				xfir = 0;
		}

	//
	if (xfir == 0) {
		for (int i = 0; i < jdx; i++)
			printf("%c", y[i]);
	}
	else {
		for (int i = 0; i < idx; i++)
			printf("%c", x[i]);
	}

	return 0;
}