#include "moni.h"
#include "delay.h"
#include "oled.h"
#include "huidu.h"
extern int i,moni21,moni22,moni23,moni24,moni25,moni26,moni27,moni28;
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//LSENS(光敏传感器)驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/7
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved										  
//////////////////////////////////////////////////////////////////////////////////
  
//初始化光敏传感器
//void Lsens_Init(void)
//{
//  GPIO_InitTypeDef  GPIO_InitStructure;
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能GPIOF时钟
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOA时钟
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//使能GPIOC时钟
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//使能GPIOB时钟
//  //先初始化ADC3通道7IO口
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_10;//
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;//不带上下拉
//  GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化  
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_2|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;//
//  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化  
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;//
//  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化  
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;//
//  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化  	
//	Adc3_Init();//初始化ADC3
//	Adc1_Init();//初始化ADC3
//	
//}
//读取Light Sens的值
//0~100:0,最暗;100,最亮 
//void Lsens_Get_Val1(void)
//{
//	u32 temp_val1=0,temp_val2=0,temp_val3=0,temp_val4=0,temp_val5=0,temp_val6=0,temp_val7=0,temp_val8=0;
//	u32 temp_va21=0,temp_va22=0,temp_va23=0,temp_va24=0,temp_va25=0,temp_va26=0,temp_va27=0,temp_va28=0;

//	u8 t;
//	u8 s1,s2,s3,s4,s5,s6,s7,s8;
//	u8 m1,m2,m3,m4,m5,m6,m7,m8;
//	
//	u8 k1,k2,k3,k4,k5,k6,k7,k8;
//	u8 l1,l2,l3,l4,l5,l6,l7,l8;
//	
//	for(t=0;t<LSENS_READ_TIMES;t++)
//	{
//		temp_val1+=Get_Adc3(ADC_Channel_9);	//读取ADC值,通道5
//		temp_val2+=Get_Adc3(ADC_Channel_14);
//		temp_val3+=Get_Adc3(ADC_Channel_15);	
//		temp_val4+=Get_Adc3(ADC_Channel_4);
//		temp_val5+=Get_Adc3(ADC_Channel_5);
//		temp_val6+=Get_Adc3(ADC_Channel_8);
//		temp_val7+=Get_Adc3(ADC_Channel_2);
//		temp_val8+=Get_Adc3(ADC_Channel_3);
//		
//		temp_va21+=Get_Adc1(ADC_Channel_4);	//读取ADC值,通道5
//		temp_va22+=Get_Adc1(ADC_Channel_5);
//		temp_va23+=Get_Adc1(ADC_Channel_6);	
//		temp_va24+=Get_Adc1(ADC_Channel_7);
//		temp_va25+=Get_Adc1(ADC_Channel_14);
//		temp_va26+=Get_Adc1(ADC_Channel_15);
//		temp_va27+=Get_Adc1(ADC_Channel_8);
//		temp_va28+=Get_Adc1(ADC_Channel_9);
////		delay_ms(2);
//	}
//	temp_val1/=LSENS_READ_TIMES;//得到平均值 
//	temp_val2/=LSENS_READ_TIMES;
//	temp_val3/=LSENS_READ_TIMES;
//	temp_val4/=LSENS_READ_TIMES;
//	temp_val5/=LSENS_READ_TIMES;
//	temp_val6/=LSENS_READ_TIMES;
//	temp_val7/=LSENS_READ_TIMES;
//	temp_val8/=LSENS_READ_TIMES;
//	
//	temp_va21/=LSENS_READ_TIMES;//得到平均值 
//	temp_va22/=LSENS_READ_TIMES;
//	temp_va23/=LSENS_READ_TIMES;
//	temp_va24/=LSENS_READ_TIMES;
//	temp_va25/=LSENS_READ_TIMES;
//	temp_va26/=LSENS_READ_TIMES;
//	temp_va27/=LSENS_READ_TIMES;
//	temp_va28/=LSENS_READ_TIMES;
//	if(temp_val1>4000)temp_val1=4000;
//	s1 = (u8)(100-(temp_val1/40));
//	if(s1>18) k1=0;
//	else  k1= 1;

