#pragma warning(disable:4996)
#include <stdio.h>

//�Լ� ����
void eliminate(char []);

int main(void) {

	//���� �� �Է�
	char ar[100], *p = ar;

	for (; p < ar + 100; p++) {
		scanf("%c", p);

		if (*p == '*')	//*������ �迭 ���� �Է¹ޱ�
			break;
	}

	//�Լ� ȣ��
	eliminate(ar);

	//���� �� ���
	for (p = ar; p < ar + 100; p++) {
		printf("%c", *p);
	
		if (*p == '*')	//*������ �迭 ���� ����ϱ�
			break;
	}

	return 0;
}

//�Լ� ����
void eliminate(char ar[]) {

	int N = 0, fl, idx = 0;
	char *p = ar, *q, rr[100], *r = rr;

	//�迭�� ���� ���
	for (; p < ar + 100; p++, N++) 
		//*�� ������ �ݺ� �����ϹǷ� �ε����� �¾ƶ������� ������ ����
		if (*p == '*')
			break;

	//�ߺ� ���� 	
	//<= ���� �������� ���� �� ������ *�� ������ �����ؾ� �Կ� ����; *p++ = '*';
	for (p = ar; p <= ar + N; p++){
		fl = 0;

		//���� ���� ���� ������ �ߺ��Ǵ� ���Ұ� ���� �� �ߺ� ǥ��
		for (q = ar; q < p; q++)
			if (*p == *q) 
				fl = 1;

		//�ߺ��Ǵ� ���Ұ� ������ ������ �� �� �迭�� ����
		if (fl == 0) {
			*r++ = *p;
			idx++; //���̵� ���ϱ�
		}
	}

	//�� �迭�� ���� �迭�� �����
	for (r = rr, p = ar; r < rr + idx; r++, p++)
		*p = *r;
}