//整数逆序
    //%10 得到个位
    // /10 去掉个位
    // 700 - 007 -7 
#include <stdio.h>

int main () //main mian
{
    int x = 0;
    int y = 0;
    int gewei = 0;
    scanf("%d", &x);

    while (x > 0)
    {
        gewei = x%10;
        y = y*10 + gewei; 
        x /= 10;
    }

    printf("%d", y);

    

    return 0;
}