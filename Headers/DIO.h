/*
 * DIO.h
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-040
 */

#include "Std_Types.h"
#include "Dio_Cfg.h"

#ifndef HEADERS_DIO_H_
#define HEADERS_DIO_H_


#define DIO_DEV_ERROR_DETECT (uint8)(1)

#define DIO_ModuleId 0
#define DIO_InstanceId 0
#define DIO_ApiId 0

/*Dio Channel Type Typedef that defines which pin to use Numaric
 * [SWS_Dio_00015]
 * */
typedef uint8_t Dio_ChannelType;

/*typedef for Dio_PortLevelType
 * [SWS_Dio_00186]
 * */
typedef uint32_t Dio_PortLevelType;

/*Specifies if the pin is std_high or std_low*/
typedef uint8_t Dio_LevelType;

/*defines number of pins in the port*/
typedef uint8_t Dio_PortType;

/*Dio Direction Type*/
typedef uint8_t Dio_DirectionType;

/*DIO ID Number*/
typedef uint8_t Dio_IdType;
/*Enum That Defines IDS of Channels*/
enum Channels_IDS
{
    /*PORTA IDS*/
    channel0_ID,
    channel1_ID,
    channel2_ID,
    channel3_ID,
    channel4_ID,
    channel5_ID,
    channel6_ID,
    channel7_ID,
    /*PORTB IDS*/
    channel8_ID,
    channel9_ID,
    channel10_ID,
    channel11_ID,
    channel12_ID,
    channel13_ID,
    channel14_ID,
    channel15_ID,
    /*PORTC IDS*/
    channel16_ID,
    channel17_ID,
    channel18_ID,
    channel19_ID,
    cahnnel20_ID,
    channel21_ID,
    channel22_ID,
    channel23_ID,
    /*PORTD IDS*/
    channel24_ID,
    channel25_ID,
    channel26_ID,
    channel27_ID,
    channel28_ID,
    channel29_ID,
    channel30_ID,
    cahnnel31_ID,
    /*PORTE IDS*/
    channel32_ID,
    channel33_ID,
    channel34_ID,
    channel35_ID,
    channel36_ID,
    channel37_ID,
    /*PORTF IDS*/
    channel38_ID,
    channel39_ID,
    channel40_ID,
    cahnnel41_ID,
    channel42_ID,
    cahnnel43_ID,
};

/*Defines IDS For Ports*/
enum
{
    PORTA_ID,
    PORTB_ID,
    PORTC_ID,
    PORTD_ID,
    PORTE_ID,
    PORTF_ID
};

/*Structure Definiton For Channel Group*/
typedef struct Dio_ChannelGroup
{
    uint8_t mask;
    uint8_t offset;
    Dio_PortType port;
} Dio_ChannelGroupType;

/*Struct To Represent channels*/
typedef struct
{
    /*Defines ID Of Channel*/
    Dio_IdType Channel_ID;
    /*Defines Which Port*/
    Dio_PortType Port;
    /*Which pin in port*/
    Dio_ChannelType Channel;
    /*input or Output*/
    Dio_DirectionType Dir;
} Dio_Channel_S_t;

/*Struct To Represent Ports*/
typedef struct
{
    /*element To Specify ID*/
    Dio_PortType Port_ID;
    /*Element To Specify Which Port*/
    Dio_PortType Port;
    /*Element To Specify Direction*/
    Dio_DirectionType Dir;
} Dio_Port_S_t;

/*DIO Read Channel Declaration*/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/*Dio Read Channel Definition*/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/*Dio Read Port Definition*/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
/*Dio Write Port Definition*/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/*Prototype For Write Channel Group*/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,
                           Dio_PortLevelType Level);

#endif /* HEADERS_DIO_H_ */
