//运算符 = + ，算子 1 2 a b
//计算时间差
#include <stdio.h>

int main() {
//算法
    // int hour1 ,minute1;
    // int hour2 ,minute2;

    // printf("输入两个时间：");
    // scanf("%d %d" ,&hour1 ,&minute1);
    // scanf("%d %d" ,&hour2 ,&minute2);
    
    // //换算成最小单位分钟
    // int cha =0;
    // cha = hour1*60 + minute1 - (hour2*60 + minute2);
    // printf("两时间的差值是：%d小时%d分钟", cha/60 ,cha%60);
//运算符顺序
    //单目不变 + 单目取负- 如 a*-b
    //赋值运算符 自右向左
//交换变量
//复合赋值
    // += -= *= %=
    //total *= sum + 12; total = total* (sum + 12);
    // ++ --
        //前缀 ++a a+1
        //后缀 a++ a
    int a =10;

    printf("a++=%d\n", a++);
    printf("a=%d\n", a);
    printf("++a=%d\n", ++a);
    printf("a=%d\n", a);
    //++--  ++i++ 

/// pintia.cn
    return 0;


}