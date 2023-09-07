#pragma warning (disable:4996)
#include <stdio.h>

int count_prime_number(int, int);
int is_prime_number(int);

int main(void) {

	int N, num, cnt = 0, max = 0, mum;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		
		cnt = count_prime_number(cnt, num);
		if (max < cnt) {
			max = cnt;
			mum = num;
		}
	}

	if (max == 0)
		printf("%d\n", max);
	else
		printf("%d\n%d", max, mum);

	return 0;
}

int count_prime_number(int cnt, int num) {

	if (is_prime_number(num) && num < 100) 
		cnt++;
	else
		cnt = 0;

	return cnt;
}

int is_prime_number(int num) {

	int isp = 1;

	for (int i = 2; i < num; i++)
		if (num % i == 0)
			isp = 0;

	if (num < 2)
		isp = 0;

	return isp;
}
//11 13 17 19 101 71 73 74 2 3 5 58 97 89 79 11 37
//32 33 34 35 36 42 44 45 46 54