 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Shady Soltan
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT==STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

/*Global Variables For The Source File*/
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;
STATIC const Port_PinConfig* Port_Pins = NULL_PTR;

/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module
************************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* check if the input configuration pointer is not a NULL_PTR */
    if (NULL_PTR == ConfigPtr)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
    }
    else
#endif
    {
    Port_Pins = ConfigPtr->Port_PinConfig; /* point to the required Port Registers base address */
    Port_PinType Pin;

    for(Pin=0; Pin<PORT_PIN_NUM; Pin++)
    {
        volatile uint32* CurrentPort_Ptr = NULL_PTR;
        uint8 pin_mode = 0;
        /*Pin Mode Checker*/
        uint8 Pin_Mode_Error = 0;
        switch(Port_Pins[Pin].portId)
        {
        case PortConf_PORTA_NUM:
            CurrentPort_Ptr = (volatile uint32*)GPIO_PORTA_BASE_ADDRESS;
            break;
        case PortConf_PORTB_NUM:
            CurrentPort_Ptr = (volatile uint32*)GPIO_PORTB_BASE_ADDRESS;
            break;
        case PortConf_PORTC_NUM:
            CurrentPort_Ptr = (volatile uint32*)GPIO_PORTC_BASE_ADDRESS;
            break;
        case PortConf_PORTD_NUM:
            CurrentPort_Ptr = (volatile uint32*)GPIO_PORTD_BASE_ADDRESS;
            break;
        case PortConf_PORTE_NUM:
            CurrentPort_Ptr = (volatile uint32*)GPIO_PORTE_BASE_ADDRESS;
            break;
        case PortConf_PORTF_NUM:
            CurrentPort_Ptr = (volatile uint32*)GPIO_PORTF_BASE_ADDRESS;
            break;
        }

        /*Adjust the mode for PORTA pins*/
        if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) //PORTA - PIN0
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN1) //PORTA - PIN1
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN2) //PORTA - PIN2
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN3) //PORTA - PIN3
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN4) //PORTA - PIN4
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN5) //PORTA - PIN5
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN6) //PORTA - PIN6
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 5;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN7) //PORTA - PIN7
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 5;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) //PORTB - PIN0
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN1) //PORTB - PIN1
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN2) //PORTB - PIN2
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN3) //PORTB - PIN3
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN4) //PORTB - PIN4
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN5) //PORTB - PIN5
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN6) //PORTB - PIN6
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN7) //PORTB - PIN7
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) //PORTC - PIN0
        {
            pin_mode = 0;
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN1) //PORTC - PIN1
        {
            pin_mode = 0;
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN2) //PORTC - PIN2
        {
            pin_mode = 0;
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN3) //PORTC - PIN3
        {
            pin_mode = 0;
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN4) //PORTC - PIN4
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_UART_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_QEI:
                pin_mode = 6;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN5) //PORTC - PIN5
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_UART_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN6) //PORTC - PIN6
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_UART_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_USB:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN7) //PORTC - PIN7
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_UART_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_USB:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) //PORTD - PIN0
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_SPI_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_PWM_B:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN1) //PORTD - PIN1
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_SPI_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_PWM_B:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN2) //PORTD - PIN2
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_SPI_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_USB:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN3) //PORTD - PIN3
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_SPI_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_QEI:
                pin_mode = 6;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_USB:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN4) //PORTD - PIN4
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN5) //PORTD - PIN5
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN6) //PORTD - PIN6
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN7) //PORTD - PIN7
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_NMI:
                pin_mode = 8;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTE_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) //PORTE - PIN0
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTE_NUM && Port_Pins[Pin].pinId == PortConf_PIN1) //PORTE - PIN1
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTE_NUM && Port_Pins[Pin].pinId == PortConf_PIN2) //PORTE - PIN2
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTE_NUM && Port_Pins[Pin].pinId == PortConf_PIN3) //PORTE - PIN3
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTE_NUM && Port_Pins[Pin].pinId == PortConf_PIN4) //PORTE - PIN4
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_PWM_B:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTE_NUM && Port_Pins[Pin].pinId == PortConf_PIN5) //PORTE - PIN5
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_PWM_B:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTF_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) //PORTF - PIN0
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_NMI:
                pin_mode = 8;
                break;

            case PORT_PIN_MODE_COMPARATOR_OUT:
                pin_mode = 9;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTF_NUM && Port_Pins[Pin].pinId == PortConf_PIN1) //PORTF - PIN1
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_COMPARATOR_OUT:
                pin_mode = 9;
                break;

            case PORT_PIN_MODE_TRACE_CLK:
                pin_mode = 14;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTF_NUM && Port_Pins[Pin].pinId == PortConf_PIN2) //PORTF - PIN2
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_PWM_B:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_TRACE_CLK:
                pin_mode = 14;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTF_NUM && Port_Pins[Pin].pinId == PortConf_PIN3) //PORTF - PIN3
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_TRACE_CLK:
                pin_mode = 14;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTF_NUM && Port_Pins[Pin].pinId == PortConf_PIN4) //PORTF - PIN4
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_QEI:
                pin_mode = 6;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_USB:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else
        {
            /*Do nothing*/
        }

        #if(PORT_DEV_ERROR_DETECT==STD_ON)
        /*The Mode Is Not available For The Configured Pin*/
        if (Pin_Mode_Error != 0)
        {
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_INVALID_MODE);
        }
        else
        {
            /*Do Nothing*/
        }
        #endif

        /*Unlock and Commit the Special Pins*/
        if ((Port_Pins[Pin].portId == PortConf_PORTF_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) || (Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN7))
        {
            *(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_COMMIT_REG_OFFSET) , Port_Pins[Pin].pinId);
        }
        else if ( ((Port_Pins[Pin].portId) == PortConf_PORTC_NUM) && ((Port_Pins[Pin].pinId) <= PortConf_PIN3))
        {
            /*Do not commit or lock for JTAG Pins from PC0 to PC3*/
        }
        else
        {
            /*Do nothing no need to lock or commit for other pins*/
        }

        /*Adjust the mode of the pin*/
        if(((Port_Pins[Pin].portId) == PortConf_PORTC_NUM) && ((Port_Pins[Pin].pinId) <= PortConf_PIN3))
        {
            /*Do Nothing*/
        }
        else if (Port_Pins[Pin].port_pin_mode == PORT_PIN_MODE_DIO)
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pinId);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pinId);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            *(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[Pin].pinId * 4));     /* Clear the PMCx bits for this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[Pin].pinId);            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
        }
        else if (Port_Pins[Pin].port_pin_mode == PORT_PIN_MODE_ADC)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pinId);        /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pinId);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            *(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[Pin].pinId * 4));     /* Clear the PMCx bits for this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[Pin].pinId);            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pinId);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pinId);               /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            *(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_CTL_REG_OFFSET) |= ((0x0000000F & pin_mode) << (Port_Pins[Pin].pinId * 4));     /* Clear the PMCx bits for this pin */
        }

        /*Adjust the direction of the pin*/
        if(((Port_Pins[Pin].portId) == PortConf_PORTC_NUM) && ((Port_Pins[Pin].pinId) <= PortConf_PIN3))
        {
            /*Do Nothing*/
        }
        else if(Port_Pins[Pin].direction == PORT_PIN_OUT)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pinId);
        }
        else if(Port_Pins[Pin].direction == PORT_PIN_IN)
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pinId);
        }
        else
        {
            /*Do Nothing*/
        }

        /*Adjust the internal resistor of the pin*/
        if(((Port_Pins[Pin].portId) == PortConf_PORTC_NUM) && ((Port_Pins[Pin].pinId) <= PortConf_PIN3))
        {
            /*Do Nothing*/
        }
        else if(Port_Pins[Pin].resistor == PULL_UP && Port_Pins[Pin].direction == PORT_PIN_IN)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[Pin].pinId);
        }
        else if(Port_Pins[Pin].resistor == PULL_DOWN && Port_Pins[Pin].direction == PORT_PIN_IN)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[Pin].pinId);
        }
        else
        {
            /*Do Nothing*/
        }

        /*Adjust the initial level for the pin*/
        if(((Port_Pins[Pin].portId) == PortConf_PORTC_NUM) && ((Port_Pins[Pin].pinId) <= PortConf_PIN3))
        {
            /*Do Nothing*/
        }
        else if(Port_Pins[Pin].initial_value == STD_HIGH && Port_Pins[Pin].direction == PORT_PIN_OUT)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[Pin].pinId);
        }
        else if(Port_Pins[Pin].initial_value == STD_LOW && Port_Pins[Pin].direction == PORT_PIN_OUT)
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[Pin].pinId);
        }
        else
        {
            /*Do Nothing*/
        }
      }
    Port_Status = PORT_INITIALIZED;
   }
}

