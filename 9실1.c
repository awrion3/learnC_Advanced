#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//변수 선언 및 포인터 주소 연결
	int x, y, z, *px = &x, *py = &y, *pz = &z, *tmp;

	//변수 값 입력(포인터 변수 사용)
	scanf("%d%d%d", px, py, pz);

	//변수 값 연산
	tmp = pz;
	pz = py; 
	py = px;
	px = tmp; //tmp를 활용해 포인터 주소 한칸씩 이동

	//변수 값 출력(포인터 변수 사용)
	printf("%d %d %d", *px, *py, *pz);

	return 0;
}