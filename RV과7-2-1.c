#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char ch, X[100], idx = 0;
	char Y[100], jdx = 0, isdup;
	int C[100] = { 0 };

	scanf("%c", &ch);
	while (ch != '!') {
		X[idx++] = ch;
		scanf("%c", &ch);
	}

	for (int i = 0; i < idx; i++){
		isdup = 0;
		for (int j = 0; j < i; j++)
			if (X[i] == X[j])
				isdup = 1;

		if (isdup == 0)
			Y[jdx++] = X[i];
	}

	for (int j = 0; j < jdx; j++)	   //�ߺ������� �迭 Y ��������
		for (int i = 0; i < idx; i++)	
			if (X[i] == Y[j])		   //�迭 X�� ���� ���� ���� Ȯ�� �� ����
				++C[j];

	for (int i = 0; i < jdx; i++)
		printf("%c %d\n", Y[jdx - 1 - i], C[jdx - 1 - i]);

	return 0;
}
//ccccaaaattttbbbbccccaaaattttdddd!