#ifndef __GPIO_H
#define __GPIO_H
#include "sys.h"
	


//电机端口定义
#define youqianr PGout(9)	// DS0  //9
#define youqianw PGout(11)	// DS1	 //11
#define zuoqianr PGout(12)      //10
#define zuoqianw PGout(10)     //12
#define zuohour PCout(1)
#define zuohouw PCout(0)
#define youhour PCout(2)
#define youhouw PCout(3)
#define deng		PBout(12)//0时亮，1时不亮

#define sda			PCout(6)
#define beep		PDout(4)

#define trig PDout(14)	// DS0
#define echo PDin(15)	// DS1	 
void LED_Init(void);//初始化		
void chaosheng_Init(void);
#endif
