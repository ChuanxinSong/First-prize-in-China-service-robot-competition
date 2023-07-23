#include "pid.h"
#include "delay.h"
#include "oled.h"
#include "gpio.h"
 
extern int speed1,speed2,speed3,speed4,flag1,flag2,flag3,flag4,va,vb,vc,vd;//va,b,c,d：目标转速
extern int32_t output2,output1,output3,output4;//output1:zuoqian;output2:youqian;output3:zuohou;output4:youhou
double kp,ki,kd,Up,Ui,Ud;

/////////////////////////////////

 void  zuoqian_sudu_Ctrl(u16 v)
{
	 static double error1,error11,error12;
	kp=0.4;
  ki=1.2;
  kd=0;

	error1=va-v;
  Up=kp*(error1-error11);
	Ui=ki*error11;
	Ud=kd*(error1 - 2*error11 + error12);
	error12=error11;
	error11=error1;
  output1+=(int)(Up+Ui+Ud);
  if(output1>4900)
  {
	  output1=4900;
	} 		
	if(output1<-4900)
	{
	  output1=-4900;
	}
	if(output1<0)
	{
	 output1*=(-1);
		flag1*=(-1);
	}
	 
	}

		


void youqian_sudu_Ctrl(u16 v)
{
	 static double _error2,_error21,_error22;
//	int32_t output1;
	kp=0.4;//1.5起可以动
  ki=1.2;
  kd=0;

	_error2=vb-v;
  Up=kp*(_error2-_error21);
	Ui=ki*_error21;
	Ud=kd*(_error2 - 2*_error21 + _error22);
	_error22=_error21;
	_error21=_error2;
  output2+=(int)(Up+Ui+Ud);
  if(output2>4800)
  {
	  output2=4800;
	} 		
	if(output2<-4800)
	{
	  output2=-4800;
	}
	if(output2<0)
	{
   output2*=(-1);
		flag2*=(-1);
	}
	 
	}
	
//    
void  zuohou_sudu_Ctrl(u16 v)
{
	 static double error3,error31,error32;
//	flag3=1;
	kp=0.4;
  ki=0.8;
  kd=0;

	error3=vc-v;
  Up=kp*(error3-error31);
	Ui=ki*error31;
	Ud=kd*(error3 - 2*error31 + error32);
	error32=error31;
	error31=error3;
  output3+=(int)(Up+Ui+Ud);
  if(output3>4900)
  {
	  output3=4900;
	} 		
	if(output3<-4900)
	{
	  output3=-4900;
	}		
//	if(output3<0)
//	{
//   output3*=(-1);
//		flag3*=(-1);
////		zuohour=0;
////		zuohouw=1;
//	}
//	if(vc>0&&output3>0)
//	{
//	zuohour=1;
//	zuohouw=0;
//	TIM_SetCompare1(TIM9,output3);		
//	}
//		if(vc>0&&output3<0)
//	{
//	zuohour=0;
//	zuohouw=1;
//	TIM_SetCompare1(TIM9,(-1)*output3);		
//	}
//		if(vc<0&&output3>0)
//	{
//	zuohour=0;
//	zuohouw=1;
//	TIM_SetCompare1(TIM9,output3);		
//	}
//		if(vc<0&&output3<0)
//	{
//	zuohour=1;
//	zuohouw=0;
//	TIM_SetCompare1(TIM9,-1*output3);		
//	}
	if(output3>0)
	{
	 zuohour=1;
		zuohouw=0;
	}
	if(output3<0)
	{
	zuohour=0;
	zuohouw=1;
	TIM_SetCompare1(TIM9,-1*output3);		
	}
//	TIM_SetCompare1(TIM9,output3);		

	}	
			

void  youhou_sudu_Ctrl(u16 v)
{
	 static double error4,error41,error42;
	kp=0.4;
  ki=1.2;
  kd=0;

	error4=vd-v;
  Up=kp*(error4-error41);
	Ui=ki*error41;
	Ud=kd*(error4 - 2*error41 + error42);
	error42=error41;
	error41=error4;
  output4+=(int)(Up+Ui+Ud);
  if(output4>4900)
  {
	  output4=4900;
	} 		
	if(output4<-4900)
	{
	  output4=-4900;
	}

//	if(output4<0)
//	{
//   output4*=(-1);
//		flag4*=(-1);
//	}
		if(output4>0)
	{
	 youhour=1;
		youhouw=0;
	}
	if(output4<0)
	{
	youhour=0;
	youhouw=1;
	TIM_SetCompare2(TIM9,-1*output4);		
	}
	 
	}
