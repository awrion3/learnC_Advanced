#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//���� ���� �� �ʱ�ȭ
	int a[11], b[11], num, *p, n = 0, m = 0, max = -1, min = 101;

	for (p = a; p < a + 11; p++){	//101ȣ �л����� ���� �Է�
		scanf("%d", &num);
		if (num == -1)	//-1 �Է� �� �ݺ� ����
			break;
		else {
			*p = num;	//�迭 a�� �� ����
			n++;		//n���� ���� �Է� ī��Ʈ
		}
	}

	for (p = b; p < b + 11; p++) {	//102ȣ �л����� ���� �Է�
		scanf("%d", &num);
		if (num == -1)	//-1 �Է� �� �ݺ� ����
			break;
		else {
			*p = num;	//�迭 b�� �� ����
			m++;		//m���� ���� �Է� ī��Ʈ
		}
	}

	for (p = a; p < a + n; p++) {	//�����͸� ����� �迭 a�� ������
		if (*p > max)	//�ִ밪 ����
			max = *p;
		if (*p < min)	//�ּҰ� ����
			min = *p;
	}
	
	for (p = b; p < b + m; p++) {	//�����͸� ����� �迭 b�� ������
		if (*p > max)	//�ִ밪 ����
			max = *p;
		if (*p < min)	//�ּҰ� ����
			min = *p;
	}

	//�� ȣ���� ������ �л� ���� ���� ���
	printf("%d %d\n", n, m);
	//��ü ���� �� �ְ� �� ���� ������ ���
	printf("%d %d", max, min);

	return 0;
}

/*
10 50 70 -1
20 100 -1

5 20 23 80 80 -1
70 50 50 45 5 15 28 46 76 11 -1
*/