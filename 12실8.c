#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int N, len, min = 101;
	char **p, tmp[101], *q = NULL;

	scanf("%d", &N);
	getchar();	//gets ���

	p = (char**)malloc(N * sizeof(char*));	//���� ������ ���
	
	if (p == NULL) {	//�����Ҵ� �� Ȯ��
		printf("Not enough Memory");
		return -1;
	}

	for (int i = 0; i < N; i++){
		gets_s(tmp, 100);	
		len = strlen(tmp);	//�ӽ� ���ڿ� ���� ���

		p[i] = (char*)malloc((len + 1) * sizeof(char));	//�� ���� �����ؼ� ���߾� ���

		if (p[i] == NULL) {	//�����Ҵ� �� Ȯ��
			printf("Not enough Memory");
			return -1;
		}

		strcpy(p[i], tmp);	//����� ���ڿ��� ����

		if (len < min) {	//�ּ� ���� ���ڿ� ���ϱ�
			min = len;
			q = p[i];
		}
	}

	printf("%s", q);	//�ּ� ���� ���ڿ� ���

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