/*
int 寄存器宽度

整数的内部表达

补码
    我们希望 -1 + 1 -> 0 如何做到（什么+1 = 0）
    0000 0001 + 1111 1111 = 1 0000 0000 
    或者
    -1 = 0 - 1

    1111 1111 被当作纯二进制看待时，是55， 补码时是-1
    对于-a， 其补码就是 0-a， 实际是 2^n-a

    补码的意义就是拿补码和原码可以加出一个溢出的“零”
    直接加就可以得到结果

数的范围
    对于一个字节（8位），可以表达的是：
        0000 0000 - 1111 1111
    其中
        0000 0000 -> 0
        1111 1111 ~ 1000 0000 -> -1~-128
        0000 0001 ~ 0111 1111 -> 1~127

unsigned
    设计目的 纯二进制运算移位

整数的输入输出
    %d  int 小于int char short int 都可
    %u  unsigned
    %ld long long 大于int
    %lu unsigned

8进制和16进制
    0   %d输出十进制
    0x
    %o  八进制 无前缀
    %x  16进制 无前缀 小写%x输出小写，大写%X输出大写

    8进制与16进制只是如何把数字表达为字符串，与内部如何表达数字无关
    16位适合表示二进制 4位二进制
    8进制一位数字正常表达3位二进制 早期计算机字长12

选择整数类型
    为什么整数那么多种？
        short 早期单片机整数需要、底层程序准确表达内存
    没有特殊需要，int
        现在cpu字长普遍32位或64位，一次内存读写就是一个int，一次计算也是一个int，选择更短的类型不会更快，甚至更慢
        现代编译器一般会设置内存对齐，更短的类型实际在内存中也可能占据一个int大小（虽然sizeof告诉你更小）
        unsigned与否只是输出的不同，内部计算相同
        这些特性与底层硬件相关

浮点类型
    类型    字长    范围    有效数字
    float   32              7       靠近0的范围无法表达 0， +-inf，nan
    double  64              15
浮点的输入输出
    类型    scanf   printf
    float   %f      %f,%e   %e，%E科学计数法
    double  %lf     %f,%e
科学计数法
        -5.67E+16
    可选+-号 可选小数点 可用e或E 符号-或+省略 不可有空格
输出精度
    %.nf小数点后n位
    printf("%.3f\n", -0.0049);
    printf("%.30f\n", -0.0049);
超过范围的浮点数
    printf输出inf表示超过范围的浮点数： +-无穷
    printf输出nan表示不存在的浮点数
    printf("%f\n", 12.0/0.0);
    printf("%f\n", -12.0/0.0);
    printf("%f\n", 0.0/0.0);
    printf("%f\n", 12/0); 报错
浮点运算的精度
    a = 1.345f;
    b = 1.123f;
    c = a + b;
    带小数点的字面量是double而非float
    float需要f或F后缀表明身份

    f1 == f2 可能失败
    fabs(f1 - f2) < 1e-12 绝对值小于精度
    参考：android计算器低级错误 www.guokr.com/article/27173
*浮点数内部表达
    浮点数计算由专用硬件实现
    double与float计算部件相同
选择浮点类型
    没用特殊需要，只使用double
    现代CPU特性， 64位

字符类型
    char是一种整数，也是一种特殊类型：字符
        用单引号表示字符字面量 'a', '1'
        ''也是一个字符
        printf scanf 用%o来输入输出字符
字符的输入输出
    输入'1'字符给 char c
    scanf("%c", &c);
    printf("%d", c); //整数
    printf("‘%c’", c); //字符

    有何不同
    scanf("%d %c",&i, &c);
    scanf("%d%c",&i, &c);
    ' ' = 32
大小写转换
    字母ASCLL顺序排列
    大小写分开排列
    'a' - 'A' = 距离
    a + 'a' - 'A'大写转小写
    a - 'a'+ 'A' 小写转大写
逃逸字符
    \" \" \\ \'
    回退一格    \b 光标回去但不删除，但有的终端shell会删除
    制表位      \t
    回车换行
        源于打字机
        \n 换行
        \r 回车
        shell自动将\n解释为两个动作
自动类型转换
    运算符两边类型不一致，自动较大
    char - short - int - long - longlong
    int - float - double

    printf 小于int 自动转换int
            double 自动转double
    scanf 不会 short %hd
强制类型转换
    (类型)值
    (int)3.2
    (short)32
    注意安全性
    short 32768 -32768  1000 0000 0000 0000

    不改变变量本身，只是解释方式
    强制类型转换优先级高于四则运算



*/
#include <stdbool.h>
#include <stdio.h>

int main ()
{
    //char c = 255;
    // unsigned char c = 255; //不补码
    // int a = 255;

    // printf("%d %d", c, a);
    // 11111111
    // 00000000 00000000 00000000 11111111

    char c;
    char d;
    c = 1;
    d = '1';
    printf("c=%d\n",c);
    printf("d=%d\n",d);
    printf("%c\n", d);

//字符计算
    // char a = 'A';
    // a ++;
    // printf("%d\n", a); //B
    // char b = 'a';
    // printf("%d\n", b);

    // int i = 'Z' - 'A';
    // printf("%d\n", i); //25

//强制类型转换
    // double a = 1.0;
    // double b = 2.0;
    // int i = (int)a/b;
    // int a = 5;
    // int b = 6;
    // double d = (double)(a/b); //先除后转
    // double e = (double)a/b; //先转后除
    // scanf("%c")
    








    return 0;
}