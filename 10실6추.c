#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>			//���ڿ� ó�� �Լ� ����

//�Լ� ����
void StringAdd(char [], char, int);	
int Convertor(char);				

int main(void) {

	char str[20], *p = str, ch;	//�� ���� ����1 + �ִ� �Է�8 + �ִ� ����7 = 16
	int len, even = 0, fl = -1;

	scanf("%s", str);	//���� ������ ���ڿ� �Է�
	len = strlen(str);	//���ڿ� ���� ���ϱ�

	for (int i = 0; i < len; i++) {		//�� ���� ������ �Ⱦ�
		if (Convertor(*(p + i)) % 2 == 0) {	//��ȯ�� ���ڰ� ¦���� ���
			even = 1;	//¦������ ǥ��
			ch = '*';	//���� Ư������ ����

			if (fl == even) {	//�������� ¦�����ٸ�
				StringAdd(str, ch, i);	//���ӵǴ� ��쿡 �Լ� ȣ���Ͽ� ���� ���� ���̿� �߰�
				i++;	//���� �������� ���� �迭 �ε��� +1	
				len++;	//���ڿ� ���̵� +1
			}
			fl = even;	//���� ǥ�� ����
		}
		else {								//��ȯ�� ���ڰ� Ȧ���� ���
			even = 0;	//Ȧ������ ǥ��
			ch = '+';	//���� Ư������ ����

			if (fl == even) {	//�������� Ȧ�����ٸ�
				StringAdd(str, ch, i);	//���ӵǴ� ��쿡 �Լ� ȣ���Ͽ� ���� ���� ���̿� �߰�
				i++;	//���� �������� ���� �迭 �ε��� +1	
				len++;	//���ڿ� ���̵� +1
			}
			fl = even;	//���� ǥ�� ����
		}
	}

	printf("%s", str);	//���� �߰��� ���ڿ� ���

	return 0;
}

//�Լ� ����
void StringAdd(char arr[], char ch, int index) {

	char *p;	//�������� ����
	int len;

	len = strlen(arr);	//���ڿ� ���� ���ϱ�

	for (p = arr + len; p >= arr + index; p--)	//�迭�� �ι��ں��� �����Ͽ� �ε������� �Ⱦ�
		*(p + 1) = *p;	//��ĭ�� �ڷ� �̵���Ű��

	p = arr + index;	//�ش� �迭�� �ε��� ��ġ�� 
	*p = ch;			//�ش� Ư������ ����
}

int Convertor(char x) {

	int n = 0;	//�������� ���� �� �ʱ�ȭ

	n = x - '0';	//���ڸ� ���ڷ� ��ȯ(���ڴ� ��� ���ڸ� ���� ���� == 1 ~ 9 ���� )

	return n;	//��ȯ�� ���� ��ȯ
}
/*
132456
33332222
*/