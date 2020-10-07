#include <stdio.h>
/* 辗转相除法
a%b a=b b=t
a   b   t
12  18  12
18  12  6
12  6   0
6   0   
*/

int main () 
{
    int a, b;
    int t;
    scanf("%d %d", &a, &b);

    while (b != 0)
    {
        t = a%b;
        a = b;
        b = t;
    }

    printf("最大公约数%d", a);



    return 0;
}