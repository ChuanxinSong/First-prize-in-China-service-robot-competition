#include "huidu.h"

extern int va,vb,vc,vd,renwu1,moshu,renwu2,renwu3,renwu4,tansuo1,tansuo2,tansuo3,tansuo4,cha;
extern int moni21,moni22,moni23,moni24,moni25,moni26,moni27,moni28,moshi,e;
extern double s;
extern double sa;
extern float pitch,roll,yaw;

 void huidu_init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;


  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能GPIOF时钟
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//使能GPIOE时钟
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOA时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能GPIOD时钟
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_12 | GPIO_Pin_13|GPIO_Pin_14 | GPIO_Pin_15; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;//上拉
	
  GPIO_Init(GPIOF, &GPIO_InitStructure);

 	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8|GPIO_Pin_10; 
  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
		  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_12; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);
			  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_12; 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; 
  GPIO_Init(GPIOD, &GPIO_InitStructure);

}	
	 
void chafang1()
{
	while(cha==0)//前进然后左拐
	{
		static int u=9;
		while(u==9)
		{
			qianjin();
			if(GD2==0||GD1==0)
			{
				u=0;
			}
//			while(qianzonghe<5)
//				qianjin();
//			delay_ms(400);
		}
		while(u==0)
		{
//			jiance();
			qianchaomanxun();
			if(qianzonghe<=2)
			{
				u=1;
			}
		}
		while(u==1)
		{
			xiaoqianjin();
			if(GD2==0)
			{
				ting();
				u=2;
			}
		}
		while(u==2)
		{
			xiaozuoguai();
//			jiance();
			if(moni18==0)
			{
				while(moni18==0)
				{
//					jiance();
					xiaozuoguai();
				}
				delay_ms(100);
				u=3;
				ting();
			}
		}
		while(u==3)
		{
			xiaozuoguai();
//			jiance();
			if(moni15==0||moni16==0)
			{
				u=4;
				cha=1;
			}
		}
	}
	while(cha==1)//前进然后右拐
	{
//		jiance();
		qianchaomanxun();
		if(qianzonghe<=2)
		{
			while(qianzonghe<=2)
			{
//				jiance();
				xiaoqianjin();
			}
			
			
			while(GD2!=0)
			{
				xiaoqianjin();
			}
			ting();
			delay_ms(200);
			
			chushihua();
			ting();
//			jiance();
			while(moni18!=0)
			{
//				jiance();
				youguai();
			}
			ting();
			delay_ms(200);
			while(moni14!=0&&moni13!=0&&moni12!=0&&moni11!=0)
			{
//				jiance();
				xiaoyouguai();
			}
//			houtui();
//			delay_ms(50);
			ting();
			cha=2;
			break;
		}
	}
	while(cha==2)//xunjin然后查房
	{
		static int u=1;
//		jiance();

		while(u==1)
		{
//			jiance();
			qianmanxun();
			
			//qianchaomanxun();
			if(qianzonghe==8)
			{
//				jiance();
				if(qianzonghe==8)
				{
					u=2;
				}
				else
				{
					continue;
				}
			}
		}
		beep=1;
		while(u==2)
		{
//			jiance();
			while(1)
			{
				if(fabs(yaw)<89.5)
				{
						guaiwan(30,30,20,20,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(30,30,20,22,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaoqianjin();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
//				jiance();
				if(GD3==0)
				{
				//	ting();
					beep=0;
					u=3;
					break;
				}
			}
		}
		while(u==3)
		{
			beep=0;
			while(qianzonghe==8)
			{
	//			jiance();
				if(fabs(yaw)<89.5)
				{
						guaiwan(30,30,20,20,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(30,30,20,22,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaoqianjin();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
			}
			u=6;
		}
		while(u==6)
		{
			ting();
			delay_ms(1000);
			laba();
			delay_ms(6500);
			u++;
			cha=3;
		}
	}
	while(cha==3)//后退然后右拐
	{
		static int u=0;
		while(u==0)
		{
			while(1)
			{
				if(fabs(yaw)<89.5)
				{
						guaiwan(20,20,40,40,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(20,20,40,42,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaohoutui();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
//				jiance();
//				if(houzonghe!=7)
				if(GD2==0)
				{
					ting();
					u=2;
					break;
				}
			}
		}
		while(u==2)
		{

			jiaodu();	
			
			while(fabs(yaw)<135)
			{
				youguai();
				jiaodu();
			}
			ting();
			delay_ms(100);
			while(1)
			{
				xiaoyouguai();
//				jiance();
				if(moni15==0||moni14==0||moni13==0||moni12==0)
				{
					u++;
					cha=4;
					break;
				}
			}
		}
	}	
	while(cha==4)//前进然后前进	
	{
//		jiance();
		qianmanxun();
		if(qianzonghe<2)
		{
			while(qianzonghe<4)
			{
//				jiance();
				qianjin();
			}
				cha++;
		}
	}
	while(cha==5)//前进然后左拐
	{
//		jiance();
		qianchaomanxun();
		if(qianzonghe<2)
		{
			
			while(GD1!=0)
			{
				xiaoqianjin();
			}
			ting();
			
			ting();
			delay_ms(100);
			chushihua();
//			jiance();
			 jiaodu();
			while(yaw<60)
			{
				guaiwan(95,40,95,40,-1,1,-1,1);
				jiaodu();
			}
			ting();
			delay_ms(200);
			while(yaw<88)
			{
				guaiwan(60,40,20,22,-1,1,-1,1);
				//xiaozuoguai();
				jiaodu();
			}
//			while(houzonghe!=7)
//			{
//				houjiance();
//				guaiwan(30,30,70,72,-1,1,-1,1);
////				guaiwan(30,30,70,72,-1,1,-1,1);
//			}
//			ting();
//			delay_ms(200);
//			while(moni26!=0||moni27!=0&&moni28!=0)
//			{
//				jiance();
//				guaiwan(30,30,70,72,-1,1,-1,1);
//			}
//			while(houzonghe!=7)
//			{
//				jiance();
//				xiaohoutui();
//			}
//			while(moni25!=0)
//			{
//				jiance();
//				guaiwan(30,30,70,72,-1,1,-1,1);
//			}

//			TIM6->CNT=0;
//			TIM_Cmd(TIM6,ENABLE);
//			e=0;
//			while(1)
//			{
//				if(e>200)
//					break;
//				beep=1;
//				jiance();
//				e++;
//				if(moni22==1&&(moni24==0)&&moni27==1)
//				{	
//					xiaohoutui();
//				}	
//				if(moni22==1&&moni24==1&&moni25==0&&moni27==1)//youguai
//				{
//					houguaiwan(40,30,40,30,1,-1);
//				}		
//				
//				else if(moni24==1&&moni25==1&&moni26==0&&moni28==1)//中右拐
//				{
//						houguaiwan(40,30,40,30,1,-1);		
//				}		

//				else if(moni24==1&&moni25==1&&moni26==1&&moni27==0)//da右拐
//				{
//					houguaiwan(30,30,30,30,1,-1);
//				}
//					else if(moni24==1&&moni25==1&&moni26==1&&moni27==1&&moni28==0)//da右拐
//				{
//					houguaiwan(30,40,30,40,1,-1);
//				}
//					
//				else if(moni22==1&&moni23==0&&moni25==1&&moni26==1)//xiao左拐弯
//							houguaiwan(30,40,30,40,-1,1);
//						
//				else if(moni22==0&&moni24==1&&moni25==1&&moni27==1)//zhong左拐弯
//							houguaiwan(45,30,45,30,-1,1);
//				houchaomanxun();
//			}
//			qianjin();
//			while(qianzonghe!=7)
//			{
//				jiance();
//				qianchaomanxun();
//			}
			beep=0;
			cha++;
		}
	}
	while(cha==6)//前进查房
	{
		jiaodu();
		while(1)
		{
		
			static int l=0;
				beep=1;
			if(l==0)
			{
				l++;
				jiaodu();
			}
			if(yaw>=89&&yaw<=91)
			{
				xiaoqianjin();
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
				l++;
			}
			if(yaw<89)
			{
				l++;
				guaiwan(35,35,20,22,-1,1,-1,1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(yaw>90)
			{
				l++;
				guaiwan(35,35,20,20,1,-1,1,-1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(l>600)
				break;
		}
//		jiance();
		while(GD3!=0)
		{
//			jiance();
			if(yaw>=89&&yaw<=91)
			{
				xiaoqianjin();
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(yaw<89)
			{
				guaiwan(35,35,20,22,-1,1,-1,1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(yaw>90)
			{
				guaiwan(35,35,20,20,1,-1,1,-1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
		}
		beep=0;
		while(qianzonghe==8)
		{
//			jiance();
			if(yaw>=89&&yaw<=91)
			{
				xiaoqianjin();
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(yaw<89)
			{
				guaiwan(35,35,20,22,-1,1,-1,1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(yaw>90)
			{
				guaiwan(35,35,20,20,1,-1,1,-1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
		}
		ting();
		delay_ms(1000);
		laba();
		delay_ms(6500);
		cha++;
	}
	while(cha==7)//后退然后左拐
	{
		static int u=0;
		jiance();
		while(u==0)
		{
			while(GD1!=0)
			{
//				jiance();
			if(fabs(yaw)<89)
				{
						guaiwan(20,20,40,40,-1,1,-1,1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>91)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(20,20,40,42,1,-1,1,-1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=91&&fabs(yaw)>=89)
				{
						xiaohoutui();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
			}
			u+=1;
		}
		while(u==1)
		{
	//		jiance();
		//	houchaomanxun();
			if(GD1==0)
			{
				ting();
				jiaodu();
				while(yaw<150)
				{
					jiaodu();
					zuoguai();
				}
				ting();
				delay_ms(200);
				jiance();
				while(moni15!=0&&moni16!=0&&moni17!=0&&moni18!=0)
				{
//					jiance();
					xiaozuoguai();
				}
				u=2;
			}
//			if(houzonghe<=4&&moni28==0)
//			{
//				while(houzonghe<=5)
//				{
//					jiance();
//					xiaohoutui();
//				}
//				while(GD1!=0)
//				{
//					jiance();
//					houchaomanxun();
//				}
//				while(moni18!=0)
//				{
//					jiance();
//					zuoguai();
//				}
//				while(moni18==0)
//				{
//					jiance();
//					zuoguai();
//				}
//				u=2;
//				break;
//			}
		}
		while(u==2)
		{
//			jiance();
			xiaozuoguai();
			if(moni15==0||moni16==0||moni17==0)
			{
				ting();
				u++;
				cha++;
			}
		}
	}
	while(cha==8)//前进然后zuoguai
	{
//		jiance();
		qianmanxun();
		if(qianzonghe<=2)
		{
			while(qianzonghe<=2)
			{
//				jiance();
				xiaoqianjin();
			}
			while(GD2!=0)
			{
//				jiance();
				xiaoqianjin();
			}
			beep=1;
			ting();
			delay_ms(50);
			if(GD2!=0)
			{
				while(GD2!=0)
				{
					jiance();
					xiaohoutui();
				}
			}
			while(moni18!=0)
			{
//				jiance();
				zuoguai();
			}
			while(moni18==0)
			{
				
//				jiance();
				zuoguai();
			}
			delay_ms(50);
			ting();
			delay_ms(100);
			while(1)
			{
				beep=0;
				jiance();
				xiaozuoguai();
				if(moni15==0||moni16==0)
				{
					beep=0;
					ting();
					cha++;
					break;
				}
			}
		}
	}
	while(cha==9)//前进然后ting
	{
		jiance();
		qianmanxun();
		if(qianzonghe<=2)
		{
//			while(houzonghe!=7)
//			{
//				jiance();
//				qianjin();
//			}
			while(GD2!=0)
				qianjin();
			delay_ms(800);
			cha++;
		}
	}
	while(cha==10)//停（）
	{
		ting();
		delay_ms(2000);
		cha++;
	}
	
	
/////


///

//	
	while(cha==11)//后退
	{
//		beep=1;
//		jiance();
		while(GD1!=0&&GD2!=0)
			houtui();
//		while(houzonghe==7)
//		{
//			jiance();
//			houtui();
//		}
//		while(houzonghe<=5)
//		{
//			jiance();
//			houtui();
//		}
//		delay_ms(100);
		cha++;
		
	}
	while(cha==12)//后退然后左拐
	{
		beep=0;
		jiance();
		houchaomanxun();
		if(houzonghe<=2)
		{
//			beep=1;
			while(GD2!=0)
			{
				xiaohoutui();
			}
			ting();
			delay_ms(100);
//			jiance();
			while(moni18!=0)
			{
//				qianjiance();
				zuoguai();
			}
			while(moni18==0)
			{
//				qianjiance();
				zuoguai();
			}
//			delay_ms(100);
			ting();
			delay_ms(200);
			while(moni15!=0&&moni16!=0&&moni17!=0)
			{
//				qianjiance();
				xiaozuoguai();
			}
			cha++;
		}
	}
	while(cha==13)//前进然后右拐
	{
//		jiance();
		qianchaomanxun();
		if(qianzonghe<=2)
		{
			while(GD2!=0)
			{
				xiaoqianjin();
			}
			ting();
			delay_ms(100);
//			jiance();
			while(moni18!=0)
			{
//				jiance();
				youguai();
			}
			ting();
			delay_ms(200);
			while(moni14!=0&&moni13!=0&&moni12!=0)
			{
//				jiance();
				xiaoyouguai();
			}
			TIM_Cmd(TIM7, DISABLE);
			cha++;
		}
	}
	while(cha==14)//前进然后抓取
	{
		static int l=0;
		while(l==0)
		{
			s=ceju();
			if(s<23)
			{
				l=1;
				break;
			}
//			qianjiance();
			qianchaomanxun();
		}
		while(l==1)
		{
			houjiance();
			if(houzonghe<=5)
				xiaohoutui();
			if(GD2==0)
			{
				l=2;
				ting();
				shunazhunbei();
				break;
			}
			houchaomanxun();
		}
		while(l==2)
		{
//			while(GD3!=0)
//			{
//				qianchaomanxun();
//			}
			s=ceju();
			if(s<=31)
			{
				l=3;
				ting();
				duoji3(700);
		delay_ms(500);
				break;
			}
			jiance();
			qianchaomanxun();
		}
		while(l==3)
		{
			int i;
			ting();
			for(i=2400;i>1550;i-=20)
			{
				duoji1(i);
				delay_ms(20);
			}
			for(i=550;i<700;i+=20)//800
			{
				duoji4(i);
				delay_ms(20);
			}
			
			l++;
			cha++;
		}
	}
	while(cha==15)//后退然后右拐
	{
		int i;
		TIM_Cmd(TIM6, ENABLE);
		jiance();
		houchaomanxun();
		if(houzonghe<=4)
		{
			xiaohoutui();
		}
		if(GD2==0)
		{
			ting();
			for(i=820;i<1850;i+=25)
			{
				duoji2(i);
				delay_ms(20);
			}
			for(i=700;i<850;i+=25)
			{
				duoji3(i);
				delay_ms(20);
			}
			for(i=800;i<2450;i+=25)
			{
				duoji4(i);
				delay_ms(20);
			}
			delay_ms(100);
//			jiance();
			while(moni11!=0)
			{
//				jiance();
				youguai();
				
			}
			while(moni11==0)
			{
				youguai();
			}
			delay_ms(60);
			ting();
			delay_ms(100);
			while(moni14!=0&&moni13!=0)
			{
//				jiance();
				xiaoyouguai();
			}
			cha++;
		}
	}
	while(cha==16)//qianjin然后前进
	{
//		qianjiance();
		qianmanxun();
		if(qianzonghe<=2)
		{
			while(qianzonghe<5)
			{
//				jiance();
				qianjin();
			}
			cha++;
		}
	}
	while(cha==17)//qianjin然后右拐
	{
//		jiance();
		qianchaomanxun();
		if(qianzonghe<=2)
		{
			while(qianzonghe<=2)
			{
//				jiance();
				xiaoqianjin();
			}
			
			
			while(GD2!=0)
			{
				xiaoqianjin();
			}
			ting();
			ting();
			delay_ms(100);
			
			chushihua();
			jiance();
			while(moni18!=0)
			{
				jiance();
				youguai();
			}
			ting();
			delay_ms(200);
			qianjin();
			delay_ms(400);
			jiaodu();
			while(fabs(yaw)<88)
			{
				jiaodu();
				xiaoyouguai();
			}
//			while(moni14!=0&&moni13!=0&&moni12!=0&&moni15!=0)
//			{
////				jiance();
//				xiaoyouguai();
//			}
			
			ting();
			cha=18;
			break;
		}
		
	}
//			houtui();
//			delay_ms(150);
	while(cha==18)//前进然后放下
	{
		static int u=5;
//		jiance();

//		while(u==1)
//		{
//			
////			jiance();
//			qianchaomanxun();
//			if(qianzonghe==8)
//			{
////				jiance();
//				if(qianzonghe==8)
//				{
//					u=5;
//				}
//				else
//				{
//					continue;
//				}
//			}
//		}
		while(u==5)
		{
			while(1)
			{
				if(fabs(yaw)<89.5)
				{
						guaiwan(30,30,20,20,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(30,30,20,22,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaoqianjin();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
//				jiance();
				if(GD3==0)
				{
					ting();
					u=2;
					break;
				}
			}
		}

		while(u==2)
		{
			
//			jiance();
			while(1)
			{
				s=ceju();
				if(fabs(yaw)<89.5)
				{
						guaiwan(30,30,20,20,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(30,30,20,22,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaoqianjin();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
//				jiance();
				if(s<15)
				{
					ting();
					u=3;
					break;
				}
			}
		}
		while(u==3)
		{
			int i;
			ting();
			for(i=900;i<1800;i+=20)
			{
				duoji3(i);
				delay_ms(20);
			}
			for(i=1850;i>820;i-=20)
			{
				duoji2(i);
				delay_ms(20);
			}
			for(i=1800;i<2120;i+=10)
			{
				duoji3(i);
				delay_ms(20);
			}
			for(i=1550;i<1650;i+=5)
			{
				duoji1(i);
				delay_ms(20);
			}
			for(i=1650;i<1900;i+=10)
			{
				duoji1(i);
				delay_ms(20);
			}
			for(i=1900;i<2300;i+=25)
			{
				duoji1(i);
				delay_ms(20);
			}
//			delay_ms(1000);
			u++;
			cha=19;
		}
	}
	while(cha==19)//后退然后右拐
	{
		static int u=0;
		while(u==0)
		{
			
			while(1)
			{
				if(fabs(yaw)<89.5)
				{
						guaiwan(20,20,40,40,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(20,20,40,42,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaohoutui();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
//				jiance();
//				if(houzonghe!=7)
				if(GD3!=0)
				{
					int i;
					ting();
					for(i=2200;i>1600;i-=25)
					{
						duoji3(i);
						delay_ms(20);
					}
					for(i=2200;i>1650;i-=30)
					{
						duoji1(i);
						delay_ms(20);
					}
					for(i=1600;i>900;i-=20)
					{
						duoji3(i);
						delay_ms(20);
					}
					u=1;
					break;
				}
			}
		}
		while(u==1)
		{
			while(1)
			{
				if(fabs(yaw)<89.5)
				{
						guaiwan(20,20,40,40,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(20,20,40,42,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaohoutui();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
//				jiance();
//				if(houzonghe!=7)
				if(GD2==0)
				{
					ting();
					u=2;
					break;
				}
			}
		}
		while(u==2)
		{

			jiaodu();	
			
			while(fabs(yaw)<135)
			{
				youguai();
				jiaodu();
			}
			ting();
			delay_ms(100);
			qianjin();
			delay_ms(400);
			while(1)
			{
				xiaoyouguai();
//				jiance();
				if(moni15==0||moni14==0||moni13==0||moni12==0)
				{
					u++;
					cha=20;
					break;
				}
			}
		}
	}
	while(cha==20)//前进然后前进
	{
//		jiance();
		qianchaomanxun();
		if(qianzonghe<2)
		{
			while(qianzonghe<4)
			{
//				jiance();
				qianjin();
			}
				cha++;
		}
	}
	while(cha==21)//前进然后右拐
	{
//		jiance();
		qianchaomanxun();
		if(qianzonghe<=2)
		{
			while(GD2!=0)
			{
				xiaoqianjin();
			}
			ting();
			delay_ms(100);
			jiance();
			while(moni18!=0)
			{
				jiance();
				youguai();
			}
			ting();
			delay_ms(200);
			while(moni14!=0&&moni13!=0&&moni12!=0)
			{
//				jiance();
				xiaoyouguai();
			}
			cha++;
		}
	}
	while(cha==22)//前进然后抓取
	{ 
		static int l=0;
		while(l==0)
		{
			s=ceju();
			if(s<20)
			{
				l=1;
				break;
			}
//			qianjiance();
			qianchaomanxun();
		}
		while(l==1)
		{
			houjiance();
			if(houzonghe<=5)
				xiaohoutui();
			if(GD2==0)
			{
				l=2;
				ting();
				shunazhunbei();
				break;
			}
			houchaomanxun();
		}
		while(l==2)
		{
			s=ceju();
			if(s<=18.2)
			{
				l=3;
				ting();
				duoji3(700);
		delay_ms(500);
				break;
			}
			jiance();
			qianchaomanxun();
		}
		while(l==3)
		{
			int i;
			ting();
			for(i=2400;i>1550;i-=20)
			{
				duoji1(i);
				delay_ms(20);
			}
			for(i=550;i<800;i+=20)
			{
				duoji4(i);
				delay_ms(20);
			}
			for(i=820;i<1850;i+=25)
			{
				duoji2(i);
				delay_ms(20);
			}
			for(i=700;i<850;i+=25)
			{
				duoji3(i);
				delay_ms(20);
			}
			for(i=800;i<2450;i+=25)
			{
				duoji4(i);
				delay_ms(20);
			}
			l++;
			cha++;
		}
	}
	while(cha==23)//后退然后右拐
	{
		jiance();
		houchaomanxun();
		if(houzonghe<=4)
		{
			xiaohoutui();
		}
		if(GD2==0)
		{
			ting();
			delay_ms(100);
			jiance();
			while(moni11!=0)
			{
//				jiance();
				youguai();
				
			}
			while(moni11==0)
				youguai();
			delay_ms(50);
			ting();
			delay_ms(100);
			while(moni14!=0&&moni13!=0)
			{
				jiance();
				xiaoyouguai();
			}
			cha++;
		}
	}
	while(cha==24)//前进然后后退
	{
//		jiance();
		qianchaomanxun();
		if(qianzonghe<=2)
		{
			ting();
			delay_ms(100);
			xiaoqianjin();
			while(1)
			{
					houjiance();
					houchaomanxun();
					if(houzonghe<=2)
					{
						while(GD2!=0)
						{
							xiaohoutui();
						}
						ting();
						delay_ms(200);
						chushihua();
						jiaodu();
						while(moni11!=0)
							youguai();
						while(moni11==0)
							youguai();
						while(fabs(yaw)<55)
						{
//							guaiwan(50,50,20,20,1,-1,1,-1);
							youguai();
							jiaodu();
						}
						qianjin();
						delay_ms(850);
//						while(moni11==0)
//							youguai();
						ting();
						delay_ms(200);
						jiaodu();
						while(fabs(yaw)<88)
						{
								guaiwan(50,50,20,20,1,-1,1,-1);//xiaoyouguai();
							jiaodu();
						}
//						while(moni11!=0)
//							xiaoyouguai();
//						while(moni11==0)
//							youguai();
//						while(fabs(yaw)<30)
//						{
//							guaiwan(50,50,20,20,1,-1,1,-1);
//							//youguai();
//							jiaodu();
//						}
////						qianjin();
////						delay_ms(100);
////						while(moni11==0)
////							youguai();
//						ting();
//						delay_ms(200);
//						jiaodu();
//						while(fabs(yaw)<88)
//						{
//								guaiwan(50,50,20,20,1,-1,1,-1);//xiaoyouguai();
//							jiaodu();
//						}
						ting();
						cha++;
						break;
					}
			}	
			
			
		}
	}
	while(cha==25)//前进然后放下
	{
		jiaodu();
		
		while(1)
		{
			static int l=0;
				beep=1;
			if(l==0)
			{
				l++;
				jiaodu();
			}
			if(fabs(yaw)>=89.5&&fabs(yaw)<=90.5)
			{
				xiaoqianjin();
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
//				l++;
			}
			if(fabs(yaw)<89.5)
			{
//				l++;
				guaiwan(35,35,20,22,1,-1,1,-1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(fabs(yaw)>90.5)
			{
//				l++;
				guaiwan(35,35,20,20,-1,1,-1,1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(GD3==0)
				break;
		}
	//	jiance();
		beep=0;
		s=ceju();
		while(s>15)
		{
			
//			jiance();
			if(fabs(yaw)>=89&&fabs(yaw)<=91)
			{
				xiaoqianjin();
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(fabs(yaw)<89)
			{
				guaiwan(33,33,20,22,1,-1,1,-1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(fabs(yaw)>90)
			{
				guaiwan(33,33,20,20,-1,1,-1,1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			s=ceju();
		}
		ting();
		cha++;
	}
	while(cha==26)//fang xia
	{
		int i;
			ting();
			for(i=900;i<1800;i+=20)
			{
				duoji3(i);
				delay_ms(20);
			}
			for(i=1850;i>820;i-=20)
			{
				duoji2(i);
				delay_ms(20);
			}
			for(i=1800;i<2120;i+=10)
			{
				duoji3(i);
				delay_ms(20);
			}
			for(i=1550;i<1650;i+=5)
			{
				duoji1(i);
				delay_ms(20);
			}
			for(i=1650;i<1900;i+=10)
			{
				duoji1(i);
				delay_ms(20);
			}
			for(i=1900;i<2300;i+=25)
			{
				duoji1(i);
				delay_ms(20);
			}
//			delay_ms(1000);
			cha=27;
//		cha++;
	}
	while(cha==27)//后退然后左拐
	{
		static int u=0;
		while(u==0)
		{
			while(1)
			{
				if(fabs(yaw)<89)
				{
						guaiwan(20,20,40,40,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>91)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(20,20,40,42,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=91&&fabs(yaw)>=89)
				{
						xiaohoutui();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(GD3!=0)
				{
						int i;
						ting();
						for(i=2200;i>1600;i-=25)
						{
							duoji3(i);
							delay_ms(20);
						}
						for(i=2200;i>1650;i-=30)
						{
							duoji1(i);
							delay_ms(20);
						}
						for(i=1600;i>900;i-=20)
						{
							duoji3(i);
							delay_ms(20);
						}
						u=1;
						break;
				}
			}
		}
		while(u==1)
		{
			while(GD1!=0)
			{
//				jiance();
			if(fabs(yaw)<89)
				{
						guaiwan(20,20,40,40,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>91)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(20,20,40,42,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=91&&fabs(yaw)>=89)
				{
						xiaohoutui();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
			}
			u+=1;
		}
		while(u==2)
		{
	//		jiance();
		//	houchaomanxun();
			if(GD1==0)
			{
				ting();
				jiaodu();
				while(fabs(yaw)>30)
				{
					jiaodu();
					zuoguai();
				}
				while(fabs(yaw)>20)
				{
					jiaodu();
					xiaozuoguai();
				}
				ting();
				delay_ms(200);
//				jiance();
				qianjin();
				delay_ms(500);
				while(moni15!=0&&moni16!=0&&moni17!=0)
				{
					jiance();
					xiaozuoguai();
				}
				u=3;
			}
		}
		while(u==3)
		{
//			jiance();
			xiaozuoguai();
//			if(moni15==0||moni16==0||moni17==0)
//			{
//				ting();
				u++;
				cha++;
//			}
		}
	}
	while(cha==28)//前进然后zuo拐
	{
//		jiance();
		qianmanxun();
		if(qianzonghe<=2)
		{
			while(qianzonghe<=2)
			{
				jiance();
				xiaoqianjin();
			}
			while(GD2!=0)
			{
				jiance();
				xiaoqianjin();
			}
			ting();
			delay_ms(50);
			if(GD2!=0)
			{
				while(GD2!=0)
				{
					jiance();
					xiaohoutui();
				}
			}
			while(moni18!=0)
			{
				jiance();
				zuoguai();
			}
			while(moni18==0)
			{
				jiance();
				xiaozuoguai();
			}
			ting();
			delay_ms(100);
			while(1)
			{
				jiance();
				xiaozuoguai();
				if(moni15==0||moni16==0)
				{
					ting();
					cha++;
					break;
				}
			}
		}
	}
	while(cha==29)//前进然hou ting
	{
		jiance();
		qianmanxun();
		if(qianzonghe<=2)
		{
//			while(houzonghe!=7)
//			{
//				jiance();
//				qianjin();
//			}
			while(GD2!=0)
				qianjin();
			delay_ms(800);
			while(1)
			{
				ting();
			}
		}
	}
		
		
}

void chafang2()
{
	while(cha==0)//前进然后左拐
	{
		static int u=9;
		while(u==9)
		{
			qianjin();
			if(GD1==0||GD2==0)
			{
				u=0;
			}
			
		}
		while(u==0)
		{
//			jiance();
			qianchaomanxun();
			if(qianzonghe<=2)
			{
				u=1;
			}
		}
		while(u==1)
		{
			xiaoqianjin();
			if(GD2==0)
			{
				ting();
				u=2;
			}
		}
		while(u==2)
		{
			xiaozuoguai();
//			jiance();
			if(moni18==0)
			{
				while(moni18==0)
				{
//					jiance();
					xiaozuoguai();
				}
				delay_ms(100);
				u=3;
				ting();
			}
		}
		while(u==3)
		{
			xiaozuoguai();
//			jiance();
			if(moni15==0||moni16==0)
			{
				u=4;
				cha=1;
			}
		}
	}
	while(cha==1)//前进然后右拐
	{
//		jiance();
		qianchaomanxun();
		if(qianzonghe<=2)
		{
			while(qianzonghe<=2)
			{
//				jiance();
				xiaoqianjin();
			}
			
			
			while(GD2!=0)
			{
				xiaoqianjin();
			}
			ting();
			delay_ms(200);
			
			chushihua();
			ting();
//			jiance();
			while(moni18!=0)
			{
//				jiance();
				youguai();
			}
			ting();
			delay_ms(200);
			while(moni14!=0&&moni13!=0&&moni12!=0&&moni11!=0)
			{
//				jiance();
				xiaoyouguai();
			}
			ting();
			cha=2;
			break;
		}
	}
	while(cha==2)//xunjin然后查房
	{
		static int u=1;
//		jiance();

		while(u==1)
		{
//			jiance();
			qianchaomanxun();
			if(qianzonghe==8)
			{
//				jiance();
				if(qianzonghe==8)
				{
					u=2;
				}
				else
				{
					continue;
				}
			}
		}
		beep=1;
		while(u==2)
		{
//			jiance();
			while(1)
			{
				if(fabs(yaw)<89.5)
				{
						guaiwan(30,30,20,20,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(30,30,20,22,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaoqianjin();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
//				jiance();
				if(GD3==0)
				{
				//	ting();
					beep=0;
					u=3;
					break;
				}
			}
		}
		while(u==3)
		{
			beep=0;
			while(qianzonghe==8)
			{
	//			jiance();
				if(fabs(yaw)<89.5)
				{
						guaiwan(30,30,20,20,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(30,30,20,22,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaoqianjin();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
			}
			u=6;
		}
		while(u==6)
		{
			ting();
			delay_ms(1000);
			laba();
			delay_ms(6500);
			u++;
			cha=3;
		}
	}
	while(cha==3)//后退然后右拐
	{
		static int u=0;
		while(u==0)
		{
			while(1)
			{
				if(fabs(yaw)<89.5)
				{
						guaiwan(20,20,40,40,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(20,20,40,42,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaohoutui();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
//				jiance();
//				if(houzonghe!=7)
				if(GD2==0)
				{
					ting();
					u=2;
					break;
				}
			}
		}
		while(u==2)
		{

			jiaodu();	
			
			while(fabs(yaw)<135)
			{
				youguai();
				jiaodu();
			}
			ting();
			delay_ms(100);
			qianjin();
			delay_ms(400);
			while(1)
			{
				xiaoyouguai();
//				jiance();
				if(moni15==0||moni14==0||moni13==0||moni12==0)
				{
					u++;
					cha=4;
					break;
				}
			}
		}
	}	
	while(cha==4)//前进然后前进	
	{
//		jiance();
		qianmanxun();
		if(qianzonghe<2)
		{
			while(qianzonghe<4)
			{
//				jiance();
				qianjin();
			}
				cha++;
		}
	}
	while(cha==5)//前进然后左拐
	{
//		jiance();
		qianchaomanxun();
		if(qianzonghe<2)
		{
			
			while(GD1!=0)
			{
				xiaoqianjin();
			}
			ting();
			
			ting();
			delay_ms(100);
			chushihua();
//			jiance();
			 jiaodu();
			while(yaw<60)
			{
				guaiwan(95,40,95,40,-1,1,-1,1);
				jiaodu();
			}
			ting();
			delay_ms(200);
			while(yaw<88)
			{
				guaiwan(60,40,20,22,-1,1,-1,1);
				//xiaozuoguai();
				jiaodu();
			}
//			while(houzonghe!=7)
//			{
//				houjiance();
//				guaiwan(30,30,70,72,-1,1,-1,1);
////				guaiwan(30,30,70,72,-1,1,-1,1);
//			}
//			ting();
//			delay_ms(200);
//			while(moni26!=0||moni27!=0&&moni28!=0)
//			{
//				jiance();
//				guaiwan(30,30,70,72,-1,1,-1,1);
//			}
//			while(houzonghe!=7)
//			{
//				jiance();
//				xiaohoutui();
//			}
//			while(moni25!=0)
//			{
//				jiance();
//				guaiwan(30,30,70,72,-1,1,-1,1);
//			}

//			TIM6->CNT=0;
//			TIM_Cmd(TIM6,ENABLE);
//			e=0;
//			while(1)
//			{
//				if(e>200)
//					break;
//				beep=1;
//				jiance();
//				e++;
//				if(moni22==1&&(moni24==0)&&moni27==1)
//				{	
//					xiaohoutui();
//				}	
//				if(moni22==1&&moni24==1&&moni25==0&&moni27==1)//youguai
//				{
//					houguaiwan(40,30,40,30,1,-1);
//				}		
//				
//				else if(moni24==1&&moni25==1&&moni26==0&&moni28==1)//中右拐
//				{
//						houguaiwan(40,30,40,30,1,-1);		
//				}		

//				else if(moni24==1&&moni25==1&&moni26==1&&moni27==0)//da右拐
//				{
//					houguaiwan(30,30,30,30,1,-1);
//				}
//					else if(moni24==1&&moni25==1&&moni26==1&&moni27==1&&moni28==0)//da右拐
//				{
//					houguaiwan(30,40,30,40,1,-1);
//				}
//					
//				else if(moni22==1&&moni23==0&&moni25==1&&moni26==1)//xiao左拐弯
//							houguaiwan(30,40,30,40,-1,1);
//						
//				else if(moni22==0&&moni24==1&&moni25==1&&moni27==1)//zhong左拐弯
//							houguaiwan(45,30,45,30,-1,1);
//				houchaomanxun();
//			}
//			qianjin();
//			while(qianzonghe!=7)
//			{
//				jiance();
//				qianchaomanxun();
//			}
			beep=0;
			cha++;
		}
	}
	while(cha==6)//前进查房
	{
		jiaodu();
		while(1)
		{
		
			static int l=0;
				beep=1;
			if(l==0)
			{
				l++;
				jiaodu();
			}
			if(yaw>=89&&yaw<=91)
			{
				xiaoqianjin();
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
				l++;
			}
			if(yaw<89)
			{
				l++;
				guaiwan(35,35,20,22,-1,1,-1,1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(yaw>90)
			{
				l++;
				guaiwan(35,35,20,20,1,-1,1,-1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(l>600)
				break;
		}
//		jiance();
		while(GD3!=0)
		{
//			jiance();
			if(yaw>=89&&yaw<=91)
			{
				xiaoqianjin();
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(yaw<89)
			{
				guaiwan(35,35,20,22,-1,1,-1,1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(yaw>90)
			{
				guaiwan(35,35,20,20,1,-1,1,-1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
		}
		beep=0;
		while(qianzonghe==8)
		{
//			jiance();
			if(yaw>=89&&yaw<=91)
			{
				xiaoqianjin();
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(yaw<89)
			{
				guaiwan(35,35,20,22,-1,1,-1,1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(yaw>90)
			{
				guaiwan(35,35,20,20,1,-1,1,-1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
		}
		ting();
		delay_ms(1000);
		laba();
		delay_ms(6500);
		cha++;
	}
	while(cha==7)//后退然后左拐
	{
		static int u=0;
		jiance();
		while(u==0)
		{
			while(GD1!=0)
			{
//				jiance();
			if(fabs(yaw)<89)
				{
						guaiwan(20,20,40,40,-1,1,-1,1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>91)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(20,20,40,42,1,-1,1,-1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=91&&fabs(yaw)>=89)
				{
						xiaohoutui();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
			}
			u+=1;
		}
		while(u==1)
		{
	//		jiance();
		//	houchaomanxun();
			if(GD1==0)
			{
				ting();
				jiaodu();
				while(yaw<150)
				{
					jiaodu();
					zuoguai();
				}
				qianjin();
				delay_ms(400);
				ting();
				delay_ms(200);
//				jiance();
				while(moni15!=0&&moni16!=0&&moni17!=0&&moni18!=0)
				{
//					jiance();
					xiaozuoguai();
				}
				u=2;
			}
//			if(houzonghe<=4&&moni28==0)
//			{
//				while(houzonghe<=5)
//				{
//					jiance();
//					xiaohoutui();
//				}
//				while(GD1!=0)
//				{
//					jiance();
//					houchaomanxun();
//				}
//				while(moni18!=0)
//				{
//					jiance();
//					zuoguai();
//				}
//				while(moni18==0)
//				{
//					jiance();
//					zuoguai();
//				}
//				u=2;
//				break;
//			}
		}
		while(u==2)
		{
//			jiance();
			xiaozuoguai();
			if(moni15==0||moni16==0||moni17==0)
			{
				ting();
				u++;
				cha++;
			}
		}
	}
	while(cha==8)//前进然后zuoguai
	{
//		jiance();
		qianmanxun();
		if(qianzonghe<=2)
		{
			while(qianzonghe<=2)
			{
//				jiance();
				xiaoqianjin();
			}
			while(GD2!=0)
			{
//				jiance();
				xiaoqianjin();
			}
			beep=1;
			ting();
			delay_ms(50);
			if(GD2!=0)
			{
				while(GD2!=0)
				{
					jiance();
					xiaohoutui();
				}
			}
			while(moni18!=0)
			{
//				jiance();
				zuoguai();
			}
			while(moni18==0)
			{
				
//				jiance();
				zuoguai();
			}
			delay_ms(50);
			ting();
			delay_ms(100);
			while(1)
			{
				beep=0;
				jiance();
				xiaozuoguai();
				if(moni15==0||moni16==0)
				{
					beep=0;
					ting();
					cha++;
					break;
				}
			}
		}
	}
	while(cha==9)//前进然后ting
	{
		jiance();
		qianmanxun();
		if(qianzonghe<=2)
		{
//			while(houzonghe!=7)
//			{
//				jiance();
//				qianjin();
//			}
			while(GD2!=0)
				qianjin();
			delay_ms(800);
			cha++;
		}
	}
	while(cha==10)//停（）
	{
		ting();
		delay_ms(2000);
		cha++;
	}
	///
	
	
	///
	
	
	///
	while(cha==11)//后退
	{
//		beep=1;
		while(GD1!=0&&GD2!=0)
			houtui();
//		jiance();
//		while(houzonghe==7)
//		{
//			jiance();
//			houtui();
//		}
//		while(houzonghe<=5)
//		{
//			jiance();
//			houtui();
//		}
//		delay_ms(100);
		cha++;
		
	}
	while(cha==12)//后退然后左拐
	{
		beep=0;
		jiance();
		houchaomanxun();
		if(houzonghe<=2)
		{
//			beep=1;
			while(GD2!=0)
			{
				xiaohoutui();
			}
			ting();
			delay_ms(100);
//			jiance();
			while(moni18!=0)
			{
//				qianjiance();
				zuoguai();
			}
			while(moni18==0)
			{
//				qianjiance();
				zuoguai();
			}
			//delay_ms(100);
			ting();
			delay_ms(200);
			while(moni15!=0&&moni16!=0&&moni17!=0)
			{
//				qianjiance();
				xiaozuoguai();
			}
			cha++;
		}
	}
	while(cha==13)//前进然后右拐
	{
//		jiance();
		qianchaomanxun();
		if(qianzonghe<=2)
		{
			while(GD2!=0)
			{
				xiaoqianjin();
			}
			ting();
			delay_ms(100);
//			jiance();
			while(moni18!=0)
			{
//				jiance();
				youguai();
			}
			ting();
			delay_ms(200);
			while(moni14!=0&&moni13!=0&&moni12!=0)
			{
//				jiance();
				xiaoyouguai();
			}
			TIM_Cmd(TIM7, DISABLE);
			cha++;
		}
	}
	while(cha==14)//前进然后抓取
	{
		static int l=0;
		while(l==0)
		{
			s=ceju();
			if(s<23)////s<25
			{
				l=1;
				break;
			}
//			qianjiance();
			qianchaomanxun();
		}
//		xiaohoutui();
//		delay_ms(100);
		while(l==1)
		{
			houjiance();
			if(houzonghe<=5)
				xiaohoutui();
			if(GD2==0)
			{
				l=2;
				ting();
				shunazhunbei();
				break;
			}
			houchaomanxun();
		}
		while(l==2)
		{
//			while(GD3!=0)
//			{
//				qianchaomanxun();
//			}
			s=ceju();
			if(s<=31)
			{
				l=3;
				ting();
				duoji3(700);
		delay_ms(500);
				break;
			}
			jiance();
			qianchaomanxun();
		}
		while(l==3)
		{
			int i;
			ting();
			for(i=2400;i>1550;i-=20)
			{
				duoji1(i);
				delay_ms(20);
			}
			for(i=550;i<700;i+=20)//800
			{
				duoji4(i);
				delay_ms(20);
			}
			
			l++;
			cha++;
		}
	}
	while(cha==15)//后退然后右拐
	{
		int i;
		TIM_Cmd(TIM6, ENABLE);
		jiance();
		houchaomanxun();
		if(houzonghe<=4)
		{
			xiaohoutui();
		}
		if(GD2==0)
		{
			ting();
			for(i=820;i<1850;i+=25)
			{
				duoji2(i);
				delay_ms(20);
			}
			for(i=700;i<850;i+=25)
			{
				duoji3(i);
				delay_ms(20);
			}
			for(i=700;i<2450;i+=25)
			{
				duoji4(i);
				delay_ms(20);
			}
			delay_ms(100);
//			jiance();
			while(moni11!=0)
			{
//				jiance();
				youguai();
				
			}
			while(moni11==0)
			{
				youguai();
			}
			delay_ms(60);
			ting();
			delay_ms(100);
			while(moni14!=0&&moni13!=0)
			{
//				jiance();
				xiaoyouguai();
			}
			cha++;
		}
	}
	while(cha==16)//前进然后后退
	{
//		jiance();
		qianchaomanxun();
		if(qianzonghe<=2)
		{
			ting();
			delay_ms(100);
			xiaoqianjin();
			while(1)
			{
					jiance();
					houchaomanxun();
					if(houzonghe<=2)
					{
						while(GD2!=0)
						{
							xiaohoutui();
						}
						ting();
						delay_ms(200);
						chushihua();
						while(moni11!=0)
						{
							youguai();//youguai();
						}
						while(moni11==0)
							youguai();
						ting();
						delay_ms(200);
						qianjin();
						delay_ms(200);
						jiaodu();
						while(fabs(yaw)<88)
						{
							xiaoyouguai();
							jiaodu();
						}
						ting();
						cha++;
						break;
					}
			}	
			
			
		}
	}
	while(cha==17)//前进然后放下
	{
		jiaodu();
		while(1)
		{
			static int l=0;
				beep=1;
			if(l==0)
			{
				l++;
				jiaodu();
			}
			if(fabs(yaw)>=89&&fabs(yaw)<=91)
			{
				xiaoqianjin();
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
				l++;
			}
			if(fabs(yaw)<89)
			{
				l++;
				guaiwan(35,35,20,22,1,-1,1,-1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(fabs(yaw)>91)
			{
				l++;
				guaiwan(35,35,20,20,-1,1,-1,1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(GD3==0)
				break;
		}
		s=ceju();
//		jiance();
		beep=0;
		while(s>15)
		{
			
//			jiance();
			if(fabs(yaw)>=89&&fabs(yaw)<=91)
			{
				xiaoqianjin();
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(fabs(yaw)<89)
			{
				guaiwan(31,31,20,22,1,-1,1,-1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			if(fabs(yaw)>91)
			{
				guaiwan(31,31,20,20,-1,1,-1,1);
				while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
			}
			s=ceju();
		}
		ting();
		cha++;
	}
	while(cha==18)//fang xia
	{
		int i;
			ting();
			for(i=900;i<1800;i+=20)
			{
				duoji3(i);
				delay_ms(20);
			}
			for(i=1850;i>820;i-=20)
			{
				duoji2(i);
				delay_ms(20);
			}
			for(i=1800;i<2120;i+=10)
			{
				duoji3(i);
				delay_ms(20);
			}
			for(i=1550;i<1650;i+=5)
			{
				duoji1(i);
				delay_ms(20);
			}
			for(i=1650;i<1900;i+=10)
			{
				duoji1(i);
				delay_ms(20);
			}
			for(i=1900;i<2300;i+=25)
			{
				duoji1(i);
				delay_ms(20);
			}
		cha++;
	}
	while(cha==19)//后退然后左拐
	{
		static int u=0;
//		jiance();
		while(u==0)
		{
			while(1)
			{
				if(fabs(yaw)<89)
				{
						guaiwan(20,20,40,40,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>91)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(20,20,40,42,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=91&&fabs(yaw)>=89)
				{
						xiaohoutui();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(GD3!=0)
				{
					int i;
					ting();
					for(i=2200;i>1600;i-=25)
					{
						duoji3(i);
						delay_ms(20);
					}
					for(i=2200;i>1650;i-=30)
					{
						duoji1(i);
						delay_ms(20);
					}
					for(i=1600;i>900;i-=20)
					{
						duoji3(i);
						delay_ms(20);
					}
					break;
				}
			}
			while(GD1!=0)
			{
//				jiance();
			if(fabs(yaw)<89)
				{
						guaiwan(20,20,40,40,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>91)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(20,20,40,42,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=91&&fabs(yaw)>=89)
				{
						xiaohoutui();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
			}
			u+=1;
		}
		while(u==1)
		{
	//		jiance();
		//	houchaomanxun();
			if(GD1==0)
			{
				ting();
				jiaodu();
				while(fabs(yaw)>30)
				{
					jiaodu();
					zuoguai();
				}
				while(fabs(yaw)>20)
				{
					jiaodu();
					xiaozuoguai();
				}
				ting();
				delay_ms(200);
				qianjin();
				delay_ms(300);
//				jiance();
//				while(moni15!=0&&moni16!=0&&moni17!=0)
//				{
//					jiance();
//					xiaozuoguai();
//				}
				u=2;
			}
		}
		while(u==2)
		{
			jiance();
			xiaozuoguai();
			if(moni15==0||moni16==0||moni17==0)
			{
				ting();
				u++;
				cha++;
			}
		}
	}
	while(cha==20)//前进然后后退左拐
	{
		static int u=0;
		while(u==0)
		{
			qianchaomanxun();
			if(qianzonghe<=2)
			{
				xiaohoutui();
				houjiance();
				u=1;
			}
		}
		while(u==1)
		{
			houjiance();
			houchaomanxun();
			if(houzonghe<=2)
			{
				while(GD2!=0)
					xiaohoutui();
				u++;
				
			}
		}
		while(u==2)
		{
			ting();
			delay_ms(200);
			while(moni18!=0)
				zuoguai();
			while(moni18==0)
				zuoguai();
			ting();
			delay_ms(200);
			while(moni15!=0&&moni16!=0&&moni17!=0)
				xiaozuoguai();
			u++;
			cha++;
		}
	}
	while(cha==21)//qianjin zhuaqu
	{
		static int l=0;
		while(l==0)
		{
			s=ceju();
			if(s<23)
			{
				l=1;
				xiaohoutui();
				delay_ms(600);
				break;
			}
//			qianjiance();
			qianchaomanxun();
		}
		
		while(l==1)
		{
			houjiance();
			if(houzonghe<=5)
				xiaohoutui();
			if(GD2==0)
			{
				l=2;
				ting();
				shunazhunbei();
				break;
			}
			houchaomanxun();
		}
		while(l==2)
		{
			s=ceju();
			if(s<=18.2)
			{
				l=3;
				ting();
				duoji3(700);
		delay_ms(500);
				break;
			}
			jiance();
			qianchaomanxun();
		}
		while(l==3)
		{
			int i;
			ting();
			for(i=2400;i>1550;i-=20)
			{
				duoji1(i);
				delay_ms(20);
			}
			for(i=550;i<700;i+=20)//800
			{
				duoji4(i);
				delay_ms(20);
			}
			
			l++;
			cha++;
		}
	}
	while(cha==22)//后退然后右拐
	{
		TIM_Cmd(TIM7, ENABLE);
		jiance();
		houchaomanxun();
		if(houzonghe<=4)
		{
			xiaohoutui();
		}
		if(GD2==0)
		{
			int i;
			ting();
			for(i=820;i<1850;i+=25)
			{
				duoji2(i);
				delay_ms(20);
			}
			for(i=700;i<850;i+=25)
			{
				duoji3(i);
				delay_ms(20);
			}
			for(i=700;i<2450;i+=25)//800
			{
				duoji4(i);
				delay_ms(20);
			}
			delay_ms(100);
//			jiance();
			while(moni11!=0)
			{
//				jiance();
				youguai();
				
			}
			while(moni11==0)
				youguai();
			delay_ms(200);
			ting();
			delay_ms(200);
			while(moni14!=0&&moni13!=0&&moni12!=0)
			{
//				jiance();
				xiaoyouguai();
			}
			cha++;
		}
	}
	while(cha==23)//qianjin然后前进
	{
//		qianjiance();
		qianmanxun();
		if(qianzonghe<=2)
		{
			while(qianzonghe<5)
			{
//				jiance();
				qianjin();
			}
			cha++;
		}
	}
	while(cha==24)//qianjin然后右拐
	{
//		jiance();
		qianchaomanxun();
		if(qianzonghe<=2)
		{
			while(qianzonghe<=2)
			{
//				jiance();
				xiaoqianjin();
			}
			
			
			while(GD2!=0)
			{
				xiaoqianjin();
			}
			ting();
			ting();
			delay_ms(100);
			
			chushihua();
//			jiance();
			while(moni18!=0)
			{
				jiance();
				youguai();
			}
			ting();
			delay_ms(200);
			qianjin();
			delay_ms(400);
//			while(moni14!=0&&moni13!=0&&moni12!=0&&moni11!=0)
//			{
////				jiance();
//				xiaoyouguai();
//			}
			jiaodu();
			while(fabs(yaw)<88)
			{
				jiaodu();
				youguai();
			}
			ting();
//			houtui();
//			delay_ms(100);
			cha=25;
			break;
		}
		
	}
	while(cha==25)//前进然后放下
	{
		static int u=5;
//		jiance();

//		while(u==1)
//		{
////			jiance();
//			qianchaomanxun();
//			if(qianzonghe==8)
//			{
////				jiance();
//				if(qianzonghe==8)
//				{
//					u=5;
//				}
//				else
//				{
//					continue;
//				}
//			}
//		}
		while(u==5)
		{
			while(1)
			{
				if(fabs(yaw)<89.5)
				{
						guaiwan(33,33,22,22,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(33,33,20,22,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaoqianjin();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
//				jiance();
				if(GD3==0)
				{
					ting();
					u=2;
					break;
				}
			}
		}

		while(u==2)
		{
			
//			jiance();
			while(1)
			{
				s=ceju();
				if(fabs(yaw)<89)
				{
						guaiwan(30,30,20,20,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>91)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(30,30,20,22,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=91&&fabs(yaw)>=89)
				{
						xiaoqianjin();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
//				jiance();
				if(s<=15)
				{
					ting();
					u=3;
					break;
				}
			}
		}
		while(u==3)
		{
			int i;
			ting();
			for(i=900;i<1800;i+=20)
			{
				duoji3(i);
				delay_ms(20);
			}
			for(i=1850;i>820;i-=20)
			{
				duoji2(i);
				delay_ms(20);
			}
			for(i=1800;i<2120;i+=10)
			{
				duoji3(i);
				delay_ms(20);
			}
			for(i=1550;i<1650;i+=5)
			{
				duoji1(i);
				delay_ms(20);
			}
			for(i=1650;i<1900;i+=10)
			{
				duoji1(i);
				delay_ms(20);
			}
			for(i=1900;i<2300;i+=25)
			{
				duoji1(i);
				delay_ms(20);
			}
//			delay_ms(1000);
			u++;
			cha=26;
		}
	}
	while(cha==26)//后退然后右拐
	{
		static int u=0;
		while(u==0)
		{
			while(1)
			{
				if(fabs(yaw)<89.5)
				{
						guaiwan(20,20,40,40,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(20,20,40,42,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaohoutui();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(GD3!=0)
				{
					int i;
					ting();
					for(i=2200;i>1600;i-=25)
					{
						duoji3(i);
						delay_ms(20);
					}
					for(i=2200;i>1650;i-=30)
					{
						duoji1(i);
						delay_ms(20);
					}
					for(i=1600;i>900;i-=20)
					{
						duoji3(i);
						delay_ms(20);
					}
					break;
				}
			}
			while(1)
			{
				if(fabs(yaw)<89.5)
				{
						guaiwan(20,20,40,40,1,-1,1,-1);//guaiwan(70,70,70,70,-1,1,-1,1);
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
				if(fabs(yaw)>90.5)
				{
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0)
								guaiwan(20,20,40,42,-1,1,-1,1);//guaiwan(65,65,65,65,1,-1,1,-1);
				}
				if(fabs(yaw)<=90.5&&fabs(yaw)>=89.5)
				{
						xiaohoutui();
					while(mpu_dmp_get_data(&pitch,&roll,&yaw)!=0);
					
				}
//				jiance();
//				if(houzonghe!=7)
				if(GD2==0)
				{
					ting();
					u=2;
					break;
				}
			}
		}
		while(u==2)
		{

			jiaodu();	
			
			while(fabs(yaw)<135)
			{
				youguai();
				jiaodu();
			}
			ting();
			delay_ms(100);
			qianjin();
			delay_ms(250);
			while(1)
			{
				xiaoyouguai();
//				jiance();
				if(moni15==0||moni14==0||moni13==0)
				{
					u++;
					cha=27;
					break;
				}
			}
		}
	}
	while(cha==27)//前进然后右拐
	{
		qianmanxun();
		if(qianzonghe<=2)
		{
			while(qianzonghe<5)
				qianjin();
			while(GD2!=0)
			{
				qianchaomanxun();
			}
			ting();
			delay_ms(200);
			while(moni11!=0)
			{
				youguai();
			}
			while(moni11==0)
				youguai();
			xiaoyouguai();
			delay_ms(100);
			ting();
			delay_ms(200);
			while(moni14!=0&&moni13!=0)
			{
				xiaoyouguai();
			}
			cha++;
		}
	}
	while(cha==28)//前进然后停
	{
		qianmanxun();
		if(qianzonghe<=2)
		{
			while(GD2!=0)
			{
//				jiance();
				qianjin();
			}
			delay_ms(800);
			while(1)
			{
				ting();
			}
		}
	}
}

