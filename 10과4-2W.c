#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int check_w(char*, char*);

int main(void) {

	int N, M, max = -1, mnt[10] = { 0 }, cmp;
	char tmp[101], wlist[10][101];

	scanf("%d", &N);
	scanf("%d", &M);
	getchar();

	for (int i = 0; i < N; i++) {
		gets_s(tmp, 100);
		strcpy(wlist[i], tmp);

		mnt[i] = check_w(tmp, tmp + M);
	}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			if (mnt[j] < mnt[j + 1]) {
				cmp = mnt[j];
				mnt[j] = mnt[j + 1];
				mnt[j + 1] = cmp;

				strcpy(tmp, wlist[j]);
				strcpy(wlist[j], wlist[j + 1]);
				strcpy(wlist[j + 1], tmp);
			}
	

	for (int i = 0; i < N; i++)
		if (mnt[i] > 0)
			printf("%s\n", wlist[i]);

	return 0;
}
/*

*/
int check_w(char* p, char* q) {

	char *t = p;
	int len, cnt = 0;

	len = strlen(p);

	if (p + len >= q) {
		for (t = p; t < q; t++)
			if (!(*t >= 'A' && *t <= 'Z') && !(*t >= 'a' && *t <= 'z') && *t != ' ')
				cnt++;
	}
	else {
		for (t = p; t < p + len; t++)
			if (!(*t >= 'A' && *t <= 'Z') && !(*t >= 'a' && *t <= 'z') && *t != ' ')
				cnt++;
	}

	return cnt;
}

/*
5 15
1 year is 365 days.
How are you doing?
**Notice**
Winter is coming
1+1=2
*/