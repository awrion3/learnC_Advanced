#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int N, x[100], max = 1, cnt = 1, mdx;

	//
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);

	//
	mdx = N - 1; //�ִ� �κй迭 ���� 1�� ��쿡 ������ �迭(����) �ε���
	for (int i = 0; i < N - 1; i++)
		if (x[i] * x[i + 1] < 0) {
			cnt++;
			if (max <= cnt) { //������ �迭
				max = cnt;
				mdx = i + 1;
			}
		}
		else
			cnt = 1;

	//
	printf("%d\n", max);

	for (int i = mdx - max + 1; i <= mdx; i++)
		printf(" %d", x[i]);

	return 0;
}