#pragma warning(disable:4996)
#include <stdio.h>

//구조체 정의
struct complex {
	double real, imag;
};

//함수 선언
struct complex add(struct complex, struct complex);

int main(void) {

	//구조체 선언
	struct complex cp1, cp2, cp3;

	scanf("%lf %lf", &cp1.real, &cp1.imag);
	scanf("%lf %lf", &cp2.real, &cp2.imag);

	//함수 호출 및 구조체 단순 대입 
	cp3 = add(cp1, cp2);

	printf("%.1f + %.1fi", cp3.real, cp3.imag);

	return 0;
}

//함수 정의
struct complex add(struct complex a, struct complex b) {

	//구조체 변수 선언
	struct complex c;

	//넘겨받은 구조체 변수값들 활용
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;

	return c;
}
/*
2.3 4.5
3.4 5.0
*/