#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, M, cnt = 0, max = 0, num;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		printf("%d:", M);

		for (int i = 1; i <= M; i++)
			if (M % i == 0) {
				printf(" %d", i);
				cnt++;
			}
		printf(" %d\n", cnt);

		if (max < cnt) {
			max = cnt;
			num = M;
		}
		cnt = 0;
	}
	printf("%d", num);

	return 0;
}