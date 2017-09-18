
#include "UART_printf.h"
#include "stdio.h"

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
uint8_t aTxBuffer[BUFFER_SIZE] = "USART Example: 8xUsarts Tx/Rx Communication";
uint8_t aRxBuffer[USART_MAX_INDEX][BUFFER_SIZE];
/* Buffer used for reception */
USART_InitTypeDef USART_InitStructure;
__IO uint8_t TxCounter = 0;
extern __IO uint8_t ReceiveState;
USART_TypeDef* UsartInstance[USART_MAX_INDEX] = {USART1, USART2, USART3, USART4, USART5, USART6, USART7, USART8};
uint8_t UsartIndex = 0;
static __IO uint32_t TimingDelay;

void LED_conf(void);
int main(void)
{
	if (SysTick_Config(SystemCoreClock / 1000))
  { 
    /* error */ 
    while (1);
  }
  MYUSART_Config();
	RCC_Configuration();
  LED_conf();
	NVIC_Configuration();
	
//  USART_SendData(EVAL_COM1, 'a');
  
//  
//  printf("\n\rUSART Printf Example: retarget the C library printf function to the USART\n\r");
  /* Loop until the end of transmission */
  /* The software must wait until TC=1. The TC flag remains cleared during all data
     transfers and it is set by hardware at the last frame’s end of transmission*/
//  while (USART_GetFlagStatus(EVAL_COM1, USART_FLAG_TC) == RESET)
//  {}
		for(UsartIndex = 0; UsartIndex < USART_MAX_INDEX; UsartIndex++)
  {
    USART_Init(UsartInstance[UsartIndex], &USART_InitStructure);
    
    /* Enable 8xUSARTs Receive interrupts */
    USART_ITConfig(EVAL_COM1, USART_IT_RXNE, ENABLE);
    
    /* Enable the 8xUSARTs */
    USART_Cmd(UsartInstance[UsartIndex], ENABLE);
  }
	//GPIO_SetBits(GPIOA,GPIO_Pin_5);
  printf("aaaaaa");
  GPIO_SetBits(GPIOA,GPIO_Pin_5);
  while (1)
  {
    
  }
}
void LED_conf(void)
{
  GPIO_InitTypeDef        GPIO_InitStructure;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

  /* Configure PC10 and PC11 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
}

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  USART_SendData(EVAL_COM1, (uint8_t) ch);

  /* Loop until transmit data register is empty */
  while (USART_GetFlagStatus(EVAL_COM1, USART_FLAG_TXE) == RESET)
  {}

  return ch;
}
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}

#ifdef  USE_FULL_ASSERT


void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

