#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct person {
	char name[11], birth[11];	//생일 관련 문자열 추가
	int wt, it;
	double res;
};

void swap(struct person*, struct person*);

int main(void) {

	struct person sp[100], *p;

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {	//생일 문자열 추가로 입력
		scanf("%s %s %d %d", sp[i].name, sp[i].birth, &sp[i].wt, &sp[i].it);
		sp[i].res = sp[i].wt * 0.8 + sp[i].it * 0.2;
	}

	for (int i = 0; i < N - 1; i++)
		for (p = sp; p < sp + N - 1; p++)
			if (p->res <= (p + 1)->res) {		//총점이 같거나 후자가 큰 경우
				if (p->res == (p + 1)->res) {	//총점이 같은 경우엔

					if (p->wt <= (p + 1)->wt) {		//필기 점수가 같거나 후자가 큰 경우
						if (p->wt == (p + 1)->wt) {	//필기 점수가 같은 경우엔
							if (strcmp(p->birth, (p + 1)->birth) < 0)	//후자가 생일이 늦은 경우에,
								swap(p, p + 1);	//호출하여 값 교환
						}
						else				//필기 점수 후자가 더 큰 경우에,
							swap(p, p + 1);		//호출하여 값 교환
					}
				}
				else						//총점 후자가 더 큰 경우에,
					swap(p, p + 1);				//호출하여 값 교환
			}

	for (p = sp; p < sp + M; p++)			//내림차순 정렬된 구조체에서 해당 합격자만큼 출력
		printf("%s %.1f\n", p->name, p->res);

	return 0;
}

void swap(struct person *p, struct person *q) {

	struct person tmp;	//구조체 선언

	tmp = *p;			//구조체 원소 간 대입하여 교환
	*p = *q;
	*q = tmp;
}
/*
7 3
Aaaaa 1995-10-07 75 85
Bbbbb 1991-11-15 90 64
Ccccc 1994-12-08 94 82
Ddddd 1993-07-17 78 70
Eeeee 1995-10-07 65 85
Fffff 1991-11-05 90 64
Ggggg 1990-08-21 90 64
*/