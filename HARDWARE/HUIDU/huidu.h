#ifndef _huidu_H
#define _huidu_H
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "oled.h"
#include "adc.h"
#include "timer.h"
#include "gpio.h"
#include "bianmaqi.h"
#include "stdio.h"
#include "stdlib.h"
#include "huidu.h"
#include "duoji.h"
#include "pid.h"
#include "Frie_Computer.h" //?????,?????
#include "moni.h"
#include "chaoshengbo.h"
#include "myiic.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "mpu6050.h"
#include "math.h"
//qian1,qian4,hou3撒
//方忖子業
//#define qian1 PFin(11)	  // 子業1
//#define qian2 PFin(12)	// 子業2
//#define qian3 PFin(13)	// 子業3
//#define qian4 PFin(14)	// 子業4
//#define qian5 PFin(15)	  // 子業5
//#define qian6 PEin(7)	  // 子業6
//#define qian7 PEin(8)	// 子業7
//#define qian8 PEin(10)	// 子業8

#define moni11 PFin(11)	  // 子業1
#define moni12 PFin(12)	// 子業2
#define moni13 PFin(13)	// 子業3
#define moni14 PFin(14)	// 子業4
#define moni15 PFin(15)	  // 子業5
#define moni16 PEin(7)	  // 子業6
#define moni17 PEin(8)	// 子業7
#define moni18 PEin(10)	// 子業8


#define GD1 PAin(11)	  // 高窮1
#define GD2 PAin(12)	// 高窮2

#define GDZ PCin(11)  //恣念高窮
#define GDY PCin(12)	//嘔念高窮
#define GD3 PDin(3)
#define GD4 PDin(4)

void huidu_init(void);
void xiangzi1(void);
void xiangzi2(void);
void	xiangzi3(void);
void	xiangzi4(void);
void chafang1(void);
void chafang2(void);
#endif