/************************************************************************************
* Service Name: Port_SetPinDirection
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID Number
*                  Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function Sets the port pin direction
************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirection Direction)
{
#if (PORT_DEV_ERROR_DETECT==STD_ON)
    if (PORT_NOT_INITIALIZED==Port_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
    }
    else
    {
        /*Do Nothing*/
    }

    if(Pin >= PORT_PIN_NUM)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_PARAM_PIN);
    }
    else
    {
        /*Do Nothing*/
    }

    if(Port_Pins[Pin].pin_direction_changeable == STD_OFF)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
    }
    else
    {
        /*Do Nothing*/
    }
#endif

    /*Main Function body*/
    volatile uint32* CurrentPort_Ptr = NULL_PTR;
    switch(Port_Pins[Pin].portId)
    {
    case PortConf_PORTA_NUM:
        CurrentPort_Ptr = (volatile uint32*)GPIO_PORTA_BASE_ADDRESS;
        break;
    case PortConf_PORTB_NUM:
        CurrentPort_Ptr = (volatile uint32*)GPIO_PORTB_BASE_ADDRESS;
        break;
    case PortConf_PORTC_NUM:
        CurrentPort_Ptr = (volatile uint32*)GPIO_PORTC_BASE_ADDRESS;
        break;
    case PortConf_PORTD_NUM:
        CurrentPort_Ptr = (volatile uint32*)GPIO_PORTD_BASE_ADDRESS;
        break;
    case PortConf_PORTE_NUM:
        CurrentPort_Ptr = (volatile uint32*)GPIO_PORTE_BASE_ADDRESS;
        break;
    case PortConf_PORTF_NUM:
        CurrentPort_Ptr = (volatile uint32*)GPIO_PORTF_BASE_ADDRESS;
        break;
    }

    /*Adjust the direction of the pin*/
    if(Port_Pins[Pin].direction == PORT_PIN_OUT)
    {
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pinId);
    }
    else if(Port_Pins[Pin].direction == PORT_PIN_IN)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pinId);
    }
    else
    {
        /*Do Nothing*/
    }
}
#endif

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction
************************************************************************************/
void Port_RefreshPortDirection(void)
{
#if (PORT_DEV_ERROR_DETECT==STD_ON)
    if (PORT_NOT_INITIALIZED==Port_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
    }
    else
#endif
    {
        Port_PinType Pin;
        for(Pin=0; Pin<PORT_PIN_NUM; Pin++)
        {
            volatile uint32* CurrentPort_Ptr = NULL_PTR;

            switch(Port_Pins[Pin].portId)
            {
            case PortConf_PORTA_NUM:
                CurrentPort_Ptr = (volatile uint32*)GPIO_PORTA_BASE_ADDRESS;
                break;
            case PortConf_PORTB_NUM:
                CurrentPort_Ptr = (volatile uint32*)GPIO_PORTB_BASE_ADDRESS;
                break;
            case PortConf_PORTC_NUM:
                CurrentPort_Ptr = (volatile uint32*)GPIO_PORTC_BASE_ADDRESS;
                break;
            case PortConf_PORTD_NUM:
                CurrentPort_Ptr = (volatile uint32*)GPIO_PORTD_BASE_ADDRESS;
                break;
            case PortConf_PORTE_NUM:
                CurrentPort_Ptr = (volatile uint32*)GPIO_PORTE_BASE_ADDRESS;
                break;
            case PortConf_PORTF_NUM:
                CurrentPort_Ptr = (volatile uint32*)GPIO_PORTF_BASE_ADDRESS;
                break;
            }

            /*refresh the current pin direction during runtime if it is configured non changeable*/
            if((Port_Pins[Pin].pin_direction_changeable) == STD_OFF)
            {
                if(Port_Pins[Pin].direction == PORT_PIN_OUT)
                {
                    SET_BIT((*(volatile uint32*)((volatile uint8*)CurrentPort_Ptr+PORT_DIR_REG_OFFSET)),Port_Pins[Pin].pinId);
                }
                else if(Port_Pins[Pin].direction == PORT_PIN_IN)
                {
                    CLEAR_BIT((*(volatile uint32*)((volatile uint8*)CurrentPort_Ptr+PORT_DIR_REG_OFFSET)),Port_Pins[Pin].pinId);
                }
                else
                {
                    /*Do Nothing*/
                }
            }
            else
            {
                /*Do Nothing*/
            }
        }
    }
}

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out):  versioninfo - Pointer to where to store the version information of this module
* Return value: None
* Description: Returns the version information of this module
************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if(PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if input pointer is not Null pointer */
    if(versioninfo == NULL_PTR)
    {
        /* Report to DET  */
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
    }
    else
#endif /* (PORT_DEV_ERROR_DETECT == STD_OFF) */
    {
        /* Copy the module Id */
        versioninfo->moduleID = (uint16)PORT_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
        /* Copy the vendor Id */
        versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
    }
}
#endif

