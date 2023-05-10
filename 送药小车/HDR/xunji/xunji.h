#ifndef __XUNJI_H
#define __XUNJI_H


void xunji_Init(void);


#define SEARCH_LL_IO          GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_10)



#define SEARCH_L_IO           GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_11)



#define SEARCH_R_IO           GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_12)



#define SEARCH_RR_IO          GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)



#define COMM_STOP  'S'//停止
#define COMM_UP    'U'//前
#define COMM_BACK  'B'//后退
#define COMM_LEFT_90  'L'//左转
#define COMM_RIGHT_90 'R'//右转
#define COMM_LEFT  'O'//左转
#define COMM_RIGHT 'P'//右转
#define COMM_QUICK 'Q'//前

#endif


