#include "my_func.h"

int reg_from_file(TEL** p, int cnt, int max) {	//파일 등록 함수//

	FILE* fp;	//파일 구조체 포인터 선언
	TEL smp;	//구조체 관련 변수 선언
	char tmp[101], tmp2[101], tmp3[101];	//임시 문자열
	int len;	//문자열 길이

	fp = fopen("PHONE_BOOK.txt", "r");	//읽기 모드로 파일 열기
	if (fp == NULL)	//파일 열기 실패 시, 함수 종료 및 인덱스 반환
		return cnt;

	//파일로부터 이름, 전화번호, 생일 입력
	fscanf(fp, "%s %s %s", tmp, tmp2, tmp3);

	while (!feof(fp)) {	//파일의 끝 확인
		if (cnt >= max) {					//점검//
			printf("OVERFLOW\n");
			fclose(fp);	//파일 닫기
			return cnt;	//초과시 함수 종료 및 인덱스 반환
		}
		else {
			//구조체 원소 하나당 동적할당2
			p[cnt] = (TEL*)malloc(sizeof(TEL));
			if (p[cnt] == NULL)	//동적할당2 확인
				return -1;

			//문자열 동적할당3-1
			len = strlen(tmp);
			p[cnt]->name = (char*)malloc((len + 1) * sizeof(char));
			strcpy(p[cnt]->name, tmp);		//할당된 공간에 이름 문자열 저장

			//문자열 동적할당3-2
			len = strlen(tmp2);
			p[cnt]->tel_no = (char*)malloc((len + 1) * sizeof(char));
			strcpy(p[cnt]->tel_no, tmp2);	//할당된 공간에 전화번호 문자열 저장

			//문자열 동적할당3-3
			len = strlen(tmp3);
			p[cnt]->birth = (char*)malloc((len + 1) * sizeof(char));
			strcpy(p[cnt]->birth, tmp3);	//할당된 공간에 생일 문자열 저장

			for (int i = 0; i < cnt; i++) {	//정렬//
				if (strcmp(p[i]->name, p[cnt]->name) > 0) {	//기존 이름보다 새 이름이 앞설 경우
					smp = *(p[i]);
					*(p[i]) = *(p[cnt]);			   //구조체 간 대입을 통해 삽입 위치로 이동
					*(p[cnt]) = smp;
				}
			}

			cnt++;	//구조체 배열 크기 조정
		}

		//파일로부터 이름, 전화번호, 생일 입력
		fscanf(fp, "%s %s %s", tmp, tmp2, tmp3);
	}

	fclose(fp);	//파일 닫기
	return cnt;	//인덱스 반환
}