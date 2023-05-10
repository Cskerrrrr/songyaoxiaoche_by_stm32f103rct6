#ifndef __TIMER_H
#define __TIMER_H
#include "stm32f10x.h"

void TIM1_init(u16 arr,u16 psc);
void TIM1_IRQHandler(void);

#endif

