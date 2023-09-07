#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int n, b, a = 0; //첫 입력의 이전 입력에 대한 초기화
	int cnt = 1, max = 1; //1로 초기화

	scanf("%d", &n);

	while (n != 0) {
		b = a;
		a = n;

		if (b * a > 0) {
			cnt++;
			if (max < cnt) //else문이 아닌 if문에 위치해야 갱신 및 저장됨
				max = cnt;
		}
		else 	
			cnt = 1;

		scanf("%d", &n);
	}

	printf("%d", max);

	return 0;
}