#include "sys.h"
#include "bianmaqi.h"



//TIM5_CH1 ----- PA0
//TIM5_CH2 ----- PA1
//TIM4_CH1 ----- PD12
//TIM4_CH2 ----- PD13
//TIM2_CH1 ----- PA15
//TIM2_CH2 ----- PB3
//TIM3_CH1 ----- PC6
//TIM3_CH2 ----- PC7
void Encoder_Configuration(void)//±àÂëÆ÷Ä£Ê½
{
    GPIO_InitTypeDef gpio;
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOD|RCC_AHB1Periph_GPIOC,ENABLE);
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM5|RCC_APB1Periph_TIM4|RCC_APB1Periph_TIM2|RCC_APB1Periph_TIM3 ,ENABLE);
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
    gpio.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1|GPIO_Pin_15;
    gpio.GPIO_Mode = GPIO_Mode_AF;
    gpio.GPIO_OType = GPIO_OType_PP;
    gpio.GPIO_PuPd = GPIO_PuPd_NOPULL;
    gpio.GPIO_Speed = GPIO_Speed_100MHz;
    
     GPIO_Init(GPIOA,&gpio);
	
	      gpio.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_12;	
	GPIO_Init(GPIOD,&gpio);

	       gpio.GPIO_Pin = GPIO_Pin_3;	
	GPIO_Init(GPIOB,&gpio);
	
//		      gpio.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;	
//	GPIO_Init(GPIOC,&gpio);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource0,  GPIO_AF_TIM5);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource1,  GPIO_AF_TIM5);
//    
//		  GPIO_PinAFConfig(GPIOC, GPIO_PinSource6,  GPIO_AF_TIM3);
//    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7,  GPIO_AF_TIM3);
		
		
		GPIO_PinAFConfig(GPIOD, GPIO_PinSource13,  GPIO_AF_TIM4);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource12,  GPIO_AF_TIM4);
		
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource3,  GPIO_AF_TIM2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource15,  GPIO_AF_TIM2);
	
    TIM_EncoderInterfaceConfig(TIM5, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
//        TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
				 TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
        TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
    TIM_Cmd(TIM5, ENABLE);
//		    TIM_Cmd(TIM3, ENABLE);
    TIM_Cmd(TIM2, ENABLE);
		    TIM_Cmd(TIM4, ENABLE);				
}
