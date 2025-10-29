#ifndef __DEV_GPIO_H
#define __DEV_GPIO_H

typedef struct GPIODevice{
	char* Name;
	void* Port;
	int value;
	unsigned short Pin;
	int(*Init)(struct GPIODevice *ptdev);
	int(*Write)(struct GPIODevice *ptdev, unsigned char state);
	int(*Read)(struct GPIODevice *ptdev);
	struct GPIODevice* next;
}GPIODEV;

void IODevicesRegister(void);
void IODevicesInsert(GPIODEV *ptDev);
GPIODEV *IODevicesFind(const char *name);

#endif
