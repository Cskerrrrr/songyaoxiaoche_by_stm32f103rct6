#ifndef __XUNJI_H
#define __XUNJI_H


void xunji_Init(void);


#define SEARCH_LL_IO          GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_10)



#define SEARCH_L_IO           GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_11)



#define SEARCH_R_IO           GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_12)



#define SEARCH_RR_IO          GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)



#define COMM_STOP  'S'//ֹͣ
#define COMM_UP    'U'//ǰ
#define COMM_BACK  'B'//����
#define COMM_LEFT_90  'L'//��ת
#define COMM_RIGHT_90 'R'//��ת
#define COMM_LEFT  'O'//��ת
#define COMM_RIGHT 'P'//��ת
#define COMM_QUICK 'Q'//ǰ

#endif


