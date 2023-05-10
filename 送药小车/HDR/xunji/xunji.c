#include <xunji.h>
#include "stm32f10x.h"
#include "delay.h"


extern  char Res;

extern int turn_left90,turn_right90,i,turn;

void xunji_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
}

void SearchRun(void)
{

	if(SEARCH_L_IO == 0 && SEARCH_R_IO == 0 && SEARCH_LL_IO == 0 && SEARCH_RR_IO == 0)
	{
		Res = 'U';
	}
	if(SEARCH_RR_IO == 1 && SEARCH_L_IO == 0 && SEARCH_LL_IO == 0 && SEARCH_R_IO == 1)//��
	{
		Res = 'R';
		turn_right90 = 1;
	}
	if(SEARCH_RR_IO == 1 && SEARCH_L_IO == 0 && SEARCH_LL_IO == 0 && SEARCH_R_IO == 0)//��
	{
		Res = 'R';
		turn_right90 = 1;
	}
 	if(SEARCH_R_IO == 0 && SEARCH_RR_IO == 0 && SEARCH_LL_IO == 1 && SEARCH_L_IO == 0 )//��
	{
		Res = 'L';
		turn_left90 = 1;
	}
	if(SEARCH_R_IO == 0 && SEARCH_RR_IO == 0 && SEARCH_LL_IO == 1 && SEARCH_L_IO == 1 )//��
	{
		Res = 'L';
		turn_left90 = 1;
	}
	if(SEARCH_R_IO == 1 && SEARCH_RR_IO == 0 && SEARCH_L_IO == 0 && SEARCH_LL_IO == 0)
	{
		Res = 'P';
	}
	
	if(SEARCH_R_IO == 0 && SEARCH_RR_IO == 0 && SEARCH_L_IO == 1 && SEARCH_LL_IO == 0)
	{
		Res = 'O';
	}
	
	if(SEARCH_R_IO == 1 && SEARCH_RR_IO == 1 && SEARCH_L_IO == 1 && SEARCH_LL_IO == 1)
	{
	  Res = 'S';
		turn_left90 = 0;
		turn_right90 = 0;
	}	
	

//	
//#define COMM_STOP  'S'//ֹͣ
//#define COMM_UP    'U'//ǰ
//#define COMM_BACK  'B'//����
//#define COMM_LEFT_90  'L'//��ת
//#define COMM_RIGHT_90 'R'//��ת
//#define COMM_LEFT  'O'//��ת
//#define COMM_RIGHT 'P'//��ת
//#define COMM_QUICK 'Q'//ǰ
	
	
	
	
	
	
}

	



