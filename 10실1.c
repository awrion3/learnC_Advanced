#pragma warning(disable:4996)
#include <stdio.h>

//����ü ����
struct vector {
	int ar[3];
};

int main(void) {

	//����ü ����
	struct vector v1, v2, v3;
	int dot = 0;

	//����ü ����1 �Է�
	for (int i = 0; i < 3; i++)
		scanf("%d", &v1.ar[i]);

	//����ü ����2 �Է�
	for (int i = 0; i < 3; i++)
		scanf("%d", &v2.ar[i]);

	//����ü ����3 ���
	for (int i = 0; i < 3; i++) {
		v3.ar[i] = v1.ar[i] * v2.ar[i];
		printf("%d ", v3.ar[i]);
	}
	printf("\n");

	//����ü ����3 ���
	for (int i = 0; i < 3; i++)
		dot += v3.ar[i];

	//����� ���
	printf("%d", dot);

	return 0;
}
/*
1 2 3
-1 5 5
*/