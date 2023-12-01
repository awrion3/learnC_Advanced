#include "my_func.h"

void find_by_birth(TEL** p, int cnt) { //검색 함수//

	char bday[5], * q;	//찾으려는 생일 관련 변수
	int key, mon;		//생일 달 관련 변수

	printf("Birth:");	//입력//
	scanf("%d", &key);

	for (int i = 0; i < cnt; i++) {	//구조체 배열 접근하여
		strcpy(bday, p[i]->birth + 4);	//생일 월일 임시 문자열로 저장

		mon = 0;		//값 초기화
		for (q = bday; q < bday + 2; q++) {	//임시 문자열의 생일 월에 대하여
			mon *= 10;
			mon += *q - '0';				//정수형 값으로 변환
		}

		if (key == mon)	//찾으려는 생일 달인 경우 해당자 정보 출력
			printf("%s %s %s\n", p[i]->name, p[i]->tel_no, p[i]->birth);
	}
}