/*
C是有类型的语言
c语言的变量
    在使用前定义
    确定类型
C语言后的两个发展方向
    C++/JAVA 更强调类型，检查更加严格
    JavaScript、Python 、Pho不看重类型，不需要事先定义

类型安全
    强类型观点认为有助于发现程序的简单错误
    反对观点认为过于强调类型迫使程序员面对底层、实现而非事务逻辑
总的来说，早期语言强调类型。面向底层语言强调类型
C需要类型，但对类型安全检查不足够

C语言的类型
    整数
    char、 short、 int 、long 、longlong99
    浮点数
    float 、double、 long double 99
    逻辑
    bool99
    指针
    自定义类型
类型有何不同
    名称
    输入输出格式化 %d %ld %lf
    数的范围：char< short <int < float < double
    内存占用大小：1~16字节
    内存中的表现形式：二进制（补码）、浮点（编码）

sizeof
    sizeof(int)
    静态的

*/

#include <stdio.h>

int main ()
{
    int a;
    a= 6;
    printf("ldouble %ld\n", sizeof(long double));
    printf("a+1.0 %ld\n", sizeof(a + 1.0));
    printf("a=%d\n", a);

    return 0;
}