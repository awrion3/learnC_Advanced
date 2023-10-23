#pragma warning(disable:4996)
#include <stdio.h>

struct student {
	char name[21];
	int kor, eng, math;
};

struct average {
	double kor, eng, math;
};

struct average calculate_avg(struct student*, int);

int main(void) {

	struct student ar[50];
	struct average st;

	int N, k = 0, e = 0, m = 0;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%s %d %d %d", ar[i].name, &ar[i].kor, &ar[i].eng, &ar[i].math);

	st = calculate_avg(ar, N);

	for (int i = 0; i < N; i++) {
		if (st.kor > ar[i].kor)
			k++;
		if (st.eng > ar[i].eng)
			e++;
		if (st.math > ar[i].math)
			m++;
	}

	printf("%.1f %.1f %.1f\n", st.kor, st.eng, st.math);
	printf("%d %d %d", k, e, m);

	return 0;
}

struct average calculate_avg(struct student* st, int N) {

	struct student *p;
	struct average sa = { 0 }; //
	
	for (p = st; p < st + N; p++) {
		sa.kor += p->kor;
		sa.eng += p->eng;
		sa.math += p->math;
	}

	sa.kor = (double)sa.kor / N;
	sa.eng = (double)sa.eng / N;
	sa.math = (double)sa.math / N;

	return sa;
}
/*
5
Kim 100 90 80
Lee 88 94 92
Park 92 100 100
Hong 84 82 85
Nam 80 84 72
*/