#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	FILE* fp;
	int num, cnt = 0, sum = 0;
	double avg;

	fp = fopen("data.txt", "w");

	scanf("%d", &num);
	while (!feof(stdin)) {
		fprintf(fp, "%d\n", num);
		scanf("%d", &num);
	}

	fclose(fp);

	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("Couldn't open file");
		return -1;
	}

	fscanf(fp, "%d", &num);
	while (!feof(fp)) {
		cnt++;
		sum += num;
		fscanf(fp, "%d", &num);
	}

	avg = (double)sum / cnt;

	fclose(fp);

	printf("%d\n%d\n%.2f", cnt, sum, avg);

	return 0;
}