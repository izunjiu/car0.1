#ifndef __GPIO_CONFIG_H
#define __GPIO_CONFIG_H

#define D1						\
{								\
	.Name 	= "D1",				\
	.Port 	= GPIOB,			\
	.value 	= 0,				\
	.Pin  	= GPIO_PIN_12,		\
	.Init	= GPIODrvInit,		\
	.Write	= GPIODrvWrite,		\
	.Read	= GPIODrvRead,		\
	.next	= NULL,				\
}

#define K1						\
{								\
	.Name 	= "K1",				\
	.Port 	= GPIOA,			\
	.value 	= 0,				\
	.Pin  	= GPIO_PIN_0,		\
	.Init	= GPIODrvInit,		\
	.Write	= GPIODrvWrite,		\
	.Read	= GPIODrvRead,		\
	.next	= NULL,				\
}

#endif
