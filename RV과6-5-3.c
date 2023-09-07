#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, v, ev = 0, od = 0;

	scanf("%d", &N);

	while (N != 0) {
		v = N % 10;
		if (v % 2 == 0) {
			ev *= 10;
			ev += v;
		}
		else {
			od *= 10;
			od += v;
		}
		N /= 10;
	}

	printf("%d %d", ev, od);

	return 0;
}