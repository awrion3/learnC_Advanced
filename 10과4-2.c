#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//���ڿ� ó�� ǥ�� �Լ� ����

//�Լ� ����
int check_w(char*, char*);

int main(void) {

	char str[101], wlist[10][101], wnt[10], tstr[101];		//�� ���� ���� ����
	int N, M, i = 0, idx, tmp;	   //������ ���� ���� �� �ʱ�ȭ
	
	scanf("%d%d", &N, &M);	//���ڿ� N�� ���� M��° �� �Է�
	getchar();				//����Ű ���� ����

	for (int k = 0; k < N; k++) {	//���ڿ� N�� �Է¹ޱ�
		gets_s(str, 100);	//���� ���Ե� ���ڿ� �Է�

		//ó������ M��° ���ڱ��� ���ĺ� ���� ���� ���� ���� Ȯ���� ��ȯ�� ����
		wnt[i] = check_w(str, str + M - 1); 

		strcpy(wlist[i], str); //���ڿ��� ������ �迭�� ����
		
		i++;	//�ε��� ����
	}

	idx = i;	//�ε��� ����
	for (int i = 0; i < idx - 1; i++) {		//���� ���� �������
		for (int j = 0; j < idx - 1; j++)
			if (wnt[j] < wnt[j + 1]) {	//���� ���� ������ ������
				tmp = wnt[j];
				wnt[j] = wnt[j + 1];	//�迭�� �������� �̵�
				wnt[j + 1] = tmp;

				strcpy(tstr, wlist[j]);			//���ڿ��� ������ ������ ����
				strcpy(wlist[j], wlist[j + 1]);	
				strcpy(wlist[j + 1], tstr);		//������ �迭 ������ ��ȯ�ϸ� �̵�
			}
	}

	for (int i = 0; i < idx; i++)		//������ �迭�� �ε����� �����Ͽ�
		if (wnt[i] != 0)				//���ĺ� ���� ���� ������ ������ 0�� ��츦 ���ϰ�
			printf("%s\n", wlist[i]);	//���ĵ� ���ڿ� ���

	return 0;
}

//�Լ� ����
int check_w(char *p, char *q) {

	char *t;
	int len, cnt = 0;	//���� ���� �� �ʱ�ȭ

	len = strlen(p);	//���ڿ� ���� ���ϱ�

	if (p + len - 1 < q) {	//q�� ���� ���ڿ��� ������ ���� �ּҺ��� �� ū ���
		for (t = p; t < p + len; t++) {	//���ڿ� �������� �˻��Ͽ�
			if (!(*t >= 'A' && *t <= 'Z') &&
				!(*t >= 'a' && *t <= 'z') &&	//���� ���ĺ���
				!(*t == ' '))					//������ �ƴ� ������ ���
				cnt++;	//���� ���� ī��Ʈ
		}
	}
	else {					//q�� ���� ���ڿ��� ������ ���� �ּ� ���� �ִ� ���
		for (t = p; t <= q; t++) {		//M��° ���ڱ��� �˻��Ͽ�
			if (!(*t >= 'A' && *t <= 'Z') &&
				!(*t >= 'a' && *t <= 'z') &&	//���� ���ĺ���
				!(*t == ' '))					//������ �ƴ� ������ ���
				cnt++;	//���� ���� ī��Ʈ
		}
	}

	return cnt;		//���� ���� ī��Ʈ ��ȯ
}
/*
5 15
1 year is 365 days.
How are you doing?
**Notice**
Winter is coming
1+1=2
*/