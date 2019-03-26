/*
 * Det.h
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-040
 */

#ifndef HEADERS_DET_H_
#define HEADERS_DET_H_

enum DIO_DET_ERRORS
{
    DIO_E_PARAM_INVALID_CHANNEL_ID = 0x0A, /* User  passed invalid channel ID */
    DIO_E_PARAM_INVALID_PORT_ID = 0x14, /* User  passed invalid Port ID */
    DIO_E_PARAM_INVALID_GROUP = 0x1F, /* User  passed invalid group of channels */
    DIO_E_PARAM_POINTER = 0x20, /* User passed Null Pointer */
};

#endif /* HEADERS_DET_H_ */
