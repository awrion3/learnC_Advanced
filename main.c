#include "my_func.h"

int main(void) {

	FILE* fp; 		//���� ����ü ������ ����
	TEL** tel_list;	//���� ������ ����
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
		if (N == 6) {
			fp = fopen("PHONE_BOOK.txt", "w");	//���� ���� ���� ����
			if (fp == NULL)	//���� ���� Ȯ��
				return -1;

			for (int i = 0; i < count; i++)	//���Ϸ� ����ü ������ �迭�� ����� �����͸� ���
				fprintf(fp, "%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth);

			fclose(fp);	//���� �ݱ�
			break;
		}

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
		case 5:	//���� ���� �Լ� ȣ��
			count = reg_from_file(tel_list, count, max_num);//�ε��� ��ȯ
		}
	}

	//����ü ���� �����Ҵ� ����
	for (int i = 0; i < count; i++) {
		//����ü ���� ��� �����Ҵ�3 ����
		free(tel_list[i]->name); free(tel_list[i]->tel_no); free(tel_list[i]->birth);
		free(tel_list[i]); //����ü ���� �����Ҵ�2 ����
	}
	free(tel_list);	//����ü ������ �迭 �����Ҵ�1 ����

	return 0;
}