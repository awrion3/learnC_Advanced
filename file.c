#include "my_func.h"

int reg_from_file(TEL** p, int cnt, int max) {	//���� ��� �Լ�//

	FILE* fp;	//���� ����ü ������ ����
	TEL smp;	//����ü ���� ���� ����
	char tmp[101], tmp2[101], tmp3[101];	//�ӽ� ���ڿ�
	int len;	//���ڿ� ����

	fp = fopen("PHONE_BOOK.txt", "r");	//�б� ���� ���� ����
	if (fp == NULL)	//���� ���� ���� ��, �Լ� ���� �� �ε��� ��ȯ
		return cnt;

	//���Ϸκ��� �̸�, ��ȭ��ȣ, ���� �Է�
	fscanf(fp, "%s %s %s", tmp, tmp2, tmp3);

	while (!feof(fp)) {	//������ �� Ȯ��
		if (cnt >= max) {					//����//
			printf("OVERFLOW\n");
			fclose(fp);	//���� �ݱ�
			return cnt;	//�ʰ��� �Լ� ���� �� �ε��� ��ȯ
		}
		else {
			//����ü ���� �ϳ��� �����Ҵ�2
			p[cnt] = (TEL*)malloc(sizeof(TEL));
			if (p[cnt] == NULL)	//�����Ҵ�2 Ȯ��
				return -1;

			//���ڿ� �����Ҵ�3-1
			len = strlen(tmp);
			p[cnt]->name = (char*)malloc((len + 1) * sizeof(char));
			strcpy(p[cnt]->name, tmp);		//�Ҵ�� ������ �̸� ���ڿ� ����

			//���ڿ� �����Ҵ�3-2
			len = strlen(tmp2);
			p[cnt]->tel_no = (char*)malloc((len + 1) * sizeof(char));
			strcpy(p[cnt]->tel_no, tmp2);	//�Ҵ�� ������ ��ȭ��ȣ ���ڿ� ����

			//���ڿ� �����Ҵ�3-3
			len = strlen(tmp3);
			p[cnt]->birth = (char*)malloc((len + 1) * sizeof(char));
			strcpy(p[cnt]->birth, tmp3);	//�Ҵ�� ������ ���� ���ڿ� ����

			for (int i = 0; i < cnt; i++) {	//����//
				if (strcmp(p[i]->name, p[cnt]->name) > 0) {	//���� �̸����� �� �̸��� �ռ� ���
					smp = *(p[i]);
					*(p[i]) = *(p[cnt]);			   //����ü �� ������ ���� ���� ��ġ�� �̵�
					*(p[cnt]) = smp;
				}
			}

			cnt++;	//����ü �迭 ũ�� ����
		}

		//���Ϸκ��� �̸�, ��ȭ��ȣ, ���� �Է�
		fscanf(fp, "%s %s %s", tmp, tmp2, tmp3);
	}

	fclose(fp);	//���� �ݱ�
	return cnt;	//�ε��� ��ȯ
}