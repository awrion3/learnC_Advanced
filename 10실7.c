#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N, V = 0, cnt = 0, num;
	char ar[50], *par = ar, *pstr = NULL, *q;
	//�� ����1 + �ִ� ����6 + �ִ� �ڸ��� ǥ��9 + �ִ� ���� ǥ��20 ���� ũ�� ����
	
	scanf("%d", &N);	//���� �Է�

	while (N != 0) {
		V *= 10;	//�� ������
		V += (N % 10); //���ڸ��� ���ϱ�

		cnt++;		//��ü �ڸ��� ���
		N /= 10;
	}

	while (V != 0) {
		num = V % 10;	//�� �ڸ��� �˻�

		if (num == 1) 		
			pstr = "one ";
		else if (num == 2)
			pstr = "two ";
		else if (num == 3)
			pstr = "three ";
		else if (num == 4)
			pstr = "four ";
		else if (num == 5)
			pstr = "five ";
		else if (num == 6)
			pstr = "six ";
		else if (num == 7)
			pstr = "seven ";
		else if (num == 8)
			pstr = "eight ";
		else if (num == 9)
			pstr = "nine ";
		else
			pstr = ""; //0�� ���� ������� ����

		for (q = pstr; *q; q++, par++)  //par�� �̾�޾� �ٿ��ֱ�
			*par = *q;
		
		if (num != 0) {	//0�� ��� �ڸ��� ǥ�⵵ ���Կ� ����//
			if (cnt == 4)
				pstr = "THO ";
			else if (cnt == 3)
				pstr = "HUN ";
			else if (cnt == 2)
				pstr = "TEN ";
			else
				pstr = "";	//���� �ڸ����� �ƹ��͵� ������ ����
		}					//(�� �ʱ�ȭ�� ���ľ� �Ʒ��� ������ �ڸ����� �ѹ��� �ٴ� ���� ������)
	
		for (q = pstr; *q; q++, par++)	//par�� �̾�޾� �ٿ��ֱ�
			*par = *q;

		V /= 10;		//�ڸ��� ����
		cnt--;	//ī���� ����
	}

	*par = '\0';	//(�ٿ��ֱ� �� �� �׻� �� ���ڴ� ���ܿ����Ƿ�)�� ���� �߰� (�ε��� ���� ���)
	printf("%s", ar);

	return 0;
}