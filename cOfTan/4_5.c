#include <stdio.h>
#include <math.h>

int main ()
{
    float x;
    int judge = 0;

    do
    {
        printf("请输入小于1000的正数：");
        scanf("%f", &x);
        if ( x < 1000 && x > 0)
        {
            judge = 1;
        }
        
    } while (judge != 1);
    printf("%f", sqrt(x) );

    return 0;
}