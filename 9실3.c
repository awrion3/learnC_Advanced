#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//���� ���� �� �ʱ�ȭ
	int ar[50] = { 0 }, N;
	int *pa = ar, cnt = 0;

	//���� �� �Է�
	scanf("%d", &N);

	for (; pa < ar + N; pa++)	//�ּ� �񱳸� �̿��Ͽ� �迭 ���� ����
		scanf("%d", pa);

	//���� �� ����
	for (pa = ar; pa < ar + N; pa++, cnt++) {
		if (*pa == 0)	//0�� ������ �������� ���� ���� ���
			break;
	}

	//���� �� ���
	printf("%d\n", cnt);

	return 0;
}