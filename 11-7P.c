#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct student {
	char name[21];
	char r_name[21];
};

struct student* change(struct student*);

int main(void) {

	struct student st[10] = { 0 }, *p, *q;
	int N;

	scanf("%d", &N);
	getchar();

	for (p = st; p < st + N; p++) 
		gets_s(p->name, 20);

	q = change(st);

	for (p = st; p < st + N; p++)
		printf("%s\n", p->r_name);

	printf("longest=%s", q->r_name);

	return 0;
}

struct student* change(struct student* st) {

	struct student *p, *map = NULL;
	char tmp[21], *r, rmp[2][21] = { 0 }, rev[21], sp[2] = " ";
	int len, max = -1, i;

	for (p = st; strlen(p->name); p++) {
		strcpy(tmp, p->name);

		len = strlen(tmp);
		if (len > max) {
			max = len;
			map = p;
		}

		for (r = tmp; r < tmp + len; r++)
			if (*r == ' ')
				*r = '\0';

		i = 0;
		strcpy(rmp[i++], tmp);
		for (r = tmp; r < tmp + len; r++)
			if (*r == '\0')
				strcpy(rmp[i], r + 1);

		strcpy(rev, rmp[i--]);
		strcat(rev, sp);
		strcat(rev, rmp[i]);

		strcpy(p->r_name, rev);
	}

	return map;
}
/*
3
hong gildong
kim hana
kim johnson
*/