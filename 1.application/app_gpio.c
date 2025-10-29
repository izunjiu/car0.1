#include "devices.h"
#include "Mytype.h"
#include "stm32f4xx_hal.h"
void app_test(void)
{
	//注册设备对象
	IODevicesRegister();
	//查找LED、Btn设备对象
	GPIODEV *ptLED = IODevicesFind("D1");
	if(NULLDEV == ptLED)	return;
	GPIODEV *ptBTN = IODevicesFind("K1");
	if(NULLDEV == ptBTN)	return;
	//初始化GPIO对象
	ptLED->Init(ptLED);
	ptBTN->Init(ptBTN);
	while(1)
	{
		//Test git 
		//按键按下切换灯的状态
		int state = ptBTN->Read(ptBTN);
		if(0 == state)
		{
			HAL_Delay(50);
			state = ptBTN->Read(ptBTN);
			if(0 == state)
				HAL_Delay(50);
				state = ptBTN->Read(ptBTN);
				if(0 == state)
					ptLED->Write(ptLED, !ptLED->Read(ptLED));
		}
	}
}
