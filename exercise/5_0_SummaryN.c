/* 前n项和
本题要求编写程序,计算序列 2/1+3/2+5/3+8/5+… 的前N项之和。
注意该序列从第2项起，每一项的分子是前一项分子与分母的和，分母是前一项的分子。

循环n次
第一项
    a =2
    b =1
第二项
    c = a+b
    a
*/
#include <stdio.h>

int main () 
{
    int a = 2;
    int b = 1;
    int c;
    float sum;
    int i, n;
    scanf("%d", &n);

    for ( i = 0; i < n; i++)
    {
        sum += 1.0*a/b;
        c = a;
        a += b;
        b = c;
    }
    printf("%.2f", sum);

    return 0;
}