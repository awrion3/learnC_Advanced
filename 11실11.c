#pragma warning(disable:4996)
#include <stdio.h>

//����ü ����
struct student {
	char name[10];
	int score;
};

//�Լ� ����
struct student* select_min(struct student *);

int main(void) {

	//����ü �迭 ���� �� ������ ����� ����
	struct student st[5], *p = NULL;

	//������ �ּ� �񱳸� ���� ����ü �迭 �����Ͽ� ����ü ���Һ� ����� �Է�
	for (p = st; p < st + 5; p++)
		scanf("%s %d", p->name, &p->score);

	//�Լ� ȣ�� �� ����ü �迭�� Ư�� ����ü ������ �ּ� ��ȯ�ޱ�
	p = select_min(st);
	
	//�����͸� Ȱ���Ͽ� �ش� ����ü ������ ����� ���������Ͽ� ���
	printf("%s %d", p->name, p->score);

	return 0;
}

//�Լ� ����
struct student* select_min(struct student *ps) {

	struct student *p, *mp = ps;	//�ݺ��� ���� ������ �� ����� ������ �ּҰ� �ʱ�ȭ�ϱ�
	double mavg = 101;		

	for (p = ps; p < ps + 5; p++)	//�����ͷ� ����ü �迭 �����Ͽ� ����ü ���ҵ��� ����� ���ϸ� ����
		if (mavg > p->score) {
			mavg = p->score;
			mp = p;
		}

	//����ü �迭�� Ư�� ����ü ���Ҹ� ����Ű�� �ּ� ��ȯ
	return mp;
}

/*
akim 75
bkim 85
ckim 65
dkim 95
ekim 100
*/