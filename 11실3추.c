#pragma warning(disable:4996)
#include <stdio.h>

struct person {
	char name[11];	//������ �̸�(�� ���� ����)
	int wt, it;		//�ʱ����, �������� ����
	double res;		//����
};

//�Լ� ����
void swap(struct person*, struct person*);

int main(void) {

	struct person sp[100], *p;	//����ü �迭 �� ������ ����

	int N, M;	//������, �հ��� �� �Է�
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {	//�����ں� �̸�, ���� ������ �Է�
		scanf("%s %d %d", sp[i].name, &sp[i].wt, &sp[i].it);
		sp[i].res = sp[i].wt * 0.8 + sp[i].it * 0.2;	//������ ����
	}

	for (int i = 0; i < N - 1; i++) 	//���� ���� �������
		for (p = sp; p < sp + N - 1; p++) 	//����ü �迭�� �����ͷ� �����Ͽ�
			if (p->res < (p + 1)->res) 	//���ڰ� �� ū ������ ���, �������� ����
				swap(p, p + 1);			//swap �Լ� ȣ���Ͽ� �� ����ü ���Ҹ� ��ȯ
	
	for (p = sp; p < sp + M; p++) 	//�������� ���� ���: ù ���Һ��� ���� ū �� ���� ����ü �迭
		printf("%s %.1f\n", p->name, p->res);	//���ʷ� �հ��� ����ŭ ���
	
	return 0;
}

void swap(struct person *p, struct person *q) {

	struct person tmp;	//����ü ����

	tmp = *p;	//����ü �� ������ ���� �� ����ü ������ ������� �Բ� ��ȯ
	*p = *q;
	*q = tmp;
}
/*
7 3
Aaaaa 75 85
Bbbbb 86 77
Ccccc 94 82
Ddddd 78 70
Eeeee 65 85
Fffff 83 90
Ggggg 90 70
*/