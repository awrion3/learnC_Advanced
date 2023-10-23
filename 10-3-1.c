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

	for (p = A; p <= A + aln; p++) {	//널 문자까지 복사
		if (strncmp(p, B, bln) == 0) {	//B 단어가 포함되어 있는 부분은 C 단어로 치환해서 복사
			for (q = C; q < C + cln; q++, r++)
				*r = *q;
			p += bln - 1;	//위의 p++ 고려
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