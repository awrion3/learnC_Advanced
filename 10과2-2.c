#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//���ڿ� ó�� ǥ�� �Լ� ����

int main(void) {

	char str[201], *p = str, dic[20][200], tmp[200];
	char word[200], sp[2] = {" "}, new[201] = {""};		 //�� ���� ���� (sp�� new�� �ʱ�ȭ ���̿� ����)
	int i = 0, j = 0, idx, len, is = 0;			//�ε��� ���� �� �ʱ�ȭ

	gets_s(str, 200);	//���� �Է�
	scanf("%s", word);	//�ܾ� �Է�

	len = strlen(str);	//���� ���� Ȯ��
	for (; p <= str + len; p++) {	//���� �� ���ڱ��� �ȱ�
		if (*p == ' ' || *p == '\0') {	//����(Ȥ�� �� ����)�� ��� �ܾ� �и�
			dic[i][j] = '\0';	//�ܾ�� �� ���� �߰�
			dic[i++];			 //�ٸ� �ܾ�� �ε��� �̵�
			j = 0;				 //�ܾ �ε��� �ʱ�ȭ
		}
		else {				//������ �ƴ� ���� ����
			dic[i][j++] = *p;	//�ܾ� ���ں� �����ϱ�
		}
	}

	idx = i;	//�ε��� ����
	for (int i = 0; i < idx; i++) {	//������ �迭�� ����� �и��� �ܾ� ������
		if (strcmp(dic[i], word) == 0) {	//��ġ �ܾ��� ���
			is = 1;
			break;							//Ȯ���ϸ� �ݺ� ����
		}
	}

	len = strlen(word);	//�ܾ� ���� Ȯ��
	if (is == 0) {	//��ġ�ϴ� �ܾ �ƴϸ� �ܾ� �߰��� �����ϱ�//
		for (p = word; p <= word + len; p++) {	//�ܾ� �� ���ڱ��� �Ⱦ�
			if (*p == '\0') {	  //�� ������ ��� �ܾ� ���� ������
				dic[i][j] = '\0';	//�ܾ�� �� ���� �߰�
				dic[i++];			//���� �ܾ�� �ε��� �̵�
			}
			else {				  //�� ���� ������ ������ ���ں��� ����
				dic[i][j++] = *p;	//�ܾ� ���ں� �����ϱ�
			}
		}
	}

	idx = i;	//�ε��� ���Ӱ� ����
	for (int i = 0; i < idx; i++)	//������ �迭�� ����� �и��� �ܾ� ���
		printf("%s\n", dic[i]);

	for (int k = 0; k < idx - 1; k++) {	//���� ���� ������� idx - 1ȸ �ݺ�
		for (int i = 0; i < idx - 1; i++) {	//�ε��� ������ ������ ������ �迭 ����
			if (strcmp(dic[i], dic[i + 1]) > 0) {	//�� �ܾ ���� �� �ڿ� �ִ� ���
				strcpy(tmp, dic[i + 1]);
				strcpy(dic[i + 1], dic[i]);			//strcpy ����Ͽ� �� �ܾ ��ȯ
				strcpy(dic[i], tmp);
			}
		}
	}

	for (int i = 0; i < idx; i++) {	//���ĵ� �ܾ �ϳ��� �������� �����ϱ�
		strcat(new, dic[i]);	
		strcat(new, sp);		//�ܾ� ���̿� ���� �߰�
	}

	//���յ� �� ���� ���
	printf("%s", new);

	return 0;
}
/*
ant apple ace ape
arch

bag bat back bean box
back

��)
������ �迭�̹Ƿ�, dic[i]�� �ּҰ� �ƴ� ���� '�ƴ�'�� ����
dic[i] = char *�� = *(dic + i) = �迭 �̸� dic[i] = �迭 dic[i]�� 0�� ����(dic[i][0])�� �ּ� = �����Ϳ� ���� ����
*/