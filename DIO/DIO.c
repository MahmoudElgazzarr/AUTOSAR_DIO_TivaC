/*
 * DIO.c
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-040
 */
#include "Det.h"
#include "Dio_Cfg.h"
#include "DIO.h"

/*Syncrounous and Renterant*/
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
    return STD_HIGH;
}

/*Syncrounous and Renterant*/
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{

}
