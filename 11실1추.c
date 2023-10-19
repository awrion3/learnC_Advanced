#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct student {
	char name[10], id[11];	//두 문자열 널 문자 고려
	char grade;
};

int main(void) {

	struct student st[5];	//구조체 배열 선언
	char stname[10];

	//값 차례로 입력
	for (int i = 0; i < 5; i++) 
		scanf("%s %s %c", st[i].name, st[i].id, &st[i].grade);

	scanf("%s", stname);
	
	//찾고자 하는 학생의 정보 출력
	for (int i = 0; i < 5; i++)
		if (strcmp(st[i].name, stname) == 0) 
			printf(" %s %c\n", st[i].id, st[i].grade);

	return 0;
}
/*
lee1 2017102656 A
lee2 2018111823 A
park 2018059961 A
choi 2018010101 F
lee3 2019565656 B
park
*/