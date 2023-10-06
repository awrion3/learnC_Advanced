#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 표준 함수 포함

int main(void) {

	char str[201], *p = str, dic[20][200], tmp[200];  //널 문자 포함
	int i = 0, j = 0, idx, len;				 //인덱스 선언 및 초기화

	gets(str);			//문장 입력
	len = strlen(str);	//문장 길이 확인

	for (; p <= str + len; p++) {	//문장 널 문자까지 훑기
		if (*p == ' ' || *p == '\0') {	//공백(혹은 널 문자)인 경우 단어 분리
			dic[i][j] = '\0';	//단어마다 널 문자 추가
			dic[i++];			 //다른 단어로 인덱스 이동
			j = 0;				 //단어별 인덱스 초기화
		}
		else {				//공백이 아닌 문자 저장
			dic[i][j++] = *p;	//단어 문자별 저장하기
		}
	}

	idx = i;	//인덱스 저장
	for (int i = 0; i < idx; i++)	//이차원 배열에 저장된 분리된 단어 출력
		printf("%s\n", dic[i]);

	for (int k = 0; k < idx - 1; k++) {	//버블 정렬 방식으로 idx - 1회 반복
		for (int i = 0; i < idx - 1; i++) {	//인덱스 범위에 유의해 이차원 배열 접근
			if (strcmp(dic[i], dic[i + 1]) > 0) {	//앞 단어가 사전 상 뒤에 있는 경우
				strcpy(tmp, dic[i + 1]);
				strcpy(dic[i + 1], dic[i]);			//strcpy 사용하여 두 단어를 교환
				strcpy(dic[i], tmp);
			}
		}
	}

	for (int i = 0; i < idx; i++)	//이차원 배열에 정렬된 분리된 단어 출력
		printf("%s ", dic[i]);

	return 0;
}
/*
simple is best
i am a boy

팁)
인덱스별 초기화에 유의

팁)
여기서 dic[i]에 저장된 값은 주소고, == *(dic + i)는 주소 값 참조 (char* 형)
dic[i][j]의 값은 문자다 == *(*(dic + i) + j)는 문자 값 참조하고 있음 (char 형)
*/