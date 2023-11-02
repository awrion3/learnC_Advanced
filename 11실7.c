#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int row, col, **p, fl = 0;	//이중 포인터 선언
	char ch = 'a';

	scanf("%d %d", &col, &row);	//열 행 입력

	p = (int**)malloc(row * sizeof(int*));	
	//이중 포인터 (포인터 배열 선언 예: *ar[5], 이러한 배열 이름 *ar를 가리키는 포인터;
	//포인터'의' 주소를 가리키는 포인터)

	for (int i = 0; i < row; i++){
		p[i] = (int*)malloc(col * sizeof(int));	
		//p[i]는 주소(포인터 배열의 원소), 참고: *p[i]는 값(포인터 배열의 원소가 가리키는 값) 
		//== *(p + i)                            == **(p + i)

		for (int j = 0; j < col; j++){
			if (ch > 'z')				//초과한 경우 초기화
				ch = 'A';
			if (ch > 'Z' && ch < 'a')	//사이인 경우 초기화
				ch = 'a';				
			
			p[i][j] = ch++;	//p[i]가 주소라면, 옆은 *(p[i] + j)을 의미한다
			//포인터 배열의 원소인 포인터p[i]가 가리키는 배열을 접근하여 각 원소값 저장
		}
	}
	
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++)	//저장된 값 출력
			printf("%c ", p[i][j]);
		printf("\n");
	}

	for (int i = 0; i < row; i++)	//차례로 동적할당 해제
		free(p[i]);
	free(p);

	return 0;
}
/*
9 6
*/