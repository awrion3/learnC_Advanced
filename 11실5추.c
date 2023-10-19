#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct person {
	char name[11], birth[11];	//���� ���� ���ڿ� �߰�
	int wt, it;
	double res;
};

void swap(struct person*, struct person*);

int main(void) {

	struct person sp[100], *p;

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {	//���� ���ڿ� �߰��� �Է�
		scanf("%s %s %d %d", sp[i].name, sp[i].birth, &sp[i].wt, &sp[i].it);
		sp[i].res = sp[i].wt * 0.8 + sp[i].it * 0.2;
	}

	for (int i = 0; i < N - 1; i++)
		for (p = sp; p < sp + N - 1; p++)
			if (p->res <= (p + 1)->res) {		//������ ���ų� ���ڰ� ū ���
				if (p->res == (p + 1)->res) {	//������ ���� ��쿣

					if (p->wt <= (p + 1)->wt) {		//�ʱ� ������ ���ų� ���ڰ� ū ���
						if (p->wt == (p + 1)->wt) {	//�ʱ� ������ ���� ��쿣
							if (strcmp(p->birth, (p + 1)->birth) < 0)	//���ڰ� ������ ���� ��쿡,
								swap(p, p + 1);	//ȣ���Ͽ� �� ��ȯ
						}
						else				//�ʱ� ���� ���ڰ� �� ū ��쿡,
							swap(p, p + 1);		//ȣ���Ͽ� �� ��ȯ
					}
				}
				else						//���� ���ڰ� �� ū ��쿡,
					swap(p, p + 1);				//ȣ���Ͽ� �� ��ȯ
			}

	for (p = sp; p < sp + M; p++)			//�������� ���ĵ� ����ü���� �ش� �հ��ڸ�ŭ ���
		printf("%s %.1f\n", p->name, p->res);

	return 0;
}

void swap(struct person *p, struct person *q) {

	struct person tmp;	//����ü ����

	tmp = *p;			//����ü ���� �� �����Ͽ� ��ȯ
	*p = *q;
	*q = tmp;
}
/*
7 3
Aaaaa 1995-10-07 75 85
Bbbbb 1991-11-15 90 64
Ccccc 1994-12-08 94 82
Ddddd 1993-07-17 78 70
Eeeee 1995-10-07 65 85
Fffff 1991-11-05 90 64
Ggggg 1990-08-21 90 64
*/