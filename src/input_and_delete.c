//
// Created by DELL on 25-9-17.
//
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int input(int *e,int place,int put);//插入函数
int delete(int *e,int place);//删除函数
int main(void) 
{
	system("chcp 65001");   //加入此行代码可不出现中文乱码
	int a[10] = {1,2,3,4,5,6};
	int *we = &a;
 	int place1,put2;
	printf("输入的是实际位置，从1开始:\n");
	scanf("%d %d",&place1,&put2);//输入的是实际位置，从1开始
	input(we,place1,put2);
	return 0;
}



int input(int *e,int place,int put)//插入函数
{
	int sum = 0;
	int p;
	int y = e[place-1];
	for (int i = 0;e[i] != 0;i++)//判断总共有几位有效数字
		sum++;
	p = sum;
	if (sum != 10)//判断是否爆格
	{
		for (int j = 0;j<=sum-place;j++)//将后一个向后移动一格，为其腾出位置
		{
			e[p] = e[p-1];
			p -= 1;
		}
		e[place-1] = put;
		printf("第%d位本为%d，插入后输出为：%d\n",place,y,e[place-1]);
	}
	else
		printf("This list is full.");
}
int delete(int *e,int place)//删除函数
{
	int sum = 0;
	int p;
	int y;
	y = e[place-1];
	for (int i = 0;e[i] != 0;i++)//判断总共有几位有效数字
		sum++;
	p = place;
	for (int j = 0;j<sum-place;j++)//将后一个向前移动一格
	{
		e[p-1] = e[p];
		p += 1;
	}
	printf("第%d位本为%d，删除后输出为：%d\n",place,y,e[place-1]);
}