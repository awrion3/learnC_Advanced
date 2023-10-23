#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int check_u(char*, char*);

int main(void) {

	char tmp[101], mtr[101] = { 0 };
	int N, len, cnt, max = -1;

	scanf("%d", &N);
	getchar();       //

	for (int i = 0; i < N; i++){
		gets_s(tmp, 100);
		len = strlen(tmp);
		
		cnt = check_u(tmp, tmp + len - 1);
		if (max < cnt) {
			max = cnt;
			strcpy(mtr, tmp);
		}
	}

	printf("%s", mtr);

	return 0;
}

int check_u(char* p, char* q) {

	char *r;
	int cnt = 0;

	for (r = p; r <= q; r++) 
		if (!(*r >= 'A' && *r <= 'Z') && !(*r >= 'a' && *r <= 'z') && *r != ' ')
			cnt++;

	return cnt;
}
/*
5
1 year is 365 days.
How are you doing?
**Notice**
Winter is coming.
1+1=2
*/