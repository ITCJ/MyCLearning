/*
计算公式近似值1
【问题描述】

已知ex的近似值可由下面公式计算得出：

ex=1 + x/1! + x2/2! + x3/3! + ...... + xn/n!
给定x和n，利用上述公式求得ex的近似值。

【输入形式】

从控制台输入小数x，和整数n（n>=1），用空格隔开。

【输出形式】

向控制台输出求得的ex 的近似值（小数点后保留6位有效数据）。

【样例输入】

7   27

【样例输出】

1096.633156

【样例说明】

输入的x为7，n的值为27，即：求e7的近似值，利用上述公式求得的近似值为：1096.633156。

【评分标准】

该题要求输出ex的近似值，共有5个测试点。上传C语言文件名为formula.c。
*/

#include <stdio.h>

//分数阶乘计算函数xn/n!
//double accCum(int base, double x)
//{
//    double result2 = 1;
//
//    for (int i = 1; i <= base; i++)
//    {
//        result2 *= x / i;
//    }
//    return result2;
//}
//
//int main()
//{
//    double x = 0.0;
//
//    int count = 1;
//    int n;
//    scanf("%lf %d", &x, &n);
//    double result = 0;
//
//    for (int i = 0; i <= n; i++)
//    {
//        result += accCum(i, x);
//    }
//
//    printf("%f", result);
//    return 0;
//}