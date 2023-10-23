#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char ar[100], *p;
	int fl = 0, max = -1, len = 0;

	for (p = ar; p < ar + 100; p++){
		scanf("%c", p);
		if (*p == '#')
			break;
	}

	for (p = ar; *p != '#'; p++) {
		if (*p >= 'a' && *p <= 'z') {
			printf("%c", *p);	

			if (*(p + 1) == '#')	//만약 #포함이었으면 굳이 X
				printf("\n");

			fl = 1;
			len++;
		}
		else {
			if (max < len)
				max = len;
			len = 0;

			if (fl == 1)
				printf("\n");
			fl = 0;
		}
	}

	printf("%d", max);

	return 0;
}
/*
banana25apple#
roll out electric334car#
*/