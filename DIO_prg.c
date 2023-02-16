/*********************************************************************/
/*********************************************************************/
/**********Author: Mohamed Rezk Bayoumi*******************************/
/**********File: DIO_private.h****************************************/
/**********Date: 2nd sep 2022*****************************************/
/**********Version: V1************************************************/
/********* Desc: Mohamed Rezk Bayoumi*******************************/
/*********************************************************************/
/*********************************************************************/


#include <STD_TYPES.h>
#include <bit_math.h>
#include "DIO_private.h"



void DIO_VidSetPinDirection(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Dir)
{
    /*this function supposed to determine the pin direction
    *whether it's input or output 
    *PORTA_REG -> Copy_u8Port=0
    *PORTB_REG -> Copy_u8Port=1
    *PORTC_REG -> Copy_u8Port=2
    *PORTD_REG -> Copy_u8Port=3
    */
    switch(Copy_U8Dir)
    {
        case INPUT:
        switch(Copy_U8Port)
        {
            case PORTA:
            {
            CLEAR_BIT(DDRA,Copy_U8Pin);
            break;
            }
            case PORTB: /*PORT B*/
            {
            CLEAR_BIT(DDRB,Copy_U8Pin);
            break;
            }
            case PORTC: /*PORTC_REG*/
            {
            CLEAR_BIT(DDRC,Copy_U8Pin);
            break;
            }
            case PORTD: /*PORTD_REG*/
            {
            CLEAR_BIT(DDRD,Copy_U8Pin);
            break;
            }
            default :
            {
            	break; /*Do nothing*/

            }

        }break;
        case 1:
        switch(Copy_U8Port)
        {
            case 0: /*PORTA_REG*/
            {
            SET_BIT(DDRA,Copy_U8Pin);
            break;
            }
            case 1: /*PORT B*/
            {
            SET_BIT(DDRB,Copy_U8Pin);
            break;
            }
            case 2: /*PORTC_REG*/
            {
            SET_BIT(DDRC,Copy_U8Pin);
            break;
            }
            case 3: /*PORTD_REG*/
            {
            SET_BIT(DDRD,Copy_U8Pin);
            break;
            }
            default :
            	break;
        }break;

    }
}









void DIO_VidSetPortDirection(u8 Copy_U8Port,u8 Copy_U8Dir)
{
    switch (Copy_U8Port)
    {
        case 0: /*PORTA_REG*/
        DDRA=Copy_U8Dir;
        break;
        case 1: /*PORTB_REG*/
        DDRB=Copy_U8Dir;
        break;
        case 2: /*PORTC_REG*/
        DDRC=Copy_U8Dir;
        break;
        case 3: /*PORTD_REG*/
        DDRD=Copy_U8Dir;
        break;
        default:
        ;

    }
}

void DIO_VidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Val)
{
    if(Copy_U8Val==0)
    {
        switch(Copy_U8Port)
        {
            case 0: /*PORTA_REG*/
            {
            CLEAR_BIT(PORTA_REG,Copy_U8Pin);
            break;
            }
            case 1: /*PORT B*/
            {
            CLEAR_BIT(PORTB_REG,Copy_U8Pin);
            break;
            }
            case 2: /*PORTC_REG*/
            {
            CLEAR_BIT(PORTC_REG,Copy_U8Pin);
            break;
            }
            case 3: /*PORTD_REG*/
            {
            CLEAR_BIT(PORTD_REG,Copy_U8Pin);
            break;
            }
            default :
            {
            	break; /*Do nothing*/
            }
        }
    }

    else if(Copy_U8Val==1)
    {
        switch(Copy_U8Port)
        {
            case 0: /*PORTA_REG*/
            SET_BIT(PORTA_REG,Copy_U8Pin);
            break;
            case 1: /*PORT B*/
            SET_BIT(PORTB_REG,Copy_U8Pin);
            break;
            case 2: /*PORTC_REG*/
            SET_BIT(PORTC_REG,Copy_U8Pin);
            break;
            case 3: /*PORTD_REG*/
            SET_BIT(PORTD_REG,Copy_U8Pin);
            break;
            default :
            	break;
        }
     }
}



void DIO_VidSetPortValue(u8 Copy_U8Port,u8 Copy_U8Val)
{
    switch (Copy_U8Port)
    {
        case 0: /*PORTA_REG*/
        PORTA_REG=Copy_U8Val;
        break;
        case 1: /*PORTB_REG*/
        PORTB_REG=Copy_U8Val;
        break;
        case 2: /*PORTC_REG*/
        PORTC_REG=Copy_U8Val;
        break;
        case 3: /*PORTD_REG*/
        PORTD_REG=Copy_U8Val;
        break;
        default:
        ;    

}
}

void DIO_VidTogglePinValue(u8 Copy_U8Port,u8 Copy_U8Pin)
{
    switch(Copy_U8Port)
    {
        case 0: /*PORTA_REG*/
        TOGGLE_BIT(PORTA_REG,Copy_U8Pin);
        break;
        case 1: /*PORTB_REG*/
        TOGGLE_BIT(PORTB_REG,Copy_U8Pin);
        break;
        case 2: /*PORTC_REG*/
        TOGGLE_BIT(PORTC_REG,Copy_U8Pin);
        break;
        case 3: /*PORTD_REG*/
        TOGGLE_BIT(PORTD_REG,Copy_U8Pin);
        break;
        default:
        ; 
    }
}

u8 DIO_U8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin)
{
    u8 Loc_PinVal;
    switch(Copy_U8Port)
    {
        case 0: /*PINA_REG*/
        Loc_PinVal=GET_BIT(PINA_REG,Copy_U8Pin);
        break;
        case 1: /*PINB_REG*/
        Loc_PinVal=GET_BIT(PINB_REG,Copy_U8Pin);
        break;
        case 2: /*PORTC_REG*/
        Loc_PinVal=GET_BIT(PINC_REG,Copy_U8Pin);
        break;
        case 3: /*PORTD_REG*/
        Loc_PinVal=GET_BIT(PIND_REG,Copy_U8Pin);
        break;
        default:
        ; 
    }
    return Loc_PinVal;
}
