#include "my_func.h"

int delete_tel(TEL** p, int cnt) { //���� �Լ�//

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