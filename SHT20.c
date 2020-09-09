#include "SHT20.H"

void SHT_WR_Byte(u8 dat);
{
	Start();
	SendData(0x80);
	RecvACK();
	SendData(dat);
	RecvACK();
	Stop();
}

void SHT_RD_Byte()
{
	Start();
	SendData(0x81);
	RecvACK();
	RecvData();
	SendACK();
}