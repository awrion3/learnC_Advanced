#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	FILE* fp;
	char str[10], *p;

	fp = fopen("test1.txt", "r");
	if (fp == NULL) {
		printf("Couldn't open file");
		return -1;
	}

	fgets(str, sizeof(str), fp);
	while (!feof(fp)) {
		fgets(str, sizeof(str), fp);
	}

	fclose(fp);

	for (p = str; p < str + 9; p++){
		if (*p >= 'A' && *p <= 'Z')
			*p += 'a' - 'A';
		else if (*p >= 'a' && *p <= 'z')
			*p -= 'a' - 'A';
	}

	fp = fopen("test2.txt", "w");

	fputs(str, fp);

	fclose(fp);

	return 0;
}