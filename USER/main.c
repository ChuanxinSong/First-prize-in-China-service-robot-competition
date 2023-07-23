#include "huidu.h"

	int flag=0,e=0;
	double sum;
	extern double l;
	double s,sa;
uint16_t var[1]; //??4?????????,?????4
int speed1,speed2,speed3,speed4,flag1,flag2,flag3,flag4,va=0,vb=0,vc=0,vd=0,moshi;//speed1,2,3,4:编码器测得速度；va,b,c,d:目标速度；flag1,2:前进后退标志位；

int i=1,moni21,moni22,moni23,moni24,moni25,moni26,moni27,moni28,lm=0;

int32_t output1=0,output2=0,output3=0,output4=0;

float pitch,roll,yaw; 		//欧拉角

int renwu1=0,renwu2=0,renwu3=0,renwu4=0,tansuo1=0,tansuo2=0,tansuo3=0,tansuo4=0,cha=0;//renwu1：箱子1;

int main(void)
{
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);		//延时初始化 
  uart_init(115200);	//串口初始化波特率为115200
	OLED_Init();//oled初始化
	OLED_Fill(0x00);//oled清屏
	////初始化MPU6050

	while(MPU_Init())
		delay_ms(20);						//初始化MPU6050
	while(mpu_dmp_init())
	{
	//	delay_ms(20);
	}
	while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
		delay_ms(20);


	huidu_init();//灰度初始化
	LED_Init();//电机io口初始化
	chaosheng_Init();
	Adc3_Init();
	Encoder_Configuration();//编码器初始化
	TIM6_Int_Init(10000-1,168-1);//中断初始化//数一次2*10de-3ms//yicizhongduan20ms
	TIM14_PWM_Init(100-1,48-1);//控制电机1左前 //84M/84=1Mhz的计数频率,重装载值5000，所以PWM频率为 1M/100=10Khz.
	TIM13_PWM_Init(100-1,48-1);//右前
	TIM9_CH1_PWM_Init(100-1,96-1);//左后
	TIM9_CH2_PWM_Init(100-1,96-1);//右后
	TIM1_PWM_Init(20000-1,168-1);//1MHZ,PWM频率为1M/20000=50hz,即周期为0.02s,20ms
	TIM8_PWM_Init(20000-1,168-1);//舵机初始化	500到2500即为0到180度,,,1500为90°
	TIM7_Int_Init(1000-1,8400-1);//中断初始化0.1s进入一次中断
	
		duoji4(1500);
	delay_ms(500);
	duoji3(900);
	delay_ms(500);
		duoji2(1850);
	delay_ms(500);
	duoji1(1500);
	delay_ms(500);
	
	for(i=1500;i<2450;i+=20)
	{
		duoji4(i);
		delay_ms(20);
	}
//	shunazhunbei();
//	duoji3(700);
//		delay_ms(500);
//laba();
guaiwan(0,0,0,0,1,1,1,1);

//duoji4(2450);
//	duoji3(2120);
//	duoji2(900);
while(1)
{
	if(GDZ==0)
	{
		moshi=1;
		break;
	}
	if(GDY==0)
	{
		moshi=2;
		break;
	}
}
//cha=24;
//if(cha==0)
//{
//		qianjin();
//		delay_ms(1000);
//}

	while(1)
	{
//		houjiance();
		if(moshi==1)//xian放A再放B
		{
			chafang1();
		}
		if(moshi==2)//先放B再放A
		{
			chafang2();
		}
//		jiance();
//		xianshi();
//		s=ceju();
//		Dis_Num(4,0,moni11,1);
//		Dis_Num(4,1,moni12,1);
//		Dis_Num(4,2,moni13,1);
//		Dis_Num(4,3,moni14,1);
//		Dis_Num(4,5,moni15,1);
//		Dis_Num(4,6,moni16,1);	
//		Dis_Num(4,7,moni17,1);
//		Dis_Num(4,8,moni18,1);
		
		
    }
}


void TIM6_DAC_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM6,TIM_IT_Update)==SET) //溢出中断
	{
	  flag=1;
		
	}
	TIM_ClearITPendingBit(TIM6,TIM_IT_Update);  //清除中断标志位
}


void TIM7_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM7,TIM_IT_Update)==SET) //溢出中断
	{
		lm++;
	if(lm<25)
	xianshi();
	else
	{
		lm=0;
			OLED_Init();//oled初始化
			OLED_Fill(0x00);//oled清屏
		xianshi();
	}

	}
	TIM_ClearITPendingBit(TIM7,TIM_IT_Update);  //清除中断标志位
}

