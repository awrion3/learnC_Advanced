#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

struct student {	//����ü ����

	char name[8];
	int kor, eng, math;
	int score;
	double avg;

};

int main(void) {

	int N;
	struct student *p;	//����ü ����

	scanf("%d", &N);

	p = (struct student*)malloc(N * sizeof(struct student)); //�����Ҵ�...�� Ȯ��

	for (int i = 0; i < N; i++) {	//����ü �迭 + ����ü ������ ��� ����
		scanf("%s %d %d %d", p[i].name, &p[i].kor, &p[i].eng, &p[i].math);
		p[i].avg = (double)(p[i].kor + p[i].eng + p[i].math) / 3;
	}

	for (int i = 0; i < N; i++) {
		printf("%s %.1f ", p[i].name, p[i].avg);	//��� ���

		if (p[i].kor >= 90 || p[i].eng >= 90 || p[i].math >= 90)	//��� �߰��� �Ű� ���
			printf("GREAT ");
		if (p[i].kor < 70 || p[i].eng < 70 || p[i].math < 70)
			printf("BAD ");
		
		printf("\n");
	}
	
	free(p);	//�����Ҵ� ����

	return 0;
}
/*
2
Kim 100 82 34
Young 90 100 99
*/