#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//�� ��� ���� ���Խ�Ű��
#include <stdlib.h>

int main(void) {

	char tmp[101], **p, *qmp;
	int N, len;
	
	scanf("%d", &N);
	getchar();	//������ gets ���

	//�����Ҵ� �� Ȯ��
	p = (char**)malloc(N * sizeof(char*));	//���� ������ 
	
	if (p == NULL) {
		printf("not enough memory!");
		return -1;
	}
	
	for (int i = 0; i < N; i++) {
		gets_s(tmp, 100);
		len = strlen(tmp);

		//�����Ҵ� �� Ȯ��
		p[i] = (char*)malloc((len + 1) * sizeof(char));
		
		if (p[i] == NULL) {
			printf("not enough memory!");
			return -1;
		}
		
		strcpy(p[i], tmp);	//��ܵ� ���ڿ� ������ �ӽ� ���ڿ� �����ϱ�
	}

	//�̹��� ���������� �������� ����(���� �ܾ� �տ� ��ġ)
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			if (strcmp(p[j], p[j + 1]) > 0) {
				qmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = qmp;
			}

	for (int i = 0; i < N; i++)	//���� ��� ���
		printf("%s\n", p[i]);

	for (int i = 0; i < N; i++)	//���ʴ�� �����Ҵ� ����
		free(p[i]);
	free(p);

	return 0;
}
/*
4
apricot
peach
willow
birch
*/