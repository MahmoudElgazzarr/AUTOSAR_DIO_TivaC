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
    /*Variable To Hold The returned Value*/
    Dio_LevelType Pin_Level;

    if (Elements[ChannelId].Dir == OUTPUT)
    {
        /*Report Error To Det and return Error*/
    }
    /*Switch Ports and Read From Specified Port*/
    switch (Elements[ChannelId].Port)
    {
    case (uint8_t)0:
        Pin_Level = Get_Bit(PORTA->DATA, Elements[ChannelId].Channel);
        break;
    case (uint8_t)1:
        Pin_Level = Get_Bit(PORTB->DATA, Elements[ChannelId].Channel);
        break;
    case (uint8_t)2:
        Pin_Level = Get_Bit(PORTC->DATA, Elements[ChannelId].Channel);
        break;
    case (uint8_t)3:
        Pin_Level = Get_Bit(PORTD->DATA, Elements[ChannelId].Channel);
        break;
    case (uint8_t)4:
        Pin_Level = Get_Bit(PORTE->DATA, Elements[ChannelId].Channel);
        break;
    case (uint8_t)5:
        Pin_Level = Get_Bit(PORTF->DATA, Elements[ChannelId].Channel);
        break;
    default:
        /*report Error To Det*/
        break;
    }
    return Pin_Level;
}

/*Syncrounous and Renterant
 * [SWS_Dio_00028]
 * */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    switch (Elements[ChannelId].Port)
    {
    case 0:
        /*Set Bit STD_HIGH*/
        if (Level == STD_HIGH)
        {
            Set_Bit(PORTA->DATA, Elements[ChannelId].Channel);
            break;
        }
        /*Set Bit STD_LOW*/
        else
        {
            Clear_Bit(PORTA->DATA, Elements[ChannelId].Channel);
            break;
        }
    case 1:
        if (Level == STD_HIGH)
        {
            Set_Bit(PORTB->DATA, Elements[ChannelId].Channel);
            break;
        }
        /*Set Bit STD_LOW*/
        else
        {
            Clear_Bit(PORTB->DATA, Elements[ChannelId].Channel);
            break;
        }
    case 2:
        if (Level == STD_HIGH)
        {
            Set_Bit(PORTC->DATA, Elements[ChannelId].Channel);
            break;
        }
        /*Set Bit STD_LOW*/
        else
        {
            Clear_Bit(PORTC->DATA, Elements[ChannelId].Channel);
            break;
        }
    case 3:
        if (Level == STD_HIGH)
        {
            Set_Bit(PORTD->DATA, Elements[ChannelId].Channel);
            break;
        }
        /*Set Bit STD_LOW*/
        else
        {
            Clear_Bit(PORTD->DATA, Elements[ChannelId].Channel);
            break;
        }
    case 4:
        if (Level == STD_HIGH)
        {
            Set_Bit(PORTE->DATA, Elements[ChannelId].Channel);
            break;
        }
        /*Set Bit STD_LOW*/
        else
        {
            Clear_Bit(PORTE->DATA, Elements[ChannelId].Channel);
            break;
        }
    case 5:
        if (Level == STD_HIGH)
        {
            Set_Bit(PORTF->DATA, Elements[ChannelId].Channel);
            break;
        }
        /*Set Bit STD_LOW*/
        else
        {
            Clear_Bit(PORTF->DATA, Elements[ChannelId].Channel);
            break;
        }
    default:
        /*report Error To Det*/
        break;

    }

}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    Dio_PortLevelType Port_Data;
    switch (PortId)
    {
    case 0:
        Port_Data = PORTA->DATA;
        break;
    case 1:
        Port_Data = PORTB->DATA;
        break;
    case 2:
        Port_Data = PORTC->DATA;
        break;
    case 3:
        Port_Data = PORTD->DATA;
        break;
    case 4:
        Port_Data = PORTE->DATA;
        break;
    case 5:
        Port_Data = PORTF->DATA;
        break;
    default:
        break;
    }
    return Port_Data;
}
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    switch (PortId)
    {
    case 0:
        PORTA->DATA = Level;
        break;
    case 1:
        PORTB->DATA = Level;
        break;
    case 2:
        PORTC->DATA = Level;
        break;
    case 3:
        PORTD->DATA = Level;
        break;
    case 4:
        PORTE->DATA = Level;
        break;
    case 5:
        PORTE->DATA = Level;
        break;
    default:
        break;
    }
}
void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level )
{

}
