// <done>
/* 
 테스트 대상 프로그램은 아래의 모듈로 구성된다.

 * Thermostat: 설정 온도를 입력 받아 감지된 온도와의 차에 따라 냉난방기를 제어하는 역할을 한다.
   * Thermostat_SetDesiredTemperature(): 목표 온도를 설정하는 API
   * Thermostat_Wakeup(): 타이머에 의해 주기적으로 실행되는 API. 주요 제어 로직이 있다.
	 * Thermostat_Create(): 제어기 초기화
 * FanController: 송풍팬을 제어하는 모듈
   * FanController_SetFanSpeed(): 인자로 전달한 속도(rpm)로 송풍팬을 가동시킨다.
 * HeaterController: 난방기를 제어하는 모듈
   * HeaterController_TurnOn(): 난방기를 켜는 API
   * HeaterController_TurnOff(): 난방기를 끄는 API
 * CoolerController: 냉방기를 제어하는 모듈
   * CoolerController_TurnOn(): 냉방기를 켜는 API
   * CoolerController_TurnOff(): 냉방기를 끄는 API
 * SensorProbe: 현재 온도를 반환하는 모듈
   * SensorProbe_GetTemperature(): 현재 온도를 반환하는 API
*/

/************************************
  FanController.h  소스 코드 내용
 ************************************
void  FanController_SetFanSpeed(unsigned short  speed);
*************************************/

/************************************
  HeaterController.h  소스 코드 내용
 ************************************
void  HeaterController_TurnOn();
void  HeaterController_TurnOff();
*************************************/

/************************************
  CoolerController.h  소스 코드 내용
 ************************************
void  CoolerController_TurnOn();
void  CoolerController_TurnOff();
*************************************/

/************************************
  SensorProbe.h  소스 코드 내용
 ************************************
int  SensorProbe_GetTemperature();
*************************************/



/************************************
  테스트 대상 Thermostat.c  소스 코드 내용
 ************************************ 

#include "Thermostat.h"

#include "HeaterController.h"
#include "CoolerController.h"
#include "SensorProbe.h"
#include "FanController.h"



static int  desiredTemperature_ = 0;
static int  wasHeaterOrCooler;  

// 
void  Thermostat_Create()
{
	HeaterController_TurnOff();
	CoolerController_TurnOff();

	desiredTemperature_ = -1;  // unset
	wasHeaterOrCooler = 0;
}

void  Thermostat_SetDesiredTemperature(int  desired)
{
	desiredTemperature_ = desired;
}

void  Thermostat_Wakeup()
{
	
	const int  currentTemperature = SensorProbe_GetTemperature();

	if ( currentTemperature == desiredTemperature_ )
	{
		if ( wasHeaterOrCooler == 0 )
		{
			HeaterController_TurnOff();
			LOG("STOP HEATER");
		}
		else if ( wasHeaterOrCooler == 1 )
		{
			CoolerController_TurnOff();
			LOG("STOP COOLER");
		}
		else
		{
		}		
	}
	else
	{
		if ( currentTemperature < desiredTemperature_ )
		{
			HeaterController_TurnOn();
			wasHeaterOrCooler = 0;

			if ( desiredTemperature_ - currentTemperature >= 10 )
			{
				FanController_SetFanSpeed(500);
				LOG("HEATER 500");
			}
			else if ( desiredTemperature_ - currentTemperature > 2 )
			{
				FanController_SetFanSpeed(200);
				LOG("HEATER 200");
			}
			else
			{
				FanController_SetFanSpeed(0);
				LOG("HEATER 0");
			}
		}
		else
		{
			CoolerController_TurnOn();
			wasHeaterOrCooler = 1;

			if ( currentTemperature - desiredTemperature_ >= 10 )
			{
				FanController_SetFanSpeed(500);
				LOG("COOLER 500");
			}
			else if ( currentTemperature - desiredTemperature_ > 2 )
			{
				FanController_SetFanSpeed(200);
				LOG("COOLER 500");
			}
			else
			{
				FanController_SetFanSpeed(0);
				LOG("COOLER 0");
			}
		}
	}
}
************************************/



#include "Thermostat.h"

#include "CoolerController.h"
#include "HeaterController.h"
#include "SensorProbe.h"
#include "FanController.h"

#include <stdio.h>

// NOTE: 필요한 경우 아래의 함수 외 다른 test double을 구현해서 사용할 수 있다.
void  CoolerController_TurnOn()
{

}

void  CoolerController_TurnOff()
{

}

void  FanController_SetFanSpeed(unsigned short  speed)
{

}

void  HeaterController_TurnOn()
{

}

void  HeaterController_TurnOff()
{

}

int fake =0;
int  SensorProbe_GetTemperature()
{
	return fake;
}


void setup()
{
	// TODO: 각 테스트의 초기화에 필요한 코드를 작성하시오.
	Thermostat_Create();
	
}

void teardown()
{
	// TODO: 각 테스트가 끝난 후 정리 작업에 필요한 코드를 작성하시오.
	Thermostat_Create();
}

// NOTE: 아래 함수는 수정 불가.
void run(void(* testFunction)())
{
	setup();
	
	testFunction();

	teardown();
}


void test1()
{
	// TODO: 난방기가 켜지고 송풍팬을 500rpm으로 동작시키는 테스트 코드를 작성하시오.
	fake = 20;
	
	Thermostat_SetDesiredTemperature(fake+15);
	Thermostat_Wakeup();
	
	
}

void test2()
{
	// TODO: 난방기가 켜지고 송풍팬을 200rpm으로 동작시키는 테스트 코드를 작성하시오.
	fake = 20;
	
	Thermostat_SetDesiredTemperature(fake+6);
	Thermostat_Wakeup();
}

void test3()
{
	// TODO: 난방기가 켜지고 송풍팬을 0rpm으로 동작시키는 테스트 코드를 작성하시오.
	fake = 20;
	
	Thermostat_SetDesiredTemperature(fake+1);
	Thermostat_Wakeup();
}

void test4()
{
	// TODO: 난방기가 꺼지고 송풍팬을 0rpm으로 동작시키는 테스트 코드를 작성하시오.
	fake = 20;
	
	Thermostat_SetDesiredTemperature(fake);
	Thermostat_Wakeup();
}

void test5()
{
	// TODO: 냉방기가 켜지고 송풍팬을 500rpm으로 동작시키는 테스트 코드를 작성하시오.
	fake = 20;
	
	Thermostat_SetDesiredTemperature(fake-15);
	Thermostat_Wakeup();
}



// NOTE: 아래 함수는 수정 불가.
int main()
{
	run(test1);
	run(test2);
	run(test3);
	run(test4);
	run(test5);

	return 0;
}
