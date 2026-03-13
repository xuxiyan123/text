#include<REGX52.H>
#include <intrins.h>
#include<data.h>

//注意 使用的是普中51开发板

/*整体思路是 用计时器0来检测按键是否按下，10ms检测一次，按键1，2
开始时begin函数，LED1亮，按下按键1，开始计时，进入过程journey函数
过程使用计时器1，每10ms一次，当按键1按下时，停止计时，
9.97~9.99，10.10~10.30亮LED6
9.99~10.10亮LED6，7
按下按键2返回begin函数
*/

unsigned int count = 0;//按键检测的变量
unsigned int time = 0;//时间
unsigned char byte_0 = 0;//检测按键1是否按下
unsigned char byte_1 = 0;//检测按键2是否按下

void start_0(void);//配置计时器0  改动time,按键的计时器
void start_1(void);//配置计时器1 
void botton(void);//开始按键检测
void begin(void);//开始界面，LED1亮
void journey(void);//过程与结束

void main()
{
	botton();
	begin();//开始界面
  
	while(1);
}	



//开始界面，LED1亮
void begin()
{
	time = 0;
	byte_0=0;
	P2_0 = 0;
	while (byte_0==0);//等待按键1按下
	P2_0 = 1;
	byte_0 = 0;
	journey();//开始计时
}


//按键检测开始
void botton()
{
	EA = 1;//打开中断总开关
	ET0 = 1;//打开计时器0中断开关
	ET1 = 1;//打开计时器1中断开关
	start_0();
}

//过程
void journey()
{
	byte_0 = 0;//一系列的初始化，以防万一
	P2_6 = 1;
	P2_7 = 1;
	start_1();//开启计时
	while (byte_0==0)//刷新数码管，检测按键是否按下
		{
			show_num(1,time/1000);
			show_num(2,(time%1000)/100);
			show_num(3,(time%100)/10);
			show_num(4,time%10);
			show_num(2,10);
		}
	TR1 = 0;//关闭计时器1
	byte_0 = 0;
	byte_1 = 0;
	if (time >=990 && time <= 1010)//成绩评估
		{
			P2_6 = 0;
			P2_7 = 0;
		}
	else if ((time >=970 && time <990) || (time <= 1030  && time > 1010))
		{
			P2_6 = 0;
		}
	//结束，显示成绩
	while (1)
		{
			show_num(1,time/1000);
			show_num(2,(time%1000)/100);		
			show_num(3,(time%100)/10);
			show_num(4,time%10);
			show_num(2,10);
			if (byte_1 == 1)//检测按键2
				{
					byte_1 = 0;
					P2_6 = 1;
					P2_7 = 1;
					begin();//从头开始
				}
		}
}

//配置计时器0  改动time
void start_0()
{
	TMOD = 0x11;//配置gate c/T M1 M0
	TL0 = 55536 % 256;//自增寄存器低位
	TH0 = 55536 / 256;//自增寄存器高位
	TF0 = 0;//清除中断标志位
	TR0 = 1;//打开计时器0

}
//配置计时器1  改动time
void start_1()
{
	//TMOD = 0x11;//配置gate c/T M1 M0
	TL1 = 55536 % 256;//自增寄存器低位
	TH1 = 55536 / 256;//自增寄存器高位	
	TF1 = 0;//清除中断标志位
	TR1 = 1;//打开计时器0
}
//计时器0的中断函数
void inter0(void) interrupt 1
{
	if (P3_1 == 0)//当按键电平发生变化时，进入循环
		{
			while (P3_1==0)//跳过抖动时期
				{
					count++;
					if (count>10)//当探测出连续20次低电平时，认为按下
						{
							if (byte_0 <1)
								{
									byte_0++;
								}
							count = 0;//及时清零
							break;
						}	
				}
			while(P3_1==0);//等待电平重回高点
		}
		
		if (P3_0 == 0)//当按键电平发生变化时，进入循环
		{
			while (P3_0==0)//跳过抖动时期
				{
					count++;
					if (count>10)//当探测出连续20次低电平时，认为按下
						{
							if (byte_1 <1)
								{
									byte_1++;
								}
							count = 0;//及时清零
							break;
						}	
				}
			while(P3_0==0);//等待电平重回高点
		}
		start_0();//若要循环，使用此函数
}	


//计时器1的中断函数
void inter1(void) interrupt 3
{
	time++;
	start_1();
}





