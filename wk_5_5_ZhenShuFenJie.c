#include <stdio.h>

int main ()
{
    int x, y;
    int cnt = 1;
    int mask =1;
    scanf("%d", &x);
    y = x;

    while (x > 9)
    {
        x /= 10;
        cnt ++;    
        mask *= 10;
    }
    
    int i;
    while (mask > 0)
    {
        i = y / mask;
        y %= mask;
        mask /= 10;

        printf("%d", i);
        if (mask > 0)
        {
            printf("  ");
        }
    }

    printf("\n");


    return 0;
}