#include <stdio.h>
int main()
{
    int a[] = {1,2,3,4};//数组在一定程度上就是指针
    // printf("%d\n",sizeof(a));//**16整个数组的长度
    // printf("%d\n",sizeof(a+0));//**8相当于&a[0],&a
    // printf("%d\n",sizeof(*a));//4相当于a[0]
    // printf("%d\n",sizeof(a+1));//**8相当与&a[0]+1
    // printf("%d\n",sizeof(&a+1));//**8地址，但是其地址比&a[0]大16,加一加的是整个数组的长度
    // printf("%d\n",sizeof(a[1]));//单个元素的长度4
    // printf("%d\n",sizeof(&a));//地址的长度8
    // printf("%d\n",sizeof(*&a));//整个数组的长度16->*与&抵消
    // printf("%d\n",sizeof(&a[0]));//第一个元素地址的长度8
    // printf("%d\n",sizeof(&a[0]+1));//8
}