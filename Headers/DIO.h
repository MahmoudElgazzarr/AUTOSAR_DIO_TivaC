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

/*Dio Channel Type Typedef that defines which pin to use Numaric
 * [SWS_Dio_00015]
 * */
typedef uint8_t Dio_ChannelType;

/*Specifies if the pin is std_high or std_low*/
typedef uint8_t Dio_LevelType;

/*defines number of pins in the port*/
typedef uint8_t Dio_PortType;

/*Dio Direction Type*/
typedef uint8_t Dio_DirectionType;

/*Structure Definiton For Channel Group*/
typedef struct Dio_ChannelGroup
{
    uint8_t mask;
    uint8_t offset;
    Dio_PortType port;
}Dio_ChannelGroupType;

/*Struct To Represent channels*/
typedef struct
{
    /*Defines Which Port*/
     Dio_PortType Port;
    /*Which pin*/
    Dio_ChannelType Channel;
    /*input or Output*/
    Dio_DirectionType Dir;
}Dio_Channel_S_t;

/*DIO Read Channel Declaration*/
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );

/*Dio Read Channel Definition*/
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );

#endif /* HEADERS_DIO_H_ */
