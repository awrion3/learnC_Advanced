#pragma warning(disable:4996)
#include <stdio.h>

//����ü ����
struct student {
	char name[9];
	int kor, eng, mat;
	double avg;
	char result;
};

int main(void) {

	//����ü �迭 ����
	struct student st[50], *p = NULL;
	int N;

	scanf("%d", &N);

	//����ü ������ Ȱ���Ͽ� ����ü �迭�� ���Һ� ��� ���� ����
	for (p = st; p < st + N; p++) 
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->mat);
	
	for (p = st; p < st + N; p++) {
		p->avg = 0;
		p->avg = (double)(p->kor + p->eng + p->mat)/3;	//�� ��ȯ�� ����

		//����ü �����͸� ���� ������ ����ü �迭�� �� ����ü ������ ����� ���� �ű��
		if (p->avg >= 90 && p->avg <= 100)
			p->result = 'A';
		else if (p->avg >= 80 && p->avg <= 90)
			p->result = 'B';
		else if (p->avg >= 70 && p->avg <= 80)
			p->result = 'C';
		else
			p->result = 'D';
	}

	//����ü �����͸� ���� ����ü �迭 �����Ͽ� ���� ������ �� ���
	for (p = st; p < st + N; p++)
		printf("%s %.1f %c\n", p->name, p->avg, p->result);

	return 0;
}
/*
2
Kim 82 72 58
Young 90 100 99
*/