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
void input(struct parking_info*, int);		//input 함수
void compute(struct parking_info*);			//compute 함수
void display(struct parking_info*, int);	//display 함수

int main(void) {

	struct parking_info st[100], *p;	//구조체 배열 및 포인터 선언
	int N;
		
	scanf("%d", &N);	//정수 N 입력
	
	//함수 호출하여 구조체 배열값 저장
	input(st, N);

	//함수 호출하여 1대씩 주차요금 계산하여 저장
	for (p = st; p < st + N; p++)
		compute(p);

	//함수 호출하여 구조체 배열값 출력
	display(st, N);

	return 0;
}

//함수 정의
void input(struct parking_info *p, int N) {

	struct parking_info *ps;	//구조체 포인터 선언

	for (ps = p; ps < p + N; ps++) {	//구조체 배열을 포인터로 접근하여
		scanf("%d %d %c", &ps->num, &ps->tel, &ps->opt);	//차량번호 및 전화번호, 상품 입력
		
		if (ps->opt == 'S') {	//상품이 정기권인 경우
			getchar();	//엔터키 남김 제거//
			scanf("%c %d", &ps->mem, &ps->day);		//정기권 가입유무, 가입종류 입력	
		}
		
		scanf("%d", &ps->min);						//대여시간 입력
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

void display(struct parking_info *p, int N) {

	struct parking_info *ps; //구조체 포인터 선언

	//구조체 배열을 포인터로 접근하여
	for (ps = p; ps < p + N; ps++) {	
		//차량 번호, 전화 번호, 상품 옵션, 주차 요금 출력하기 
		printf("%d %d %c %.0f\n", ps->num, ps->tel, ps->opt, ps->fee);	
	}	
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

팁)
%.ㅁf 시리즈 모두 반올림 자동 적용됨 
(int) 사용시 버림 자동 적용됨
*/