#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	char ch;
	int M;

	scanf("%c", &ch);
	scanf("%d", &M); //�ڷ��� ���������� ��ġ�� ����
	//char�� int�� ���� �������̳�, double���� ��꿡�� �����ؾ�.
	//�⺻������ int ������ ���� Ÿ���� ����� int�� �ڵ���ȯ
	//���� ���������� ����, �ڷ��� char�� �ٽ� char�� int�� ��갪�� ������ ��, (char) �ʿ��ϰ� ��.

	M %= 26;

	//..�Ѿ�� 'A'���� ����, +M�� ��, ����-'Z' ����-1�� ���
	if (ch >= 'A' && ch <= 'Z')
		ch = ch + M > 'Z' ? 'A' + (ch - 'Z' + M - 1) : ch + M;
	else if (ch >= 'a' && ch <= 'z') 
		ch = ch + M > 'z' ? 'a' + (ch - 'z' + M - 1) : ch + M;
	else
		ch;

	printf("%c", ch);

	return 0;
}