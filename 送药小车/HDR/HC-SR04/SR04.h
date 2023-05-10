#ifndef __SR04_H
#define __SR04_H

#include "stm32f10x.h"

#define TRIG GPIO_Pin_11
#define ECHO GPIO_Pin_12
#define GPIO_SR04 GPIOA
#define TRIG_Low  GPIO_ResetBits(GPIO_SR04,TRIG)
#define TRIG_High GPIO_SetBits(GPIO_SR04,TRIG)
#define ECHO_Low  GPIO_ResetBits(GPIO_SR04,ECHO)
#define ECHO_high GPIO_SetBits(GPIO_SR04,ECHO)

void SR04_UserConfiguer(void);
void SR04_Read_Data(float*cmA);
#endif


