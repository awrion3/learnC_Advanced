#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {

	int N, s1[20], s2[20], tmp, rak[20];
	double avg[20], dmp;
	int A, B;
	char paf[20];

	//
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &s1[i]);

	for (int i = 0; i < N; i++)
		scanf("%d", &s2[i]);

	for (int i = 0; i < N; i++)
		avg[i] = s1[i] * 0.4 + s2[i] * 0.6;

	//
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			if (avg[i] < avg[j]) {
				dmp = avg[i];
				avg[i] = avg[j];
				avg[j] = dmp;

				tmp = s1[i];
				s1[i] = s1[j];
				s1[j] = tmp;

				tmp = s2[i];
				s2[i] = s2[j];
				s2[j] = tmp;
			}

	//
	for (int i = 0; i < N; i++) {
		rak[i] = 1;
		for (int j = 0; j < N; j++)
			if (avg[i] < avg[j])
				++rak[i];
	}

	//
	A = N * 0.3;
	B = N * 0.7;

	for (int i = 0; i < N; i++)
		if (rak[i] <= A)
			paf[i] = 'A';
		else if (rak[i] <= B)
			paf[i] = 'B';
		else {
			if (s2[i] >= 60)
				paf[i] = 'B';
			else
				paf[i] = 'F';
		}

	//
	for (int i = 0; i < N; i++)
		printf("%d %d %.1f %d %c\n", s1[i], s2[i], avg[i], rak[i], paf[i]);

	return 0;
}
//7
//32 30 92 70 70 68 12
//80 35 90 60 60 50 90