/************************************************************************************
* Service Name: Port_SetPinMode
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
*                  Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.
************************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
#if (PORT_DEV_ERROR_DETECT==STD_ON)
    if (PORT_NOT_INITIALIZED==Port_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
    }
    else
    {
        /*Do Nothing*/
    }

    if(Pin >= PORT_PIN_NUM)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_PARAM_PIN);
    }
    else
    {
        /*Do Nothing*/
    }

    if(Port_Pins[Pin].pin_mode_changeable == STD_OFF)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_MODE_UNCHANGEABLE);
    }
    else
    {
        /*Do Nothing*/
    }

#endif
        /*Main Function body*/
        volatile uint32* CurrentPort_Ptr = NULL_PTR;
        uint8 pin_mode = 0;
        switch(Port_Pins[Pin].portId)
        {
        case PortConf_PORTA_NUM:
            CurrentPort_Ptr = (volatile uint32*)GPIO_PORTA_BASE_ADDRESS;
            break;
        case PortConf_PORTB_NUM:
            CurrentPort_Ptr = (volatile uint32*)GPIO_PORTB_BASE_ADDRESS;
            break;
        case PortConf_PORTC_NUM:
            CurrentPort_Ptr = (volatile uint32*)GPIO_PORTC_BASE_ADDRESS;
            break;
        case PortConf_PORTD_NUM:
            CurrentPort_Ptr = (volatile uint32*)GPIO_PORTD_BASE_ADDRESS;
            break;
        case PortConf_PORTE_NUM:
            CurrentPort_Ptr = (volatile uint32*)GPIO_PORTE_BASE_ADDRESS;
            break;
        case PortConf_PORTF_NUM:
            CurrentPort_Ptr = (volatile uint32*)GPIO_PORTF_BASE_ADDRESS;
            break;
        }
        /*Pin mode error checker 1-->Error in mode 0-->No error*/
        uint8 Pin_Mode_Error = 0;

        /*Adjust the mode for PORTA pins*/
        if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) //PORTA - PIN0
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN1) //PORTA - PIN1
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN2) //PORTA - PIN2
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN3) //PORTA - PIN3
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN4) //PORTA - PIN4
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN5) //PORTA - PIN5
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN6) //PORTA - PIN6
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 5;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTA_NUM && Port_Pins[Pin].pinId == PortConf_PIN7) //PORTA - PIN7
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 5;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }

        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) //PORTB - PIN0
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN1) //PORTB - PIN1
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN2) //PORTB - PIN2
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN3) //PORTB - PIN3
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN4) //PORTB - PIN4
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN5) //PORTB - PIN5
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN6) //PORTB - PIN6
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTB_NUM && Port_Pins[Pin].pinId == PortConf_PIN7) //PORTB - PIN7
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) //PORTC - PIN0
        {
            pin_mode = 0;
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN1) //PORTC - PIN1
        {
            pin_mode = 0;
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN2) //PORTC - PIN2
        {
            pin_mode = 0;
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN3) //PORTC - PIN3
        {
            pin_mode = 0;
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN4) //PORTC - PIN4
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_UART_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_QEI:
                pin_mode = 6;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN5) //PORTC - PIN5
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_UART_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN6) //PORTC - PIN6
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_UART_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_USB:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTC_NUM && Port_Pins[Pin].pinId == PortConf_PIN7) //PORTC - PIN7
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_UART_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_USB:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) //PORTD - PIN0
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_SPI_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_PWM_B:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN1) //PORTD - PIN1
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_SPI_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_PWM_B:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN2) //PORTD - PIN2
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_SPI_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_USB:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN3) //PORTD - PIN3
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_SPI_B:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_QEI:
                pin_mode = 6;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_USB:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN4) //PORTD - PIN4
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN5) //PORTD - PIN5
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN6) //PORTD - PIN6
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTD_NUM && Port_Pins[Pin].pinId == PortConf_PIN7) //PORTD - PIN7
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_NMI:
                pin_mode = 8;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTE_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) //PORTE - PIN0
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTE_NUM && Port_Pins[Pin].pinId == PortConf_PIN1) //PORTE - PIN1
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTE_NUM && Port_Pins[Pin].pinId == PortConf_PIN2) //PORTE - PIN2
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTE_NUM && Port_Pins[Pin].pinId == PortConf_PIN3) //PORTE - PIN3
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTE_NUM && Port_Pins[Pin].pinId == PortConf_PIN4) //PORTE - PIN4
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_PWM_B:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTE_NUM && Port_Pins[Pin].pinId == PortConf_PIN5) //PORTE - PIN5
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_I2C:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_PWM_B:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTF_NUM && Port_Pins[Pin].pinId == PortConf_PIN0) //PORTF - PIN0
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_NMI:
                pin_mode = 8;
                break;

            case PORT_PIN_MODE_COMPARATOR_OUT:
                pin_mode = 9;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTF_NUM && Port_Pins[Pin].pinId == PortConf_PIN1) //PORTF - PIN1
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_UART_A:
                pin_mode = 1;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_COMPARATOR_OUT:
                pin_mode = 9;
                break;

            case PORT_PIN_MODE_TRACE_CLK:
                pin_mode = 14;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTF_NUM && Port_Pins[Pin].pinId == PortConf_PIN2) //PORTF - PIN2
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 4;
                break;

            case PORT_PIN_MODE_PWM_B:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_TRACE_CLK:
                pin_mode = 14;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTF_NUM && Port_Pins[Pin].pinId == PortConf_PIN3) //PORTF - PIN3
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_SPI_A:
                pin_mode = 2;
                break;

            case PORT_PIN_MODE_CAN:
                pin_mode = 3;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_TRACE_CLK:
                pin_mode = 14;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else if(Port_Pins[Pin].portId == PortConf_PORTF_NUM && Port_Pins[Pin].pinId == PortConf_PIN4) //PORTF - PIN4
        {
            switch(Port_Pins[Pin].port_pin_mode)
            {
            case PORT_PIN_MODE_DIO:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_ADC:
                pin_mode = 0;
                break;

            case PORT_PIN_MODE_PWM_A:
                pin_mode = 5;
                break;

            case PORT_PIN_MODE_QEI:
                pin_mode = 6;
                break;

            case PORT_PIN_MODE_GPT:
                pin_mode = 7;
                break;

            case PORT_PIN_MODE_USB:
                pin_mode = 8;
                break;

            default:
                Pin_Mode_Error = 1;
                break;
            }
        }
        else
        {
            /*Do nothing*/
        }

        #if(PORT_DEV_ERROR_DETECT==STD_ON)
        /*The Mode Is Not available For The Configured Pin*/
        if (Pin_Mode_Error != 0)
        {
            Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
        }
        else
        {
            /*Do Nothing*/
        }
        #endif

        /*Adjust the mode of the pin*/
        if (Port_Pins[Pin].port_pin_mode == PORT_PIN_MODE_DIO)
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pinId);                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pinId);                           /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            *(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[Pin].pinId * 4));                   /* Clear the PMCx bits for this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[Pin].pinId);                       /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
        }
        else if (Port_Pins[Pin].port_pin_mode == PORT_PIN_MODE_ADC)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pinId);                      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pinId);                           /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            *(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[Pin].pinId * 4));                   /* Clear the PMCx bits for this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[Pin].pinId);                       /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pinId);                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pinId);                             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            *(volatile uint32 *)((volatile uint8 *)CurrentPort_Ptr + PORT_CTL_REG_OFFSET) |= ((0x0000000F & pin_mode) << (Port_Pins[Pin].pinId * 4));       /* Clear the PMCx bits for this pin */
        }

}
#endif
