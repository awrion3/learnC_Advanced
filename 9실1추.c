#pragma warning(disable:4996)
#include <stdio.h>

//�Լ� ����
void input(int*, int);
int* sel_max(int*, int);
void output(int*, int);

int main(void) {

	int in[100], out[100], * max, i, N, M;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) { //�ش� �۾� N�� �ݺ�
		input(in, M);			//�Լ� ȣ���Ͽ� M���� ���� �Է�
		max = sel_max(in, M);	//�� �� ���� ���� �ߺ� �Է� Ƚ���� ���� ������ �ּҷ� max�� ����
		out[i] = *max;			//�ش� �Է¿� ���� �ߺ� �Է� Ƚ�� *max�� ����
	}

	output(out, N); //�Լ� ȣ���Ͽ� ��� 

	return 0;
}

//�Լ� ����
void input(int *p, int M) {//�Է� ����

	int *pa = p;

	for (; pa < p + M; pa++)
		scanf("%d", pa);
}

int* sel_max(int* p, int M) {

	int* pa = p, * qa = p;
	int dup, max = -1, * mdx = p;
	//�ߺ� Ƚ�� = �ڱ��ڽ��� ������ ���¿��� ���, ���� ��� ���� �ߺ����� ���� ��,
	//�ִ� �ߺ� Ƚ���� 0�� �Ǹ�, �̸� �ݿ��ϱ� ���ؼ��� max�� -1�� �����Ѵ�
	//���� �ݺ��� �������� ���� �ñ��� ����� �ּ� mdx�� p�� �ʱ�ȭ�Ѵ�

	for (; pa < p + M; pa++) {
		dup = 0;
		for (qa = p; qa < p + M; qa++) //qa = p �ʱ�ȭ ���� ������ �ʵ��� �Ѵ�//
			if (*pa == *qa && pa != qa)	//���� �ּҴ� ���� == �ڱ� �ڽ� ����
				dup++;

		//=�� ���� �ʾҴٴ� �� = �ߺ� Ƚ���� ������ ��, (�װ��� �ڱ� �ڽ��̵�, �ٸ� ���� ó�� ������ �ּҷ� ����)
		if (dup > max) {//���� ó�� ���� �ߺ� Ƚ���� 0�̾ �ϴ� �� ù �ּҷ� ���ŵ� ����
			max = dup;
			mdx = pa; //�ش� ���� �ּ� ����
		}
	}

	return mdx;
}

void output(int *p, int N) {//��� ����

	int *pa = p;

	for (; pa < p + N; pa++)
		printf(" %d", *pa);
}

/*
3 5
1 2 2 1 3
2 4 2 4 3
1 2 3 4 5

2 3
2 1 1
0 1 0
*/