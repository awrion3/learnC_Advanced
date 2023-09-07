#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, num, M, pal;
	int max, min, cnt, fl = 0;

	scanf("%d", &N);
	while (N != 0) {

		num = N; pal = N;
		M = 0;
		while (num != 0) {
			pal *= 10;
			M *= 10;
			M += num % 10;
			num /= 10;	
		}
		pal += M; //대칭정수 구하기
 		
		num = pal; cnt = 0;
		while (num != 0) {
			if (num % 10 == 3)
				cnt++;	//대칭정수 내 3의 개수 확인
			num /= 10;
		}

		printf("%d %d ", pal, cnt); //출력
		
		//대칭정수 관련 최대 최소값 초기화
		if (fl == 0) { 
			max = pal;
			min = pal;
			fl = 1;
		}
		else {
			if (pal > max)
				max = pal;
			if (pal < min)
				min = pal;
		}
		
		scanf("%d", &N);
	}

	printf("\n%d %d", min, max); //출력

	return 0;
}