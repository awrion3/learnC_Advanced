#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>		//문자열 처리 표준 함수 포함

//구조체 hotel_info 정의
struct hotel_info {
	char name[31];		//이름 문자열
	int grade;			//등급 정수
	double rate, dis;	//평판도 실수, 거리 실수
	char food;			//조식포함 여부 문자
};

//함수 원형 선언
int in_hotel_info(struct hotel_info *);
void out_hotel_info(struct hotel_info *, int, int, double);

int main(void) {

	struct hotel_info ar[100];	//구조체 배열 선언
	int N, G;	//정수형 변수 선언
	double D;	//실수형 변수 선언

	//함수 호출 및 호텔 수 반환
	N = in_hotel_info(ar);

	//원하는 호텔의 등급과 거리 입력
	scanf("%d %lf", &G, &D);

	//함수 호출하여 원하는 호텔 중 평판도가 가장 높은 호텔의 정보 출력
	out_hotel_info(ar, N, G, D);

	return 0;
}

//함수 정의
int in_hotel_info(struct hotel_info *st) {

	struct hotel_info *p; //구조체 포인터 선언
	int N = 0;					//정수형 변수 선언 및 초기화
	char tmp[31], end[2] = "0";	//문자열 선언

	for (p = st; p < st + 100; p++) {	//구조체 배열을 포인터로 접근
		//호텔의 이름 입력
		scanf("%s", tmp);
		if (strcmp(tmp, end) == 0)	//호텔 이름으로 "0" 입력시 종료
			break;
		else						//입력받은 호텔 이름 저장
			strcpy(p->name, tmp);
		//호텔의 등급, 평판도, 거리, 조식포함 여부 입력받아 저장
		scanf("%d %lf %lf %c", &p->grade, &p->rate, &p->dis, &p->food);
		N++;	//호텔 수 계산
	}

	return N;	//호텔 수 반환
}

void out_hotel_info(struct hotel_info *st, int N, int G, double D) {

	struct hotel_info *p, *res = st;	//구조체 포인터 선언 및 초기화
	double max = 0;

	for (p = st; p < st + N; p++) {	//구조체 배열을 포인터로 접근하여
		if (p->grade >= G && p->dis <= D) {	//G 이상 등급, D 이하의 거리 호텔 중
			if (max <= p->rate) {	//평판도가 같거나 높은 호텔에 대하여
				if (max < p->rate) {	//평판도가 가장 높은 호텔로
					max = p->rate;		//평판도 갱신
					res = p;			//해당 구조체 원소로 주소 갱신
				}
				else {	//평판도가 같은 경우
					//사전 순서상 새 호텔 이름이 더 빠른 경우만
					if (strcmp(res->name, p->name) > 0) {	
						max = p->rate;		//평판도 갱신
						res = p;			//해당 구조체 원소로 주소 갱신
					}
				}
			}
		}
	}

	//조건을 만족하는 호텔의 이름, 등급, 평판도, 거리, 조식포함 여부 출력
	printf("%s %d %.1f %.1f %c", res->name, res->grade, res->rate, res->dis, res->food);
}
/*
marriott 4 4.7 12.5 Y
ibis 2 3.5 5.6 N
novotel 3 3.0 2.7 N
renaissance 3 3.5 4.8 N
hyatt 5 3.5 7.4 Y
bestwestern 2 2.5 3.8 Y
0
3 7.5
*/