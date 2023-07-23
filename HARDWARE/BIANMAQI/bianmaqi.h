#ifndef __BIANMAQI_H__
#define __BIANMAQI_H__
#include	"stdlib.h"

//编码器是500转的话转一圈CNT的值变化2000
void Encoder_Configuration(void);

#define Encoder_Start1()   TIM2->CNT = 0x7fff//CNT是数据寄存器，
#define Encoder_Reset1()   TIM2->CNT = 0x7fff
#define Encoder_Get_Cnt1() ((TIM2->CNT)-0x7fff)

#define Encoder_Start2()   TIM3->CNT = 0x7fff//CNT是数据寄存器，
#define Encoder_Reset2()   TIM3->CNT = 0x7fff
#define Encoder_Get_Cnt2() ((TIM3->CNT)-0x7fff)

#define Encoder_Start3()   TIM4->CNT = 0x7fff//CNT是数据寄存器，
#define Encoder_Reset3()   TIM4->CNT = 0x7fff
#define Encoder_Get_Cnt3() ((TIM4->CNT)-0x7fff)

#define Encoder_Start4()   TIM5->CNT = 0x7fff//CNT是数据寄存器，
#define Encoder_Reset4()   TIM5->CNT = 0x7fff
#define Encoder_Get_Cnt4() ((TIM5->CNT)-0x7fff)

#define	you							abs((int)(TIM2->CNT-0xfff))//编码器TIM2	5800
#define	zuo							abs((int)(TIM4->CNT-0xfff))///编码器TIM4	2200
#endif 