//	if(temp_val2>4000)temp_val2=4000;
//	s2 = (u8)(100-(temp_val2/40));
//	if(s2>38) k2=0;//25
//	else  k2= 1;
//	
//	if(temp_val3>4000)temp_val3=4000;
//	s3 = (u8)(100-(temp_val3/40));
//	if(s3>49) k3=0;//31
//	else  k3= 1;
//	
//		if(temp_val4>4000)temp_val4=4000;
//	s4 = (u8)(100-(temp_val4/40));
//	if(s4>49) k4=0;//35
//	else  k4= 1;
//	
//		if(temp_val5>4000)temp_val5=4000;
//	s5 = (u8)(100-(temp_val5/40));
//	if(s5>49) k5=0;//34
//	else  k5= 1;
//	
//		if(temp_val6>4000)temp_val6=4000;
//	s6 = (u8)(100-(temp_val6/40));
//	if(s6>45) k6=0;//36
//	else  k6= 1;
//	
//	
//		if(temp_val7>4000)temp_val7=4000;
//	s7 = (u8)(100-(temp_val7/40));
//	if(s7>37) k7=0;//23
//	else  k7= 1;
//	
//	
//	
//		if(temp_val8>4000)temp_val8=4000;
//	s8 = (u8)(100-(temp_val8/40));
//	if(s8>30) k8=0;
//	else  k8= 1;
//	
//	if(temp_va21>4000)temp_va21=4000;
//	m1 = (u8)(100-(temp_va21/40));
//	if(m1>18) l1=0;
//	else  l1= 1;

//	if(temp_va22>4000)temp_va22=4000;
//	m2 = (u8)(100-(temp_va22/40));
//	if(m2>19) l2=0;//18
//	else  l2= 1;
//	
//	if(temp_va23>4000)temp_va23=4000;
//	m3 = (u8)(100-(temp_va23/40));
//	if(m3>26) l3=0;//31
//	else  l3= 1;
//	
//		if(temp_va24>4000)temp_va24=4000;
//	m4 = (u8)(100-(temp_va24/40));
//	if(m4>26) l4=0;//35
//	else  l4= 1;
//	
//		if(temp_va25>4000)temp_va25=4000;
//	m5 = (u8)(100-(temp_va25/40));
//	if(m5>31) l5=0;//28
//	else  l5= 1;
//	
//		if(temp_va26>4000)temp_va26=4000;
//	m6 = (u8)(100-(temp_va26/40));
//	if(m6>25) l6=0;//20
//	else  l6= 1;
//	
//	
//		if(temp_va27>4000)temp_va27=4000;
//	m7 = (u8)(100-(temp_va27/40));
//	if(m7>27) l7=0;//20
//	else  l7= 1;
//	
//	
//	
//		if(temp_va28>4000)temp_va28=4000;
//	m8 = (u8)(100-(temp_va28/40));
//	if(m8>17) l8=0;//15
//	else  l8= 1;	
////	  moni11=k1;
////	  moni12=k2;
////		moni13=k3;
////		moni14=k4;
////		moni15=k5;
////		moni16=k6;
////		moni17=k7;
////		moni18=k8;
////		
////	  moni21=l1;
////	  moni22=l2;
////		moni23=l3;
////		moni24=l4;
////		moni25=l5;
////		moni26=l6;
////		moni27=l7;
////		moni28=l8;		
//				Dis_Num(0,1,s1,2);
//				Dis_Num(0,4,s2,2);
//				Dis_Num(0,7,s3,2);
//				Dis_Num(0,11,s4,2);
//				Dis_Num(2,1,s5,2);
//				Dis_Num(2,4,s6,2);
//				Dis_Num(2,7,s7,2);
//				Dis_Num(2,11,s8,2);
//				Dis_Num(4,1,m1,2);
//				Dis_Num(4,4,m2,2);
//				Dis_Num(4,7,m3,2);
//				Dis_Num(4,11,m4,2);
//				Dis_Num(6,1,m5,2);
//				Dis_Num(6,4,m6,2);
//				Dis_Num(6,7,m7,2);
//				Dis_Num(6,11,m8,2);

//			
//}



