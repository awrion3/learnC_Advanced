#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	 //���ڿ� ó�� �Լ� ���� ��� ���� ����
#define MAX_NUM 100  //��ó���⿡�� ��� ���� (����� ����)

//����ü ����
struct tel {
	char name[21];		//�̸� 20 bytes
	char tel_no[16];	//��ȭ��ȣ 15 bytes
	char birth[9];		//���� 8 bytes
};

//�Լ� ���� ����
void menu(void);					  //�޴�
int reg_insert(struct tel *, int);	   //���
void show_all(struct tel *, int);      //����
int delete_tel(struct tel *, int);     //����
void find_by_birth(struct tel *, int); //�˻�

int main(void) {

	struct tel tel_list[MAX_NUM] = {0}, *p = tel_list;   //����ü �迭: �ִ� 100�� ����
	int count = 0, N;	//ī����: ���� ����Ǿ� �ִ� ����ó ����

	while (1) {	//���� ���� ���� �� ���� �ݺ� ����//
		//�޴� ���
		menu();

		//���ϴ� �޴� ���� �Է�
		scanf("%d", &N);

		//���� �޴� ���� �� ���α׷� ����
		if (N == 5)
			break;

		//�ش��ϴ� �޴� ����� �ϴ� �Լ� ȣ�� 
		switch (N) {
		case 1:	//��� ���� �Լ� ȣ��
			count = reg_insert(p, count);	//�ε��� ��ȯ
			break;	
		case 2:	//���� ���� �Լ� ȣ��
			show_all(p, count);
			break;
		case 3:	//���� ���� �Լ� ȣ��
			count = delete_tel(p, count);	//�ε��� ��ȯ
			break;
		case 4: //�˻� ���� �Լ� ȣ��
			find_by_birth(p, count);
			break;
		}
	}

	return 0;	//���α׷� ����
}

//�Լ� ����
void menu(void) { //�޴� ���//
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");	//���� �������̽� ���� ���
}

int reg_insert(struct tel *p, int cnt) { //��� �Լ�//
	
	struct tel *t = p + cnt, *q, smp;	//����ü ���� ���� ����
	
	if (cnt >= MAX_NUM)					//����//
		printf("OVERFLOW\n");
	else {								//�Է�//
		printf("Name:");
		scanf("%s", t->name);		//�̸�
		printf("Phone_number:");
		scanf("%s", t->tel_no);		//��ȭ��ȣ
		printf("Birth:");
		scanf("%s", t->birth);		//���� ���ڿ� �Է�

		for (q = p; q < p + cnt; q++)	//����//
			if (strcmp(q->name, t->name) > 0) {	//���� �̸����� �� �̸��� �ռ� ���
				smp = *q;	
				*q = *t;				//����ü �� ������ ���� ���� ��ġ�� �̵�
				*t = smp;
			}

		cnt++;	//����ü �迭 ũ�� ����

		//���� ����� ����ó ���� ���
		printf("<<%d>>\n", cnt);	
	}

	return cnt;	//�ε��� ��ȯ
}

void show_all(struct tel *p, int cnt) {	//���� �Լ�//
	
	struct tel *t;		//����ü ���� ���� ����

	if (cnt != 0) {		//����ü �迭 ũ�� 0�� �ƴ� ���
		for (t = p; t < p + cnt; t++)	//����ü ������ ���� ���
			printf("%s %s %s\n", t->name, t->tel_no, t->birth);
	}
}

int delete_tel(struct tel *p, int cnt) { //���� �Լ�//

	struct tel *t, *q = NULL;	//����ü ���� ���� ����
	char tmp[21];	//�ӽ� ���ڿ�
	int del = 0;	//�÷��� ���� ����

	if (cnt == 0)					//����//
		printf("NO MEMBER\n");
	else {							//����//
		printf("Name:");
		scanf("%s", tmp);				//�̸� �Է�
		
		for (t = p; t < p + cnt; t++)	//�̸� ��ġ��
			if (strcmp(t->name, tmp) == 0){
				q = t;		//�ش� ����ü ���� ��ġ ����
				del = 1;	//��ġ ���� Ȯ��
			}
	}

	if (del == 1) {			//�̸� ��ġ ���� ��
		for (t = q; t < p + cnt; t++) 	
			*t = *(t + 1);	//�ش� ����ü ���� ����

		cnt--;	//����ü �迭 ũ�� ���� �ݿ�
	}

	return cnt;	//�ε��� ��ȯ
}

void find_by_birth(struct tel *p, int cnt) { //�˻� �Լ�//

	struct tel *t;		//����ü ���� ���� ����
	char bday[5], *q;	//ã������ ���� ���� ����
	int key, mon;		//���� �� ���� ����

	printf("Birth:");	//�Է�//
	scanf("%d", &key);

	for (t = p; t < p + cnt; t++) {	//����ü �迭 �����Ͽ�
		strcpy(bday, t->birth + 4);	//���� ���� �ӽ� ���ڿ��� ����
		
		mon = 0;		//�� �ʱ�ȭ
		for (q = bday; q < bday + 2; q++){	//�ӽ� ���ڿ��� ���� ���� ���Ͽ�
			mon *= 10;
			mon += *q - '0';				//������ ������ ��ȯ
		}

		if (key == mon)	//ã������ ���� ���� ��� �ش��� ���� ���
			printf("%s %s %s\n", t->name, t->tel_no, t->birth);
	}
}