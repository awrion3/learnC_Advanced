#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int row, col, **p, fl = 0;	//���� ������ ����
	char ch = 'a';

	scanf("%d %d", &col, &row);	//�� �� �Է�

	p = (int**)malloc(row * sizeof(int*));	
	//���� ������ (������ �迭 ���� ��: *ar[5], �̷��� �迭 �̸� *ar�� ����Ű�� ������;
	//������'��' �ּҸ� ����Ű�� ������)

	for (int i = 0; i < row; i++){
		p[i] = (int*)malloc(col * sizeof(int));	
		//p[i]�� �ּ�(������ �迭�� ����), ����: *p[i]�� ��(������ �迭�� ���Ұ� ����Ű�� ��) 
		//== *(p + i)                            == **(p + i)

		for (int j = 0; j < col; j++){
			if (ch > 'z')				//�ʰ��� ��� �ʱ�ȭ
				ch = 'A';
			if (ch > 'Z' && ch < 'a')	//������ ��� �ʱ�ȭ
				ch = 'a';				
			
			p[i][j] = ch++;	//p[i]�� �ּҶ��, ���� *(p[i] + j)�� �ǹ��Ѵ�
			//������ �迭�� ������ ������p[i]�� ����Ű�� �迭�� �����Ͽ� �� ���Ұ� ����
		}
	}
	
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++)	//����� �� ���
			printf("%c ", p[i][j]);
		printf("\n");
	}

	for (int i = 0; i < row; i++)	//���ʷ� �����Ҵ� ����
		free(p[i]);
	free(p);

	return 0;
}
/*
9 6
*/