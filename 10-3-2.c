#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char A[101], B[101], R[251] = {0}, *p, W[100][101];
	char WB[100][101], sp[2] = " ";
	int al, bl, i = 0, k = 0, idx, dup, j = 0;
	
	gets_s(A, 100);
	gets_s(B, 100);

	//
	al = strlen(A);
	for (p = A; p <= A + al; p++)
		if (*p == ' ')
			*p = '\0';

	strcpy(W[i++], A);	//ù �ܾ� ����
	for (p = A; p < A + al; p++)
		if (*p == '\0') 
			strcpy(W[i++], p + 1);
	//

	idx = i;
	for (int i = 0; i < idx; i++) {			//�� �ܾ� ����
		dup = 0;
		for (int k = 0; k < i; k++) {
			if (strcmp(W[i], W[k]) == 0) 	//���� �ܾ� ����Ʈ�� ���Ͽ� �ߺ� Ȯ��
				dup = 1;
		}
		if (dup == 1)
			W[i][0] = '*';		//�ش� �ߺ� �ܾ� ǥ��
	}

	//
	bl = strlen(B);
	for (p = B; p < B + bl; p++)
		if (*p == ' ')
			*p = '\0';

	k = 0;
	strcpy(WB[k++], B);	//ù �ܾ� ����
	for (p = B; p < B + bl; p++)
		if (*p == '\0')
			strcpy(WB[k++], p + 1);
	//

	j = 0, k = 0;
	for (int i = 0; i < idx; i++) {
		if (W[i][0] == '*') {	//�ߺ� �ܾ��� ��� B���� ����
			strcat(R, WB[j++]);
			strcat(R, sp);
		}
		else {	//�ߺ����� �ʴ� �ܾ�� A���� ���� (���� ������� �ε����� ��� �̵�)
			strcat(R, W[k]);
			strcat(R, sp);
		}
		k++;
	}

	printf("%s", R);

	return 0;
}
/*
red orange red yellow green red blue purple yellow
white black gray pink brown blush crimson garnet vermilion indigo 
*/