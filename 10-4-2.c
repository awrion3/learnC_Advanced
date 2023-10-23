#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int check_w(char*, char*);

int main(void) {

	char tmp[101], snt[10] = { 0 }, lis[10][101] = { 0 };
	int N, M, max = -1, cmp;
	
	scanf("%d %d", &N, &M);
	getchar();

	for (int i = 0; i < N; i++) {
		gets_s(tmp, 100);

		strcpy(lis[i], tmp);
		snt[i] = check_w(tmp, tmp + M - 1);
	}
	
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++) {	//버블 정렬
			if (snt[j] < snt[j + 1]) {		//개수 기준 내림차순 정렬
				cmp = snt[j];			
				snt[j] = snt[j + 1];
				snt[j + 1] = cmp;

				strcpy(tmp, lis[j]);		//문자열 리스트도 같이 정렬
				strcpy(lis[j], lis[j + 1]);
				strcpy(lis[j + 1], tmp);
			}
		}

	for (int i = 0; i < N; i++) {
		if (snt[i] > 0) {			//개수가 0보다 큰 경우에만 정렬 결과 출력
			printf("%s\n", lis[i]);
		}
	}

	return 0;
}

int check_w(char* p, char* q) {

	char* r;
	int len, cnt = 0;

	len = strlen(p);

	if (q > p + len - 1) {	//문자열 범위 벗어나는 경우
		for (r = p; r <= p + len - 1; r++)	//문자열 마지막 원소까지만 해서 계산
			if (!(*r >= 'A' && *r <= 'Z') && !(*r >= 'a' && *r <= 'z') && *r != ' ')
				cnt++;
	}
	else {
		for (r = p; r <= q; r++)
			if (!(*r >= 'A' && *r <= 'Z') && !(*r >= 'a' && *r <= 'z') && *r != ' ')
				cnt++;
	}

	return cnt;
}
/*
5 15
1 year is 365 days.
How are you doing?
**Notice**
Winter is coming.
1+1=2
*/