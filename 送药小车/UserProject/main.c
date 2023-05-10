#include "sys.h" 

float Target_Speed = 0;						//期望速度
short gyrox,gyroy,gyroz;					//角速度
float Pitch,Roll,Yaw;						//角度
int Encoder_Left,Encoder_Right;				//编码器速度

extern char Res;
extern int turn_left90,turn_right90, turn;




int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//w4级抢占,4级响应。
	uart1_init(115200);
	USART2_Init(115200);
	delay_init();
	NVIC_Config();
	Encoder_TIM2_Init();
	Encoder_TIM3_Init();
	Motor_Init(7199,0);
	MPU_Init();
	mpu_dmp_init();
    MPU6050_EXTI_Init();
	xunji_Init();
	while(1)
	{
//			SearchRun(); 
			
	}
}
