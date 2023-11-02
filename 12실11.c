#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *p, *t = NULL, idx = 0, n = 5; 

    p = (int*)malloc(n * sizeof(int));
    if (p == NULL)
        return -1;

    while (n <= 20) {   //�Է� �� ���� Ƚ���� ����
        scanf("%d", &p[idx++]);     //�ε����� ��� �����ؼ� ��ȭ (�� �������� �Է¹޾� ����)

        if (idx >= 5) {      //idx = 5���� �ʰ��ӿ� ���� (Ȥ�� �Ʒ��ٱ��� �����ؼ� �׳� idx >= n)
            if ((idx - 5) % 3 == 0) {   //3 ������ Ȯ���ϱ� ���� (0 % 3 == 0, ����: 0 / 3 == 0)
                n += 3; //3������ ���� ����
                
                t = (int*)malloc(n * sizeof(int));
                if (t == NULL)
                    return -1;

                for (int i = 0; i < n; i++) //�ӽ� ����
                    t[i] = p[i];

                p = t;  //���� �迭 ���� (�����, �ֳ��ϸ� ���� �迭�� �ƴ� �����Ҵ��̹Ƿ�.)
            }
        }

        if (p[idx - 1] == -1)   //idx ������ ����
            break;
    }

    for (int i = 0; i < idx; i++)
        printf(" %d", p[i]);
   
    free(p);    //t�� p�� �����߱⿡ free�� �ʿ� X (���� ���� ����Ű�Ƿ� �ι� ���� �Ұ���)

    return 0;
}
/*
3 4 5 6 7 8 9 -1
3 4 5 -1
*/