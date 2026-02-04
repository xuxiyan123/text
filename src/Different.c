#include<stdio.h>
#include<string.h>

// Created by DELL on 25-9-28.
int main()
{   /*指针与数组的不同点在于在取地址时，&a(数组)是整个数组的长度，而&a(指针)是指针的地址的长度*/
    //在输出printf("%x",p) or printf("%d",sizeof(p + 1))时，会对p进行强制类型转换

    char *p = "abcdef";//可看作char p[] = "abcdef"
    //printf("%d\n", p);//p代表的&p[0]
    //printf("%d\n", &p[0]);//指的是字符数组第一个元素地址
    // printf("%d\n", &p[0]+1);//指的是字符数组第一个元素地址+1
    // printf("%x\n", p+1);//=>&p[0]+1
    // printf("%d\n", *p);//1 指的是第一个元素=>p[0]
    // printf("%d\n", p[0]);//1 第一个元素
    // printf("%d\n", &p);//8 指针的地址
    // printf("%d\n", &p+1);//8 指针的地址+一个指针的长度

    char pp[] = "abcdef";//可看作char p[] = "abcdef"
    //printf("%x\n", pp);//pp代表的&p[0]
    //printf("%x\n", &pp[0]);//指的是字符数组第一个元素地址
    //printf("%x\n", &pp[0]+1);//指的是字符数组第一个元素地址+1
    // printf("%x\n", pp+1);//=>&p[0]+1
    // printf("%c\n", *pp);//1 指的是第一个元素=>p[0]
    // printf("%d\n", pp[0]);//1 第一个元素
    // printf("%x\n", &pp);//8 整个数组的地址
    // printf("%x\n", &pp+1);//8 pp[0]的地址+一个数组的长度
}