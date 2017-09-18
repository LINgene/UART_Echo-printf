

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __UART_PRINTF_H
#define __UART_PRINTF_H
#include "stm32f0xx.h"

typedef enum 
{
  COM1 = 0,
  COM2 = 1
} COM_TypeDef;   

#define BUFFER_SIZE       44
#define USART_MAX_INDEX   8

#define COMn                             1

/**
 * @brief Definition for COM port1, connected to USART1
 */ 
#define EVAL_COM1                        USART2
#define EVAL_COM1_CLK                    RCC_APB1Periph_USART2

#define EVAL_COM1_TX_PIN                 GPIO_Pin_2
#define EVAL_COM1_TX_GPIO_PORT           GPIOA
#define EVAL_COM1_TX_GPIO_CLK            RCC_AHBPeriph_GPIOA
#define EVAL_COM1_TX_SOURCE              GPIO_PinSource2
#define EVAL_COM1_TX_AF                  GPIO_AF_1

#define EVAL_COM1_RX_PIN                 GPIO_Pin_3
#define EVAL_COM1_RX_GPIO_PORT           GPIOA
#define EVAL_COM1_RX_GPIO_CLK            RCC_AHBPeriph_GPIOA
#define EVAL_COM1_RX_SOURCE              GPIO_PinSource3
#define EVAL_COM1_RX_AF                  GPIO_AF_1

#define EVAL_COM1_CTS_PIN                GPIO_Pin_11
#define EVAL_COM1_CTS_GPIO_PORT          GPIOA
#define EVAL_COM1_CTS_GPIO_CLK           RCC_AHBPeriph_GPIOA
#define EVAL_COM1_CTS_SOURCE             GPIO_PinSource11
#define EVAL_COM1_CTS_AF                 GPIO_AF_1

#define EVAL_COM1_RTS_PIN                GPIO_Pin_12
#define EVAL_COM1_RTS_GPIO_PORT          GPIOA
#define EVAL_COM1_RTS_GPIO_CLK           RCC_AHBPeriph_GPIOA
#define EVAL_COM1_RTS_SOURCE             GPIO_PinSource12
#define EVAL_COM1_RTS_AF                 GPIO_AF_1
#define EVAL_COM1_IRQn                   USART2_IRQn

void STM_EVAL_COMInit(COM_TypeDef COM, USART_InitTypeDef* USART_InitStruct);
void MYUSART_Config(void);
void RCC_Configuration(void);
void NVIC_Configuration(void);
void TimingDelay_Decrement(void);

#endif /* __MAIN_H */
