#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int a, b, c, m = 0;
	scanf("%d%d%d", &a, &b, &c);

	//���� �� �Է��� �����Ƿ� = ����
	m += b * (a < b && b < c);
	m += b * (a > b && b > c);

	m += a * (b < a && a < c);
	m += a * (b > a && a > c);

	m += c * (a > c && c > b);
	m += c * (a < c && c < b);
	
	printf("%d", m);

	return 0;
}