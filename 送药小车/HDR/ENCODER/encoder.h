#ifndef __ENCODER_H
#define __ENCODER_H

#include "sys.h"

void Encoder_TIM2_Init(void);
void Encoder_TIM3_Init(void);
int Read_Spead(int TIMx);
void TIM2_IRQHander(void);
void TIM3_IRQHander(void);






#endif
