#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char ar[201], wd[20][200], *p, tm[200];
	int n, i = 0, idx;

	gets_s(ar, 200);
	n = strlen(ar);

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

	idx = i;
	for (int i = 0; i < idx; i++)
		printf("%s\n", wd[i]);

	for (int i = 0; i < idx - 1; i++)
		for (int j = 0; j < idx - 1; j++)	//���� ����
			if (strcmp(wd[j], wd[j + 1]) > 0) {	//������ �迭 �������� ����
				strcpy(tm, wd[j]);
				strcpy(wd[j], wd[j + 1]);
				strcpy(wd[j + 1], tm);
			}

	for (int i = 0; i < idx; i++)
		printf("%s ", wd[i]);

	return 0;
}
/*
simple is best
i am a boy
*/