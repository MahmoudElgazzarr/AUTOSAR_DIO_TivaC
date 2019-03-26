/*
 * Dio_Lcfg.c
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-040
 */

#include "Std_Types.h"
#include "Dio_MemMap.h"
#include "Dio_Cfg.h"
#include "DIO.h"
#include "DIO_Internal.h"

/*Array Of Channels Defined By User*/
Dio_Channel_S_t Channels_Elements[Num_Channels] = { { channel39_ID, PORTF_R,
                                                      Channel1, OUTPUT },
                                                    { channel40_ID, PORTF_R,
                                                      Channel2, OUTPUT } };

/*Array Of Structure of Ports Add By User*/
Dio_Port_S_t Ports_Elements[Num_Ports] = { { PORTA_ID, PORTA_R, OUTPUT } };

/**/
