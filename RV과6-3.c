#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int n, b, a = 0; //ù �Է��� ���� �Է¿� ���� �ʱ�ȭ
	int cnt = 1, max = 1; //1�� �ʱ�ȭ

	scanf("%d", &n);

	while (n != 0) {
		b = a;
		a = n;

		if (b * a > 0) {
			cnt++;
			if (max < cnt) //else���� �ƴ� if���� ��ġ�ؾ� ���� �� �����
				max = cnt;
		}
		else 	
			cnt = 1;

		scanf("%d", &n);
	}

	printf("%d", max);

	return 0;
}