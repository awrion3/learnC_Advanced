#pragma warning (disable:4996)
#include <stdio.h>

char decrypt(char, int);
char encrypt(char, int);

int main(void) {

	char ar[100], ch;
	int M1, M2, idx = 0;

	scanf("%c", &ch);
	while (ch != '*') {
		ar[idx++] = ch;
		scanf("%c", &ch);
	}

	scanf("%d%d", &M1, &M2);

	for (int i = 0; i < idx; i++)
		printf("%c", decrypt(ar[i], M1));
	printf("\n");

	for (int i = 0; i < idx; i++)
		printf("%c", encrypt(decrypt(ar[i], M1), M2));

	return 0;
}

char decrypt(char ch, int M) {

	M %= 26;
	if (ch >= 'A' && ch <= 'Z') 
		ch = ch - M < 'A' ? 'Z' + (ch - 'A' - M + 1) : ch - M;
	else if (ch >= 'a' && ch <= 'z') 
		ch = ch - M < 'a' ? 'z' + (ch - 'a' - M + 1) : ch - M;

	return ch;
}

char encrypt(char ch, int M) {

	M %= 26;
	if (ch >= 'A' && ch <= 'Z')
		ch = ch + M > 'Z' ? 'A' + (ch - 'Z' + M - 1) : ch + M;
	else if (ch >= 'a' && ch <= 'z')
		ch = ch + M > 'z' ? 'a' + (ch - 'z' + M - 1) : ch + M;

	return ch;
}