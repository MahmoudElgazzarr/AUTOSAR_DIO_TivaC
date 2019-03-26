/*
 * Std_Types.h
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-040
 */
#include "Platform_Types.h"
#include "Compiler.h"

#ifndef HEADERS_STD_TYPES_H_
#define HEADERS_STD_TYPES_H_


/*Channel Level Type*/
enum Voltage_Level
{
    STD_LOW = (uint8_t) 0x00,
    STD_HIGH = (uint8_t)0x01
};
/*uint8 Function Return Type*/
typedef uint8_t Std_ReturnType;


/*Not Standard*/
enum PIN_INPUT_OUTPUT
{
    OUTPUT = (uint8_t) 0U,
    INPUT = (uint8_t)  1U
};
/*declare structure which hold version type*/
typedef struct{
    uint16_t vendorID;
    uint16_t moduleID;
    uint8_t sw_major_version;
    uint8_t sw_minor_version;
    uint8_t w_patch_version;
}Std_VersionInfoType;

/**define API's return if OK=1 or not OK=0**/
#define E_OK 1
#define E_NOT_OK 0

#endif /* HEADERS_STD_TYPES_H_ */
