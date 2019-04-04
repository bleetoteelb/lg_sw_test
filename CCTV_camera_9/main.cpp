// <done>
#include <iostream>

#include "./lib/CctvController.h"


// 테스트 대상은 아래 주석과 같이 구현되어 있다. 
// 필요한 경우 아래 주석의 내용을 참고하여 테스트 입력과 테스트 코드를 작성하시오. 
// NOTE: 테스트 대상 코드는 빌드에 이미 포함되어 있으니 아래 주석을 해제하여 사용하지 마시오.

// #define NOT_DETECTED (-3000)

/**
 * MotionDetector class
 * 센서로 움직임을 감지하여 움직임이 발생한 위치를 가져올 수 있는 드라이버 인터페이스
 *
class MotionDetector
{
public:
	/**
	 * 센서로 움직임을 감지하여 움직임이 발생한 위치를 가져올 수 있는 드라이버 인터페이스
	 * @return 동작을 감지하여 동작이 발상하면 해당 위치(각도)를, 동작이 감지되지 않은 경우 NOT_DETECTED를 반환한다.
	 *
	virtual int detectMovement() = 0;
};

/**
 * CctvController class
 * Cctv를 제어하는 장비 (테스트 대상)
 *
class CctvController
{
private:
	MotionDetector& detector_;

public:
	/**
	 * Cctv를 제어하는 모듈을 초기화
	 * 최초 감시 시야각도 범위 : -20도~20도, 오류도 : 0 로 초기화하는 로직이 포함되어 있다.
	 *
	CctvController(MotionDetector& detector) : detector_(detector) {...}

	/**
	 * Cctv를 제어하는 함수. 특정 시간 간격으로 주기적으로 호출된다. (테스트 대상)
	 * 움직임 감지기에서 감지 위치를 받아 카메라를 이동시키는 제어를 하고 누적 오류도를 계산한다.
	 * @return 현재까지 누적된 오류도를 반환한다.
	 *
	int calculateRangeAndError() 
	{
		int detectedDegree = detector_.detectMovement();

		if (detectedDegree == NOT_DETECTED)
			return errorRate_;

		if (detectedDegree < currentRangeStart_ || currentRangeEnd_ < detectedDegree)
			return errorRate_;

		int expand_deg = adjustRange(detectedDegree - 10, detectedDegree + 10); // 카메라 각도 조정

		if (expand_deg == 0)
			errorRate_ += -2;
		else if (expand_deg <= 3)
			errorRate_ += 0;
		else if (expand_deg <= 5)
			errorRate_ += 2;
		else if (expand_deg <= 7)
			errorRate_ += 3;
		else if (expand_deg <= 9)
			errorRate_ += 5;
		else if (expand_deg <= 10)
			errorRate_ += 7;

		if (errorRate_ > 30)
			errorRate_ = 30;
		if (errorRate_ < 0)
			errorRate_ = 0;

		return errorRate_;
	}

	...

private:
	int errorRate_;
	int currentRangeStart_;
	int currentRangeEnd_;
	...
};
*/



/* [문제 1. 작성 내용] */
// 테스트 케이스를 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
// 각 테스트 케이스의 구조: { 입력 개수 N, 움직임 발생 방향 각도 1, ... 움직임 발생 방향 각도 N} 형식
// ( 0 번 요소 : 테스트 케이스의 움직임 발생 요소 갯수
//			1~ : 움직임 발생 방향 각도. 최소 -90, 최대 90, 현재 CCTV 감시 시야각도 내의 각도로 설정)
//				 만약 해당 시점에서 움직임 발생하지 않은 상황으로 처리할 경우 NOT_DETECTED 상수 사용
// 예를 들어 testInput이 { 15,-15,NOT_DETECTED,23,11}으로 작성되는 경우,
// 15, -15, (감지 되지 않음), 23, 11 에서 감지되는 상황을 표현한다. 
int testInput_example[] = { 5, 15, -15, NOT_DETECTED, 23, 11 }; // 예제 : 5번의 감지 상황 진행 , 15, -15, (감지 되지 않음), 23, 11 상황 - 최종 오류도 -> 7

int testInput_1_1[] = { 21,0,11,15,21,29,-20,-30,-40,10,10,10,10,10,01,10,10,10,10,10,10,-46}; //TODO: 문제1.(1-1) 최종 오류도가 9가 되는 상황
int testInput_1_2[] = { 14,0,11,15,23,-20,-30,-40,-50,10,10,10,10,10,-56}; //TODO: 문제2.(1-2) 최종 오류도가 23이 되는 상황  ( '오류도가 0보다 작아질 때' 조건 한번만 발생 , -2만큼 변경되는 조건 6번 사용 )
int testInput_1_3[] = { 17,0,11,15,23,-20,-30,-40,-50,10,10,10,10,10,10,10,10,-56 }; //TODO: 문제3.(1-3) 최종 오류도가 17이 되는 상황  ( 2만큼 변경되는 조건 1번 사용 )


// 문제2.

class MotionDetector_test : public MotionDetector
{
private:
	int* test_order;
	int cnt=0;
public:
	MotionDetector_test(int* k):test_order(k){}

	int detectMovement(){
		return test_order[cnt++];
	}
};

void test_2_1(void)
{
	//TODO: 문제2. (2-1) 움직임이 다음의 순서대로 방향에서 발생하는 상황 : (15) – (발견 안됨) – (23) – (-18) – (-26)
	int input_test[] = {15,NOT_DETECTED,23,-18,-26};

	MotionDetector_test mdtest(input_test);
	CctvController cctv(mdtest);

	int cnt = 5;
	while(cnt--) cctv.calculateRangeAndError();
}

void test_2_2(void)
{
	//TODO: 문제2. (2-2) 움직임이 다음의 순서대로 방향에서 발생하는 상황 : (2) – (-11) – (발견 안됨) – (발견안됨) – (15) – (-21)
	int input_test[] = {2,-11,NOT_DETECTED,NOT_DETECTED,15,-21};

	MotionDetector_test mdtest(input_test);
	CctvController cctv(mdtest);

	int cnt = 6;
	while(cnt--) cctv.calculateRangeAndError();
}

// main 함수는 작성한 테스트 케이스를 실행하여 확인하는 용도로 사용한다.
// 필요에 따라서 마음대로 변경해도 무방하다. main 함수의 내용은 채점과 무관하다.
int main(void)
{
	printTestInputResult("input_example", testInput_example);
	printTestInputResult("input_1_1", testInput_1_1);
	printTestInputResult("input_1_2", testInput_1_2);
	printTestInputResult("input_1_3", testInput_1_3);

	test_2_1();

	test_2_2();

	return 0;
}