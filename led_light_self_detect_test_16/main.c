#define MAX_LED 20

typedef struct LedConfig_
{
	int powerMin;
	int powerMax;
	int numOfLED;
} LedConfig;

typedef struct TestInput_{
	LedConfig ledConfig;
	int ledPowers[MAX_LED];
} TestInput;

/* [작성 내용] */
/* 1. 테스트 케이스를 아래 배열에 추가하시오. 배열의 이름은 수정 불가함, 디폴트로 주어진 내용도 수정 불가함 */
/* 2. 테스트 케이스 구조 : { {최소 입력 전력, 최대 입력 전력, LED의 개수 N}, {LED 1의 소비 전력, ..., LED N의 소비 전력} } */
/*  예를 들어, { {4000,  5000, 5}, {950, 950, 650, 850, 900} }는 최소 입력 전력이 4000, 최대 입력 전력이 5000, LED의 개수가 5개, LED의 소비 전력이 각각 950, 950, 650, 850, 900 임을 의의한다. */
TestInput testParameters[] = {
	{ {4000,  5000, 5} , {950, 950, 650, 850, 900 } }, // 테스트용 입력
	{ {3000,  5000, 8}, {100,150,300,550,600,600,600,600 } }, // TODO: 항목 1-1 입력을 추가하시오.
	{ {5000,  6000, 6}, {660,670,780,990,990,990 } }, // TODO: 항목 1-2 입력을 추가하시오.
	{ {900,  1100, 6}, {100,100,100,110,220,430 }}, // TODO: 항목 1-3 입력을 추가하시오.
};


// 테스트 대상은 아래 주석과 같이 구현되어 있다. 
// 필요한 경우 아래 주석의 내용을 참고하여 테스트 입력과 테스트 코드를 작성하시오. 
// NOTE: 테스트 대상 코드는 빌드에 이미 포함되어 있으니 아래 주석을 해제하여 사용하지 마시오.

#include "./lib/Check_Condition.h"
/* 
* Check_Condition.h 에는 아래 함수의 정의가 있다
* 
// 최소 입력 전력, 최대 입력 전력, LED의 개수로 초기화한다.
void initMachine(int powerMin, int powerMax, int numOfLed);

// 자가 진단 로직 (테스트 대상)
int checkCondition()
{
	int i, sum;
	int check[5] = { 0, 0, 0, 0, 0 };

	// getPowerOf()를 호출하여 각 LED의 소비 전력을 측정 
	for (i = 0; i < num_of_LED; i++) {
		LED_power[LED_count++] = getPowerOf(i);
	}

	// 각 LED 전력이 범위를 벗어났는지 확인
	for (i = 0; i < num_of_LED; i++) {
		if (LED_power[i] < VALUE_MIN || LED_power[i] > VALUE_MAX) return 0;
	}

	// 입력 전력 범위를 만족하는지 확인
	sum = 0;
	for (i = 0; i < num_of_LED; i++) {
		sum += LED_power[i];
	}
	if (sum < input_power_min || sum > input_power_max) return 0;

	// 전력 불균형 지수 단계 계산
	for (i = 1; i < num_of_LED; i++) {
		int diff = LED_power[i - 1] - LED_power[i];
		if (diff < 0) diff = -diff;
		if (diff == 0) check[0]++;
		else if (diff <= 100) check[1]++;
		else if (diff <= 200) check[2]++;
		else if (diff <= 300) check[3]++;
		else check[4]++;
	}

	// 전력 불균형 지수 단계 중 4단계가 있는지 확인
	if (check[4] > 0) return 0;

	// 전력 불균형 지수 단계를 모두 포함하는지 확인
	for (i = 0; i < 4; i++) {
		if (check[i] == 0) return 0;
	}

	// 전력 불균형 지수 단계의 합이 한계값을 초과하는지 확인
	sum = 0;
	for (i = 1; i < 4; i++) {
		sum += check[i] * i;
	}
	if (sum > INDEX_LIMIT) return 0;

	// 위 조건을 모두 통과하면 테스트 입력 조건을 만족
	return 1;
}
*/

/**
 * LED의 소비 전력 정보를 가져오는 인터페이스
 * @param index 전력사용량을 가져올 LED번호, 0번 부터 시작한다.
 * @return index 번째 LED의 전력사용량을 반환
 */
int* f_input;
int getPowerOf(int index)
{
	
	// TODO: 원하는 LED 전력을 전달할 수 있도록 fake/stub을 구현하시오.
	return f_input[index]; // FIXME: 필요한 코드로 대체하시오.
}

void test_2_1(void)
{
	// TODO: 항목 2-1. 
	// 최소 입력 전력, 최대 입력 전력, LED의 개수가 각각 3000, 4000, 5 이고 LED들의 소비 전력이 300, 400, 400, 600, 300 인 경우를 재현하는 코드를 작성하시오.
	int f[] = {300,400,400,600,300};
	f_input = f;
	initMachine(3000,4000,5);
	checkCondition();
}

void test_2_2(void)
{
	// TODO: 항목 2-2. 
	// 최소 입력 전력, 최대 입력 전력, LED의 개수가 각각 1000, 2000, 6 이고 LED들의 소비 전력이 200, 300, 100, 50, 400, 300 인 경우를 재현하는 코드를 작성하시오.
	int f[] = {200,300,100,50,400,300};
	f_input = f;
	initMachine(1000,2000,6);
	checkCondition();
}

// 참고용으로 실행하고 싶은 코드가 있다면 아래 main()에 작성하여 활용할 수 있다.
// main 함수의 코드는 채점과 관련이 없다.
int main(void)
{
	// printTestResult는 testParameters의 내용을 테스트 입력으로 수행한 checkCondition()의 결과를 화면에 출력해준다.
	printTestResults();
	test_2_1();
	test_2_2();
	
	return 0;
}
