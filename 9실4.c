#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//���� ���� �� �ʱ�ȭ
	int ar[3] = { 0 }, *p = ar, *q, tmp;

	//���� �� �Է�
	for (; p < ar + 3; p++)
		scanf("%d", p);

	//���� �� ����
	for (p = ar; p < ar + 2; p++) //�ּ� �񱳸� ���� �迭 ���� ����
		for (q = p + 1; q < ar + 3; q++) //���� ������ �������
			if (*p > *q) {				 //�������� ����
				tmp = *p;	
				*p = *q;
				*q = tmp;	//tmp�� Ȱ���Ͽ� �� ��ȯ
			}

	//���� �� ���
	printf("%d", *(ar + 1));	//�迭 �������� �������� �� �߾Ӱ� ���

	return 0;
}