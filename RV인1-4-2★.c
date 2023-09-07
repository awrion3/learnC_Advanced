#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char ch, min, smin, fl = 0;
	char rh, rmin, rsmin, pl = 0;

	scanf("%c", &ch);
	while (ch != '!') {

		if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') {

			rh = ch >= 'a' && ch <= 'z' ? 'A' + 2 * (ch - 'a') + 1 : 'A' + 2 * (ch - 'A'); //char range

			if (fl == 0) {
				rmin = 127; rsmin = 126; //char

				min = ch; smin = ch;
				fl = 1;
			}

			if (rmin > rh) {
				rsmin = rmin;
				rmin = rh;

				smin = min;
				min = ch;
			}
			else if (rmin < rh && rsmin > rh) {
				rsmin = rh;

				smin = ch;
			}
			pl = 1;
		}
		else {
			if (pl == 1) {
				printf("%c%c\n", min, smin);
				pl = 0;
			}
			fl = 0;
		}
		scanf("%c", &ch);
	}
	return 0;
}
//***sAd123Ijfgh789Kup###!
//2468eE#$%gG^13Ttsuv57*()!

/*
	char ch, rh, min, smin;
	char al = 0, fl = 0, rin, srin;

	scanf("%c", &ch);
	while (ch != '!') {

		if (fl == 0) {
			rin = 'A' + 2 * ('z' - 'a') + 1;
			srin = 'A' + 2 * ('y' - 'a') + 1;
			min = ch; //errorÁ¦°Å
			fl = 1;
		}

		if (ch >= 'A' && ch <= 'Z') {
			rh = 'A' + 2 * (ch - 'A');

			if (rh < rin) {
				srin = rin;
				rin = rh;

				smin = min;
				min = ch;
			}
			else if (rh < srin) {
				srin = rh;
				smin = ch;
			}
			al = 1;
		}
		else if (ch >= 'a' && ch <= 'z') {
			rh = 'A' + 2 * (ch - 'a') + 1;

			if (rh < rin) {
				srin = rin;
				rin = rh;

				smin = min;
				min = ch;
			}
			else if (rh < srin) {
				srin = rh;
				smin = ch;
			}
			al = 1;
		}
		else {
			if (al == 1)
				printf("%c%c\n", min, smin);
			fl = 0;
			al = 0;
		}
		scanf("%c", &ch);
	}

*/