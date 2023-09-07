#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N, s1[20], s2[20], rak[20], P;
	double avg[20];
	char paf[20];

	//
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &s1[i]);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &s2[i]);

	//
	for (int i = 0; i < N; i++)
		avg[i] = s1[i] * 0.4 + s2[i] * 0.6;

	for (int i = 0; i < N; i++) {
		rak[i] = 1;
		for (int j = 0; j < N; j++)
			if (avg[i] < avg[j])
				++rak[i];
	}

	//
	P = N * 0.7;

	for (int i = 0; i < N; i++)
		if (rak[i] <= P) 
			paf[i] = 'P';
		else {
			if (s2[i] >= 80)
				paf[i] = 'P';
			else
				paf[i] = 'F';
		}

	//
	for (int i = 0; i < N; i++)
		printf("%d %d %d %.1f %d %c\n", i + 1, s1[i], s2[i], avg[i], rak[i], paf[i]);

	return 0;
}
//0 90 60 70 60 80 60 30 20 30
//80 30 90 60 60 50 90 90 20 30