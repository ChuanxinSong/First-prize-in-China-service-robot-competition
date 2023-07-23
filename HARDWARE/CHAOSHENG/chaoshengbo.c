#include "sys.h"
#include "chaoshengbo.h"
#include "delay.h"
#include "timer.h"
#include  "gpio.h"
#include "huidu.h"
extern int flag;



double ceju(void)
		{
			int i;
			double l;
		 double s1;
			double p=0;
			double ju[7];
				TIM_Cmd(TIM7, DISABLE);//guanbi定时器	
			
//第一次测量			
			for(i=1;i<=3;i++)
			{
					trig=1;
				 delay_us(30);
				 trig=0;
					while(echo==0);
					TIM6->CNT=0;
					TIM_Cmd(TIM6, ENABLE);  //开启定时器计数
			 
					while(echo==1)
					{
						if(flag==1)
							break;
					}
			 
					TIM_Cmd(TIM6, DISABLE);//guanbi定时器
			 
			 
					 if(flag==1)
					 {
							ju[i]=400;
							flag=0;
					 }
					 
					 else
					 {
							l=(int)(TIM_GetCounter(TIM6));
							ju[i]=(l*0.0346);//cm
					 }
					 p+=ju[i];
					 delay_ms(3);
			}
			s1=p/3;
			
//			max=1;
//			min=1;
//			for(i=1;i<=5;i++)
//			{
//				if(ju[i]>ju[max])
//					max=i;
//				if(ju[i]<ju[min])
//					min=i;

//			}
//			p=p-ju[max]-ju[min];
//			s1=p/3;			
//			for(i=1;i<=3;i++)
//			{
////				if((i==max)||(i==min))
////					continue;
////				if((abs(ju[i]-s1))>0.4)
////				{
////					p-=ju[i];
////					j--;
////				}
//				s1=p/j;
//			}
	 return s1;

			 
		}	




		