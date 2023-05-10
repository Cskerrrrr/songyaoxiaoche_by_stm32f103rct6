#include "motor.h"

void Motor_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStruct;
	TIM_OCInitTypeDef  TIM_OCInitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	//使能定时器3时钟
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //使能GPIO外设和AFIO复用功能模块时钟
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 |GPIO_Pin_7 |GPIO_Pin_8 |GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	
	TIM_TimeBaseStruct.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
	TIM_TimeBaseStruct.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值 
	TIM_TimeBaseStruct.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStruct.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStruct); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
	//初始化TIM3 Channel2 PWM模式	 
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
 	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_Low; //输出极性:TIM输出比较极性高
	TIM_OCInitStruct.TIM_Pulse = 0;
	
	TIM_OC1Init(TIM4, &TIM_OCInitStruct);  //根据T指定的参数初始化外设TIM3 OC2
	TIM_OC2Init(TIM4, &TIM_OCInitStruct);  //根据T指定的参数初始化外设TIM3 OC2
	TIM_OC3Init(TIM4, &TIM_OCInitStruct);  //根据T指定的参数初始化外设TIM3 OC2
	TIM_OC4Init(TIM4, &TIM_OCInitStruct);  //根据T指定的参数初始化外设TIM3 OC2

	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM3在CCR2上的预装载寄存器
  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM3在CCR2上的预装载寄存器
  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM3在CCR2上的预装载寄存器
  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM3在CCR2上的预装载寄存器
	TIM_Cmd(TIM4, ENABLE);  //使能TIM3
}



//限幅
void Limit(int *motoA,int *motoB)
{
	if(*motoA>7299)*motoA=7299;
	if(*motoA<-7299)*motoA=-7299;
	
	if(*motoB>7299)*motoB=7299;
	if(*motoB<-7299)*motoB=-7299;
}


int GFP_abs(int p)
{
	int q;
	q=p>0?p:(-p);
	return q;
}






void SETPWM(int motor_left, int motor_right)
{
	if(motor_left<0)	   	TIM_SetCompare1(TIM4,GFP_abs(motor_left)),			TIM_SetCompare2(TIM4,0); //hou
	else           			  TIM_SetCompare1(TIM4,0),				TIM_SetCompare2(TIM4,GFP_abs(motor_left)); //qian
	
	if(motor_right<0)			 TIM_SetCompare3(TIM4,0),			TIM_SetCompare4(TIM4,GFP_abs(motor_right));	//hou
	else 	        			  TIM_SetCompare3(TIM4,GFP_abs(motor_right)),TIM_SetCompare4(TIM4,0);//qian

}




