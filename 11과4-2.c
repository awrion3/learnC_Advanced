#pragma warning(disable:4996)
#include <stdio.h>

//구조체 정의
struct parking_info {
	int num, tel;	//차량번호, 전화번호 
	char opt, mem;	//상품, 정기권 가입유무
	int day, min;	//정기권 가입종류, 주차시간
	double fee;		//요금
};

//함수 원형 선언
void input(struct parking_info*, int);
void compute(struct parking_info*);
void display(struct parking_info*, int);
void parking_info_sort(struct parking_info*, int);	//정렬을 위한 sort 함수

int main(void) {

	struct parking_info st[100], *p;	//구조체 배열 및 포인터 선언
	int N;

	scanf("%d", &N);	//정수 N 입력

	//함수 호출하여 구조체 배열값 저장
	input(st, N);

	//함수 호출하여 1대씩 주차요금 계산하여 저장
	for (p = st; p < st + N; p++)
		compute(p);

	//함수 호출하여 구조체 배열 정렬
	parking_info_sort(st, N);

	//함수 호출하여 요금 리스트 및 요금 총액 출력
	display(st, N);

	return 0;
}

//함수 정의
void input(struct parking_info *p, int N) {

	struct parking_info *ps;	//구조체 포인터 선언

	for (ps = p; ps < p + N; ps++) {	//구조체 배열을 포인터로 접근하여
		//차량번호 및 전화번호, 상품 입력
		scanf("%d %d %c", &ps->num, &ps->tel, &ps->opt);	
		//상품이 정기권인 경우
		if (ps->opt == 'S') {	
			getchar();		//엔터키 남김 제거//
			//정기권 가입유무, 가입종류 입력
			scanf("%c %d", &ps->mem, &ps->day);			
		}		
		//대여시간 입력
		scanf("%d", &ps->min);						
	}
}

void compute(struct parking_info *p) {

	p->fee = 0;	//요금 초기화

	//상품이 S고,
	if (p->opt == 'S') {	
		if (p->mem == 'N') {	//정기권에 아직 가입이 안 된 경우,
			if (p->day == 7)		//가입종류에 따라 가입비용을 
				p->fee = 30000;		//3만원
			else if (p->day == 30)
				p->fee = 100000;	//10만원
			else if (p->day == 180)
				p->fee = 500000;	//50만원 부과
		}
	}
	//상품이 D면,
	else {	
		p->fee = 5000;	//기본요금 5000원 부과
	}

	//상품 옵션에 관계없이 대여시간이 4시간을 초과할 시,
	if (p->min > 240) {
		//초과한 정도 계산 (소수점 이하 버림)
		p->min = (int)((p->min - 240) / 10);	
		//초과 금액 계산하여 추가
		p->fee += p->min * 200;			
	}
}

void parking_info_sort(struct parking_info *p, int N) {
	
	struct parking_info *q, smp;	//구조체 관련 선언

	//상품 옵션 및 차량 번호를 기준으로 오름차순 정렬
	for (int i = 0; i < N - 1; i++)			//버블 정렬 방식으로
		for (q = p; q < p + N - 1; q++) {	//구조체 배열을 포인터로 접근하여
				//상품 옵션이 같거나 후자가 작은 경우에 대하여
				if (q->opt >= (q + 1)->opt) {	
					//상품 옵션이 같으면
					if (q->opt == (q + 1)->opt) {	
						//차량 번호를 기준으로 후자가 작으면
						if (q->num > (q + 1)->num) {
							smp = *q;
							*q = *(q + 1);	//구조체 간 대입하여 정렬
							*(q + 1) = smp;
						}
					}
					//상품 옵션에서 후자가 작으면
					else {
						smp = *q;
						*q = *(q + 1);		//구조체 간 대입하여 정렬
						*(q + 1) = smp;
					}
				}
		}
}

void display(struct parking_info *p, int N) {

	struct parking_info *ps;	//구조체 포인터 선언
	double fees = 0, feed = 0;	//요금 총액 관련 double형 변수 선언

	for (ps = p; ps < p + N; ps++) {	//구조체 배열을 포인터로 접근하여
		//차량 번호, 전화 번호, 상품 옵션, 주차 요금 출력하기 
		printf("%d %d %c %.0f\n", ps->num, ps->tel, ps->opt, ps->fee);
	}

	for (ps = p; ps < p + N; ps++) {	//구조체 배열을 포인터로 접근
		if (ps->opt == 'D') {	//상품 옵션이 D인 경우
			feed += ps->fee;	//D 상품 주차료 총합 누적
		}
		else {					//상품 옵션이 S인 경우
			fees += ps->fee;	//S 상품 주차료 총합 누적
		}
	}
	//D의 총액, S의 총액, 전체 총액 출력
	printf("%.0f %.0f %.0f", feed, fees, feed + fees);
}

/*
4
1111 12345678 S N 7 230
2222 22223333 D 240
3333 44445555 D 255
4444 66667777 S Y 30 200

6
3777 28171652 S Y 30 348
1989 97027706 D 429
7757 25158262 S Y 30 392
2714 15392245 D 560
8506 12389677 D 47
5113 59262609 S N 30 967
*/