#ifndef _duoji_H
#define _duoji_H
#include "sys.h"


//TIM1_CH1:PE9  //duoji1
//TIM1_CH2:PE11  //duoji2  //5
//
//TIM8_CH3:PC8  4
//TIM8_CH4:PC9   3//7.2


void TIM1_PWM_Init(u32 arr,u32 psc);
void TIM8_PWM_Init(u32 arr,u32 psc);

void duoji1(u32	asc);//数越大张开的角度越大
void duoji2(u32	asc);//数减小逆时针转动
void duoji3(u32 asc);//数越小越往上
void duoji4(u32 asc);//数越大越往上

void hengna(void);
void hengfang(void);
void shuna(void);
void shunazhunbei(void);
void shuipingshufangzhunbei(void);
void shuipingshufang(void);
void shufang(void);
void gaoju(void);
void fang(void);
#endif

