#include "my_func.h"

int reg_insert(TEL** p, int cnt, int max) { //��� �Լ�//

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