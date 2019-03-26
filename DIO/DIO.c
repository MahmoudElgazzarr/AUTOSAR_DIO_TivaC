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

/*Extern Channel Array Of Structure*/
extern Dio_Channel_S_t Channels_Elements[Num_Channels];

/*Extern Channel Array Of Structure For Ports*/
extern Dio_Port_S_t Ports_Elements[Num_Ports];

/*Syncrounous and Renterant*/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    /*Todo Check Version Of Autosar Here*/
    /*Variable To Hold The returned Value*/
    Dio_LevelType Pin_Level;
    Dio_ChannelType arr_index, Channel_Place_In_arr;

    if ((ChannelId > MIN_NUM_CHANNELS) && (ChannelId < MAX_NUM_CHANNELS))
    {
        /*Conver Index Of Channel To Arr Index As Index Is Not Configured*/
        for (arr_index = 0; arr_index < Num_Channels; arr_index++)
        {
            if (ChannelId == Channels_Elements[arr_index].Channel_ID)
            {
                Channel_Place_In_arr = arr_index;
                break;
            }
        }
        /*Switch Ports and Read From Specified Port*/
        switch (Channels_Elements[Channel_Place_In_arr].Port)
        {
        case (uint8_t) 0:
            Pin_Level = Get_Bit(
                    PORTA->DATA,
                    Channels_Elements[Channel_Place_In_arr].Channel);
            break;
        case (uint8_t) 1:
            Pin_Level = Get_Bit(
                    PORTB->DATA,
                    Channels_Elements[Channel_Place_In_arr].Channel);
            break;
        case (uint8_t) 2:
            Pin_Level = Get_Bit(
                    PORTC->DATA,
                    Channels_Elements[Channel_Place_In_arr].Channel);
            break;
        case (uint8_t) 3:
            Pin_Level = Get_Bit(
                    PORTD->DATA,
                    Channels_Elements[Channel_Place_In_arr].Channel);
            break;
        case (uint8_t) 4:
            Pin_Level = Get_Bit(
                    PORTE->DATA,
                    Channels_Elements[Channel_Place_In_arr].Channel);
            break;
        case (uint8_t) 5:
            Pin_Level = Get_Bit(
                    PORTF->DATA,
                    Channels_Elements[Channel_Place_In_arr].Channel);
            break;
        default:
            /*report Error To Det*/
            break;
        }
        return Pin_Level;
    }
    else
    {
#ifdef DIO_DEV_ERROR_DETECT
        Det_ReportError(DIO_ModuleId, DIO_InstanceId, DIO_ApiId,
                        DIO_E_PARAM_INVALID_CHANNEL_ID);
#endif
    }
}

