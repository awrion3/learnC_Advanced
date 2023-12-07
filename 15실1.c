#pragma warning(disable:4996)
#include <stdio.h>
#define ABS(a) ((a) > 0 ? (a) : -(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(void) {

	int num, mum = 0, aum = 0;

	for (int i = 0; i < 6; i++){
		scanf("%d", &num);
		mum = MAX(mum, ABS(num));
		aum = mum == ABS(num) ? num : aum;
	}

	printf("%d %d", aum, mum);

	return 0;
}