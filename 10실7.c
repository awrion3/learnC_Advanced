#pragma warning(disable:4996)
#include <stdio.h>

//����ü ����
struct numbers {
	int num;
	int rank;
};

int main(void) {

	//����ü �迭 ����
	struct numbers rk[10];

	//����ü �迭�� ����ü ���Һ� ����� �Է�
	for (int i = 0; i < 10; i++)
		scanf("%d", &rk[i].num);

	//����ü �迭�� ����ü ���Һ� ����� Ȱ���Ͽ� �ٸ� �����(���) ���ϱ�
	for (int i = 0; i < 10; i++) {
		rk[i].rank = 1;	//����ü �迭�� ����ü ���Һ� ����� �ʱ�ȭ

		for (int j = 0; j < 10; j++)
			if (rk[i].num < rk[j].num) {
				++rk[i].rank;
			}
	}
	
	//3������ 7���� ����� ������ �����(����) ����ϱ�
	for (int i = 0; i < 10; i++)
		if (rk[i].rank == 3)
			printf("%d ", rk[i].num);
	
	for (int i = 0; i < 10; i++)
		if (rk[i].rank == 7)
			printf("%d", rk[i].num);

	return 0;
}
/*
78 65 23 43 82 95 31 15 8 54
*/