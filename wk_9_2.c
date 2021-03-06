/*
1+1=2?

指针计算
    +- += - -=v整数
    递加递减 ++/--
    两个指针相减

*p++  
    取出p所指数据，将p移至下一位置
    ++优先级高于*（但p++的结果是p+1前的结果）
    常用于数组类连续空间操作
    在某些cpu，可以被翻译成一条汇编指令

指针比较
    <,<=,==,>,>=<!=
    比较他们在内存中地址
    数组单元地址线性递增

0地址（虚拟）《操作系统》
    0地址不能随便碰
    指针不应该具有0值
    用0地址表示特殊的事情
        返回指针无效
        指针没有被真正初始化，先初始化为0
    NULL（大写）是一个预定义符号，表示0地址
        有的编译器不愿意用0表示0地址（建议用NULL）

指针的类型
    指针的大小都一样，都是地址
    但指向不同类型的指针不能互相赋值
    为了避免用错指针
        如，将int 指针指向char数组，将导致4个char数改变

指针的类型转换
    void* 不知道指向什么东西的指针
        计算时与char*相同（但不相同
    指针也可以转换类型
        int *p = &i; void*q = (void*)p
    这并没有改变p所指变量类型，二十让后人用不同眼光通过p看它所指的变量
    我不再当你是int啦，我认为你就是个void!

    常用于底层、系统程序

用指针来做什么
    传入比较大的数据
    传入数组对数组操作
    函数返回值不止一个结果
        需要函数来修改不止一个变量
    动态的申请内存

动态内存分配


*/
#include <stdio.h>

int main () 
{
//+1 实际上是 +sizeof ()
    char ac[] = {0,1,2,3,4,5,6,7,8,9,-1};
    char *p = ac;
    printf("p = %p\n", p);
    printf("p = %p\n", p+1);
    printf("p = %d\n", *(p+1) );

    int ai[] = {0,1,2,3,4,5,6,7,8,9,};
    int *q = ai;
    printf("q = %p\n", q);
    printf("q = %p\n", q+1);    //跨度4
    printf("q = %d\n", *(q+1) );
    //如果指针不是指向一片连续空间，（数组）无意义

//指针相减
    char *p1 = &ac[5];
    printf("p1 - p = %d\n", p1 - p);    //5

    int *q1 = &ai[5];
    printf("q1 - q = %d", q1 - q);  //6

//*p++
    //for ( p = ac; *p != -1 ; *p++)
    while ( *p != -1 )
    {
        printf("%d\n", *p++);
    }

//指针互相赋值
//指针的类型转换

    return 0;
}