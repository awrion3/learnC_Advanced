#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� ǥ�� �Լ� ����

int main(void) {

	char str[201], *p = str, dic[20][200], tmp[200];  //�� ���� ����
	int i = 0, j = 0, idx, len;				 //�ε��� ���� �� �ʱ�ȭ

	gets(str);			//���� �Է�
	len = strlen(str);	//���� ���� Ȯ��

	for (; p <= str + len; p++) {	//���� �� ���ڱ��� �ȱ�
		if (*p == ' ' || *p == '\0') {	//����(Ȥ�� �� ����)�� ��� �ܾ� �и�
			dic[i][j] = '\0';	//�ܾ�� �� ���� �߰�
			dic[i++];			 //�ٸ� �ܾ�� �ε��� �̵�
			j = 0;				 //�ܾ �ε��� �ʱ�ȭ
		}
		else {				//������ �ƴ� ���� ����
			dic[i][j++] = *p;	//�ܾ� ���ں� �����ϱ�
		}
	}

	idx = i;	//�ε��� ����
	for (int i = 0; i < idx; i++)	//������ �迭�� ����� �и��� �ܾ� ���
		printf("%s\n", dic[i]);

	for (int k = 0; k < idx - 1; k++) {	//���� ���� ������� idx - 1ȸ �ݺ�
		for (int i = 0; i < idx - 1; i++) {	//�ε��� ������ ������ ������ �迭 ����
			if (strcmp(dic[i], dic[i + 1]) > 0) {	//�� �ܾ ���� �� �ڿ� �ִ� ���
				strcpy(tmp, dic[i + 1]);
				strcpy(dic[i + 1], dic[i]);			//strcpy ����Ͽ� �� �ܾ ��ȯ
				strcpy(dic[i], tmp);
			}
		}
	}

	for (int i = 0; i < idx; i++)	//������ �迭�� ���ĵ� �и��� �ܾ� ���
		printf("%s ", dic[i]);

	return 0;
}
/*
simple is best
i am a boy

��)
�ε����� �ʱ�ȭ�� ����

��)
���⼭ dic[i]�� ����� ���� �ּҰ�, == *(dic + i)�� �ּ� �� ���� (char* ��)
dic[i][j]�� ���� ���ڴ� == *(*(dic + i) + j)�� ���� �� �����ϰ� ���� (char ��)
*/