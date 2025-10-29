#include "dev_gpio.h"
#include "drivers.h"
#include "Mytype.h"
#include <string.h>
//����һ��ͷ�ڵ㣬��ʼ��Ϊ��ָ��
static GPIODEV *gHeadDevice = NULLDEV;

//ע��GPIO�豸����
void IODevicesRegister(void)
{
	GPIODeviceCreate();
}
//����һ���µ�GPIO�豸����(ͷ�巨)
void IODevicesInsert(GPIODEV *ptDev)
{
	if(NULLDEV == gHeadDevice)
	{
		//ͷ�ڵ�Ϊ��ʱ����Ҫ������豸����ֱ�ӷ���ͷ�ڵ���Ϊͷ
		gHeadDevice = ptDev;
	}
	else
	{
		//ͷ�ڵ㲻Ϊ��ʱ���ȸ���ͷ�ڵ��λ��Ϊ����������豸�����ٽ�Ҫ������豸�������ͷ�ڵ㴦
		ptDev->next = gHeadDevice;
		gHeadDevice = ptDev;
	}
}
//����ĳ��GPIO����
GPIODEV *IODevicesFind(const char *name)
{
	//�������ͷ�ڵ㴦��ʼ����
	GPIODEV *ptDev = gHeadDevice;
	while(NULLDEV != ptDev)
	{
		//�������
		if(strstr(ptDev->Name, name))
		{
			//�ҵ���Ӧ�Ķ���ID
			return ptDev;//�����ҵ�������ڵ�
		}
		else
		{
			//�ڵ�ǰ��ͷ�ڵ�û�ҵ������ID
			//����������һ���ڵ�
			ptDev = ptDev->next;
		}
	}
	return NULLDEV;
}
