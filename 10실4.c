#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int len = 0, fl = 1;
	char ar[101], br[101], *p = ar, *q = br;  //�� ���� ���

	scanf("%s", ar);	//���ڿ� �Է�(����, ���� ����)
	scanf("%s", br);	//���ڿ� �Է�

	for (; *p; p++)
		len++;	//ù��° ���ڿ� ���� ���

	printf("%d ", len);

	for (p = ar; *p; p++, q++) 
		if (*p != *q) {
			fl = 0;	//���� ������ ǥ���ϰ� �ݺ� ����
			break;
		}

	printf("%d", fl); //��ġ ���� ���

	return 0;
}