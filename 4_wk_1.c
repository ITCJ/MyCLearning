//bool
#include <stdbool.h>
#include <stdio.h>

int main()
{
    bool b = 6>5;
    bool t = true;
    printf("%d\n", b);

//while循环 数位数
    // while ()
    // {

    // }
    //条件成立 执行语句
    //验证 边界、有效范围两端、特殊倍数 //倍数 个位数 10 0 负数
    int x;
    int n = 0;
    scanf("%d, &x");
    
    // n++;
    // x /= 10; //可以处理0
    
    while (x > 0)
    {
        //printf("hr\n"); //调试方法
        n++;
        x /= 10;
        //printf("x=%d, n=%d"); //调试方法
    }
    
    //do while 处理个位数 先做
        // do
        // {
        //     /* code */
        // } while (/* condition */); //注意分号
    
    //循环计算
        //会改变condition
    
    //这些值怎么确定
    int count = 100; //用 count =3 调试
    while (n >=0 )
    {
        count--;
        printf("%d\n", count); //顺序对输出的差别
    }   


    printf("%d\n", n);


    return 0;
}