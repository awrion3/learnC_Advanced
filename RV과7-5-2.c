#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int num, A[100], idx = 0, B[100], jdx = 0, isdup;
	int AS[100], ix = 0, BS[100], jx = 0, C[100], kdx = 0;
	int tmp;

	//�Է�
	scanf("%d", &num);
	while (num >= 0) {
		A[idx++] = num;
		scanf("%d", &num);
	}

	scanf("%d", &num);
	while (num >= 0) {
		B[jdx++] = num;
		scanf("%d", &num);
	}

	//�ߺ�����
	for (int i = 0; i < idx; i++) {
		isdup = 0;
		for (int j = 0; j < i; j++)
			if (A[i] == A[j])
				isdup = 1;

		if (isdup == 0)
			AS[ix++] = A[i];
	}

	for (int i = 0; i < jdx; i++) {
		isdup = 0;
		for (int j = 0; j < i; j++)
			if (B[i] == B[j])
				isdup = 1;

		if (isdup == 0)
			BS[jx++] = B[i];
	}

	//��ġ��
	for (int i = 0; i < ix; i++)
		C[kdx++] = AS[i];

	for (int i = 0; i < jx; i++)
		C[kdx++] = BS[i];
	
	//�������� ����
	for (int i = 0; i < kdx - 1; i++)
		for (int j = i + 1; j < kdx; j++)
			if (C[i] > C[j]) {
				tmp = C[i];
				C[i] = C[j];
				C[j] = tmp;
			}

	//�ߺ����� ���
	for (int i = 0; i < kdx; i++) {
		isdup = 0;
		for (int j = 0; j < i; j++)
			if (C[i] == C[j])
				isdup = 1;

		if (isdup == 0)
			printf(" %d", C[i]);
	}

	return 0;
}
//2 4 6 7 8 2 4 6 7 8 -1
//1 1 1 1 1 1 1 1 1 1 -1

//2 4 6 7 8 1 2 3 4 -1
//1 2 3 4 2 4 6 7 8 -1