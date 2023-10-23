#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void change(char*, char*, int, int);

int main(void) {

	char A[201], B[201], newA[201] = { 0 }, newB[201] = { 0 };	//���� ��� �� �� ���� ����
	char *p = A, *q = B;
	int N, lenA, lenB, fl = 0;

	gets_s(A, 200);
	gets_s(B, 200);
	
	N = *p > *q ? *p - *q : -(*p - *q);

	lenA = strlen(A);
	lenB = strlen(B);

	change(A, newA, lenA, N);
	change(B, newB, lenB, N);

	if (strcmp(newA, B) == 0)
		fl = 1;
	if (strcmp(A, newB) == 0)
		fl = 2;

	printf("%d", fl);

	return 0;
}

void change(char* str, char* news, int len, int N) {

	char *p, *q = news;
	int num;

	for (p = str; p < str + len; p++) {
		//�ƽ�Ű �ڵ�ǥ ���� (��ҹ��� ������� ���� ù ���� A���ͷ�, �� �빮�� ���� ����ȴٴ� ��)
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
}
/*
Qej15J
SchOOL
*/