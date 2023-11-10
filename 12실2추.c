#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int check_row(int**, int, int);
int check_col(int**, int, int);

int main(void) {

	int N, M, **p, x, y, z, row, col, res;

	scanf("%d %d", &M, &N);

	p = (int**)malloc(M * sizeof(int*));

	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < M; i++) {
		p[i] = (int*)malloc(N * sizeof(int));

		if (p[i] == NULL) {
			printf("Not enough memory");
			return -1;
		}
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			p[i][j] = 0;

	while (1){
		scanf("%d %d %d", &x, &y, &z);

		if (x == 0 && y == 0 && z == 0)
			break;
		else
			p[x][y] = z;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d", p[i][j]);
		printf("\n");
	}

	row = check_row(p, M, N);
	col = check_col(p, M, N);

	res = row > col ? row : col;

	printf("%d", res);

	for (int i = 0; i < N; i++)
		free(p[i]);
	free(p);

	return 0;
}

int check_row(int** p, int M, int N) {
	int cnt, max = -1;

	for (int i = 0; i < M; i++) {
		cnt = 0;
		for (int j = 0; j < N; j++)
			if (p[i][j] == 0) {
				cnt++;
				if (cnt > max)
					max = cnt;
			}
			else
				cnt = 0;
	}

	return max;
}

int check_col(int** p, int M, int N) {
	int cnt, max = -1;

	for (int i = 0; i < N; i++) {
		cnt = 0;
		for (int j = 0; j < M; j++)
			if (p[j][i] == 0){
				cnt++; 
				if (cnt > max)
					max = cnt;
			}
			else 
				cnt = 0;
	}

	return max;
}
/*
3 5
0 0 5
0 1 15
0 3 25
1 2 35
2 1 45
2 3 55
0 0 0
*/