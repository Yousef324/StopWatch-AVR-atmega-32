#include "SEGMENT.h"
#define F_CPU 8000000
#include <util/delay.h>




int main(void)
{
	DIO_Init();
	
	signed char count = 0, reset = 0, ModeFlag = 0 , i = 0, pauseflag = 2, ButtonPressed_2 = 0, ButtonPressed_3 = 0, ButtonPressed_4 = 0 ;
	
	while(1)
	{
		
		SegmentDisplayMux(count);
		
		if(DIO_ReadPin(PIND4) == LOW)        //MODE
		{
			if(ButtonPressed_4 == 0)
			{
				DIO_WritePin(PINC1,LOW);
				if(ModeFlag == 0)
				{
					ModeFlag = 1;
					DIO_TogglePin(PINC2);
				}
				else
				{
					ModeFlag = 0;
					DIO_TogglePin(PINC2);
					reset = count;
				}

				ButtonPressed_4 = 1;
			}
		}
		else
		{
			ButtonPressed_4 = 0;
		}
	
	
		if(DIO_ReadPin(PIND3) == LOW)
		{
			if(ButtonPressed_3 == 0)
			{
				if(ModeFlag == 1)
				{
					count+=1;
					if(count%10 == 0)
					{
						count = count - 10;
					}
				}
				else
				{
					count = reset;
				}
				
				ButtonPressed_3 = 1;
			}
		}
		else
		{
			ButtonPressed_3 = 0;
		}
		
		
		
		if(	DIO_ReadPin(PIND2) == LOW)
		{
			if(ButtonPressed_2 == 0)
			{
				if(ModeFlag == 1)
				{
					count+=10;
					if(count >= 100)
					{
						count = 0;
					}
				}
				else
				{
					pauseflag = 0;
					DIO_WritePin(PINC1,LOW);
				}
		
				ButtonPressed_2 = 1;
			}
		}

		else
		{
			ButtonPressed_2 = 0;
		}
		
		while(count > 0 && pauseflag == 0)
		{
			count--;
			for(i = 0; i<25; i++)
			{
				SegmentDisplayMux(count);
				if(DIO_ReadPin(PIND2) == LOW)
				{
					if(ButtonPressed_2 == 0)
					{
						pauseflag = 1;
						DIO_WritePin(PINC1,HIGH);
						ButtonPressed_2 = 1;
						break;
					}
				}
				else
				{
					ButtonPressed_2 = 0;
				}
				_delay_ms(10);
				
				SegmentDisplayMux(count);
				if(DIO_ReadPin(PIND3) == LOW)
				{
					if(ButtonPressed_3 == 0)
					{
						count = reset;
						ButtonPressed_3 = 1;
					}
				}
				else
				{
					ButtonPressed_3 = 0;
				}
				_delay_ms(10);
			}
			
			if(count == 0)
			{
				pauseflag = 1;
			}
		}
		
		if(count == 0 && pauseflag == 1)
		{
			for(i = 0; i<15; i++)
			{
				
				DIO_WritePin(PINC0,HIGH);
				DIO_WritePin(PINC5,HIGH);
				DIO_WritePin(S1_EN,HIGH);
				DIO_WritePin(S2_EN,LOW);
				_delay_ms(100);
					
					
				DIO_WritePin(PINC0,LOW);
				DIO_WritePin(PINC5,LOW);
				DIO_WritePin(S1_EN,LOW);
				DIO_WritePin(S2_EN,HIGH);
				_delay_ms(100);
			}
				
			pauseflag = 2;
		}
		
		
		
	}

}


