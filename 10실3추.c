#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>			//���ڿ� ó�� ǥ�� �Լ� ����

int main(void) {

	char str[201], wlist[20][200], *p, tmp[200];	//�� ���� ����
	int len, i = 0, j = 0, idx;

	gets_s(str, 200);	//������ �����ϴ� ���ڿ� �Է�

	len = strlen(str);	//���ڿ� ���� ���ϱ�

	for (p = str; p <= str + len; p++) { //�� ���ڱ��� �Ⱦ�
		if (*p == ' ' || *p == '\0') {		//�����̳� �� ���� ������
			wlist[i][j] = '\0';				//�ش� �迭�� �������� �� ���� ����
			wlist[i++];					//���� �迭�� �ε��� ����//
			j = 0;						//�� �迭�� �ε��� �ʱ�ȭ//
		}
		else {
			wlist[i][j++] = *p;			//�� �ϳ��ϳ� ī��
		}
	}

	idx = i;	//�� �迭 ���� �ε��� ����// 
	for (int i = 0; i < idx; i++)	//�� �迭 �����Ͽ� ���
		printf("%s\n", wlist[i]);

	for (int k = 0; k < idx - 1; k++) {		//���� ���� ������� idx - 1 ȸ �ݺ�
		for (int i = 0; i < idx - 1; i++)				//�Ʒ� �ε����� ����
			if (strcmp(wlist[i], wlist[i + 1]) > 0) {	//�� ���� �ܾ ������ �迭�� 
				strcpy(tmp, wlist[i]);					 
				strcpy(wlist[i], wlist[i + 1]);		 	//�� �迭�� �����ϸ� ��ȯ�ϱ�
				strcpy(wlist[i + 1], tmp);				 
			}
	}

	for (int i = 0; i < idx; i++)	//�� �迭 �����Ͽ� ���
		printf("%s ", wlist[i]);

	return 0;
}

/*
simple is best
i am a boy
*/