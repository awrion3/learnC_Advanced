#pragma warning(disable:4996)
#include <stdio.h>

//����ü ����
struct result {
	int high, low, limit, gap;
	char porf;
};

//�Լ� ����
void passorfail(struct result *);

int main(void) {

	//����ü ����
	struct result st;

	scanf("%d %d %d", &st.high, &st.low, &st.limit);

	//�Լ� ȣ��(�ּ� ����)
	passorfail(&st);

	printf("%d %c", st.gap, st.porf);

	return 0;
}

//�Լ� ����
void passorfail(struct result *p) {

	//���� �����Ͽ� ����� ����
	p->gap = p->high - p->low;

	if (p->gap <= p->limit)
		p->porf = 'P';
	else
		p->porf = 'F';
}
/*
100 95 10
*/