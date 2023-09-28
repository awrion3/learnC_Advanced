#pragma warning (disable:4996)
#include <stdio.h>				

int main(void) {

	int idx, len1 = 0, len2 = 0;
	char str1[41], str2[21], *p1 = str1, *p2 = str2; //str1에 결과 저장함을 고려해 길이 설정

	scanf("%s", str1);
	scanf("%s", str2);

	scanf("%d", &idx);	//인덱스 입력

	for (; *p1; p1++)
		len1++;
	for (; *p2; p2++)	//배열별 길이 구하기 (항상 인덱스 + 1)
		len2++;

	//이동
	for (p1 = str1 + len1; p1 >= str1 + idx; p1--)	//널 문자 포함해 이동시키기(널문자...인덱스까지)
		*(p1 + len2) = *p1;	//str1의 각 원소를 len2 칸만큼 뒤로 보내기

	//삽입
	p1 = str1 + idx; //인덱스 지점으로 연결 초기화
	for (p2 = str2; p2 < str2 + len2; p2++, p1++)		//str2 정순 삽입
			*p1 = *p2;
	
	printf("%s", str1); //널 문자 포함하여 이동시켰으므로 추가 안해도 됨//

	return 0;
}