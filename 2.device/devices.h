#ifndef __DEVICES_H
#define __DEVICES_H
/* �����豸��ͷ�ļ��Լ��������Ƿ�ʹ�� */
#include "config.h"

#if USE_GPIO_DEVICE
	#include "dev_gpio.h"
	#define USE_GPIO_DRIVER
#endif

#endif