/*Syncrounous and Renterant
 * [SWS_Dio_00028]
 * */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    /*Todo Check Version Of Autosar Here*/
    if ((ChannelId > MIN_NUM_CHANNELS) && (ChannelId < MAX_NUM_CHANNELS))
    {
        Dio_ChannelType arr_index, Channel_Place_In_arr;
        /*Conver Index Of Channel To Arr Index As Index Is Not Configured*/
        for (arr_index = 0; arr_index < Num_Channels; arr_index++)
        {
            if (ChannelId == Channels_Elements[arr_index].Channel_ID)
            {
                Channel_Place_In_arr = arr_index;
                break;
            }
        }
        if (Channels_Elements[Channel_Place_In_arr].Dir == OUTPUT)
        {
            switch (Channels_Elements[Channel_Place_In_arr].Port)
            {
            case 0:
                /*Set Bit STD_HIGH*/
                if (Level == STD_HIGH)
                {
                    Set_Bit(PORTA->DATA,
                            Channels_Elements[Channel_Place_In_arr].Channel);
                    break;
                }
                /*Set Bit STD_LOW*/
                else
                {
                    Clear_Bit(PORTA->DATA,
                              Channels_Elements[Channel_Place_In_arr].Channel);
                    break;
                }
            case 1:
                if (Level == STD_HIGH)
                {
                    Set_Bit(PORTB->DATA,
                            Channels_Elements[Channel_Place_In_arr].Channel);
                    break;
                }
                /*Set Bit STD_LOW*/
                else
                {
                    Clear_Bit(PORTB->DATA,
                              Channels_Elements[Channel_Place_In_arr].Channel);
                    break;
                }
            case 2:
                if (Level == STD_HIGH)
                {
                    Set_Bit(PORTC->DATA,
                            Channels_Elements[Channel_Place_In_arr].Channel);
                    break;
                }
                /*Set Bit STD_LOW*/
                else
                {
                    Clear_Bit(PORTC->DATA,
                              Channels_Elements[Channel_Place_In_arr].Channel);
                    break;
                }
            case 3:
                if (Level == STD_HIGH)
                {
                    Set_Bit(PORTD->DATA,
                            Channels_Elements[Channel_Place_In_arr].Channel);
                    break;
                }
                /*Set Bit STD_LOW*/
                else
                {
                    Clear_Bit(PORTD->DATA,
                              Channels_Elements[Channel_Place_In_arr].Channel);
                    break;
                }
            case 4:
                if (Level == STD_HIGH)
                {
                    Set_Bit(PORTE->DATA,
                            Channels_Elements[Channel_Place_In_arr].Channel);
                    break;
                }
                /*Set Bit STD_LOW*/
                else
                {
                    Clear_Bit(PORTE->DATA,
                              Channels_Elements[Channel_Place_In_arr].Channel);
                    break;
                }
            case 5:
                if (Level == STD_HIGH)
                {
                    Set_Bit(PORTF->DATA,
                            Channels_Elements[Channel_Place_In_arr].Channel);
                    break;
                }
                /*Set Bit STD_LOW*/
                else
                {
                    Clear_Bit(PORTF->DATA,
                              Channels_Elements[Channel_Place_In_arr].Channel);
                    break;
                }
            default:
                /*report Error To Det*/
                break;
            }
        }
        else
        {
            /*Report Invalid Pin Direction*/
#ifdef DIO_DEV_ERROR_DETECT
            Det_ReportError(DIO_ModuleId, DIO_InstanceId, DIO_ApiId,
                            DIO_E_PARAM_INVALID_CHANNEL_ID);
#endif
        }
    }
    else
    {
        /*Report Invalid Pin Direction*/
#ifdef DIO_DEV_ERROR_DETECT
        Det_ReportError(DIO_ModuleId, DIO_InstanceId, DIO_ApiId,
                        DIO_E_PARAM_INVALID_CHANNEL_ID);
#endif
    }

}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    /*Todo Check Version Of Autosar Here*/
    Dio_PortLevelType Port_Data;
    if ((PortId >= MIN_NUM_PORTS) && (PortId <= MAX_NUM_PORTS))
    {
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
    else
    {
        /*Report Invalid Port Number*/
#ifdef DIO_DEV_ERROR_DETECT
        Det_ReportError(DIO_ModuleId, DIO_InstanceId, DIO_ApiId,
                        DIO_E_PARAM_INVALID_PORT_ID);
#endif
    }
}
/**/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    /*Todo Check Version Of Autosar Here*/
    /*Todo Check Port ID if valid or not*/

    /*Conver Index Of Port To Arr Index*/
    Dio_PortType arr_index, Port_Place_In_arr;
    if ((PortId >= MIN_NUM_PORTS) && (PortId <= MAX_NUM_PORTS))
    {
        for (arr_index = 0; arr_index < Num_Ports; arr_index++)
        {
            if (PortId == Ports_Elements[arr_index].Port_ID)
            {
                Port_Place_In_arr = arr_index;
                break;
            }
        }
        /*should be Assigned Outside!*/
        if (Ports_Elements[Port_Place_In_arr].Dir == OUTPUT)
        {
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
        }
        else
        {
            /*Report Invalid Port Direction*/
#ifdef DIO_DEV_ERROR_DETECT
            Det_ReportError(DIO_ModuleId, DIO_InstanceId, DIO_ApiId,
                            DIO_E_PARAM_INVALID_PORT_ID);
#endif
        }
    }
    else
    {
        /*Report Invalid Port ID*/
#ifdef DIO_DEV_ERROR_DETECT
        Det_ReportError(DIO_ModuleId, DIO_InstanceId, DIO_ApiId,
                        DIO_E_PARAM_INVALID_PORT_ID);
#endif

    }
}

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,
                           Dio_PortLevelType Level)
/*Todo Check Version Of Autosar Here*/
{
    switch (ChannelGroupIdPtr->port)
    {
    case PORTA_R:
        if (Level == STD_HIGH)
        {
            (PORTA->DATA) |= (ChannelGroupIdPtr->mask);
            break;
        }
        else
        {
            (PORTA->DATA) &= ~(ChannelGroupIdPtr->mask);
            break;
        }
    case PORTB_R:
        if (Level == STD_HIGH)
        {
            (PORTB->DATA) |= (ChannelGroupIdPtr->mask);
            break;
        }
        else
        {
            (PORTB->DATA) &= ~(ChannelGroupIdPtr->mask);
            break;
        }
    case PORTC_R:
        if (Level == STD_HIGH)
        {
            (PORTC->DATA) |= (ChannelGroupIdPtr->mask);
            break;
        }
        else
        {
            (PORTC->DATA) &= ~(ChannelGroupIdPtr->mask);
            break;
        }
    case PORTD_R:
        if (Level == STD_HIGH)
        {
            (PORTD->DATA) |= (ChannelGroupIdPtr->mask);
            break;
        }
        else
        {
            (PORTD->DATA) &= ~(ChannelGroupIdPtr->mask);
            break;
        }
        /*Todo To Edit PORTE & F in case of level high and low*/
    case PORTE_R:
        (PORTE->DATA) |= (ChannelGroupIdPtr->mask);
        break;
    case PORTF_R:
        (PORTF->DATA) |= (ChannelGroupIdPtr->mask);
        break;
    default:
        /*Report Error*/
        break;
    }

}
