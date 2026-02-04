#include <stdio.h>
#include <string.h>
int main()
{
    //char arr[] = {'a','b','c','d','e','f'};
    // printf("%d\n", sizeof(arr));//6整个数组的长度
    // printf("%d\n", sizeof(arr+0));//8相当于&arr[0]+0
    // printf("%d\n", sizeof(*arr));//1相当于a[0]
    // printf("%d\n", sizeof(arr[1]));//1
    // printf("%d\n", sizeof(&arr));//8地址的长度
    // printf("%d\n", sizeof(&arr+1));//8，但其地址比&a[0]大一个数组的长度
    // printf("%x\n", &arr[0]);
    // printf("%x\n", &arr[0]+1);//1，其地址比&a[0]大一个元素的长度
    //
    // printf("%d\n", strlen(arr));//随机数 无'\0'结尾
    // printf("%d\n", strlen(arr+0));//随机数 地址
    // printf("%d\n", strlen(*arr));//无 无'\0'结尾
    // printf("%d\n", strlen(arr[1]));//无 无'\0'结尾
    // printf("%d\n", strlen(&arr));//随机数 地址
    // printf("%d\n", strlen(&arr+1));//随机数 地址
    // printf("%d\n", strlen(&arr[0]+1));//随机数 地址


    //char arr1[] = "abcdef";
    // printf("%d\n", sizeof(arr1));//7 加上'\0'
    //printf("%d\n", sizeof(arr1+0));//8 地址相当于&arr1[0]+0
    // printf("%d\n", sizeof(*arr1));//1 相当于arr1[0]
    // printf("%d\n", sizeof(arr1[1]));//1
    // printf("%d\n", sizeof(&arr1));//8 地址
    // printf("%d\n", sizeof(&arr1+1));//8 地址，比&arr1[0]大一个数组的大小
    // printf("%d\n", sizeof(&arr1[0]+1));//8 比&arr1[0]大1


    //printf("%d\n", strlen(arr1));//6 省去'\0'
    //printf("%d\n", strlen(*arr1));//无 指的是arr1[0],无'\0'
    // printf("%d\n", strlen(arr1[1]));//无 无'\0'
    //printf("%d\n", strlen(&arr1+1));//无 是地址 加一个数组的长度
    //以下四条均可输出，+n相当于编译器从arr1[0+n]开始数，一直到'\0'结束
    // printf("%d\n", strlen(arr1));//6
    // printf("%d\n", strlen(arr1+2));
    //printf("%d\n", strlen(&arr1));//6
    //printf("%d\n", strlen(&arr1[0]+1));//5




    char *p = "abcdef";//可看作char p[] = "abcdef"
    //printf("%x\n", p);//8 地址
    //printf("%x\n", p+1);//8 地址，比&p[0]大1
    // printf("%d\n", sizeof(*p));//1 指的是第一个元素
    // printf("%d\n", sizeof(p[0]));//1 第一个元素
    // printf("%d\n", sizeof(&p));//8 指针的地址
    // printf("%d\n", sizeof(&p+1));//8 指针的地址+8
    // printf("%d\n", sizeof(&p[0]+1));//8 指的是字符数组第一个元素地址+1

    //printf("%d\n", strlen(p));//**6 是字符串 相当于&p[0]
    // printf("%d\n", strlen(p+1));//5 从第二个元素开始数 &p[1]
    // printf("%d\n", strlen(*p));//无 指的是第一个元素
    // printf("%d\n", strlen(p[0]));//无 少'\0'
    //printf("%d\n", strlen(&p+2));//无，地址+两个指针的长度
    //printf("%d\n", strlen(&p+1));//无 地址+一个指针的长度
    //printf("%d\n", strlen(&p[0]+1));//5 从字符串的第两个元素开始数

    return 0;

}