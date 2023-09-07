#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N, num, Y[100], jdx, M1, M2, m2, ispal;
	int X[100], idx = 0, tmp;

	scanf("%d%d", &M1, &M2);

	scanf("%d", &N);
	while (N > 0) {

		num = N; jdx = 0; //각각 초기화
		while (num != 0) {
			Y[jdx++] = num % 10;
			num /= 10;
		}

		m2 = M2; //m2의 값도 초기화가 필요함
		if (jdx > M1) {
			for (int i = M1; i < jdx; i++)
				Y[i] = Y[i + 1];
			jdx--;
			m2--; //M1 if문을 거친 경우에만 조정
		}

		if (jdx > m2) {	//(미)조정된 인덱스 m2를 사용
			for (int i = m2; i < jdx; i++)
				Y[i] = Y[i + 1];
			jdx--;
		}
		
		ispal = 1;
		for (int i = 0; i < jdx; i++) 
			if (Y[i] != Y[jdx - 1 - i]) { //회문수 확인
				ispal = 0;
				break;
			}

		if (ispal == 1) //삭제 반영 회문수를 배열 X에 저장
			X[idx++] = N; 

		scanf("%d", &N);
	}

	if (idx == 0)
		printf("none");
	else {
		for (int i = 0; i < idx - 1; i++) //선택정렬
			for (int j = i + 1; j < idx; j++)
				if (X[i] < X[j]) {	//내림차순
					tmp = X[i];
					X[i] = X[j];
					X[j] = tmp;
				}

		for (int i = 0; i < idx; i++)
			printf("%d ", X[i]);
	}

	return 0;
}
//1 3
//12021 345433 12345 1022201 768833 2334 77907 12321 37773 -1