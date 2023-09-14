#pragma warning(disable:4996)
#include <stdio.h>

//�Լ� ����
void input(int *, int);
int* diff(int*, int);

int main(void) {

	//���� ���� �� �� �Է�
	int N, ar[100], *p; 

	scanf("%d", &N);

	//�Լ� ȣ��
	input(ar, N);

	//�Լ� ȣ��
	p = diff(ar, N);

	//���� �� ���
	printf("%d %d\n", *(p - 1), *p);
		
	return 0;	
}	

//�Լ� ����
void input(int* ar, int N) {

	int* p;

	//������ �ּ� �� ����Ͽ� �迭 �� ����
	for (p = ar; p < ar + N; p++) 
		scanf("%d", p);
}

int* diff(int* ar, int N) {

	int* p = ar, gap, max, *mp;

	//ù ��° ���ҿ� �� ��° ������ ���밪 ���� max �ʱ�ȭ
	max = *p - *(p + 1) < 0 ? -(*p - *(p + 1)) : *p - *(p + 1);

	//�� ��° ������ �ּҰ����� �ʱ�ȭ
	mp = p + 1;

	for (; p < ar + N - 1; p++) { 
		//�迭 �� ���� ���� ���밪 �� ���ϱ�
		gap = *p - *(p + 1) < 0 ? -(*p - *(p + 1)) : *p - *(p + 1);

		//���� ������ max �� ���� �� �� ��° �ּҰ� ���� 
		if (max < gap) {
			max = gap;
			mp = p + 1;
		}
	}

	//�ּҰ� ��ȯ
	return mp; 
}