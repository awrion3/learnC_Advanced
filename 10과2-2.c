#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//문자열 처리 표준 함수 포함

int main(void) {

	char str[201], *p = str, dic[20][200], tmp[200];
	char word[200], sp[2] = {" "}, new[201] = {""};		 //널 문자 포함 (sp와 new의 초기화 차이에 유의)
	int i = 0, j = 0, idx, len, is = 0;			//인덱스 선언 및 초기화

	gets_s(str, 200);	//문장 입력
	scanf("%s", word);	//단어 입력

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
	for (int i = 0; i < idx; i++) {	//이차원 배열에 저장된 분리된 단어 훑으며
		if (strcmp(dic[i], word) == 0) {	//일치 단어인 경우
			is = 1;
			break;							//확인하면 반복 종료
		}
	}

	len = strlen(word);	//단어 길이 확인
	if (is == 0) {	//일치하는 단어가 아니면 단어 추가로 저장하기//
		for (p = word; p <= word + len; p++) {	//단어 널 문자까지 훑어
			if (*p == '\0') {	  //널 문자인 경우 단어 저장 마무리
				dic[i][j] = '\0';	//단어마다 널 문자 추가
				dic[i++];			//다음 단어로 인덱스 이동
			}
			else {				  //널 문자 만나기 전까지 문자별로 저장
				dic[i][j++] = *p;	//단어 문자별 저장하기
			}
		}
	}

	idx = i;	//인덱스 새롭게 저장
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

	for (int i = 0; i < idx; i++) {	//정렬된 단어를 하나의 문장으로 결합하기
		strcat(new, dic[i]);	
		strcat(new, sp);		//단어 사이에 공백 추가
	}

	//결합된 한 문장 출력
	printf("%s", new);

	return 0;
}
/*
ant apple ace ape
arch

bag bat back bean box
back

팁)
이차원 배열이므로, dic[i]는 주소가 아닌 값이 '아님'에 유의
dic[i] = char *형 = *(dic + i) = 배열 이름 dic[i] = 배열 dic[i]의 0번 원소(dic[i][0])의 주소 = 포인터에 연결 가능
*/