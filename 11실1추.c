#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct student {
	char name[10], id[11];	//�� ���ڿ� �� ���� ���
	char grade;
};

int main(void) {

	struct student st[5];	//����ü �迭 ����
	char stname[10];

	//�� ���ʷ� �Է�
	for (int i = 0; i < 5; i++) 
		scanf("%s %s %c", st[i].name, st[i].id, &st[i].grade);

	scanf("%s", stname);
	
	//ã���� �ϴ� �л��� ���� ���
	for (int i = 0; i < 5; i++)
		if (strcmp(st[i].name, stname) == 0) 
			printf(" %s %c\n", st[i].id, st[i].grade);

	return 0;
}
/*
lee1 2017102656 A
lee2 2018111823 A
park 2018059961 A
choi 2018010101 F
lee3 2019565656 B
park
*/