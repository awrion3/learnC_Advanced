#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char ar[201], wd[20][200], *p, tm[200];
	char nw[200], str[201] = { 0 }, sp[2] = " ";	//�� ���� �ʱ�ȭ
	int n, i = 0, idx, is = 0;

	gets_s(ar, 200);
	scanf("%s", nw);	//�ܾ� �Է�

	n = strlen(ar);

	//������ �迭 ����
	for (p = ar; p < ar + n; p++)
		if (*p == ' ')
			*p = '\0';

	p = ar;
	strcpy(wd[i], p);	//ù �ܾ� ����
	for (p = ar; p <= ar + n; p++) {	//�� ���ڱ��� �ȱ�
		if (*p == '\0') {
			i++;
			strcpy(wd[i], p + 1);
		}
	}

	//������ �迭�� �ܾ� ��
	idx = i;
	for (int i = 0; i < idx; i++) 
		if (strcmp(wd[i], nw) == 0) {
			is = 1;
			break;
		}
	
	//������ �迭�� �ܾ� �߰�
	if (is == 0) {
		strcpy(wd[i], nw);
		i++;	//�ε��� ���� �� ����
		idx = i;
	}

	//�ܾ ���
	for (int i = 0; i < idx; i++)
		printf("%s\n", wd[i]);

	//����
	for (int i = 0; i < idx - 1; i++)
		for (int j = 0; j < idx - 1; j++)	//���� ����
			if (strcmp(wd[j], wd[j + 1]) > 0) {	//������ �迭 �������� ����
				strcpy(tm, wd[j]);
				strcpy(wd[j], wd[j + 1]);
				strcpy(wd[j + 1], tm);
			}

	//������ ����
	for (int i = 0; i < idx; i++) {
		strcat(str, wd[i]);
		strcat(str, sp);
	}

	printf("%s", str);

	return 0;
}
/*
ant apple ace ape
arch

bag bat back bean box
back
*/