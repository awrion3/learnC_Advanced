#include "my_func.h"

void find_by_birth(TEL** p, int cnt) { //�˻� �Լ�//

	char bday[5], * q;	//ã������ ���� ���� ����
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