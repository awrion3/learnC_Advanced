#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	
	//���� ���� �� �ʱ�ȭ
	char ch[10], *p = ch, *q, mch;
	int fr[10], *f = fr, max = 1;

	//���� �� �Է�
	for (; p < ch + 10; p++) 
		scanf("%c", p);

	//���� �� ����
	for (p = ch; p < ch + 10; p++) {
		*f = 0;	//�󵵼� �ʱ�ȭ
		for (q = ch; q < ch + 10; q++)
			if (*p == *q)	//�ߺ��Ǹ�	
				++*f;		//�󵵼� �� ����
		f++;	//�󵵼� �迭 ������ �ε��� ����(������ Ȱ��)//
	}

	p = ch;	mch = *p;	//���� �󵵼��� ���� ���ڸ� ù ���ڷ� �ʱ�ȭ//
	for (f = fr; f < fr + 10; p++, f++)	//������ Ȱ���Ͽ� �󵵼� �迭 ���� �� �񱳸� ����
		if (max < *f) {
			max = *f;	//���� ���� �󵵼� ��
			mch = *p;	//���� �󵵼��� ���� ���� ����
		}

	//���� �� ���
	printf("%c %d", mch, max);

	return 0;
}