void jiance(void)
{
		u32 temp_val1=0,temp_val2=0,temp_val3=0,temp_val4=0,temp_val5=0,temp_val6=0,temp_val7=0,temp_val8=0;
	u32 temp_va21=0,temp_va22=0,temp_va23=0,temp_va24=0,temp_va25=0,temp_va26=0,temp_va27=0,temp_va28=0;

	u8 t;
	u8 s2,s3,s4,s5,s6,s7,s8;
	u8 m2,m3,m4,m5,m6,m7,m8;
	
	u8 k1,k2,k3,k4,k5,k6,k7,k8;
	u8 l1,l2,l3,l4,l5,l6,l7,l8;
	
	for(t=0;t<LSENS_READ_TIMES;t++)
	{
////		temp_val1+=Get_Adc3(ADC_Channel_9);	//读取ADC值,通道5
//		temp_val2+=Get_Adc3(ADC_Channel_14);
//		temp_val3+=Get_Adc3(ADC_Channel_15);	
//		temp_val4+=Get_Adc3(ADC_Channel_4);
//		temp_val5+=Get_Adc3(ADC_Channel_5);
//		temp_val6+=Get_Adc3(ADC_Channel_8);
//		temp_val7+=Get_Adc3(ADC_Channel_2);
//		temp_val8+=Get_Adc3(ADC_Channel_3);
		
		temp_va21+=Get_Adc1(ADC_Channel_4);	//读取ADC值,通道5
		temp_va22+=Get_Adc1(ADC_Channel_5);
		temp_va23+=Get_Adc1(ADC_Channel_6);	
		temp_va24+=Get_Adc1(ADC_Channel_7);
		temp_va25+=Get_Adc1(ADC_Channel_14);
		temp_va26+=Get_Adc1(ADC_Channel_15);
		temp_va27+=Get_Adc1(ADC_Channel_8);
		temp_va28+=Get_Adc1(ADC_Channel_9);
		delay_ms(2);
	}
//	temp_val1/=LSENS_READ_TIMES;//得到平均值 
//	temp_val2/=LSENS_READ_TIMES;
//	temp_val3/=LSENS_READ_TIMES;
//	temp_val4/=LSENS_READ_TIMES;
//	temp_val5/=LSENS_READ_TIMES;
//	temp_val6/=LSENS_READ_TIMES;
//	temp_val7/=LSENS_READ_TIMES;
//	temp_val8/=LSENS_READ_TIMES;
	
	temp_va21/=LSENS_READ_TIMES;//得到平均值 
	temp_va22/=LSENS_READ_TIMES;
	temp_va23/=LSENS_READ_TIMES;
	temp_va24/=LSENS_READ_TIMES;
	temp_va25/=LSENS_READ_TIMES;
	temp_va26/=LSENS_READ_TIMES;
	temp_va27/=LSENS_READ_TIMES;
	temp_va28/=LSENS_READ_TIMES;

//	if(temp_val2>4000)temp_val2=4000;
//	s2 = (u8)(100-(temp_val2/40));
//	if(s2>40) k2=0;//25
//	else  k2= 1;
//	
//	if(temp_val3>4000)temp_val3=4000;
//	s3 = (u8)(100-(temp_val3/40));
//	if(s3>47) k3=0;//31
//	else  k3= 1;
//	
//		if(temp_val4>4000)temp_val4=4000;
//	s4 = (u8)(100-(temp_val4/40));
//	if(s4>47) k4=0;//35
//	else  k4= 1;
//	
//		if(temp_val5>4000)temp_val5=4000;
//	s5 = (u8)(100-(temp_val5/40));
//	if(s5>47) k5=0;//34
//	else  k5= 1;
//	
//		if(temp_val6>4000)temp_val6=4000;
//	s6 = (u8)(100-(temp_val6/40));
//	if(s6>43) k6=0;//36
//	else  k6= 1;
//	
//	
//		if(temp_val7>4000)temp_val7=4000;
//	s7 = (u8)(100-(temp_val7/40));
//	if(s7>37) k7=0;//23
//	else  k7= 1;
//	
//	
//	
//		if(temp_val8>4000)temp_val8=4000;
//	s8 = (u8)(100-(temp_val8/40));
//	if(s8>28) k8=0;
//	else  k8= 1;
//	
	if(temp_va22>4000)temp_va22=4000;
	m2 = (u8)(100-(temp_va22/40));
	if(m2>23) l2=0;//18
	else  l2= 1;
	
	if(temp_va23>4000)temp_va23=4000;
	m3 = (u8)(100-(temp_va23/40));
	if(m3>32) l3=0;//31
	else  l3= 1;
	
		if(temp_va24>4000)temp_va24=4000;
	m4 = (u8)(100-(temp_va24/40));
	if(m4>34) l4=0;//35
	else  l4= 1;
	
		if(temp_va25>4000)temp_va25=4000;
	m5 = (u8)(100-(temp_va25/40));
	if(m5>38) l5=0;//28
	else  l5= 1;
	
		if(temp_va26>4000)temp_va26=4000;
	m6 = (u8)(100-(temp_va26/40));
	if(m6>29) l6=0;//20
	else  l6= 1;
	
	
		if(temp_va27>4000)temp_va27=4000;
	m7 = (u8)(100-(temp_va27/40));
	if(m7>31) l7=0;//20
	else  l7= 1;
	
	
	
		if(temp_va28>4000)temp_va28=4000;
	m8 = (u8)(100-(temp_va28/40));
	if(m8>23) l8=0;//15
	else  l8= 1;	
		
//	  moni11=k1;
//	  moni12=k2;
//		moni13=k3;
//		moni14=k4;
//		moni15=k5;
//		moni16=k6;
//		moni17=k7;
//		moni18=k8;
		
	  moni21=l1;
	  moni22=l2;
		moni23=l3;
		moni24=l4;
		moni25=l5;
		moni26=l6;
		moni27=l7;
		moni28=l8;		
//				Dis_Num(0,4,s2,2);
//				Dis_Num(0,7,s3,2);
//				Dis_Num(0,11,s4,2);
//				Dis_Num(2,1,s5,2);
//				Dis_Num(2,4,s6,2);
//				Dis_Num(2,7,s7,2);
//				Dis_Num(2,11,s8,2);
				
//				Dis_Num(4,4,m2,2);
//				Dis_Num(4,7,m3,2);
//				Dis_Num(4,11,m4,2);
//				Dis_Num(6,1,m5,2);
//				Dis_Num(6,4,m6,2);
//				Dis_Num(6,7,m7,2);
//				Dis_Num(6,11,m8,2);
}


