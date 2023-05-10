#include "pid.h"
#include "xunji.h"


float Velocity_Kp = 300,		//速度环Kp
	  Velocity_Ki =15;			//速度环Kd

float Turn_Kp = -100,     //转向环
	  Turn_Kd = 1;  



int Vertical_Kp = -1, //jiaodu环
	  Vertical_Kd = 10;







int Vertical_out,Velocity_out,Turn_out;		//输出变量

int measure;//编码器速度测量值					
int motor1, motor2;

extern char Res;

int Velocity_PI(int Speed_measure);
int Turn(int gyro_Z);
int Vertical_PI(int gyro_Z);

int PWM_out,turn,turn_left90 = 0,turn_right90 = 0;

int m = 0;


void EXTI9_5_IRQHandler(void)
{
	int PWM_out;
	if(EXTI_GetITStatus(EXTI_Line5)!=0)
	{
		if(PBin(5) == 0)
		{
			EXTI_ClearITPendingBit(EXTI_Line5);
			Encoder_Left = -Read_Spead(2);						//采集编码器速度
			Encoder_Right = Read_Spead(3);
			measure = (Encoder_Left + Encoder_Right);		//将编码器速度给测量值
			mpu_dmp_get_data(&Pitch, &Roll, &Yaw);				//角度
			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);			//角速度
//			Velocity_out = Velocity_PI(measure);				//速度环计算
			Turn_out = Turn(gyroz);
//			Vertical_out = Vertical_PI(gyroz);
			PWM_out = Velocity_out;				//PWM输出
			motor1 = PWM_out + Turn_out - Vertical_out;
			motor2 = PWM_out - Turn_out + Vertical_out;
			Limit(&motor1, &motor2);							//PWM限幅
			SETPWM(motor1,motor2);								//加载PWM到电机	
		}
	}
}



int Vertical_PI(int gyro_Z)
{
	static int Encoder_err, Encoder_sum;
	static int PWM_out;
	float Turn_Target=0,Vertical_Kp,Vertical_Kd;
	
	if(GFP_abs(gyro_Z)<150)
	{
		gyro_Z = 0;
	}


	if(turn_right90 == 1 && turn == 1)  
	{
				Turn_Target = 300,Vertical_Kp = -35,Vertical_Kd = 10;
				Encoder_err = gyro_Z-0;
				Encoder_sum += Encoder_err;
				if(GFP_abs(Encoder_sum) > 115000)
				{
				Vertical_Kp = 0;
				Vertical_Kd = 0;
				Encoder_err = 0;
				Encoder_sum = 0;
				turn_right90 = 0;
				turn = 0;
				m = 0;
	      }
	}
	if(turn_left90 == 1 && turn == 1)  
	{
					Turn_Target = -300,Vertical_Kp = -20,Vertical_Kd = 10;
					Encoder_err = gyro_Z-0;
					Encoder_sum += Encoder_err;
					if(GFP_abs(Encoder_sum) > 115000)
					{
					Vertical_Kp = 0;
					Vertical_Kd = 0;
					Encoder_err = 0;
					Encoder_sum = 0;
					turn_left90 = 0;
					turn = 0;
					m = 0;
		      }
	}
	
  PWM_out = Turn_Target*Vertical_Kp + gyro_Z*Vertical_Kd; 
	
	return PWM_out;					

}




int Velocity_PI(int Speed_measure)
{
	static int Encoder_err, Encoder_err_low, Encoder_err_low_last, Encoder_sum;
	static int PWM_out;
	float Target_Velocity = 0;
	
	
   if(Res == 'U')   Target_Velocity = 25,Velocity_Ki = 8;
	else if(Res == 'L') Target_Velocity = 0,Velocity_Ki = 0,Velocity_Kp = 0;
	else if(Res == 'R') Target_Velocity = 0,Velocity_Ki = 0,Velocity_Kp = 0;
	else if(Res == 'S') Target_Velocity = 0,Velocity_Ki = 0,Velocity_Kp = 0;
    else   Target_Velocity = 0,Velocity_Ki = 0,Velocity_Kp = 0;

		if(turn_right90 == 1)
			{
				Target_Velocity = 15,Velocity_Ki = 8;
        m++;
        if(m>55)	
				{
					turn = 1;
				}					
			}
			if(turn_left90 == 1)
			{
				Target_Velocity = 15,Velocity_Ki = 8;
				m++;
        if(m>55)	
				{
					turn = 1;
				}	
			}

	
	Encoder_err = Target_Velocity - Speed_measure;
	Encoder_err_low = 0.3 * Encoder_err + 0.7 * Encoder_err_low_last;
	Encoder_err_low_last = Encoder_err_low;
	Encoder_sum += Encoder_err_low;
	if(Encoder_sum > 10000) Encoder_sum = 10000;
	if(Encoder_sum < -10000) Encoder_sum = -10000;

	
	PWM_out = Velocity_Kp*Encoder_err + Velocity_Ki*Encoder_sum;
		
	return PWM_out;
}

//转向环


int Turn(int gyro_Z)
{
	int PWM_out;
	float Turn_Target;
	float Kp = Turn_Kp,Kd = Turn_Kd;			
	
    if(Res == 'O')            Turn_Target = 62.5;//62.5
	 else if (Res == 'P')      Turn_Target = -62.5;
//	 else if (Res == 'R')  Turn_Target = -1000;
//	 else if (Res == 'L')   Turn_Target = 1000;
	 else     Turn_Target = 0;
	
	if(Res == 'U')  Kd = Turn_Kd;  
	
  else Kd = Turn_Kd;
	
	
  PWM_out = Turn_Target*Kp + gyro_Z*Kd; 
	
	return PWM_out;
}









