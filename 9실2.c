#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	//���� ����(�迭 �� ������ ����)
	char ch[20], ca, *pch = ch;
	int idx = 0;

	//���� �� �Է�(������ �ּ� ���ϸ� �迭 ����)
	for (; pch < ch + 20; pch++) {
		scanf("%c", &ca);
		if (ca == '\n')	//����Ű �Է½� �ݺ� ����
			break;	
		else 
			*pch = ca; //�����ͷ� �迭 ���� �����Ͽ� �� ����
	}

	//���� �� ����
	for (pch = ch; pch < ch + 20; pch++, idx++) {
		if (*pch == '#') //ù��° ���� #�� ��ġ Ȯ��
			break;
	}

	//���� �� ���
	for (pch = ch + idx - 1; pch >= ch; pch--)
		printf("%c", *pch); //ù��° # ���� ���ں��� �������� ���

	return 0;
}