#ifndef __ADC_H
#define __ADC_H	
#include "sys.h" 

 							   
 

void Adc3_Init(void); 				//ADC通道初始化
u16  Get_Adc3(u8 ch); 				//获得某个通道值 

void  Adc1_Init(void);
u16 Get_Adc1(u8 ch);   

#endif 















