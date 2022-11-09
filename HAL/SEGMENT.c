
#include "SEGMENT.h"

#define F_CPU 8000000
#include <util/delay.h>

void SegmentDisplay(u8 number)
{
	u8 arr[] = {0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
	
	DIO_WritePort(SEGMENT_PORT,(arr[number]<<1));
}


void SegmentDisplayBCD(u8 number)
{
	u8 d0 = 0 , d1 = 0;
	
	d0 = number % 10;
	d1 = number / 10;
	
	DIO_WritePort(SEGMENT_PORT,((d0<<4)|d1));
	
}

void SegmentDisplay_HEX_BCD(u8 number)
{
	DIO_WritePort(SEGMENT_PORT,number);
}

void SegmentDisplayMux(u8 number)
{
	u8 d0 , d1, arr[] = {0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
	d0 = number % 10;
	d1 = number / 10;
	
	DIO_WritePin(S1_EN,HIGH);
	DIO_WritePort(SEGMENT_PORT,(arr[d0]<<1));
	DIO_WritePin(S2_EN,LOW);
	_delay_ms(5);
	
	DIO_WritePin(S2_EN,HIGH);
	DIO_WritePort(SEGMENT_PORT,(arr[d1]<<1));
	DIO_WritePin(S1_EN,LOW);
	_delay_ms(5);
}

