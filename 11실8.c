#pragma warning(disable:4996)
#include <stdio.h>

//����ü ����
struct complex {
	double real, imag;
};

//�Լ� ����
struct complex add(struct complex, struct complex);

int main(void) {

	//����ü ����
	struct complex cp1, cp2, cp3;

	scanf("%lf %lf", &cp1.real, &cp1.imag);
	scanf("%lf %lf", &cp2.real, &cp2.imag);

	//�Լ� ȣ�� �� ����ü �ܼ� ���� 
	cp3 = add(cp1, cp2);

	printf("%.1f + %.1fi", cp3.real, cp3.imag);

	return 0;
}

//�Լ� ����
struct complex add(struct complex a, struct complex b) {

	//����ü ���� ����
	struct complex c;

	//�Ѱܹ��� ����ü �������� Ȱ��
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;

	return c;
}
/*
2.3 4.5
3.4 5.0
*/