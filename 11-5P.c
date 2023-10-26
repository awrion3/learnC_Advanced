#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct player {
	char name[11];
	int atk, hp;
};

int main(void) {

	struct player st[10], *p, *q, smp;
	int N, fin = 0;
	char p1[11], p2[11];

	scanf("%d", &N);

	for (p = st; p < st + N; p++) {
		scanf("%s %d %d", p->name, &p->atk, &p->hp);
	}

	for (int i = 0; i < 5; i++){
		scanf("%s", p1);
		scanf("%s", p2);

		for (p = st; p < st + N; p++)
			if (strcmp(p1, p->name) == 0) 
				for (q = st; q < st + N; q++)
					if (strcmp(p2, q->name) == 0)
						p->hp -= q->atk;
			
		for (p = st; p < st + N; p++)
			if (strcmp(p2, p->name) == 0)
				for (q = st; q < st + N; q++)
					if (strcmp(p1, q->name) == 0)
						p->hp -= q->atk;
	
		for (p = st; p < st + N; p++)
			if (p->hp <= 0) {
				fin = 1;
				p->hp = 0;
			}
				
		if (fin == 1)
			break;
	}

	for (int i = 0; i < N; i++)
		for (p = st; p < st + N -1;p++)
			if (p->hp < (p + 1)->hp) {
				smp = *p;
				*p = *(p + 1);
				*(p + 1) = smp;
			}

	for (p = st; p < st + N; p++)
		printf("%s %d\n", p->name, p->hp);

	return 0;
}
/*
5
Harry 50 100
Ron 5 40
Hermione 10 50
Voldemort 40 80
Hagrid 30 70
Harry Voldemort
Ron Hagrid
Hagrid Voldemort

4
warrior 60 100
wizard 90 50
assassin 100 30
archer 70 70
warrior archer
assassin wizard
*/