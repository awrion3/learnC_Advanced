#include "my_func.h"

int reg_insert(TEL** p, int cnt, int max) { //등록 함수//

	TEL smp;		//구조체 관련 변수 선언
	char tmp[101];	//최대 100글자 임시 문자열
	int len;		//임시 문자열 길이 관련 변수

	if (cnt >= max)					//점검//
		printf("OVERFLOW\n");
	else {							//입력//
		//구조체 원소 하나당 동적할당2
		p[cnt] = (TEL*)malloc(sizeof(TEL));
		if (p[cnt] == NULL)	//동적할당2 확인
			return -1;

		//이름 입력
		printf("Name:");
		scanf("%s", tmp);

		//문자열 동적할당3-1
		len = strlen(tmp);
		p[cnt]->name = (char*)malloc((len + 1) * sizeof(char));
		strcpy(p[cnt]->name, tmp);		//할당된 공간에 이름 문자열 저장

		//전화번호 입력
		printf("Phone_number:");
		scanf("%s", tmp);

		//문자열 동적할당3-2
		len = strlen(tmp);
		p[cnt]->tel_no = (char*)malloc((len + 1) * sizeof(char));
		strcpy(p[cnt]->tel_no, tmp);	//할당된 공간에 전화번호 문자열 저장

		//생일 문자열 입력
		printf("Birth:");
		scanf("%s", tmp);

		//문자열 동적할당3-3
		len = strlen(tmp);
		p[cnt]->birth = (char*)malloc((len + 1) * sizeof(char));
		strcpy(p[cnt]->birth, tmp);	//할당된 공간에 생일 문자열 저장

		for (int i = 0; i < cnt; i++) {	//정렬//
			if (strcmp(p[i]->name, p[cnt]->name) > 0) {	//기존 이름보다 새 이름이 앞설 경우
				smp = *(p[i]);
				*(p[i]) = *(p[cnt]);			   //구조체 간 대입을 통해 삽입 위치로 이동
				*(p[cnt]) = smp;
			}
		}

		cnt++;	//구조체 배열 크기 조정

		//현재 저장된 연락처 개수 출력
		printf("<<%d>>\n", cnt);
	}

	return cnt;	//인덱스 반환
}