#pragma warning (disable:4996)
#include <stdio.h>				

int main(void) {

	int idx, len1 = 0, len2 = 0;
	char str1[41], str2[21], *p1 = str1, *p2 = str2; //str1�� ��� �������� ����� ���� ����

	scanf("%s", str1);
	scanf("%s", str2);

	scanf("%d", &idx);	//�ε��� �Է�

	for (; *p1; p1++)
		len1++;
	for (; *p2; p2++)	//�迭�� ���� ���ϱ� (�׻� �ε��� + 1)
		len2++;

	//�̵�
	for (p1 = str1 + len1; p1 >= str1 + idx; p1--)	//�� ���� ������ �̵���Ű��(�ι���...�ε�������)
		*(p1 + len2) = *p1;	//str1�� �� ���Ҹ� len2 ĭ��ŭ �ڷ� ������

	//����
	p1 = str1 + idx; //�ε��� �������� ���� �ʱ�ȭ
	for (p2 = str2; p2 < str2 + len2; p2++, p1++)		//str2 ���� ����
			*p1 = *p2;
	
	printf("%s", str1); //�� ���� �����Ͽ� �̵��������Ƿ� �߰� ���ص� ��//

	return 0;
}