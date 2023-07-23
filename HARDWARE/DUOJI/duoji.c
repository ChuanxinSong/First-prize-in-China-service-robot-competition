#include "duoji.h"
#include "delay.h"
void TIM1_PWM_Init(u32 arr,u32 psc)
 {
  	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);    

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 	
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource9,GPIO_AF_TIM1); //GPIOE9,E11复用为定时器1
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource11,GPIO_AF_TIM1); //GPIOE9,E11复用为定时器1
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_11;           //GPIO

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能

	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz

	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出

	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //上拉

	GPIO_Init(GPIOE,&GPIO_InitStructure);              //初始化PE9

  TIM_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频

	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式

	TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值

	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 

	//TIM_TimeBaseStructure.TIM_RepetitionCounter = 0x0;//?????0

	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseStructure);//初始化定时器1
	
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2

 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能

	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //?输出极性:TIM输出比较极性高

 

	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;//在空闲时输出低，如果没有这句，通道一会出问题


	TIM_OC1Init(TIM1, &TIM_OCInitStructure); 
  TIM_OC2Init(TIM1, &TIM_OCInitStructure);


	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);  //???TIM1?CCR1????????,CCR???????????

	TIM_ARRPreloadConfig(TIM1,ENABLE);//ARPE?? 

	TIM_Cmd(TIM1, ENABLE);  //???TIM1

	TIM_CtrlPWMOutputs(TIM1, ENABLE);//???TIM1?PWM??,TIM1?TIM8??,?????????

 }
 
 
 void TIM8_PWM_Init(u32 arr,u32 psc)
 {
  	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,ENABLE);    

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); 	
  GPIO_PinAFConfig(GPIOC,GPIO_PinSource8,GPIO_AF_TIM8); //GPIOE9,E11复用为定时器1
  GPIO_PinAFConfig(GPIOC,GPIO_PinSource9,GPIO_AF_TIM8); //GPIOE9,E11复用为定时器1
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;           //GPIO

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能

	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz

	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出

	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //上拉

	GPIO_Init(GPIOC,&GPIO_InitStructure);              //初始化PE9

  TIM_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频

	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式

	TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值

	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 

	//TIM_TimeBaseStructure.TIM_RepetitionCounter = 0x0;//?????0

	TIM_TimeBaseInit(TIM8,&TIM_TimeBaseStructure);//初始化定时器1
	
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2

 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能

	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //?输出极性:TIM输出比较极性高

 

	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;//在空闲时输出低，如果没有这句，通道一会出问题


	TIM_OC3Init(TIM8, &TIM_OCInitStructure); 
  TIM_OC4Init(TIM8, &TIM_OCInitStructure);


	TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable);  //???TIM1?CCR1????????,CCR???????????

	TIM_ARRPreloadConfig(TIM8,ENABLE);//ARPE?? 

	TIM_Cmd(TIM8, ENABLE);  //???TIM1

	TIM_CtrlPWMOutputs(TIM8, ENABLE);//???TIM1?PWM??,TIM1?TIM8??,?????????

 }

void duoji1(u32 asc)//数越大张开的角度越大
{
	TIM_SetCompare1(TIM1,20000-asc );
}
void	duoji2(u32	asc)
{
	TIM_SetCompare2(TIM1,20000-asc );
}	
void duoji4(u32 asc)//数越大越往上
{
	TIM_SetCompare3(TIM8,20000-asc );//
}
void	duoji3(u32 asc)//数越小越往上
{
	TIM_SetCompare4(TIM8,20000-asc);//
}

void gaoju()//抓取后或者正常跑时
{
	int i;
	for(i=550;i<=2000;i+=10)
	{
		duoji4(i);
		delay_ms(20);
	}
	for(i=800;i<=900;i+=10)
	{
		duoji3(i);			//(20000-1300)
		delay_ms(20);
	}
	for(i=900;i<1850;i+=10)
	{
		duoji2(i);
		delay_ms(20);
	}
	for(i=2000;i<2500;i+=10)
	{
		duoji4(i);//(20000-2500)
		delay_ms(20);
	}
	






}

