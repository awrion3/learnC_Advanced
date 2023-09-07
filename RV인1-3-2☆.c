#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, num, isp, cnt = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);

		isp = 1;
		for (int j = 2; j < num; j++)
			if (num % j == 0)
				isp = 0;
		if (num < 2)
			isp = 0;

		if (isp == 1) {
			printf("%d ", num);
			cnt++;
			if (i + 1 == N)
				printf("*\n");
		}
		else {
			if (cnt > 0)
				printf("*\n");
			cnt = 0;
		}
	}

	return 0;
}
//15
//11 13 17 19 71 73 74 2 3 5 58 97 89 79 45
//12
//71 73 74 2 4 6 58 97 89 79 11 37