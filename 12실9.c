#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int N, len;
	char **p, tmp[101], *qmp;

	scanf("%d", &N);
	getchar();

	p = (char**)malloc(N * sizeof(char*));

	if (p == NULL) {
		printf("Not enough Memory");
		return -1;
	}

	for (int i = 0; i < N; i++) {
		gets_s(tmp, 100);
		len = strlen(tmp);

		p[i] = (char*)malloc((len + 1) * sizeof(char));
		
		if (p[i] == NULL) {
			printf("Not enough Memory");
			return -1;
		}

		strcpy(p[i], tmp);
	}

	for (int i = 0; i < N - 1; i++)	//�̹����� ���ڿ� �� ����
		for (int j = 0; j < N - 1; j++)
			if (strlen(p[j]) < strlen(p[j + 1])) {	//�������� ����(�� ���ڿ� �տ� ��ġ)
				qmp = p[j];
				p[j] = p[j + 1];	//���ڿ��� ������ ��� ��ܵǾ��⿡, strcpy()�� �ƴ�,
				p[j + 1] = qmp;		//����Ű�� �����͸� ��ȯ�ؾ� �Ѵ�
			}

	for (int i = 0; i < N; i++)	//���ĵ� ���ڿ��� ���
		printf("%s\n", p[i]);

	for (int i = 0; i < N; i++)	//���ʴ�� �����Ҵ� ����
		free(p[i]);
	free(p);

	return 0;
}
/*
4
Program
Good
This is string
language
*/