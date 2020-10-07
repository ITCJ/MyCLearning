#include <stdio.h>

int main() 
{
    int x = 1;
    int cnt = 0;
    // int i;
    // int isPrime = 1;
    // scanf("%d", &x);

    while (cnt <50)
    {
        int i ;
        int isPrime = 1;

        for (i = 2; i < x; i++) //有break后i不能=1，只能i =2
        {
            if (x % i == 0)
            {
                isPrime = 0;
                break; //continue 跳过这一轮循环 
            }
        }
        //当x =6，多运行了很多次

        if (isPrime == 1)
        {
            cnt ++;
            printf("%d\t", x);
            if (cnt %5 == 0)
            {
                printf("\n");
            }
        }
        
    
        // else
        // {
        //     printf("不是素数");
        // }


    x++;
    }


    return 0;
}