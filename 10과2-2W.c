#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char tmp[201], wlist[20][201] = { 0 };
	char *p, *q, word[201], str[201] = { 0 }, sp[2] = " ";
	int len, idx = 0, dup = 0;

	gets_s(tmp, 200);

	len = strlen(tmp);

	for (p = tmp; p < tmp + len; p++)
		if (*p == ' '){
			*p = '\0';
		}
	
	q = tmp;
	for (p = tmp; p <= tmp + len; p++)
		if (*p == '\0'){
			strcpy(wlist[idx++], q);
			q = p + 1;
		}

	scanf("%s", word);

	for (int i = 0; i < idx; i++)
		if (strcmp(word, wlist[i]) == 0){
			dup = 1;
			break;
		}

	if (dup == 0)
		strcpy(wlist[idx++], word);

	for (int i = 0; i < idx; i++)
		printf("%s\n", wlist[i]);

	for (int i = 0; i < idx - 1; i++)
		for (int j = 0; j < idx - 1; j++)
			if (strcmp(wlist[j], wlist[j + 1]) > 0) {
				strcpy(tmp, wlist[j]);
				strcpy(wlist[j], wlist[j + 1]);
				strcpy(wlist[j + 1], tmp);
			}

	for (int i = 0; i < idx; i++) {
		strcat(str, wlist[i]);
		strcat(str, sp);
	}

	printf("%s", str);

	return 0;
}