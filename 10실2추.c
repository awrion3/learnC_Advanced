#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>			//���ڿ� ó�� �Լ� ����

int main(void) {

	char str1[101], str2[101], *p, rstr[201];	//�� ���� ����
	char *mp, *np, mw[101], nw[101];
	int M, N, mlen, nlen, mnt = 0, nnt = 0;		//������ ���� ���� �� �ʱ�ȭ
	
	scanf("%d%d", &M, &N);		//M�� N �Է�
	getchar();					//����Ű ���� ����

	gets_s(str1, 100);			//������ �����ϴ� �� ���ڿ� �Է�
	gets_s(str2, 100);

	mlen = strlen(str1);		//�� ���ڿ��� ���� ���ϱ�
	nlen = strlen(str2);

	mp = str1;					//0��°�� ù �ܾ�� ����
	for (p = str1; p < str1 + mlen; p++) {
		if (*p == ' ') {		//���� �� ���ڷ� ��ü
			*p = '\0';
			
			mnt++;				//�ܾ� ���� ī����//
			if (mnt == M) {		//�ܾ� ������ M��°�̸�
				mp = p + 1;		//���� ������ �ܾ� ù ���ڷ� ������ ����
			}
		}
	}

	np = str2;					//0��°�� ù �ܾ�� ����
	for (p = str2; p < str2 + nlen; p++) {
		if (*p == ' ') {		//���� �� ���ڷ� ��ü
			*p = '\0';

			nnt++;				//�ܾ� ���� ī����//
			if (nnt == N) {		//�ܾ� ������ N��°�̸�
				np = p + 1;		//���� ������ �ܾ� ù ���ڷ� ������ ����
			}
		}
	}
	
	strcpy(mw, mp);	//������ �������� �� ���ڱ��� ����
	strcpy(nw, np);	

	if (strcmp(mw, nw) < 0) {	//�� �ܾ� �� ���� �� ���� �ܾ
		strcpy(rstr, mw);		//���� �����ϰ�
		strcat(rstr, nw);		//������ �ܾ �� ���� �������� �����Ѵ�
	}
	else {						//�ݴ��� ��쵵 ��������
		strcpy(rstr, nw);
		strcat(rstr, mw);
	}

	printf("%s", rstr);			//������� �ϳ��� �ܾ �ѹ��� ���

	return 0;
}
/*
2 4
book desk pencil paper
orange apple banana lemon grape
*/