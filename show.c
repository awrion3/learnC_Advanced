#include "my_func.h"

void show_all(TEL** p, int cnt) {	//보기 함수//

	if (cnt != 0) {		//구조체 배열 크기 0이 아닌 경우
		for (int i = 0; i < cnt; i++)	//구조체 원소의 정보 출력
			printf("%s %s %s\n", p[i]->name, p[i]->tel_no, p[i]->birth);
	}
}