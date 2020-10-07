/*
动态内存分配malloc() - free()

输入数据
    输入数据时，先告诉你个数然后再输入，激励每个数据
    C99可以用变量做数组定义大小，C99之前呢
    
    int *a = (int*)malloc(n*sizeof(int));

malloc 申请连续内存空间
    #include<stdlib.h>
    void* malloc(size_t size);
    向malloc申请的空间大小是以字节位单位的
    返回的结果是void*，需要类型转换位自己需要的类型
        （int*)malloc(n*sizeof(int))

没空间了
    申请失败返回0，NULL
    系统能给你多大的空间

free()
    将申请的空间还给系统
    申请过的空间，最终都应该还
        出来混的，最后都要换
    只能还申请来空间的首地址
    int i;
    void *p = 0;//赋值好习惯
    int cnt = 0;

    free(NULL);

常见问题
    申请的没free 长时间运行内存逐渐下降
        新手 忘了
        “老手”：找不到合适的free时机
    free过了再free
    地址变过了，直接去free

    附加、设计良好整体架构、经多练验、
*/
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int number;
    int* a;
    int i;//回来再定义

    printf("输入数量：");
    scanf("%d", &number);

    a = (int*)malloc(number*sizeof(int));
    //int a[number];//c99

    for ( i = 0; i < number; i++)
    {
        scanf("%d", &a[i]);
    }
    for ( i = number - 1; i >= 0 ; i--)
    {
       printf("%d", a[i]);//mallic动态内存分配就是一个数组
    }
    free(a);//释放内存
    
    void *p;
    int cnt = 0;
    while ( (p = malloc(100 * 1024*1024)) )
    {
        cnt ++;
    }
    printf("分配了%d00MB的空间\n", cnt);



    return 0;
}