#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char A[101], B[11], C[11], *p, R[251] = {0}, *q, *r = R;
	int aln, bln, cln;

	gets_s(A, 100);
	scanf("%s", B);
	scanf("%s", C);

	aln = strlen(A);
	bln = strlen(B);
	cln = strlen(C);

	for (p = A; p <= A + aln; p++) {	//�� ���ڱ��� ����
		if (strncmp(p, B, bln) == 0) {	//B �ܾ ���ԵǾ� �ִ� �κ��� C �ܾ�� ġȯ�ؼ� ����
			for (q = C; q < C + cln; q++, r++)
				*r = *q;
			p += bln - 1;	//���� p++ ���
		}
		else
			*r++ = *p; 
	}

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