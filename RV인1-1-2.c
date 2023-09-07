#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, num, TN, TH, H, T, O;
	int CE = 0, SW = 0, DS = 0;
	int fl = 1, cce = 0, csw = 0, cds = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);

		TN = num / 10000;
		TH = num / 1000 % 10;
		H = num / 100 % 10;
		T = num / 10 % 10;
		O = num % 10;

		if (!(num >= 10000 && num <= 99999)) {
			printf("none\n");
			fl = 0;
		}
		else if (!(T == 0 && O == 0)) {
			printf("none\n");
			fl = 0;
		}
		else if (TN == TH && TH == H || TN != TH && TH != H && TN != H) {
			printf("none\n");
			fl = 0;
		}
		else {
			if (H == 0 || H == 1 || H == 2) {
				if (fl == 1)
					++cce;
				printf("CE\n");
				++CE;
				fl = 1;
			}
			else if (H == 3 || H == 4) {
				if (fl == 1)
					++csw;
				printf("SW\n");
				++SW;
				fl = 1;
			}
			else if (H == 5) {
				if (fl == 1)
					++cds;
				printf("DS\n");
				++DS;
				fl = 1;
			}
			else {
				printf("none\n");
				fl = 0;
			}
		}
	}

	printf("%d %d %d\n", CE, SW, DS);
	printf("%d %d %d\n", cce, csw, cds);

	return 0;
}
//14
//11300 20000 310100 10100 21200 11600 11510 10200 33400 75500 1100 33300 112300 11400