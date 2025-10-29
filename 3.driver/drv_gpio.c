#include "drv_gpio.h"
#include "devices.h"
#include "stm32f4xx_hal.h"
#include "./drv_config/gpio_config.h"
//�ṹ�����飬�洢Ҫ������GPIO�豸����
static int GPIODrvInit(GPIODEV *ptdev);
static int GPIODrvRead(GPIODEV *ptdev);
static int GPIODrvWrite(GPIODEV *ptdev, unsigned char state);

static GPIODEV gGPIODevices[] = {
	D1,
	K1,
};
//����GPIO�豸������
void GPIODeviceCreate(void)
{
	//����ṹ���������ж��ٸ�GPIO�豸������Ҫ����
	int num = sizeof(gGPIODevices)/sizeof(GPIODEV);
	for(int i = 0; i < num; i++)
	{
		//���ṹ���е��豸����������뵽������
		IODevicesInsert(&gGPIODevices[i]);
	}
}
//GPIO������ʼ������
static int GPIODrvInit(GPIODEV *ptdev)
{
	if(NULL == ptdev)	return -1;
	return 0;
}
//GPIO������ȡ����
static int GPIODrvRead(GPIODEV *ptdev)
{
	if(NULL == ptdev)	return -1;
	int state = HAL_GPIO_ReadPin(ptdev->Port, ptdev->Pin);
	return state;
}
//GPIO����д����
static int GPIODrvWrite(GPIODEV *ptdev, unsigned char state)
{
	if(NULL == ptdev)				return -1;
	if(state != 0 && state != 1)	return -1;	
	HAL_GPIO_WritePin(ptdev->Port, ptdev->Pin, (GPIO_PinState)state);
	return 0;
}
