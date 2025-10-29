#include "dev_gpio.h"
#include "drivers.h"
#include "Mytype.h"
#include <string.h>
//定义一个头节点，初始化为空指针
static GPIODEV *gHeadDevice = NULLDEV;

//注册GPIO设备对象
void IODevicesRegister(void)
{
	GPIODeviceCreate();
}
//插入一个新的GPIO设备对象(头插法)
void IODevicesInsert(GPIODEV *ptDev)
{
	if(NULLDEV == gHeadDevice)
	{
		//头节点为空时，将要插入的设备对象直接放在头节点作为头
		gHeadDevice = ptDev;
	}
	else
	{
		//头节点不为空时，先更新头节点的位置为即将插入的设备对象，再将要插入的设备对象放在头节点处
		ptDev->next = gHeadDevice;
		gHeadDevice = ptDev;
	}
}
//查找某个GPIO对象
GPIODEV *IODevicesFind(const char *name)
{
	//从链表的头节点处开始查找
	GPIODEV *ptDev = gHeadDevice;
	while(NULLDEV != ptDev)
	{
		//链表存在
		if(strstr(ptDev->Name, name))
		{
			//找到对应的对象ID
			return ptDev;//返回找到的链表节点
		}
		else
		{
			//在当前的头节点没找到适配的ID
			//继续查找下一个节点
			ptDev = ptDev->next;
		}
	}
	return NULLDEV;
}
