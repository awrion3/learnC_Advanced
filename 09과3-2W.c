#pragma warning(disable:4996)
#include <stdio.h>

void PRT(int, char*);

int main(void) {

	char ar[101], *p, *map = NULL;
	int n = 0, fl = 0, len = 0, max = -1;

	for (p = ar; p < ar + 100; p++){
		scanf("%c", p);
		n++;
		if (*p == '#')
			break;
	}

	for (p = ar; p < ar + n; p++)
		if (*p >= 'a' && *p <= 'z'){
			printf("%c", *p);
			len++;

			if (max < len) {
				max = len;
				if (fl == 0)
					map = p;
			}
			fl = 1;
		}
		else{
			if (fl == 1)
				printf("\n");
			fl = 0; 
			len = 0;
		}

	printf("%d %c\n", max, *map);

	PRT(max, map);

	return 0;
}

void PRT(int n, char* p) {

	char* t;

	for (t = p; t < p + n; t++)
		printf("%c", *t);
}