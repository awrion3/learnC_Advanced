#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� ǥ�� �Լ� ����

int main(void) {

	char A[101], B[11], C[11], *p;	//�� ���� ����
	char R[250] = { "" }, *r = R;	//�� �迭 ���� ���� ����
	int blen, clen;				//������ ���� ����

	gets_s(A, 100);	//���� ���� ���ڿ� A �Է�

	scanf("%s", B);	//���� ������ ���ڿ� B �Է� 
	scanf("%s", C);	//���� ������ ���ڿ� C �Է� 
	
	blen = strlen(B);	//���ڿ� B ���� ���ϱ�
	clen = strlen(C);	//���ڿ� C ���� ���ϱ�

	for (p = A; *p; p++) {	//�� ���� ������ ���ڿ� A ������ 
		//�ش� �������� B ���̸�ŭ ���Ͽ��� �� 
		if (strncmp(p, B, blen) == 0) {	//���ڿ� B�� ���ڿ� A�� ���Ե� ���
			strcat(R, C);	//���ڿ� C�� ġȯ�� R�� ����

			p += (blen - 1);	//�ε��� B ���� -1��ŭ �̵�
			r += clen;			//�ε��� C ���̸�ŭ �̵�
		}
		else {				//���Ե��� ���� ���
			*r = *p;		//���� ���ڿ� A�� R�� ����
			r++;				//�ε��� ��ĭ�� �̵�	
		}
	}

	//ġȯ�� �Ϸ�� �ϳ��� ���ڿ� ���
	printf("%s", R);

	return 0;
}
/*
I have a pen. I have an applepen. PPAP.
pen
mouse

Sequence GTCGTCG
GTCG
CAGC
*/