#ifndef __MONI_H
#define __MONI_H	
#include "sys.h" 
#include "adc.h" 
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
  
#define LSENS_READ_TIMES	5		//定义光敏传感器读取次数,读这么多次,然后取平均值
 
void Lsens_Init(void); 				//初始化光敏传感器
void Lsens_Get_Val1(void);
void jiance(void);
//void qianjiance(void);
void houjiance(void);
#endif 





















