#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char ch, X[100], idx = 0;
	char Y[100], jdx = 0, isdup;
	char Z[100], kdx = 0;
	int M, fdx = 0;

	scanf("%c", &ch);
	while (ch != '!') {
		X[idx++] = ch;
		scanf("%c", &ch);
	}

	scanf("%d", &M);
	getchar();

	for (int i = 0; i < M; i++)
		scanf("%c", &Z[i]);

	//
	for (int i = 0; i < idx; i++) {
		isdup = 0;
		for (int j = 0; j < i; j++)
			if (X[i] == X[j])
				isdup = 1;

		if (isdup == 0)
			Y[jdx++] = X[i];
	}

	for (int i = 0; i < jdx; i++)
		printf("%c", Y[i]);
	printf("\n");
	
	//���� ���� Ȯ�� �� �� �ε��� ����
	for (int i = 0; i < jdx; i++)
		if (Z[kdx] == Y[i]) {
			kdx++;
			if (kdx == M) {
				fdx = i;
				break;
			}
		}
		else
			kdx = 0;

	if (fdx == 0)
		printf("none");
	else
		printf("%d", fdx - M + 1); //���� �ε��� ���

	return 0;
}
//abcdefgstopabcdefgsssstttop jklmnop!
//abcdeflowerffffooooeeeerrrrstststst!