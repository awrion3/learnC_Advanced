#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *p, *t = NULL, idx = 0, n = 5; 

    p = (int*)malloc(n * sizeof(int));
    if (p == NULL)
        return -1;

    while (n <= 20) {   //입력 총 가능 횟수에 유의
        scanf("%d", &p[idx++]);     //인덱스는 계속 누적해서 변화 (그 다음부터 입력받아 저장)

        if (idx >= 5) {      //idx = 5부터 초과임에 유의 (혹은 아랫줄까지 포함해서 그냥 idx >= n)
            if ((idx - 5) % 3 == 0) {   //3 단위로 확인하기 위함 (0 % 3 == 0, 참고: 0 / 3 == 0)
                n += 3; //3단위로 길이 연장
                
                t = (int*)malloc(n * sizeof(int));
                if (t == NULL)
                    return -1;

                for (int i = 0; i < n; i++) //임시 저장
                    t[i] = p[i];

                p = t;  //본래 배열 갱신 (연결로, 왜냐하면 실제 배열이 아닌 동적할당이므로.)
            }
        }

        if (p[idx - 1] == -1)   //idx 증가에 유의
            break;
    }

    for (int i = 0; i < idx; i++)
        printf(" %d", p[i]);
   
    free(p);    //t는 p에 연결했기에 free할 필요 X (같은 곳을 가리키므로 두번 해제 불가능)

    return 0;
}
/*
3 4 5 6 7 8 9 -1
3 4 5 -1
*/