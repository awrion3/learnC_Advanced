#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//���� ���� �� �ʱ�ȭ
	int ar[5], *p = ar, *q;
	int rank[5], *r = rank;

	//���� �� �Է�
	for (; p < ar + 5; p++)
		scanf("%d", p);

	//���� �� ����
	for (p = ar; p < ar + 5; p++) { //������ Ȱ���Ͽ� �迭�� ����� �������� ���ϸ�
		*r = 1;	//��� �ʱ�ȭ
		for (q = ar; q < ar + 5; q++)
			if (*p < *q)			//��� �Űܼ� �迭 rank�� ���� (������ Ȱ��)
				++*r;
		r++;	//��� �ε��� ����
	}

	//���� �� ���
	r = rank;	//������ ���� �ʱ�ȭ//
	for (p = ar; p < ar + 5; p++, r++)
		printf("%d=r%d ", *p, *r);	//���� �� ��� �� ���
	
	return 0;
}