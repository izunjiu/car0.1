#include "devices.h"
#include "Mytype.h"
#include "stm32f4xx_hal.h"
void app_test(void)
{
	//ע���豸����
	IODevicesRegister();
	//����LED��Btn�豸����
	GPIODEV *ptLED = IODevicesFind("D1");
	if(NULLDEV == ptLED)	return;
	GPIODEV *ptBTN = IODevicesFind("K1");
	if(NULLDEV == ptBTN)	return;
	//��ʼ��GPIO����
	ptLED->Init(ptLED);
	ptBTN->Init(ptBTN);
	while(1)
	{
		//Test git 
		//���������л��Ƶ�״̬
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
