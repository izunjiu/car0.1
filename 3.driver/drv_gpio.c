#include "drv_gpio.h"
#include "devices.h"
#include "stm32f4xx_hal.h"
#include "./drv_config/gpio_config.h"
//结构体数组，存储要创建的GPIO设备对象
static int GPIODrvInit(GPIODEV *ptdev);
static int GPIODrvRead(GPIODEV *ptdev);
static int GPIODrvWrite(GPIODEV *ptdev, unsigned char state);

static GPIODEV gGPIODevices[] = {
	D1,
	K1,
};
//创建GPIO设备对象函数
void GPIODeviceCreate(void)
{
	//计算结构体数组中有多少个GPIO设备对象需要创建
	int num = sizeof(gGPIODevices)/sizeof(GPIODEV);
	for(int i = 0; i < num; i++)
	{
		//将结构体中的设备对象逐个插入到链表中
		IODevicesInsert(&gGPIODevices[i]);
	}
}
//GPIO驱动初始化函数
static int GPIODrvInit(GPIODEV *ptdev)
{
	if(NULL == ptdev)	return -1;
	return 0;
}
//GPIO驱动读取函数
static int GPIODrvRead(GPIODEV *ptdev)
{
	if(NULL == ptdev)	return -1;
	int state = HAL_GPIO_ReadPin(ptdev->Port, ptdev->Pin);
	return state;
}
//GPIO驱动写函数
static int GPIODrvWrite(GPIODEV *ptdev, unsigned char state)
{
	if(NULL == ptdev)				return -1;
	if(state != 0 && state != 1)	return -1;	
	HAL_GPIO_WritePin(ptdev->Port, ptdev->Pin, (GPIO_PinState)state);
	return 0;
}
