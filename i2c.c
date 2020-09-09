#include "i2c.h"

void Wait()
{
	while(!(I2CMSST & 0x40));
	I2CMSST &= ~0x40;
}

void Start()
{
	I2CMSCR = 0x01;				//����START����
	Wait();
}

void SendData(char dat)
{
	I2CTXD = dat;					//д���ݵ����ݻ�����
	I2CMSCR = 0x02;				//����SEND����
	Wait();
}

void RecvACK()
{
	I2CMSCR = 0x03;
	Wait();
}

char RecvData()
{
	I2CMSCR = 0x04;			//����RECV����
	Wait();
	return I2CRXD;
}

void SendACK()
{
	I2CMSST = 0x00;		//����ACK�ź�
	I2CMSCR = 0x05;		//����ACK����
	Wait();
}

void SendNAK()
{
	I2CMSST = 0x01;		//����NAK�ź�
	I2CMSCR = 0x05;		//����ACK����
	Wait();
}

void Stop()
{
	I2CMSCR = 0x06;		//����STOP����
	Wait();
}

void I2Cinit()
{
	P_SW2 = 0x80;
	I2CCFG = 0xe0;			//ʹ��I2C����ģʽ
	I2CCFG = 0xc2;
	I2CMSST = 0x00;
}