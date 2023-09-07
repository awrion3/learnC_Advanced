#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char c1, c2, is = 0;
	char a, b, c, r1, r2, r3, si = 0;

	scanf("%c%c-%c%c%c", &c1, &c2, &a, &b, &c);

	for (int i = c1; i <= c2; i++)
		for (int j = c1; j <= c2; j++)
			for (int k = c1; k <= c2; k++)
				if (!(i == j && j == k))
					if (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u')
						if (i <= j && j <= k || k <= j && j <= i) {
							printf("%c%c%c\n", i, j, k);
							is = 1;
							if (a > i || a == i && b > j || a == i && b == j && c > k) {
								r1 = i; r2 = j; r3 = k;			//사전상 '빠른' 문자이다
								si = 1;
							}
						}

	if (is == 0)
		printf("none\n");

	if (si == 0)
		printf("none\n");
	else
		printf("%c%c%c)\n", r1, r2, r3);

	return 0;
}
//dg-fff
//np-nno
//jn-mmm

/*
	char c1, c2, is = 0;
	char t1, t2, t3, r1, r2, r3, as = 0;

	scanf("%c%c-%c%c%c", &c1, &c2, &t1, &t2, &t3);

	for (char i = c1; i <= c2; i++)
		for (char j = c1; j <= c2; j++)
			for (char k = c1; k <= c2; k++)
				if (!(i == j && i == k))
					if (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u')
						if (i <= j && j <= k || k <= j && j <= i) {
							printf("%c%c%c\n", i, j, k);
							is = 1;
							if (i < t1 || i == t1 && j < t2 || i == t1 && j == t2 && k < t3) {
								r1 = i; r2 = j; r3 = k;
								as = 1;
							}
						}

	if (is == 0)
		printf("none\n");

	if (as == 0)
		printf("none\n");
	else
		printf("%c%c%c\n", r1, r2, r3);
*/