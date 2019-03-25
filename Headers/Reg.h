#ifndef INCLUDES_REG_H_
#define INCLUDES_REG_H_



#define     __I     volatile const       /*!< Defines 'read only' permissions                 */
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */


typedef struct
{ /*DIO Structure*/
    __I uint32_t RESERVED0[255];
    __IO uint32_t DATA;                     /*DIO Data*/
    __IO uint32_t DIR;                      /*DIO Direction*/
    __IO uint32_t IS;                       /*DIO Interrupt Sense*/
    __IO uint32_t IBE;                      /*DIO Interrupt Both Edges*/
    __IO uint32_t IEV;                      /*DIO Interrupt Event*/
    __IO uint32_t IM;                       /*DIO Interrupt Mask*/
    __IO uint32_t RIS;                      /*DIO Raw Interrupt Status*/
    __IO uint32_t MIS;                      /*DIO Masked Interrupt Status*/
    __O uint32_t ICR;                       /*DIO Interrupt Clear*/
    __IO uint32_t AFSEL;                    /*DIO Alternate Function Select*/
    __I uint32_t RESERVED1[55];
    __IO uint32_t DR2R;                     /*DIO 2-mA Drive Select*/
    __IO uint32_t DR4R;                     /*DIO 4-mA Drive Select*/
    __IO uint32_t DR8R;                     /*DIO 8-mA Drive Select*/
    __IO uint32_t ODR;                      /*DIO Open Drain Select*/
    __IO uint32_t PUR;                      /*DIO Pull-Up Select*/
    __IO uint32_t PDR;                      /*DIO Pull-Down Select*/
    __IO uint32_t SLR;                      /*DIO Slew Rate Control Select*/
    __IO uint32_t DEN;                      /*DIO Digital Enable*/
    __IO uint32_t LOCK;                     /*DIO Lock*/
    __I uint32_t CR;                        /*DIO Commit*/
    __IO uint32_t AMSEL;                    /*DIO Analog Mode Select*/
    __IO uint32_t PCTL;                     /*DIO Port Control*/
    __IO uint32_t ADCCTL;                   /*DIO ADC Control*/
    __IO uint32_t DMACTL;                   /*DIO DMA Control*/
} DIO_Type;

/*Base Addresses of Ports*/
#define PORTA ((DIO_Type*)0x40004000)
#define PORTB ((DIO_Type*)0x40005000)
#define PORTC ((DIO_Type*)0x40006000)
#define PORTD ((DIO_Type*)0x40007000)
#define PORTE ((DIO_Type*)0x40024000)
#define PORTF ((DIO_Type*)0x40025000)

#endif /* INCLUDES_REG_H_ */
