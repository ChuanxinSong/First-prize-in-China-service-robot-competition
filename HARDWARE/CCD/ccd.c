#include "delay.h"
#include "ccd.h"
#include "adc.h"
#include "usart.h"

void Delay()
{
 int i;
	for(i=1;i<=1000;i++)
	;
	

}
void CCD_startbg(void)
{
	u8 i;
  CCD_SI=1;
	Delay();
	CCD_CLK=1;
	Delay();
	CCD_SI=0;
	Delay();
	CCD_CLK=0;
	  for(i=0;i<127;i++)
	 {
	   Delay();
		 CCD_CLK=1;
		 Delay();
		 CCD_CLK=0;
	  }
   Delay();
   CCD_CLK=1;
   Delay();
   CCD_CLK=0;	
}





void CCD_reader(u8 *p)
{

    uint8_t i=0;
  
    CCD_CLK=1;
	Delay();
    CCD_SI=0; 
 	Delay();
    
    CCD_SI=1; 
		Delay();
    CCD_CLK=0;
  	Delay();
      
    CCD_CLK=1;
		Delay();
    CCD_SI=0; 
  	Delay();  
   for(i=0;i<128;i++)
    { 
        CCD_CLK=0;  
        	Delay();
        p[i]=Get_Adc(ADC_Channel_5); // 将采集到的AD数据放入128的数组里
        CCD_CLK=1;
         	Delay();
    }    
}


void CCD_send(u8 *p)
{
	u8 t;
  	for(t=0;t<128;t++)
			{
	
		putchar(p[t]);		//发送数据
			}
}



 void CCD_init(void)
 {
	 GPIO_InitTypeDef  GPIO_InitStructure;
	 	
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	 //使能PA端口时钟
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;				 //端口配置
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;	 //推挽输出
	 GPIO_InitStructure.GPIO_OType =GPIO_OType_PP;
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
	 GPIO_Init(GPIOA, &GPIO_InitStructure);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_3| GPIO_Pin_4);						 //PA.1 PA.3 输出低

 }
 

