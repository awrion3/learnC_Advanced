#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int vowel(char);

int main(void) {

	char wa[101], wb[101], *p, *q;
	int lna, lnb, vl = -1;

	scanf("%s", wa);
	scanf("%s", wb);

	lna = strlen(wa);
	lnb = strlen(wb);

	p = wa, q = wb;
	while (p < wa + lna || q < wb + lnb){
		for (; p < wa + lna;)
			if (!vowel(*p)) {
				printf("%c", *p);
				p++;
			}
			else {
				printf("%c", *p);
				p++;
				break;
			}

		for (; q < wb + lnb;)
			if (!vowel(*q)) {
				printf("%c", *q);
				q++;
			}
			else {
				printf("%c", *q);
				q++;
				break;
			}
	} 
		
	return 0;
}

int vowel(char ch) {

	if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
		|| ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return 1;

	return 0;
}
/*
bbacc
ddOggh

bbaccab
ddOggh
*/