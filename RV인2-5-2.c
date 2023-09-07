#pragma warning (disable:4996)
#include <stdio.h>

int reverse_num(int);
int is_palindromic(int);
int del_digit(int, int);

int main(void) {

	int N, T;
	scanf("%d%d", &N, &T);

	printf("%d ", N);
	printf("%d ", reverse_num(N));
	printf("%d ", is_palindromic(N));
	printf("%d", del_digit(N, T));

	return 0;
}

int reverse_num(int N) {

	int v = 0;

	while (N != 0) {
		v *= 10;
		v += N % 10;
		N /= 10;
	}

	return v;
}

int is_palindromic(int N) {

	return (N == reverse_num(N));
}

int del_digit(int N, int T) {

	int num = N, x[9], idx = 0, r[9], val = 0;
	T--; //인덱스로 조정

	while (num != 0) {
		x[idx++] = num % 10;
		num /= 10;
	}

	if (is_palindromic(N)) {
		if (idx > T) {
			for (int i = T; i < idx; i++)
				x[i] = x[i + 1];
			idx--;
		}
		
		for (int i = 0; i < idx; i++)
			r[i] = x[idx - 1 - i];

		if (idx > T) {	//뒤집었으므로 T값 변동 필요 없음
			for (int i = T; i < idx; i++)
				r[i] = r[i + 1];
			idx--;
		}

		for (int i = 0; i < idx; i++) {
			val *= 10;
			val += r[i];
		}
	}
	else {
		if (idx > T) {
			for (int i = T; i < idx; i++)
				x[i] = x[i + 1];
			idx--;
		}

		for (int i = 0; i < idx; i++) //뒤집기
			r[i] = x[idx - 1 - i];

		for (int i = 0; i < idx; i++) {
			val *= 10;
			val += r[i];
		}
	}

	return val;
}
