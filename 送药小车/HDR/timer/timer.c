#include "timer.h"



int m;

void TIM1_init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef Timer_Initx;
	NVIC_InitTypeDef NVIC_Initx;
	RCC_APB1PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	Timer_Initx.TIM_ClockDivision = TIM_CKD_DIV1;
  Timer_Initx.TIM_CounterMode = TIM_CounterMode_Up;
  Timer_Initx.TIM_Period = arr;//（50khz)49999
  Timer_Initx.TIM_Prescaler = psc;//分频720-1 719
	TIM_TimeBaseInit(TIM1,&Timer_Initx);//1S
	//50000*719/72M=500ms
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE); 
	
	NVIC_Initx.NVIC_IRQChannel = TIM1_CC_IRQn;
	NVIC_Initx.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Initx.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_Initx.NVIC_IRQChannelSubPriority = 2;
  NVIC_Init(&NVIC_Initx);
	
	TIM_Cmd(TIM1,ENABLE);
}


void TIM1_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM1,TIM_IT_Update)!= RESET) //检查 TIM2 更新中断发生与否
  {
		TIM_ClearITPendingBit(TIM1,TIM_IT_Update ); //清除 TIM2 更新中断标

		 m++;

  }  
	
}
