#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//���� ���� �� ������ �ּ� ����
	int x, y, z, *px = &x, *py = &y, *pz = &z, *tmp;

	//���� �� �Է�(������ ���� ���)
	scanf("%d%d%d", px, py, pz);

	//���� �� ����
	tmp = pz;
	pz = py; 
	py = px;
	px = tmp; //tmp�� Ȱ���� ������ �ּ� ��ĭ�� �̵�

	//���� �� ���(������ ���� ���)
	printf("%d %d %d", *px, *py, *pz);

	return 0;
}