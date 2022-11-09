#ifndef SEGMENT_H_
#define SEGMENT_H_


#include "DIO_interface.h"

/****************************************************** SEGMENT PIN CONFIGURATION ****************************************************************/
#define SEGMENT_PORT			PA
#define SEGMENT_PORT_EN			PC
#define S1_EN					PINC6
#define S2_EN					PINC7

/************************************************************************************************************************************************/

void SegmentDisplay(u8 number);
void SegmentDisplayBCD(u8 number);
void SegmentDisplay_HEX_BCD(u8 number);
void SegmentDisplayMux(u8 number);




#endif /* SEGMENT_H_ */