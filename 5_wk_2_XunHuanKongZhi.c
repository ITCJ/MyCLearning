#include <stdio.h>

int main() 
{
    int x;
    // int i;
    // int isPrime = 1;
    // scanf("%d", &x);

    for (x = 1; x <= 100; x++)
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
            printf("是素数%d\n", x);
        }
        // else
        // {
        //     printf("不是素数");
        // }
    
    }




    return 0;
}