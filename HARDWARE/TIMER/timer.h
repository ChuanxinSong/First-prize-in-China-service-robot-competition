#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"
#include "huidu.h"
//////////////////////////////////////////////////////////////////////////////////	 

//arr:自动重装载值；psc：预分频系数；
#define qianzonghe (moni11+moni12+moni13+moni14+moni15+moni16+moni17+moni18)
#define zhongzonghe (qian1+qian2+qian3+qian4+qian5+qian6+qian7+qian8)
#define houzonghe (moni22+moni23+moni24+moni25+moni26+moni27+moni28)
void TIM6_Int_Init(u16 arr,u16 psc);
void TIM7_Int_Init(u16 arr,u16 psc);//中断配置定时器10
void TIM14_PWM_Init(u32 arr,u32 psc);//PF9 左前
void TIM13_PWM_Init(u32 arr,u32 psc);//PF8 右前
void TIM9_CH1_PWM_Init(u32 arr,u32 psc);//PE5 左后
void TIM9_CH2_PWM_Init(u32 arr,u32 psc);//PE6 右后
void guaiwan(u16 zuoqian,u16 youqian,u16 zuohou,u16 youhou,int flag1,int flag2,int flag3,int flag4);
void houguaiwan(u16 youhou,u16 zuohou,u16 youqian,u16 zuoqian,int flag1,int flag2);

//轮
void zuolunjin(u16 pwm);
void youlunjin(u16 pwm);
void zuoluntui(u16 pwm);
void youluntui(u16 pwm);
void zuolunting(void);
void youlunting(void);
void zuolun(u16 pwm,int flag);
void youlun(u16 pwm,int flag);
void qianjin(void);
void xiaoqianjin(void);
void xiaohoutui(void);
void houtui(void);
void ting(void);
void jiaodu(void);

///寻迹
void qiankuaixun(void);
void qianmanxun(void);
void qianchaomanxun(void);
void houchaomanxun(void);
void houkuaixun(void);
void houmanxun(void);
void jiuzheng(void);
void jixianxun(void);
void jixianxun1(void);
void houjixianxun(void);

void xianshi(void);
void zuoguai(void);
void xiaozuoguai(void);
void xiaoyouguai(void);
void youguai(void);
void shache(void);
void zhunbei(void);
void chushihua(void);

void SendData ( u8 addr );
void laba(void);
#endif
