#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//���ڿ� ó�� �Լ� ����

int main(void) {

	char str[101], mins[101], maxs[101], *p;	//�� ���� ����
	char maxw[101] = { "" }, minw[101] = { "" }, neww[201];			//���� �ִ� ���̿� ����
	int N, len, minlen = 101, maxlen = -1, M1, M2, mx = 0, mn = 0;	//������ ���� ���� �� �ʱ�ȯ

	scanf("%d%d%d", &N, &M1, &M2);	//N��, M1 �� M2��° �Է�
	getchar();						//����Ű ���� ����

	for (int i = 0; i < N; i++) {	//N���� ���ڿ� �Է¹ޱ�
		gets_s(str, 100);		//������ �����Ͽ� ���ڿ� �Է�
		len = strlen(str);		//���ڿ� ���� ���

		if (len < minlen) {		//��ȣ�� �������� �ʾ�, ���� ���� �� ���� �Էµ� ���ڿ��� �ݿ�//
			minlen = len;		//���� ª�� ���ڿ� ���� ����
			strcpy(mins, str);	//���� ª�� ���ڿ� ����
		}

		if (len > maxlen) {		
			maxlen = len;		//���� �� ���ڿ� ���� ����
			strcpy(maxs, str);	//���� �� ���ڿ� ����
		}
	}
	
	printf("%s\n", maxs);	//���� �� ���ڿ� ���
	printf("%s\n", mins);	//���� ª�� ���ڿ� ���

	for (p = maxs; p < maxs + maxlen; p++) {	//���� �� ���ڿ��� 
		if (*p == ' ')	//���� ���ڸ� �� ���ڷ� ��ü
			*p = '\0';
	}

	for (p = mins; p < mins + minlen; p++) {	//���� ª�� ���ڿ���
		if (*p == ' ')	//���� ���ڸ� �� ���ڷ� ��ü
			*p = '\0';
	}

	strcpy(maxw, maxs);	//ù �ܾ M1��° �ܾ�� �����Ͽ� ����
	for (p = maxs; p < maxs + maxlen; p++) {
		if (*p == '\0') {	//�� ���� ������
			mx++;				//ī���� ����
			if (mx == M1)	//ī���Ͱ� M1��°��
				strcpy(maxw, p + 1);	//�� ���� ������ �ܾ� ù ���� �������� �� ���ڱ��� ����
		}
	}

	strcpy(minw, mins);	//ù �ܾ M2��° �ܾ�� �����Ͽ� ����
	for (p = mins; p < mins + minlen; p++) {
		if (*p == '\0') {	//�� ���� ������
			mn++;				//ī���� ����
			if (mn == M2)	//ī���Ͱ� M2��°��
				strcpy(minw, p + 1);	//�� ���� ������ �ܾ� ù ���� �������� �� ���ڱ��� ����
		}
	}

	if (strcmp(maxw, minw) < 0) {	//M1��° �ܾ �� ���� ���
		strcpy(neww, maxw);		//���� �ܾ� ���� ����
		strcat(neww, minw);		//���� �ܾ� ����
	}
	else {							//M2��° �ܾ �� ���� ���
		strcpy(neww, minw);		//���� �ܾ� ���� ����
		strcat(neww, maxw);		//���� �ܾ� ����
	}

	printf("%s", neww);		//������� �ϳ��� �ܾ ���

	return 0;
}
/*
5 4 2
book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
candy cake icecream
july august september october november december

���� ���� ������ ����鸸 �����ϴ� ���,
ù ��° ������ ���� �� �� ���� ª�� ���ڿ��� ���ÿ� �����Ǿ�
�ش� ���� �� �� �ܾ ������ ����� ����.

�ݷ�)
5 0 2
book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
candy cake icecream
july august september october november december

���� ���:
july august september october november december
candy cake icecream
icecreamjuly

�߸� ���: 
icecream�� ����
�� 0�� �ܾ� �ݿ��� ����
-> 41, 50 �߰�
*/