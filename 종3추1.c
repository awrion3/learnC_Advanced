#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int N, len, cnt, dup;
	char **p, tmp[101];

	scanf("%d", &N);

	p = (char**)malloc(N * sizeof(char*));
	
	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++) {
		scanf("%s", tmp);
		len = strlen(tmp);

		p[i] = (char*)malloc((len + 1) * sizeof(char));

		if (p[i] == NULL) {
			printf("Not enough memory");
			return -1;
		}

		strcpy(p[i], tmp);
	}

	for (int i = 0; i < N; i++){
		cnt = 0;
		for (int j = 0; j < N; j++)
			if (strcmp(p[i], p[j]) == 0)
				cnt++;

		dup = 0;
		for (int k = 0; k < i; k++)
			if (strcmp(p[i], p[k]) == 0)
				dup = 1;

		if (cnt > 1 && dup == 0)
			printf("%s %d\n", p[i], cnt);
	}

	for (int i = 0; i < N; i++)
		free(p[i]);
	free(p);

	return 0;
}
/*
6
lion
cat
tiger
lion
cat
lion
*/