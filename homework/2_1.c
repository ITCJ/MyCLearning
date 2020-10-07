#include <stdio.h>
/*
读取半径r
输出面积、周长、体积
*/
int main ()
{
    const float PI = 3.1415926;
    int r;
    float S, C, V;

    printf("请输入一个半径：______\b\b\b");
    scanf("%d", &r);

    S = PI*r*r;
    C = 2*PI*r;
    V = 1.0*4/3*S*r;


    printf("圆的面积为：%f\n圆的周长为：%f\n圆的体积为：%f\n",
         S, C, V);

    return 0;
}





