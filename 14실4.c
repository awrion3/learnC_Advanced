#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	FILE *fp1, *fp2;
	char fn1[21], fn2[21], ch;

	scanf("%s", fn1);
	scanf("%s", fn2);

	fp1 = fopen(fn1, "a");
	if (fp1 == NULL) {
		printf("Couldn't open file");
		return -1;
	}

	fp2 = fopen(fn2, "r");
	if (fp2 == NULL) {
		printf("Couldn't open file");
		return -1;
	}

	ch = fgetc(fp2);
	while (!feof(fp2)) {
		fputc(ch, fp1);
		ch = fgetc(fp2);
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}