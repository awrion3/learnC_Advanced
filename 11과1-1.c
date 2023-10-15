#pragma warning(disable:4996)
#include <stdio.h>

typedef struct taxi_info {	//구조체 정의 및 typedef 사용
	char start[11];		//출발지 널 포함
	char target[11];	//목적지 널 포함
	double distance;	//이동거리 km
	int t_time;			//정체시간 sec
	char late_night;	//심야운행 여부 Y 혹은 N
	int tot;			//최종 택시요금 
} TAXI;	//사용자 자료형 정의

int main(void) {

	TAXI ar[20];		//구조체 배열 선언
	int N, dis, tim;	//정수형 변수 선언

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

	for (int i = 0; i < N; i++) {	//N개의 정보 출력
		printf("%s %s %d\n", ar[i].start, ar[i].target, ar[i].tot);	
	}	//출발지, 목적지, 요금 출력

	return 0;
}
/*
4
aaa bbb 2 180 N
ccc ddd 2.25 135 Y
eee fff 5 0 Y
ggg hhh 7.5 60 N
*/