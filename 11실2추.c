#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>		//atoi는 문자열 처리 함수로 문자열을 수로 반환

struct student {
	char name[10], id[11];	//널 문자 고려
	char grade;
};

int main(void) {

	struct student st[5];
	char stname[10], stgrade, styear[5] = { 0 }, tmyear[5] = { 0 };	//널 문자 미리 삽입
	int is = 0, idnum;

	//값 입력(공백 구분자 사용해서 %c 전에 getchar() 안씀)
	for (int i = 0; i < 5; i++)
		scanf("%s %s %c", st[i].name, st[i].id, &st[i].grade);	

	scanf("%s", stname);

	for (int i = 0; i < 5; i++)
		if (strcmp(st[i].name, stname) == 0) {	//찾고자 하는 학생 이름으로 찾아
			stgrade = st[i].grade;				//학점 저장

			strncpy(styear, st[i].id, 4);		//입학년도 저장: 해당 문자 개수만큼만 복사(따라서 널 문자X)

			idnum = atoi(styear) % 131;			//문자열 수로 변환하여 바로 구하기
		}

	for (int i = 0; i < 5; i++) 
		if (st[i].grade == stgrade) {	//학생과 같은 학점을 받은 학생들에 대해,
			strncpy(tmyear, st[i].id, 4);		//해당 학생의 입학년도 저장
			
			if (strcmp(styear, tmyear) == 0) {	//입학년도가 같다면,

				if (strcmp(stname, st[i].name) != 0){	//본인을 제외한 경우여야 함
					printf("%s ", st[i].name);			//해당 학생 이름 출력
					is = 1;	//본인을 제외한 같은 조건의 학생이 있는 경우 표기
				}
			}
		}

	if (is == 0)
		printf("0\n");
	else
		printf("\n");	//조건에 따라 줄바꿈 출력

	printf("%s %d\n", styear, idnum);	//찾고자 하는 학생의 입학년도와 나머지 출력

	return 0;
}
/*
lee1 2017102656 A
lee2 2018111823 A
kwon 2018111888 A
park 2018059961 A
choi 2018010101 B
park

lee1 2019102656 B
lee2 2019111823 B
park 2019123456 A
choi 2019010101 F
lee3 2019565656 B
park
*/