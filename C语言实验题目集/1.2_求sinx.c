/*
【问题描述】

已知sinx的近似计算公式如下：

 sin x = x - x3/3! + x5/5! - x7/7! + ... + (-1)n-1x2n-1/(2n-1)!

 其中x为弧度，n为正整数。编写程序根据用户输入的x和n的值，利用上述近似计算公式计算sinx的近似值，要求输出结果小数点后保留8位。

【输入形式】

从控制台输入小数x（0<=x<=10）和整数n（1<=n<=1000），两数中间用空格分隔。

【输出形式】

控制台输出公式结果：小数点后保留8位。

【样例输入1】

0.5236  4

【样例输出1】

0.50000105

【样例输入2】

0.5236  50

【样例输出2】

0.50000106

【样例说明】

输入x为0.5236，n为4，求得sinx近似计算公式的值为0.50000105，小数点后保留8位；同样，输入x为0.5236，n为50，求得sinx近似计算公式的值为0.50000106，小数点后保留8位。

注意：为保证数据的准确性和一致性，请使用double数据类型保存计算结果。
*/

/*
关键点
    用余数控制正负
    直接计算结果，不单独计算n次幂、阶乘

*/

//#include <stdio.h>
//#include <math.h>
//
//double accCum(int base, double x)
//{
//    double result = 1;
//
//    for (int i = 1; i <= base; i++)
//    {
//        result *= x / i;
//    }
//    return result;
//}
//int main()
//{
//    double x = 0.0;
//    double sin = 0.0;
//    int y = 1;
//    int count = 1;
//    int n;
//    scanf("%lf %d", &x, &n);
//    sin = x;
//
//    while (count < n)
//    {
//        y += 2;
//        double ass[2] = { 1,-1 };
//            // double up = pow(x,y);
//            // double down = (1.0 * accCum(y));
//            // double result = up/down;
//        sin += ass[count % 2] * accCum(y, x);
//        count++;
//    }
//
//    printf("%.8f", sin, n);
//
//    return 0;
//}