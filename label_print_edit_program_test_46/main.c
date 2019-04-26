// <done>
#include <stdio.h>
#include "./lib/labeleditor.h"

// 테스트 대상은 아래 주석과 같이 구현되어 있다. 
// 필요한 경우 아래 주석의 내용을 참고하여 테스트 입력과 테스트 코드를 작성하시오. 
// NOTE: 테스트 대상 코드는 빌드에 이미 포함되어 있으니 아래 주석을 해제하여 사용하지 마시오.


/*
	라벨 프린터 편집기의 입력을 처리하는 processInput()의 처리과정은 다음과 같다.

void processInput()
{
	char key = getKeyInput();

	switch (key)
	{
		// 키 별 기본/예외 기능은 각 함수 내부에서 처리됨
	case KEY_LEFT:
		Move_Cur_Left();	// 커서를 왼쪽으로 이동 처리
		break;
	case KEY_RIGHT
		Move_Cur_Right(); // 커서를 오른쪽으로 이동 처리
		break;
	case KEY_DELETE
		Delete_Char(); // 커서 왼쪽의 문자를 삭제하는 기능 처리
		break;
	default:
		Input_Char(key); // 커서 왼쪽에 key에 해당하는 문자를 삽입하는 기능 처리
		break;
	}
}
*/

/*
입력 키를 정의할 때 사용할 상수.

#define KEY_LEFT    '1'
#define KEY_RIGHT   '2'
#deifne KEY_DELETE  '3'
*/


/* [문제 1. 작성 내용] */
// 테스트 케이스를 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
// 각 테스트 케이스의 형식: { 입력 갯수, 입력 키1, 입력 키2, ... , 입력 키 N }

// 샘플 Testcase : 문제의 '[ 키 입력 동작의 예 ]' 를 테스트 하기 위한 예제
// 라벨 프린터에 입력할 키 값을 의미 (첫번째 요소는 라벨 프린터에 입력할 키 값의 개수)
char sampleInput_keys[MAX_KEY_CNT + 1] = { 10,'A','B',KEY_LEFT,'X',KEY_RIGHT,KEY_DELETE,KEY_RIGHT,KEY_LEFT,KEY_LEFT,KEY_DELETE };

//TODO: 문제1.(1-1) - 최종 결과물 : ABCDEF
char test_1_1_keys[MAX_KEY_CNT + 1] = { 13,KEY_LEFT,'A',KEY_LEFT,KEY_RIGHT,KEY_DELETE,KEY_RIGHT,KEY_DELETE,'A','B','C','D','E','F' };

//TODO: 문제1.(1-2) - 초기 상태 : ABCD, 커서 위치 : B와 C 사이, 최종 결과물 : PABDOEL
char test_1_2_keys[MAX_KEY_CNT + 1] = {14, KEY_LEFT,KEY_LEFT,KEY_LEFT,KEY_DELETE,'P',KEY_RIGHT,KEY_RIGHT,KEY_RIGHT,KEY_DELETE,KEY_RIGHT,KEY_RIGHT,'O','E','L' };

//TODO: 문제1.(1-3) - 초기 상태 : POWER, 커서 위치 : W와 E 사이, 최종 결과물 : OOEOL , 최종 커서 위치 : 세번째 문자 'E'와 네번쨰 문자'O' 사이
char test_1_3_keys[MAX_KEY_CNT + 1] = {15,KEY_DELETE,KEY_LEFT,KEY_DELETE,KEY_LEFT,KEY_DELETE,'O',KEY_RIGHT,KEY_RIGHT,'O',KEY_RIGHT,KEY_RIGHT,KEY_DELETE,'L',KEY_LEFT,KEY_LEFT };



// [문제2. 작성 내용]
// NOTE: 답안 코드 실행 중 메모리 누수가 발생하면 오답 처리됨

/**
 * 입력된 키 내용을 가져올 수 있는 장치 인터페이스
 * @return 입력된 키 값을 호출 할 때 마다 하나 씩 반환
 */

char* fake_input;
int idx;
char getKeyInput(void)
{
	return fake_input[idx++]; // FIXME : 적절한 fake 구현으로 대체
}


void test_2_1(void)
{
	// TODO: // (문제2-1)
	// 키 입력이 다음의 순서대로 방향에서 발생하는 상황 - ('A' 영문자 키) -(왼쪽 커서 이동키) -('P' 영문자 키) -(삭제 키)
	char f[] = {'A',KEY_LEFT,'P',KEY_DELETE};
	idx = 0;
	char a;
	fake_input = f;
	
	for(int i=0;i<4;i++)
		processInput();


}

void test_2_2(void)
{
	// TODO: (문제2-2) 
	// 키 입력이 다음의 순서대로 방향에서 발생하는 상황 - ('L' 영문자 키) -('O' 영문자 키) - (왼쪽 커서 이동키) -(삭제 키) -(오른쪽 커서 이동키) -('X'영문자 키)
	char f[] = {'L','O',KEY_LEFT,KEY_DELETE,KEY_RIGHT,'X'};
	idx = 0;
	char a;
	fake_input = f;
	
	for(int i=0;i<6;i++)
		processInput();
}


// 참고용으로 실행하고 싶은 코드가 있다면 아래 main()에 작성하여 활용할 수 있다.
// main 함수의 코드는 채점과 관련이 없다.

int main()
{
	printTestInputResult("Sample Input", "", 0, sampleInput_keys);

	printTestInputResult("Test_1_1 Input", "", 0, test_1_1_keys);
	printTestInputResult("Test_1_2 Input", "ABCD", 2, test_1_2_keys);
	printTestInputResult("Test_1_3 Input", "POWER", 3, test_1_3_keys);

	test_2_1();
	test_2_2();

	return 0;
}