#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char str[201], *p, news[201] = { 0 }, *q = news;	//���� ��� �� �� ���� ����
	int N, len, num;

	scanf("%s", str);
	scanf("%d", &N);

	len = strlen(str);

	for (p = str; p < str + len; p++) {
		//�ƽ�Ű �ڵ�ǥ ���� (��ҹ��� ������� ���� ù ���� A���ͷ� �����Ѵ�)
		if (*p >= 'A' && *p <= 'Z') {	
			*q = *p + N > 'Z' ? 'A' + (*p + N - 'Z' - 1) : *p + N;
			q++;
		}
		else if (*p >= 'a' && *p <= 'z') {
			*q = *p - N < 'A' ? 'Z' + (*p - N - 'A' + 1) : *p - N;
			q++;
		}
		else if (*p >= '1' && *p <= '9') {
			if (*(p + 1) >= '0' && *(p + 1) < '7') {
				num = *p - '0';	//�����̹Ƿ� atoi ��� �Ұ�
				num *= 10;
				num += *(p + 1) - '0';
				p++; //������ �߰� �̵� ����
			}
			else
				num = *p - '0';

			for (int i = 0; i < N; i++, q++)	//������ �̵� ����
				*q = 'A' + num - 1;	//0��°�� �ƴ� 1��° ���ڴ� A��
		}
		else {
			*q = ' ';
			q++;
		}
	}
	strcpy(str, news);

	printf("%s", str);

	return 0;
}
/*
CLikp5tGLE?Qej15J
2
*/