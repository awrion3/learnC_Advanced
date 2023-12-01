#include "my_func.h"

int delete_tel(TEL** p, int cnt) { //삭제 함수//

	char tmp[101];		//임시 문자열
	int del = 0, idx;	//플래그 및 인덱스 관련 변수

	if (cnt == 0)					//점검//
		printf("NO MEMBER\n");
	else {							//삭제//
		printf("Name:");
		scanf("%s", tmp);				//이름 입력

		for (int i = 0; i < cnt; i++)	//이름 일치시
			if (strcmp(p[i]->name, tmp) == 0) {
				idx = i;	//해당 구조체 원소 위치 저장
				del = 1;	//일치 여부 확인
			}
	}

	if (del == 1) {			//이름 일치 존재 시

		//삭제 대상 관련 구조체 동적할당 해제
		free(p[idx]->name);
		free(p[idx]->tel_no);	//구조체 내부 멤버 메모리 정리
		free(p[idx]->birth);

		for (int i = idx; i < cnt - 1; i++)
			*(p[i]) = *(p[i + 1]);	//구조체 간 대입을 통해 해당 구조체 원소 삭제

		cnt--;	//구조체 배열 크기 변동 반영

		free(p[cnt]);			//구조체 메모리 정리
	}

	return cnt;	//인덱스 반환
}