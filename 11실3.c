#pragma warning(disable:4996)
#include <stdio.h>

//����ü ����
struct student {
	char name[10];
	int score;
};

int main(void) {

	//����ü �迭 ����
	struct student st[5];
	double avg = 0;

	//����ü �迭�� ����ü ���Һ� ����� �Է�
	for (int i = 0; i < 5; i++){
		scanf("%s", st[i].name);
		scanf("%d", &st[i].score);
		avg += st[i].score;
	}

	avg = (double)avg / 5;	//�� ��ȯ�� ����

	//����ü �迭�� ����ü ���Һ� ����� ���
	for (int i = 0; i < 5; i++)
		if (st[i].score <= avg)
			printf("%s\n", st[i].name);

	return 0;
}

/*
akim 75
bkim 85
ckim 65
dkim 95
ekim 100
*/