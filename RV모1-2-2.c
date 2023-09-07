#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	char ch, A = 0, a = 0;
	char MIN = 'Z', max = 'a', Af, fl = 0;

	scanf("%c", &ch);
	while (ch != '0') {
		
		if (ch >= 'A' && ch <= 'Z') {
			A = 1; 
			if (MIN > ch)
				MIN = ch;
			
			if (fl == 0) {
				Af = 1;
				fl = 1;
			}
		}
		else if (ch >= 'a' && ch <= 'z') {
			a = 1;
			if (max < ch)
				max = ch;

			if (fl == 0) {
				Af = 0;
				fl = 1;
			}
		}

		scanf("%c", &ch);
	}
	
	if (A == 1 && a == 0) 
		printf("%c", MIN);
	if (A == 0 && a == 1) 
		printf("%c", max);
	if (A == 1 && a == 1) {
		if (Af == 0)
			printf("%c%c", max, MIN);
		else
			printf("%c%c", MIN, max);
	}
		
	return 0;
}