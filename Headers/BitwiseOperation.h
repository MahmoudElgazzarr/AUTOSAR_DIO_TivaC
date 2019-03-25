/*
 * BitwiseOperation.h
 *
 * Created: 2/13/2019 11:40:37 AM
 *  Author: AVE-LAP-040
 */ 


#ifndef BITWISEOPERATION_H_
#define BITWISEOPERATION_H_
/*Set Bit and Clear Bit */
#define Set_Bit(Register,Bit) ((Register) = ((Register)|(1<<(uint8_t)(Bit))))

#define Clear_Bit(Register,Bit) ((Register) &= ~(1<<(uint8_t)(Bit)))

#define Get_Bit(Register,Bit) (((Register)&(1<<(uint8_t)(Bit)))>>(uint8_t)(Bit))

#define Toggle_Bit(Register,Bit) ((Register)^=(1<<(uint8_t)(Bit)))


#endif /* BITWISEOPERATION_H_ */
