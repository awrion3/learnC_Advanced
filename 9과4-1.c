#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//변수 선언 및 초기화
	int a[11], b[11], num, *p, n = 0, m = 0, max = -1, min = 101;

	for (p = a; p < a + 11; p++){	//101호 학생들의 성적 입력
		scanf("%d", &num);
		if (num == -1)	//-1 입력 시 반복 중지
			break;
		else {
			*p = num;	//배열 a에 값 저장
			n++;		//n개의 점수 입력 카운트
		}
	}

	for (p = b; p < b + 11; p++) {	//102호 학생들의 성적 입력
		scanf("%d", &num);
		if (num == -1)	//-1 입력 시 반복 중지
			break;
		else {
			*p = num;	//배열 b에 값 저장
			m++;		//m개의 점수 입력 카운트
		}
	}

	for (p = a; p < a + n; p++) {	//포인터를 사용해 배열 a를 훑으며
		if (*p > max)	//최대값 갱신
			max = *p;
		if (*p < min)	//최소값 갱신
			min = *p;
	}
	
	for (p = b; p < b + m; p++) {	//포인터를 사용해 배열 b를 훑으며
		if (*p > max)	//최대값 갱신
			max = *p;
		if (*p < min)	//최소값 갱신
			min = *p;
	}

	//각 호에서 응시한 학생 수를 각각 출력
	printf("%d %d\n", n, m);
	//전체 점수 중 최고 및 최저 점수를 출력
	printf("%d %d", max, min);

	return 0;
}

/*
10 50 70 -1
20 100 -1

5 20 23 80 80 -1
70 50 50 45 5 15 28 46 76 11 -1
*/