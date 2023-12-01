#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	 //���ڿ� ó�� �Լ� ���� ��� ���� ����
#include <stdlib.h>	 //�����Ҵ� ���� ��� ���� ����

//����ü ����
struct tel {
	char *name;		//�̸�
	char *tel_no;	//��ȭ��ȣ
	char *birth;	//����
};
//����ü ����� ������
typedef struct tel TEL;	

//�Լ� ���� ����
void menu(void);				    //�޴�
int reg_insert(TEL**, int, int);    //���
void show_all(TEL**, int);			//����
int delete_tel(TEL**, int);			//����
void find_by_birth(TEL**, int);		//�˻�

int main(void) {

	TEL **tel_list;	//���� ������ ����
	int max_num;	//�ִ� ȸ���� (����ڷκ��� �Է�)
	int count = 0, N;	//ī����: ���� ����ó ����

	//max_num �Է�
	printf("Max_num:");
	scanf("%d", &max_num);

	//����ü ������ �迭 �����Ҵ�1
	tel_list = (TEL**)malloc(max_num * sizeof(TEL*));
	if (tel_list == NULL)	//�����Ҵ�1 Ȯ��
		return -1;

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
			count = reg_insert(tel_list, count, max_num);	//�ε��� ��ȯ
			break;
		case 2:	//���� ���� �Լ� ȣ��
			show_all(tel_list, count);
			break;
		case 3:	//���� ���� �Լ� ȣ��
			count = delete_tel(tel_list, count);			//�ε��� ��ȯ
			break;
		case 4: //�˻� ���� �Լ� ȣ��
			find_by_birth(tel_list, count);
			break;
		}
	}

	//����ü ���� �����Ҵ� ����
	for (int i = 0; i < count; i++) {
		//����ü ���� ��� �����Ҵ�3 ����
		free(tel_list[i]->name); free(tel_list[i]->tel_no); free(tel_list[i]->birth);
		free(tel_list[i]); //����ü ���� �����Ҵ�2 ����
	}
	free(tel_list);	//����ü ������ �迭 �����Ҵ�1 ����

	return 0;	//���α׷� ����
}

//�Լ� ����
void menu(void) { //�޴� ���//
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");	//���� �������̽� ���� ���
}

int reg_insert(TEL **p, int cnt, int max) { //��� �Լ�//

	TEL smp;		//����ü ���� ���� ����
	char tmp[101];	//�ִ� 100���� �ӽ� ���ڿ�
	int len;		//�ӽ� ���ڿ� ���� ���� ����
	
	if (cnt >= max)					//����//
		printf("OVERFLOW\n");
	else {							//�Է�//
		//����ü ���� �ϳ��� �����Ҵ�2
		p[cnt] = (TEL*)malloc(sizeof(TEL));	
		if (p[cnt] == NULL)	//�����Ҵ�2 Ȯ��
			return -1;

		//�̸� �Է�
		printf("Name:");
		scanf("%s", tmp);

		//���ڿ� �����Ҵ�3-1
		len = strlen(tmp);
		p[cnt]->name = (char*)malloc((len + 1) * sizeof(char));	
		strcpy(p[cnt]->name, tmp);		//�Ҵ�� ������ �̸� ���ڿ� ����

		//��ȭ��ȣ �Է�
		printf("Phone_number:");
		scanf("%s", tmp);	

		//���ڿ� �����Ҵ�3-2
		len = strlen(tmp);
		p[cnt]->tel_no = (char*)malloc((len + 1) * sizeof(char)); 
		strcpy(p[cnt]->tel_no, tmp);	//�Ҵ�� ������ ��ȭ��ȣ ���ڿ� ����

		//���� ���ڿ� �Է�
		printf("Birth:");
		scanf("%s", tmp);	

		//���ڿ� �����Ҵ�3-3
		len = strlen(tmp);
		p[cnt]->birth = (char*)malloc((len + 1) * sizeof(char)); 
		strcpy(p[cnt]->birth, tmp);	//�Ҵ�� ������ ���� ���ڿ� ����

		for (int i = 0; i < cnt; i++) {	//����//
			if (strcmp(p[i]->name, p[cnt]->name) > 0) {	//���� �̸����� �� �̸��� �ռ� ���
				smp = *(p[i]);
				*(p[i]) = *(p[cnt]);			   //����ü �� ������ ���� ���� ��ġ�� �̵�
				*(p[cnt]) = smp;
			}
		}
	
		cnt++;	//����ü �迭 ũ�� ����
		
		//���� ����� ����ó ���� ���
		printf("<<%d>>\n", cnt);
	}

	return cnt;	//�ε��� ��ȯ
}

void show_all(TEL **p, int cnt) {	//���� �Լ�//

	if (cnt != 0) {		//����ü �迭 ũ�� 0�� �ƴ� ���
		for (int i = 0; i < cnt; i++)	//����ü ������ ���� ���
			printf("%s %s %s\n", p[i]->name, p[i]->tel_no, p[i]->birth);
	}
}

int delete_tel(TEL **p, int cnt) { //���� �Լ�//

	char tmp[101];		//�ӽ� ���ڿ�
	int del = 0, idx;	//�÷��� �� �ε��� ���� ����

	if (cnt == 0)					//����//
		printf("NO MEMBER\n");
	else {							//����//
		printf("Name:");
		scanf("%s", tmp);				//�̸� �Է�

		for (int i = 0; i < cnt; i++)	//�̸� ��ġ��
			if (strcmp(p[i]->name, tmp) == 0) {
				idx = i;	//�ش� ����ü ���� ��ġ ����
				del = 1;	//��ġ ���� Ȯ��
			}
	}

	if (del == 1) {			//�̸� ��ġ ���� ��
		
		//���� ��� ���� ����ü �����Ҵ� ����
		free(p[idx]->name);
		free(p[idx]->tel_no);	//����ü ���� ��� �޸� ����
		free(p[idx]->birth);
		
		for (int i = idx; i < cnt - 1; i++)
			*(p[i]) = *(p[i + 1]);	//����ü �� ������ ���� �ش� ����ü ���� ����

		cnt--;	//����ü �迭 ũ�� ���� �ݿ�

		free(p[cnt]);			//����ü �޸� ����
	}

	return cnt;	//�ε��� ��ȯ
}

void find_by_birth(TEL **p, int cnt) { //�˻� �Լ�//

	char bday[5], *q;	//ã������ ���� ���� ����
	int key, mon;		//���� �� ���� ����

	printf("Birth:");	//�Է�//
	scanf("%d", &key);

	for (int i = 0; i < cnt; i++) {	//����ü �迭 �����Ͽ�
		strcpy(bday, p[i]->birth + 4);	//���� ���� �ӽ� ���ڿ��� ����

		mon = 0;		//�� �ʱ�ȭ
		for (q = bday; q < bday + 2; q++) {	//�ӽ� ���ڿ��� ���� ���� ���Ͽ�
			mon *= 10;
			mon += *q - '0';				//������ ������ ��ȯ
		}

		if (key == mon)	//ã������ ���� ���� ��� �ش��� ���� ���
			printf("%s %s %s\n", p[i]->name, p[i]->tel_no, p[i]->birth);
	}
}