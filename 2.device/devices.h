#ifndef __DEVICES_H
#define __DEVICES_H
/* 管理设备层头文件以及驱动层是否使用 */
#include "config.h"

#if USE_GPIO_DEVICE
	#include "dev_gpio.h"
	#define USE_GPIO_DRIVER
#endif

#endif
