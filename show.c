#include "my_func.h"

void show_all(TEL** p, int cnt) {	//���� �Լ�//

	if (cnt != 0) {		//����ü �迭 ũ�� 0�� �ƴ� ���
		for (int i = 0; i < cnt; i++)	//����ü ������ ���� ���
			printf("%s %s %s\n", p[i]->name, p[i]->tel_no, p[i]->birth);
	}
}