void	shunazhunbei()
{
	duoji4(1800);
	delay_ms(500);
	duoji3(550);
	delay_ms(500);
		duoji4(550);
		delay_ms(500);
//	duoji3(800);
//		delay_ms(500);
	
	duoji2(820);//900
		delay_ms(500);
	duoji1(2400);
	delay_ms(500);
//	delay_ms(500);


}

void shuna()
{
	int i;
	duoji4(550);
		delay_ms(500);
	
	duoji3(800);
		delay_ms(500);

	duoji2(900);
		delay_ms(500);
		
	duoji1(2000);
	delay_ms(200);
	for(i=2000;i>=1500;i-=5)
	{
		duoji1(i);
		delay_ms(20);
	}
	

}
void fang()
{
	duoji4(2450);
	duoji3(2200);
	duoji2(900);
}
void  shufang()//14
{
	int i;
	for(i=2450;i>1500;i-=10)
	{
		duoji4(i);
		delay_ms(20);
	}
		for(i=900;i>800;i-=10)
	{
		duoji3(i);
		delay_ms(20);
	}
	for(i=1850;i>900;i-=10)
	{
		duoji2(i);
		delay_ms(20);
	}
	for(i=1500;i>550;i-=10)
	{
		duoji4(i);
		delay_ms(20);
	}
		
	

	for(i=1500;i<2100;i++)
	{
		duoji1(i);
		delay_ms(10);
	}
//	for(i=1800;i>1600;i--)
//	{
//		duoji1(i);
//		delay_ms(20);
//	}
	duoji1(2300);
		delay_ms(20);
}

void shuipingshufangzhunbei()
{
	int i;
	duoji4(1780);
		delay_ms(500);
	duoji3(2250);
		delay_ms(500);
	
	duoji2(900);
		delay_ms(500);
	
	for(i=1500;i<1800;i+=5)
	{
		duoji1(i);
		delay_ms(20);
	}
	for(i=1800;i>1600;i-=1)
	{
		duoji1(i);
		delay_ms(20);
	}
	duoji1(2300);
		delay_ms(20);
}


void shuipingshufang()
{

	int i;
	duoji4(1500);
		delay_ms(500);
	duoji3(2250);
		delay_ms(500);
	
	duoji2(900);
		delay_ms(500);
	
	for(i=1500;i<1900;i+=5)
	{
		duoji1(i);
		delay_ms(20);
	}
//	for(i=1800;i>1600;i-=1)
//	{
//		duoji1(i);
//		delay_ms(20);
//	}
	duoji1(2300);
		delay_ms(20);
}

void	hengna()
{
	//先//两侧光电检测到时
//	duoji4(2400);//(20000-2500)
//	delay_ms(500);
//	duoji3(2350);			//(20000-1300)
//	delay_ms(500);
//	
//	duoji2(1900);
//	delay_ms(500);	
//	duoji1(2300);
//	delay_ms(500);
	//然后到13.5后
//	duoji4(2000);//(20000-2500)
//	delay_ms(500);
//	duoji3(2350);			//(20000-1300)
//	delay_ms(500);
//	
//	duoji2(1900);
//	delay_ms(500);	
//	duoji1(2300);
//	delay_ms(500);
	//然后到6.9和6之间
//	duoji4(1800);//(20000-2500)
//	delay_ms(500);
//	duoji3(2350);			//(20000-1300)
//	delay_ms(500);
//	
//	duoji2(1900);
//	delay_ms(500);	
//	duoji1(2300);
//	delay_ms(500);

//然后
duoji1(1550);
delay_ms(20);

//准备走
duoji4(2200);
delay_ms(20);
//后退gaoju

//	

}

void	hengfang()
{
	duoji1(1600);
	duoji2(1500);
	duoji3(1500);
	duoji4(1500);	
}


