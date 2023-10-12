#pragma warning(disable:4996)
#include <stdio.h>

//����ü ����
struct date {
	int year, month, day;
};

//�Լ� ����
struct date* select_min(struct date*, struct date*);

int main(void) {

	//����ü ���� �� ������ ����
	struct date dt1, dt2, *pd;

	scanf("%d/%d/%d", &dt1.year, &dt1.month, &dt1.day);
	scanf("%d/%d/%d", &dt2.year, &dt2.month, &dt2.day);

	//�Լ� ȣ��(����ü �ּ� �ѱ�� ��ȯ �ޱ�)
	pd = select_min(&dt1, &dt2);

	//����ü ������ Ȱ���Ͽ� ���
	printf("%d/%d/%d", pd->year, pd->month, pd->day);

	return 0;
}

//�Լ� ����
struct date* select_min(struct date *p1, struct date *p2) {

	//���� ������ ����ü ����� �� ���Ͽ� Ư�� ����ü �ּҰ����� ��ȯ
	if (p1->year < p2->year) {
		return p1;
	}
	else if (p1->year > p2->year) {
		return p2;
	}
	else {
		if (p1->month < p2->month) {
			return p1;
		}
		else if (p1->month > p2->month) {
			return p2;
		}
		else {
			if (p1->day < p2->day) {
				return p1;
			}
			else
				return p2;
		}
	}
}
/*
2016/10/9
2016/8/6

2014/10/9
2016/8/6
*/