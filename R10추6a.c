#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void StringAdd(char [], char, int);
int Convertor(char);

int main(void) {

	char ar[16], ch, *p = ar;
	int len, num, odd, old;

	scanf("%s", ar);

	len = strlen(ar);

	if (Convertor(*p) % 2 == 0)
		odd = 0;
	else 
		odd = 1;

	for (int i = 1; i < len; i++) {
		num = Convertor(*(p + i));
		old = odd;

		if (num % 2 == 0) {
			odd = 0;
			if (odd == old) {
				ch = '*';
				StringAdd(ar, ch, i);
				len++;
				i++;	//
			}
		}
		else {
			odd = 1;
			if (odd == old) {
				ch = '+';
				StringAdd(ar, ch, i);
				len++;
				i++;	//
			}
		}
	}

	printf("%s", ar);

	return 0;
}
void StringAdd(char ar[], char ch, int idx) {

	char *q, *p = ar + idx;
	int len;

	len = strlen(ar);
	
	for (q = ar + len; q >= ar + idx; q--)
		*(q + 1) = *q;

	*p = ch;
}

int Convertor(char x) {

	x -= '0';

	return x;
}

/*
132456
33332222
*/