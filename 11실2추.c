#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>		//atoi�� ���ڿ� ó�� �Լ��� ���ڿ��� ���� ��ȯ

struct student {
	char name[10], id[11];	//�� ���� ���
	char grade;
};

int main(void) {

	struct student st[5];
	char stname[10], stgrade, styear[5] = { 0 }, tmyear[5] = { 0 };	//�� ���� �̸� ����
	int is = 0, idnum;

	//�� �Է�(���� ������ ����ؼ� %c ���� getchar() �Ⱦ�)
	for (int i = 0; i < 5; i++)
		scanf("%s %s %c", st[i].name, st[i].id, &st[i].grade);	

	scanf("%s", stname);

	for (int i = 0; i < 5; i++)
		if (strcmp(st[i].name, stname) == 0) {	//ã���� �ϴ� �л� �̸����� ã��
			stgrade = st[i].grade;				//���� ����

			strncpy(styear, st[i].id, 4);		//���г⵵ ����: �ش� ���� ������ŭ�� ����(���� �� ����X)

			idnum = atoi(styear) % 131;			//���ڿ� ���� ��ȯ�Ͽ� �ٷ� ���ϱ�
		}

	for (int i = 0; i < 5; i++) 
		if (st[i].grade == stgrade) {	//�л��� ���� ������ ���� �л��鿡 ����,
			strncpy(tmyear, st[i].id, 4);		//�ش� �л��� ���г⵵ ����
			
			if (strcmp(styear, tmyear) == 0) {	//���г⵵�� ���ٸ�,

				if (strcmp(stname, st[i].name) != 0){	//������ ������ ��쿩�� ��
					printf("%s ", st[i].name);			//�ش� �л� �̸� ���
					is = 1;	//������ ������ ���� ������ �л��� �ִ� ��� ǥ��
				}
			}
		}

	if (is == 0)
		printf("0\n");
	else
		printf("\n");	//���ǿ� ���� �ٹٲ� ���

	printf("%s %d\n", styear, idnum);	//ã���� �ϴ� �л��� ���г⵵�� ������ ���

	return 0;
}
/*
lee1 2017102656 A
lee2 2018111823 A
kwon 2018111888 A
park 2018059961 A
choi 2018010101 B
park

lee1 2019102656 B
lee2 2019111823 B
park 2019123456 A
choi 2019010101 F
lee3 2019565656 B
park
*/