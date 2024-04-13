 /******************************************************************************
 *
 * Module: PORT
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - PORT Driver
 *
 * Author: Shady Soltan
 ******************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)

/* Pre-compile option for Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)

/* Pre-compile option for Port_SetPinMode API */
#define PORT_SET_PIN_MODE_API                (STD_ON)

/* Number of configured port pins */
#define PORT_PIN_NUM                         (43U)

/*Configured Ports*/
#define PortConf_PORTA_NUM                   (0U)
#define PortConf_PORTB_NUM                   (1U)
#define PortConf_PORTC_NUM                   (2U)
#define PortConf_PORTD_NUM                   (3U)
#define PortConf_PORTE_NUM                   (4U)
#define PortConf_PORTF_NUM                   (5U)

/*Configured Port Pins*/
#define PortConf_PIN0                        (0U)
#define PortConf_PIN1                        (1U)
#define PortConf_PIN2                        (2U)
#define PortConf_PIN3                        (3U)
#define PortConf_PIN4                        (4U)
#define PortConf_PIN5                        (5U)
#define PortConf_PIN6                        (6U)
#define PortConf_PIN7                        (7U)


/* Channel Index in the array of structures in Port_PBcfg.c */

/*PORTA CONFIGURED PINS*/
#define PortConf_PORTA_CHANNEL0_ID_INDEX                            (0x00)
#define PortConf_PORTA_CHANNEL1_ID_INDEX                            (0x01)
#define PortConf_PORTA_CHANNEL2_ID_INDEX                            (0x02)
#define PortConf_PORTA_CHANNEL3_ID_INDEX                            (0x03)
#define PortConf_PORTA_CHANNEL4_ID_INDEX                            (0x04)
#define PortConf_PORTA_CHANNEL5_ID_INDEX                            (0x05)
#define PortConf_PORTA_CHANNEL6_ID_INDEX                            (0x06)
#define PortConf_PORTA_CHANNEL7_ID_INDEX                            (0x07)

/*PORTB CONFIGURED PINS*/
#define PortConf_PORTB_CHANNEL0_ID_INDEX                            (0x08)
#define PortConf_PORTB_CHANNEL1_ID_INDEX                            (0x09)
#define PortConf_PORTB_CHANNEL2_ID_INDEX                            (0x10)
#define PortConf_PORTB_CHANNEL3_ID_INDEX                            (0x11)
#define PortConf_PORTB_CHANNEL4_ID_INDEX                            (0x12)
#define PortConf_PORTB_CHANNEL5_ID_INDEX                            (0x13)
#define PortConf_PORTB_CHANNEL6_ID_INDEX                            (0x14)
#define PortConf_PORTB_CHANNEL7_ID_INDEX                            (0x15)

/*PORTC CONFIGURED PINS*/
#define PortConf_PORTC_CHANNEL0_ID_INDEX                            (0x16)
#define PortConf_PORTC_CHANNEL1_ID_INDEX                            (0x17)
#define PortConf_PORTC_CHANNEL2_ID_INDEX                            (0x18)
#define PortConf_PORTC_CHANNEL3_ID_INDEX                            (0x19)
#define PortConf_PORTC_CHANNEL4_ID_INDEX                            (0x20)
#define PortConf_PORTC_CHANNEL5_ID_INDEX                            (0x21)
#define PortConf_PORTC_CHANNEL6_ID_INDEX                            (0x22)
#define PortConf_PORTC_CHANNEL7_ID_INDEX                            (0x23)

/*PORTD CONFIGURED PINS*/
#define PortConf_PORTD_CHANNEL0_ID_INDEX                            (0x24)
#define PortConf_PORTD_CHANNEL1_ID_INDEX                            (0x25)
#define PortConf_PORTD_CHANNEL2_ID_INDEX                            (0x26)
#define PortConf_PORTD_CHANNEL3_ID_INDEX                            (0x27)
#define PortConf_PORTD_CHANNEL4_ID_INDEX                            (0x28)
#define PortConf_PORTD_CHANNEL5_ID_INDEX                            (0x29)
#define PortConf_PORTD_CHANNEL6_ID_INDEX                            (0x30)
#define PortConf_PORTD_CHANNEL7_ID_INDEX                            (0x31)

/*PORTE CONFIGURED PINS*/
#define PortConf_PORTE_CHANNEL0_ID_INDEX                            (0x32)
#define PortConf_PORTE_CHANNEL1_ID_INDEX                            (0x33)
#define PortConf_PORTE_CHANNEL2_ID_INDEX                            (0x34)
#define PortConf_PORTE_CHANNEL3_ID_INDEX                            (0x35)
#define PortConf_PORTE_CHANNEL4_ID_INDEX                            (0x36)
#define PortConf_PORTE_CHANNEL5_ID_INDEX                            (0x37)

/*PORTF CONFIGURED PINS*/
#define PortConf_PORTF_CHANNEL0_ID_INDEX                            (0x38)
#define PortConf_PORTF_CHANNEL1_ID_INDEX                            (0x39)
#define PortConf_PORTF_CHANNEL2_ID_INDEX                            (0x40)
#define PortConf_PORTF_CHANNEL3_ID_INDEX                            (0x41)
#define PortConf_PORTF_CHANNEL4_ID_INDEX                            (0x42)

#endif /* PORT_CFG_H_ */


