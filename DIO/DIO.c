/*
 * DIO.c
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-040
 */
#include "Std_Types.h"
#include "Det.h"
#include "BitwiseOperation.h"
#include "Dio_Cfg.h"
#include "DIO_Internal.h"
#include "DIO.h"

extern Dio_Channel_S_t Elements[Num_Channels];

/*Syncrounous and Renterant*/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint8_t index;
    /*Variable To Hold The returned Value*/
    Dio_LevelType Pin_Level;

    if (Elements[ChannelId].Dir == OUTPUT)
    {
        /*Report Error To Det and return Error*/
    }
    /*Switch Ports and Read From Specified Port*/
    switch (Elements[ChannelId].Port)
    {
    case 0:
        Pin_Level = Get_Bit(PORTA->DATA, Elements[ChannelId].Channel);
        break;
    case 1:
        Pin_Level = Get_Bit(PORTB->DATA, Elements[ChannelId].Channel);
        break;
    case 2:
        Pin_Level = Get_Bit(PORTC->DATA, Elements[ChannelId].Channel);
        break;
    case 3:
        Pin_Level = Get_Bit(PORTD->DATA, Elements[ChannelId].Channel);
        break;
    case 4:
        Pin_Level = Get_Bit(PORTE->DATA, Elements[ChannelId].Channel);
        break;
    case 5:
        Pin_Level = Get_Bit(PORTF->DATA, Elements[ChannelId].Channel);
        break;
    default:
        /*report Error To Det*/
        break;
    }
    return Pin_Level;
}

/*Syncrounous and Renterant*/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    switch (Elements[ChannelId].Port)
    {
    case 0:
        Set_Bit(PORTA->DATA,Elements[ChannelId].Channel);
        break;
    case 1:
        Set_Bit(PORTB->DATA, Elements[ChannelId].Channel);
        break;
    case 2:
        Set_Bit(PORTC->DATA, Elements[ChannelId].Channel);
        break;
    case 3:
        Set_Bit(PORTD->DATA, Elements[ChannelId].Channel);
        break;
    case 4:
        Set_Bit(PORTE->DATA, Elements[ChannelId].Channel);
        break;
    case 5:
        Set_Bit(PORTF->DATA, Elements[ChannelId].Channel);
        break;
    default:
        /*report Error To Det*/
        break;

    }

}
