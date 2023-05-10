#include "usart2.h"
#include "usart.h"
#include "delay.h"
#include "stm32f10x_usart.h"


u8     USART2SendBuff[USART2BuffSize];        
u8     USART2ReceBuff[USART2BuffSize];        
u16 USART2ReceIn = 0;
u8  USART2ReceFullFlag = 0;



void USART2_Init(u32 bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    USART_InitTypeDef USART_InitStructure;;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    
    //USART3_TX   GPIOB.10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //PB.10
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;    //??????
    GPIO_Init(GPIOA, &GPIO_InitStructure);//???GPIOA.10
    
    //USART3_RX      GPIOB.3???
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//PB11
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//????
    GPIO_Init(GPIOA, &GPIO_InitStructure);//???GPIOB.11  
    
    //Usart3 NVIC ??
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=4;//?????3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;        //????3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;            //IRQ????
    NVIC_Init(&NVIC_InitStructure);    //??????????VIC???
    
    //USART ?????
    USART_InitStructure.USART_BaudRate = bound;//?????
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//???8?????
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//?????
    USART_InitStructure.USART_Parity = USART_Parity_No;//??????
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//????????
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;    //????
    USART_Init(USART2, &USART_InitStructure); //?????3
    
    USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);  //????????
    USART_Cmd(USART2, ENABLE);                    //????3 
}


void USART2_SendData(u8 data)
{
	while((USART2->SR&0X40)==0); 
	USART2->DR = data;
}

void USART2_SendString(u8 *DAT,u8 len)
{
	u8 i;
	for(i=0;i<len;i++)
	{
	 	USART2_SendData(*DAT++);
	}	
}

extern u8 flag;
char Res;



void USART2_IRQHandler(void)
{
    if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)  //????
    {
				Res = USART_ReceiveData(USART2);
        USART_ClearITPendingBit(USART2, USART_IT_RXNE);//?????????   ????????USART_ClearITPendingBit?????USART_ClearFlag  
    }
    else if(USART_GetITStatus(USART2, USART_IT_TXE) != RESET)    // ????  USART_GetITStatus
    {
        USART_ClearITPendingBit(USART2, USART_IT_TXE);                    // clear interrupt  ????????
    }  

		   
}
