#pragma warning(disable:4996)
#include <stdio.h>

//����ü ����
struct student {
	int gender, weight, height;
};

int main(void) {

	//����ü �迭 ����
	struct student st[10];
	int N, g1 = 0, g2 = 0, g3 = 0;

	scanf("%d", &N);

	//����ü �迭�� ����ü ���� ����� �Է� �� �з�
	for (int i = 0; i < N; i++){
		scanf("%d %d %d", &st[i].gender, &st[i].weight, &st[i].height);

		//����, ü��, Ű�� ���� ���� �з�
		if (st[i].gender == 1) {
			if (st[i].weight >= 70) {
				if (st[i].height >= 175)
					g1 += 1;
				else if (st[i].height >= 165)
					g3 += 1;
				else
					g2 += 1;
			}
			else if (st[i].weight >= 60) {
				if (st[i].height >= 175)
					g2 += 1;
				else if (st[i].height >= 165)
					g1 += 1;
				else 
					g3 += 1;
			}
			else {
				if (st[i].height >= 175)
					g3 += 1;
				else if (st[i].height >= 165)
					g2 += 1;
				else
					g1 += 1;
			}
		}
		else if (st[i].gender == 2) {
			if (st[i].weight >= 60) {
				if (st[i].height >= 175) 
					g1 += 1;
				else if (st[i].height >= 165)
					g3 += 1;
				else 
					g2 += 1;
			}
			else if (st[i].weight >= 50) {
				if (st[i].height >= 175) 
					g2 += 1;
				else if (st[i].height >= 165) 
					g1 += 1;
				else
					g3 += 1;
			}
			else {
				if (st[i].height >= 175) 
					g3 += 1;
				else if (st[i].height >= 165) 
					g2 += 1;
				else
					g1 += 1;
			}
		}
	}

	//����ü �����Ͽ� ī��Ʈ�� �� ���
	printf("%d %d %d", g1, g2, g3);

	return 0;
}

/*
2
1 66 170
2 48 155
*/