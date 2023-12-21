#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st {
	char* str;
	int cnt1;
	int cnt2;
	int num;
	int pos;
	int result;
};

int main(void) {

	struct st *p, smp;
	int N, len, idx;
	char tmp[101], *t;

	scanf("%d", &N);

	p = (struct st*)malloc(N * sizeof(struct st));
	if (p == NULL)
		return -1;

	for (int i = 0; i < N; i++){
		scanf("%s", tmp);

		len = strlen(tmp);

		p[i].str = (char*)malloc((len + 1) * sizeof(char));
		if (p[i].str == NULL)
			return -1;

		strcpy(p[i].str, tmp);

		p[i].cnt1 = 0, idx = 1;
		for (t = tmp; t < tmp + len; t++, idx++) {
			if (*t >= '0' && *t <= '9'){		
				p[i].num = *t - '0';
				p[i].pos = idx;
			}
			else if (*t != 'A' && *t != 'E' && *t != 'I' && *t != 'O' && *t != 'U'
				&& *t != 'a' && *t != 'e' && *t != 'i' && *t != 'o' && *t != 'u')
				p[i].cnt1++;

		}
		p[i].cnt2 = len;

		p[i].result = p[i].cnt1 * p[i].cnt2 * p[i].num * p[i].pos;
	}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			if (p[j].result < p[j + 1].result) {
				smp = p[j];
				p[j] = p[j + 1]; //구조체 간 대입	
				p[j + 1] = smp;
			}

	for (int i = 0; i < N; i++)
		printf("%s\n", p[i].str);

	for (int i = 0; i < N; i++)
		free(p[i].str);
	free(p);

	return 0;
}