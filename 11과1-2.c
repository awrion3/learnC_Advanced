#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//문자열 처리 표준 함수 포함

typedef struct taxi_info {	//구조체 정의 및 typedef 사용
	char start[11];		//출발지 널 포함
	char target[11];	//목적지 널 포함
	double distance;	//이동거리 km
	int t_time;			//정체시간 sec
	char late_night;	//심야운행 여부 Y 혹은 N
	int tot;			//최종 택시요금 
} TAXI;	//사용자 자료형 정의

//함수 원형 선언
TAXI* sel_max(TAXI*, int, char*, char*);

int main(void) {

	TAXI ar[20], *p;	//구조체 배열 및 포인터 선언
	int N, dis, tim;	//정수형 변수 선언
	char sta[11], des[11];	//출발지 및 목적지 문자열 입력 널 문자 포함

	scanf("%d", &N);	//N 입력

	for (int i = 0; i < N; i++) {	//N개의 정보 입력
		scanf("%s", ar[i].start);		//공백이 없는 문자열 입력
		scanf("%s", ar[i].target);
		scanf("%lf", &ar[i].distance);	//이동거리 입력
		scanf("%d", &ar[i].t_time);		//정체시간 입력
		getchar();						//엔터키 남김 제거//
		scanf("%c", &ar[i].late_night);	//심야운행 여부 입력

		ar[i].tot = 0;	//최종 요금 초기화
		if (ar[i].late_night == 'N') {	//주간 요금
			ar[i].tot += 3800;	//기본요금

			//추가 이동거리 관련 계산 (소수점 이하 버림)
			dis = (int)((ar[i].distance - 2) * 1000 / 100);
			ar[i].tot += dis * 100;	//초과한 이동거리 요금 추가

			//정체시간 관련 계산 (소수점 이하 버림)
			tim = (int)(ar[i].t_time / 30);
			ar[i].tot += tim * 100;	//정체시간 요금 추가	
		}
		else {	//심야 할증 요금
			ar[i].tot += 4800;	//기본요금

			//추가 이동거리 관련 계산 (소수점 이하 버림)
			dis = (int)((ar[i].distance - 2) * 1000 / 100);
			ar[i].tot += dis * 120;	//초과한 이동거리 요금 추가

			//정체시간 관련 계산 (소수점 이하 버림)
			tim = (int)(ar[i].t_time / 30);
			ar[i].tot += tim * 120;	//정체시간 요금 추가
		}
	}
	
	scanf("%s", sta);	//출발지 및 목적지 입력
	scanf("%s", des);

	//함수 호출 (구조체 배열의 시작주소 및 원소개수, 출발지 및 목적지 문자열 시작주소 전달)
	p = sel_max(ar, N, sta, des);	

	//해당 출발지에서 목적지로의 이동 관련 최대 택시요금인 경우를 출력 (거리, 정체시간, 심야, 요금)
	printf("%.2f %d %c %d", p->distance, p->t_time, p->late_night, p->tot);

	return 0;
}

//함수 정의
TAXI* sel_max(TAXI *p, int N, char *s, char *d) {

	TAXI *q, *m = p;	//구조체 포인터 변수 선언 및 초기화
	int max = -1;

	for (q = p; q < p + N; q++) {//구조체 배열 포인터로 접근
		//출발지와 목적지가 같으면
		if (strcmp(q->start, s) == 0 && strcmp(q->target, d) == 0) {
			//요금이 가장 큰 경우 찾아
			if (max < q->tot) {
				max = q->tot;	//최대 택시 요금 갱신
				m = q;			//구조체 배열의 해당 구조체 원소 주소 갱신
			}
		}
	}

	return m;	//해당 구조체 원소 주소 반환
}

/*
8
aaa bbb 2.25 480 N
ccc ddd 10 300 Y
eee fff 10 180 Y
aaa bbb 3 180 N
ccc ddd 12 180 Y
ggg hhh 13 60 Y
aaa bbb 4 0 N
aaa bbb 3.2 60 N
aaa bbb
*/