void houjiance()
{
	u32 temp_va21=0,temp_va22=0,temp_va23=0,temp_va24=0,temp_va25=0,temp_va26=0,temp_va27=0,temp_va28=0;

	u8 t;
	u8 m2,m3,m4,m5,m6,m7,m8;

	u8 l1,l2,l3,l4,l5,l6,l7,l8;
	
	for(t=0;t<LSENS_READ_TIMES;t++)
	{

		temp_va21+=Get_Adc1(ADC_Channel_4);	//读取ADC值,通道5
		temp_va22+=Get_Adc1(ADC_Channel_5);
		temp_va23+=Get_Adc1(ADC_Channel_6);	
		temp_va24+=Get_Adc1(ADC_Channel_7);
		temp_va25+=Get_Adc1(ADC_Channel_14);
		temp_va26+=Get_Adc1(ADC_Channel_15);
		temp_va27+=Get_Adc1(ADC_Channel_8);
		temp_va28+=Get_Adc1(ADC_Channel_9);
		delay_ms(2);
	}

	
	temp_va21/=LSENS_READ_TIMES;//得到平均值 
	temp_va22/=LSENS_READ_TIMES;
	temp_va23/=LSENS_READ_TIMES;
	temp_va24/=LSENS_READ_TIMES;
	temp_va25/=LSENS_READ_TIMES;
	temp_va26/=LSENS_READ_TIMES;
	temp_va27/=LSENS_READ_TIMES;
	temp_va28/=LSENS_READ_TIMES;

	
	if(temp_va22>4000)temp_va22=4000;
	m2 = (u8)(100-(temp_va22/40));
	if(m2>23) l2=0;//18
	else  l2= 1;
	
	if(temp_va23>4000)temp_va23=4000;
	m3 = (u8)(100-(temp_va23/40));
	if(m3>32) l3=0;//31
	else  l3= 1;
	
		if(temp_va24>4000)temp_va24=4000;
	m4 = (u8)(100-(temp_va24/40));
	if(m4>34) l4=0;//35
	else  l4= 1;
	
		if(temp_va25>4000)temp_va25=4000;
	m5 = (u8)(100-(temp_va25/40));
	if(m5>38) l5=0;//28
	else  l5= 1;
	
		if(temp_va26>4000)temp_va26=4000;
	m6 = (u8)(100-(temp_va26/40));
	if(m6>29) l6=0;//20
	else  l6= 1;
	
	
		if(temp_va27>4000)temp_va27=4000;
	m7 = (u8)(100-(temp_va27/40));
	if(m7>31) l7=0;//20
	else  l7= 1;
	
	
	
		if(temp_va28>4000)temp_va28=4000;
	m8 = (u8)(100-(temp_va28/40));
	if(m8>23) l8=0;//15
	else  l8= 1;	
		
	  moni21=l1;
	  moni22=l2;
		moni23=l3;
		moni24=l4;
		moni25=l5;
		moni26=l6;
		moni27=l7;
		moni28=l8;		
//		
//		Dis_Num(4,4,m2,2);
//				Dis_Num(4,7,m3,2);
//				Dis_Num(4,11,m4,2);
//				Dis_Num(6,1,m5,2);
//				Dis_Num(6,4,m6,2);
//				Dis_Num(6,7,m7,2);
//				Dis_Num(6,11,m8,2);
}




