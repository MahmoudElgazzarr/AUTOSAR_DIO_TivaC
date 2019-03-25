

/**
 * main.c
 */
#include "Std_Types.h"
#include "DIO_Internal.h"
#include "DIO.h"
#define SYSCTL_RCGC2_R (*((volatile unsigned long *)0x400FE108))
    /*Activate PORTF Clock*/

void main(void)
{
    volatile unsigned long delay;
    volatile unsigned long i;
    SYSCTL_RCGC2_R |= 0x00000020;     // 1) activate clock for Port F

    delay = SYSCTL_RCGC2_R;           // allow time for clock to start

    /*Disable Analog Function of PORTF*/
    PORTF->AMSEL = 0x00 ;
    /*Set Direction of PF1 , PF2 , PF3 output*/
    PORTF->DIR |= 0xff ;
    /*Disable Alternate Function of PORTF*/
    PORTF->AFSEL = 0x00 ;
    /*Enable digital I/O on PF1 , PF2 , PF3 */
    PORTF->DEN = 0xff ;
    while(1)
    {
        Dio_WriteChannel(0,STD_HIGH);
        Dio_WriteChannel(1,STD_HIGH);
        for(i=0;i<1000000;i++)
        {
        }
        Dio_WriteChannel(0,STD_LOW);
        Dio_WriteChannel(1,STD_LOW);
        for(i=0;i<1000000;i++)
        {
        }
    }
}
