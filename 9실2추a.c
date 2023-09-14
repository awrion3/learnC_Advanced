#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
void sort(int, int[], double[]);

int main(void) {

	//변수 선언 및 값 입력
	int N, *p, *q, *r, id[100], kor[100], mat[100];
	double avg[100], *s = avg;

	scanf("%d", &N);

	//포인터 주소 비교로 배열 값 입력
	p = id, q = kor, r = mat;

	for (; p < id + N; p++, q++, r++, s++) {
		scanf("%d%d%d", p, q, r);

		//입력받는 동시에 평균값 저장
		*s = (double)(*q + *r) / 2;	
	}

	//함수 호출
	sort(N, id, avg);

	//변수 값 출력
	for (p = id, s = avg; p < id + N; p++, s++)
		printf("%d %.1f\n", *p, *s);

	return 0;
}

//함수 정의
void sort(int N, int id[], double avg[]) {

	int *p, *q, imp;
	double *s, *t, tmp;

	//내림차순 선택정렬
	for (p = id, s = avg; s < avg + N - 1; s++, p++) {
		for (q = p + 1, t = s + 1; t < avg + N; t++, q++)

			//avg 기준으로 정렬
			if (*s < *t) {
				tmp = *s;
				*s = *t;
				*t = tmp;

				//id도 함께 정렬
				imp = *p;
				*p = *q;
				*q = imp;
			}
	}
}
/*
3
1 90 90
2 70 70
3 80 80
*/