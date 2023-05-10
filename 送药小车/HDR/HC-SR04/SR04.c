#include "stm32f10x.h"
#include "delay.h"



#define TRIG_Low  GPIO_ResetBits(GPIO_SR04,TRIG)
#define TRIG_High GPIO_SetBits(GPIO_SR04,TRIG)
#define ECHO_Low  GPIO_ResetBits(GPIO_SR04,ECHO)
#define ECHO_high GPIO_SetBits(GPIO_SR04,ECHO)

void SR04_UserConfiguer(void) {
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_TimeBaseInitTypeDef TIM_InitStructure;
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_TIM1,ENABLE);
//	
//	GPIO_InitStructure.GPIO_Pin = TRIG;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
//	GPIO_Init(GPIO_SR04,&GPIO_InitStructure);
//	TRIG_Low;
//	
//	GPIO_InitStructure.GPIO_Pin = ECHO;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
//	GPIO_Init(GPIO_SR04,&GPIO_InitStructure);
//  ECHO_Low;
//	
//	TIM_InitStructure.TIM_Period = 65536-1;
//	TIM_InitStructure.TIM_Prescaler = 72-1;
//	TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseInit(TIM1,&TIM_InitStructure);
//	TIM_Cmd(TIM1,ENABLE);
	
	
	
	
	
	
	
}

void SR04_Read_Data(float*cmA){
	
//	while(GPIO_ReadInputDataBit(GPIO_SR04,ECHO) == 1);
//	TRIG_High;
//	delay_ms(15);
//	TRIG_Low;
//	
//	while(GPIO_ReadInputDataBit(GPIO_SR04,ECHO) == 0);
//	TIM_SetCounter(TIM1,0);
//	TIM_Cmd(TIM1,ENABLE);
//	
//	while(GPIO_ReadInputDataBit(GPIO_SR04,ECHO) == 1);
//	TIM_Cmd(TIM1,DISABLE);
//	
//	*cmA = ((TIM_GetCounter(TIM1)*340)/1000000.0/2)*100;//cm
}
