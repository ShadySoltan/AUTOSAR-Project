 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Shady Soltan
 ******************************************************************************/

#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

#include "Port_Regs.h"

/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration = {
                                     /*PORT A*/
                     /*PORTA PIN 0*/ PortConf_PORTA_NUM,PortConf_PIN0,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTA PIN 1*/ PortConf_PORTA_NUM,PortConf_PIN1,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTA PIN 2*/ PortConf_PORTA_NUM,PortConf_PIN2,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTA PIN 3*/ PortConf_PORTA_NUM,PortConf_PIN3,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTA PIN 4*/ PortConf_PORTA_NUM,PortConf_PIN4,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTA PIN 5*/ PortConf_PORTA_NUM,PortConf_PIN5,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTA PIN 6*/ PortConf_PORTA_NUM,PortConf_PIN6,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTA PIN 7*/ PortConf_PORTA_NUM,PortConf_PIN7,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,


                                     /*PORT B*/
                     /*PORTB PIN 0*/ PortConf_PORTB_NUM,PortConf_PIN0,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTB PIN 1*/ PortConf_PORTB_NUM,PortConf_PIN1,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTB PIN 2*/ PortConf_PORTB_NUM,PortConf_PIN2,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTB PIN 3*/ PortConf_PORTB_NUM,PortConf_PIN3,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTB PIN 4*/ PortConf_PORTB_NUM,PortConf_PIN4,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTB PIN 5*/ PortConf_PORTB_NUM,PortConf_PIN5,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTB PIN 6*/ PortConf_PORTB_NUM,PortConf_PIN6,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTB PIN 7*/ PortConf_PORTB_NUM,PortConf_PIN7,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,

                                     /*PORT C*/
                     /*PORTC PIN 0*/ PortConf_PORTC_NUM,PortConf_PIN0,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTC PIN 1*/ PortConf_PORTC_NUM,PortConf_PIN1,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTC PIN 2*/ PortConf_PORTC_NUM,PortConf_PIN2,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTC PIN 3*/ PortConf_PORTC_NUM,PortConf_PIN3,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTC PIN 4*/ PortConf_PORTC_NUM,PortConf_PIN4,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTC PIN 5*/ PortConf_PORTC_NUM,PortConf_PIN5,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTC PIN 6*/ PortConf_PORTC_NUM,PortConf_PIN6,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTC PIN 7*/ PortConf_PORTC_NUM,PortConf_PIN7,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,

                                     /*PORT D*/
                     /*PORTD PIN 0*/ PortConf_PORTD_NUM,PortConf_PIN0,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTD PIN 1*/ PortConf_PORTD_NUM,PortConf_PIN1,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTD PIN 2*/ PortConf_PORTD_NUM,PortConf_PIN2,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTD PIN 3*/ PortConf_PORTD_NUM,PortConf_PIN3,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTD PIN 4*/ PortConf_PORTD_NUM,PortConf_PIN4,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTD PIN 5*/ PortConf_PORTD_NUM,PortConf_PIN5,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTD PIN 6*/ PortConf_PORTD_NUM,PortConf_PIN6,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTD PIN 7*/ PortConf_PORTD_NUM,PortConf_PIN7,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,

                                     /*PORT E*/
                     /*PORTE PIN 0*/ PortConf_PORTE_NUM,PortConf_PIN0,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTE PIN 1*/ PortConf_PORTE_NUM,PortConf_PIN1,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTE PIN 2*/ PortConf_PORTE_NUM,PortConf_PIN2,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTE PIN 3*/ PortConf_PORTE_NUM,PortConf_PIN3,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTE PIN 4*/ PortConf_PORTE_NUM,PortConf_PIN4,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTE PIN 5*/ PortConf_PORTE_NUM,PortConf_PIN5,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,

                                     /*PORT F*/
                     /*PORTF PIN 0*/ PortConf_PORTF_NUM,PortConf_PIN0,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTF PIN 1*/ PortConf_PORTF_NUM,PortConf_PIN1,PORT_PIN_MODE_DIO,PORT_PIN_OUT,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTF PIN 2*/ PortConf_PORTF_NUM,PortConf_PIN2,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTF PIN 3*/ PortConf_PORTF_NUM,PortConf_PIN3,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,OFF,
                     /*PORTF PIN 4*/ PortConf_PORTF_NUM,PortConf_PIN4,PORT_PIN_MODE_DIO,PORT_PIN_IN,PIN_LEVEL_LOW,STD_ON,STD_ON,PULL_UP

};
