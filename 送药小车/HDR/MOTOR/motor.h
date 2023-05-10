#ifndef  _MOTOR_H
#define  _MOTOR_H

#include "sys.h" 

#define Ain1  PBout(6)
#define Ain2  PBout(7)

#define Bin1  PBout(8)
#define Bin2  PBout(9)

void Motor_Init(u16 arr,u16 psc);
void Limit(int *motoA,int *motoB);
int GFP_abs(int p);
void SETPWM(int motor_left, int motor_right);

#endif

