#include "sys.h" 

float Target_Speed = 0;						//�����ٶ�
short gyrox,gyroy,gyroz;					//���ٶ�
float Pitch,Roll,Yaw;						//�Ƕ�
int Encoder_Left,Encoder_Right;				//�������ٶ�

extern char Res;
extern int turn_left90,turn_right90, turn;




int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//w4����ռ,4����Ӧ��
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
