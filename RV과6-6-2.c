#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N;

	scanf("%d", &N);

	while (N > 0 && N % 3 != 0) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - i; j++)
				printf(" ");
			for (int j = 0; j < 2 * i + 1; j++)
				if (i == 0 || i == N - 1 || j == 0 || j == 2 * i)
					printf("X");
				else
					printf("O");
			printf("\n");
		}

		scanf("%d", &N);
	}

	return 0;
}
/*
	int N;

	scanf("%d", &N);
	while (N > 1 && N % 3 != 0) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1 - i; j++)
				printf(" ");

			for (int j = 0; j < 2 * i + 1; j++)
				if (j == 0 || j == 2 * i || i + 1 == N)
					printf("X");
				else
					printf("O");

			printf("\n");
		}

		scanf("%d", &N);
	}
*/