#include <STD_TYPES.h>
#include "DIO_interface.h"
#include "sevSeg_interface.h"
#include "util/delay.h"



void main (void)
{
	DIO_VidSetPortDirection(2,0x03);

	while (1)
	{
		for(s8 counter1=0;counter1<100;counter1++)
		{


			for(s8 counter2=0;counter2<50;counter2++)
			{
				DIO_VidSetPinValue(2,0,0);
				DIO_VidSetPinValue(2,1,1);
				sevSeg_VidDisplayNumber(0,counter1/10);
				_delay_ms(10);
				DIO_VidSetPinValue(2,1,0);
				DIO_VidSetPinValue(2,0,1);
				sevSeg_VidDisplayNumber(0,counter1%10);
				_delay_ms(10);
			}

		}
	}
}
