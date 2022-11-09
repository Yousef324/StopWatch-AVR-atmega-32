#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_cfg.h"


void DIO_Init(void)
{
	DIO_Pin_type i;
	
	for(i = PINA0; i<TOTAL_PINS; i++)
	{
		DIO_PinInit(i,PinsStatusArray[i]);
	}
}


static void DIO_PinInit(DIO_Pin_type pin, DIO_PinStatus_Type status)
{
	DIO_Port_Type port = pin/8;
	u8 pin_num = pin%8;
	
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			
			case PB:
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			
			case PC:
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			
			case PD:
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		
		case INPULL:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
}



/*

void DIO_PinInit(DIO_Pin_type pin, DIO_PinStatus_Type status)
{
	if(pin>=PINA0 && pin<=PINA7)
	{
		switch(status)
		{
			case OUTPUT:
			SET_BIT(DDRA, (pin - PINA0));
			CLR_BIT(PORTA,(pin - PINA0));
			break;
			
			case INFREE:
			CLR_BIT(DDRA, (pin - PINA0));
			CLR_BIT(PORTA,(pin - PINA0));
			break;
			
			case INPULL:
			CLR_BIT(DDRA, (pin - PINA0));
			SET_BIT(PORTA,(pin - PINA0));
			break;
		}
	}
	
	else if(pin>=PINB0 && pin<=PINB7)
	{
		switch(status)
		{
			case OUTPUT:
			SET_BIT(DDRB, (pin - PINB0));
			CLR_BIT(PORTB,(pin - PINB0));
			break;
					
			case INFREE:
			CLR_BIT(DDRB, (pin - PINB0));
			CLR_BIT(PORTB,(pin - PINB0));
			break;
					
			case INPULL:
			CLR_BIT(DDRB, (pin - PINB0));
			SET_BIT(PORTB,(pin - PINB0));
			break;
		}
	}
	
	
	else if(pin>=PINC0 && pin<=PINC7)
	{
		switch(status)
		{
			case OUTPUT:
			SET_BIT(DDRC, (pin - PINC0));
			CLR_BIT(PORTC,(pin - PINC0));
			break;
				
			case INFREE:
			CLR_BIT(DDRC, (pin - PINC0));
			CLR_BIT(PORTC,(pin - PINC0));
			break;
				
			case INPULL:
			CLR_BIT(DDRC, (pin - PINC0));
			SET_BIT(PORTC,(pin - PINC0));
			break;
		}
	}
	
	else if(pin>=PIND0 && pin<=PIND7)
	{
		switch(status)
		{
			case OUTPUT:
			SET_BIT(DDRD, (pin - PIND0));
			CLR_BIT(PORTD,(pin - PIND0));
			break;
			
			case INFREE:
			CLR_BIT(DDRD, (pin - PIND0));
			CLR_BIT(PORTD,(pin - PIND0));
			break;
			
			case INPULL:
			CLR_BIT(DDRD, (pin - PIND0));
			SET_BIT(PORTD,(pin - PIND0));
			break;
		}
	}
}

*/




void DIO_WritePin(DIO_Pin_type pin, DIO_PinVoltage_type volt)
{
	DIO_Port_Type port = pin / 8;
	u8 pin_num = pin % 8;
	
	if(volt == HIGH)
	{
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
		}
	}
	
	else
	{
		switch(port)
		{
			case PA:
			CLR_BIT(PORTA,pin_num);
			break;
			
			case PB:
			CLR_BIT(PORTB,pin_num);
			break;
			
			case PC:
			CLR_BIT(PORTC,pin_num);
			break;
			
			case PD:
			CLR_BIT(PORTD,pin_num);
			break;
		}
	}
}



/*
void DIO_WritePin(DIO_Pin_type pin, DIO_PinVoltage_type volt)
{
	if(volt == HIGH)
	{
		if(pin>=PINA0 && pin <= PINA7)
		{
			SET_BIT(PORTA,(pin - PINA0));
		}
		
		else if(pin>=PINB0 && pin <= PINB7)
		{
			SET_BIT(PORTB,(pin - PINB0));
		}
		
		else if(pin>=PINC0 && pin <= PINC7)
		{
			SET_BIT(PORTC,(pin - PINC0));
		}
		
		else if(pin>=PIND0 && pin <= PIND7)
		{
			SET_BIT(PORTD,(pin - PIND0));
		}
	}
	
	else
	{
		if(pin>=PINA0 && pin <= PINA7)
		{
			CLR_BIT(PORTA,(pin - PINA0));
		}
				
		else if(pin>=PINB0 && pin <= PINB7)
		{
			CLR_BIT(PORTB,(pin - PINB0));
		}
				
		else if(pin>=PINC0 && pin <= PINC7)
		{
			CLR_BIT(PORTC,(pin - PINC0));
		}
				
		else if(pin>=PIND0 && pin <= PIND7)
		{
			CLR_BIT(PORTD,(pin - PIND0));
		}
	}
}
*/



DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_PinVoltage_type volt = LOW;
	
	DIO_Port_Type port = pin / 8;
	u8 pin_num = pin % 8;
	
	switch(port)
	{
		case PA:
		volt = (DIO_PinVoltage_type)READ_BIT(PINA,pin_num);
		break;
		
		case PB:
		volt = (DIO_PinVoltage_type)READ_BIT(PINB,pin_num);
		break;
		
		case PC:
		volt = (DIO_PinVoltage_type)READ_BIT(PINC,pin_num);
		break;
		
		case PD:
		volt = (DIO_PinVoltage_type)READ_BIT(PIND,pin_num);
		break;
	}
	return volt;
}

/*
DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_PinVoltage_type volt = LOW;
	
	if (pin>=PINA0 && pin <= PINA7)
	{
		volt = (DIO_PinVoltage_type)READ_BIT(PINA,(pin - PINA0));
	}
	
	else if(pin>=PINB0 && pin <= PINB7)
	{
		volt = (DIO_PinVoltage_type)READ_BIT(PINB,(pin - PINB0));
	}
	
	else if(pin>=PINC0 && pin <= PINC7)
	{
		volt = (DIO_PinVoltage_type)READ_BIT(PINC,(pin - PINC0));
	}
	
	else if(pin>=PIND0 && pin <= PIND7)
	{
		volt = (DIO_PinVoltage_type)READ_BIT(PIND,(pin - PIND0));
	}
	return volt;
}
*/

void DIO_TogglePin(DIO_Pin_type pin)
{
	DIO_Port_Type port = pin / 8;
	u8 pin_num = pin % 8;
	
	switch(port)
	{
		case PA:
		TOGGLE_BIT(PORTA,pin_num);
		break;
		
		case PB:
		TOGGLE_BIT(PORTB,pin_num);
		break;
		
		case PC:
		TOGGLE_BIT(PORTC,pin_num);
		break;
		
		case PD:
		TOGGLE_BIT(PORTD,pin_num);
		break;
	}
}



void DIO_WritePort(DIO_Port_Type port, u8 data)
{
	switch(port)
	{
		case PA: PORTA = data; break;
		case PB: PORTB = data; break;
		case PC: PORTC = data; break;
		case PD: PORTD = data; break;
	}
}

u8 DIO_ReadPort(DIO_Port_Type port)
{
	u8 ret_data = 0;
	
	switch(port)
	{
		case PA: ret_data = (u8)PORTA; break;
		case PB: ret_data = (u8)PORTB; break;
		case PC: ret_data = (u8)PORTC; break;
		case PD: ret_data = (u8)PORTD; break;
	}
	
	return ret_data;
}




