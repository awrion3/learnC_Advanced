#pragma warning(disable:4996)
#include <stdio.h>

//����ü ����
struct time {
	int hour, min, sec;
};

int main(void) {

	//����ü ����
	struct time t1, t2, t3;
	int a1, a2, a3;

	//����ü ������ �Է� (���� �Է� ������ ���)
	scanf("%d %d %d", &t1.hour, &t1.min, &t1.sec);
	scanf("%d %d %d", &t2.hour, &t2.min, &t2.sec);

	//�ð� �� ���
	a1 = t1.hour * 3600 + t1.min * 60 + t1.sec;
	a2 = t2.hour * 3600 + t2.min * 60 + t2.sec;

	a3 = a2 - a1;

	//�ð� ���� ���
	t3.hour = a3 / 3600;
	a3 %= 3600;
	t3.min = a3 / 60;
	a3 %= 60;
	t3.sec = a3;
	
	//����ü ������ ���
	printf("%d %d %d", t3.hour, t3.min, t3.sec);

	return 0;
}
/*
10 20 30
12 05 10

1 10 20
3 20 30
*/