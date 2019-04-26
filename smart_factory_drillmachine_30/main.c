// <done>
#include <stdio.h>
#include "drill.h"
/*
 * drill.h에는 아래 함수의 정의가 있다.
	int drill(int x1, int r1, int x2, int r2);
*/

/* [작성 내용] */
/* 1. 테스트 케이스를 아래 배열에 추가하시오 개수는 상관 없음. 배열의 이름은 수정 불가함 */
/* 2. 테스트 케이스 배열 구조 : {x1, r1, x2, r2, 기대 return 값} */ 
int tarr[][5] = { 
	{15,5,22,5,0}, // 1번 홀끼리 외관 간격 2 이내
	{10,7,30,2,0}, // 2번 좌측 홀 반지름 범위보다 큼
	{10,2,30,7,0} // 3번 우측 홀 반지름 범위보다 큼
	{5,5,22,5,0}, // 4번 왼쪽 넘어감
	{10,2,45,5,0}, // 5번 오른쪽 넘어감
	{10,0,30,2,0}, // 6번 좌측 홀 반지름 범위보다 작음
	{10,2,30,0,0}, // 7번 우측 홀 반지름 범위보다 작음
	{25,2,10,2,0}, // 8번 x1 > x2
};

/* main 함수는 작성한 테스트 케이스 검증용임 */
/* 필요에 따라서 마음대로 변경하어도 무방함 */ 
/* main 함수는 채점과 무관함 */

int main()
{
	int i;

	for(i = 0; i <(sizeof(tarr)/sizeof(tarr[0])); i++)
	{
		printf("[%d] ", i);
		printf("Expected = %d, ", tarr[i][4]);
		printf("Return = %d\n", drill(tarr[i][0], tarr[i][1], tarr[i][2], tarr[i][3]));
	}

	return 0;
}
