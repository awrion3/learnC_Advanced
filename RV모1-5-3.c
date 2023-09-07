#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N, num, isp, cnt = 0, max = 0, lnum;
	int fl = 0, big, sml;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);

		//
		if (num < 2 || num >= 100)
			isp = 0;
		else
			isp = 1;

		for (int j = 2; j < num; j++)
			if (num % j == 0)
				isp = 0;
		//
		if (isp == 1) {
			cnt++;
			if (max < cnt) {
				max = cnt;
				lnum = num;
			}
		}
		else
			cnt = 0;
		//
		if (fl == 0) {
			big = num;
			sml = num;
			fl = 1;
		}
		else {
			if (big < num)
				big = num;
			if (sml > num)
				sml = num;
		}
	}
	//Ãâ·Â
	if (max == 0) {
		printf("%d", max);
	}
	else {
		printf("%d\n%d\n", max, lnum);
		printf("%d %d", big, sml);
	}
	
	return 0;
}
//15
//11 13 17 19 71 73 74 2 3 5 -58 97 89 79 -47