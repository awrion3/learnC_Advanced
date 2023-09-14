#pragma warning(disable:4996)
#include <stdio.h>

//함수 선언
void eliminate(char []);

int main(void) {

	//변수 값 입력
	char ar[100], *p = ar;

	for (; p < ar + 100; p++) {
		scanf("%c", p);

		if (*p == '*')	//*까지만 배열 원소 입력받기
			break;
	}

	//함수 호출
	eliminate(ar);

	//변수 값 출력
	for (p = ar; p < ar + 100; p++) {
		printf("%c", *p);
	
		if (*p == '*')	//*까지만 배열 원소 출력하기
			break;
	}

	return 0;
}

//함수 정의
void eliminate(char ar[]) {

	int N = 0, fl, idx = 0;
	char *p = ar, *q, rr[100], *r = rr;

	//배열의 길이 계산
	for (; p < ar + 100; p++, N++) 
		//*을 만나면 반복 중지하므로 인덱스가 맞아떨어지게 끝남에 유의
		if (*p == '*')
			break;

	//중복 제거 	
	//<= 만약 포함하지 않을 시 마지막 *은 별도로 삽입해야 함에 유의; *p++ = '*';
	for (p = ar; p <= ar + N; p++){
		fl = 0;

		//만약 기준 원소 이전에 중복되는 원소가 존재 시 중복 표기
		for (q = ar; q < p; q++)
			if (*p == *q) 
				fl = 1;

		//중복되는 원소가 이전에 없었을 시 새 배열에 저장
		if (fl == 0) {
			*r++ = *p;
			idx++; //길이도 구하기
		}
	}

	//새 배열을 원래 배열에 덮어쓰기
	for (r = rr, p = ar; r < rr + idx; r++, p++)
		*p = *r;
}