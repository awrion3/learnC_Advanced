#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� ǥ�� �Լ� ����

int main(void) {

	int N, len, min, fl = 0;
	char ar[101], mn[101];	//���ڿ� ���� (�� ���� ���)

	scanf("%d", &N);
	getchar();	//�Ʒ� gets ����Ͽ� �ʿ�(���� ����Ű���� ���Խ�Ų ��, ���� ����Ű �Է� ������ �����ع���)//

	for (int i = 0; i < N; i++) {
		gets_s(ar, 100); //gcc������ gets(ar);�� ������ �Ѵ�//
		//������ �����ϴ� ���ڿ� == ���ڿ� ����� ǥ�� �Լ� == <stdio.h>
		
		len = strlen(ar);
		
		if (fl == 0) {	//ó�� �ʱ�ȭ
			min = len;
			strcpy(mn, ar);
			fl = 1;
		}
		else if (min > len){ //���� min ���� �� �迭 ���� ����
			min = len;
			strcpy(mn, ar);
		}
	}

	//�ּ� ������ ���ڿ� ���
	printf("%s", mn);

	return 0;
}