#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� ���� �Լ� ����
#include <stdlib.h>	//�����Ҵ� ���� �Լ� ����

//����ü ����
struct st {
	char *str;	//���ڿ� ����
	int cnt1;	//���� �� ����
	int cnt2;	//�� ���� �� ����
};

int main(void) {

	int N, len;			//������ ���� ����
	char tmp[101], *q;	//������ ���� ���� (�� ���� ����)
	struct st *sp, smp;	//����ü ������ �� ���� ����

	scanf("%d", &N);	//���� N �Է�

	sp = (struct st*)malloc(N * sizeof(struct st));	//����ü �迭 �����Ҵ�

	if (sp == NULL) {					//�����Ҵ� �˻�1
		printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
		return -1;
	}
		
	for (int i = 0; i < N; i++) {	//N���� ���ڿ� �Է�
		scanf("%s", tmp);	//���� �������� ���� ���ڿ� �Է�

		len = strlen(tmp);	//���ڿ� ���� Ȯ��

		sp[i].str = (char*)malloc((len + 1) * sizeof(char));	//����ü ��� ���ڿ� �����Ҵ� (�� ���� ����)

		if (sp[i].str == NULL) {			//�����Ҵ� �˻�2
			printf("Not enough memory");	//�޸� ���� Ȯ�� ���� �� ����
			return -1;
		}

		strcpy(sp[i].str, tmp);		//�����Ҵ�� ����ü ��� ���ڿ��� ����

		sp[i].cnt1 = 0, sp[i].cnt2 = 0;		//������ �ʱ�ȭ
		for (q = sp[i].str; q < sp[i].str + len; q++) {		//�ش� ���ڿ� �����ͷ� �����Ͽ�
			//�빮�� �� ������ ������ �ƴ� ���,
			if (*q != 'A' && *q != 'E' && *q != 'I' && *q != 'O' && *q != 'U'
				&& *q != 'a' && *q != 'e' && *q != 'i' && *q != 'o' && *q != 'u')
				sp[i].cnt1++;	//������ �� ����
			
			sp[i].cnt2++;		//�� ���� �� ����
		}
	}

	for (int i = 0; i < N - 1; i++)			//����ü �迭 ���� ���� ���
		for (int j = 0; j < N - 1; j++)
			if (sp[j].cnt1 <= sp[j + 1].cnt1) {		//������ ������ Ȯ���Ͽ�
				if (sp[j].cnt1 < sp[j + 1].cnt1) {	//���ڰ� ���� ��� �������� ����
					smp = sp[j];
					sp[j] = sp[j + 1];		//����ü �� ������ ���� ��ȯ
					sp[j + 1] = smp;
				}
				else {	//������ ���� ���� ���, �� ������ ���� Ȯ���Ͽ�
					if (sp[j].cnt2 < sp[j + 1].cnt2) {	//���ڰ� ���� ��� �������� ����
						smp = sp[j];
						sp[j] = sp[j + 1];	//����ü �� ������ ���� ��ȯ
						sp[j + 1] = smp;
					}
				}
			}

	for (int i = 0; i < N; i++)	//���ĵ� ����ü�� ��� ���ڿ� ���
		printf("%s\n", sp[i].str);	

	for (int i = 0; i < N; i++)	//����ü ��� ���ڿ� �����Ҵ� ���� ����
		free(sp[i].str);
	free(sp);					//����ü �迭 �����Ҵ� ����

	return 0;
}
/*
5
History
Politics
DonQuixote
LaPeste
Chaos
*/