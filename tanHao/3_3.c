/*
环形，保留编号
n个 排除%m 开始q 
数组 n+1
第一只开
排除
    %m 置0
下一只重开 while
判断数据是否为0 为0 则不计数%m

判断猴子是否下场
    数组编号
    新编号
    开始号
    从q开始新编号为0
        新编号%4==0 下场 
        当新编号到达n 退出循环
*/
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n, m, q;
    int quit = 0;
    scanf("%d %d %d", &n, &m, &q);
    int * monkey = (int*)malloc(n*sizeof(int));
    for (size_t i = 0; i < n; i++) //initialize
    {
        monkey[i] = 1;
    }
    
    int sum = 1;
    int i = q-1;
    while (quit != 1)
    {   
        int sum2 = 0;
        for (size_t i = 0; i < n; i++) //判断还有几个数
        {
            if (monkey[i] == 1) //切忌不要写成=，不然0又恢复了
            {
                sum2 ++;
            }
        }
        if (sum2 == 1) quit = 1; //如果只有一个数，退出

        if (monkey[i] != 0 && sum == 4)
        {
            monkey[i] = 0;
            sum = 1;
        }

        if (monkey[i] != 0)
        {
            sum += 1;
        }
        i++;
        
        i%=7;

    }
    
    // while (quit == 0)
    // {
    //     //重开起始
        
    //     for (size_t i = beginNumber; i < n; i++)
    //     {
    //         if(newNumber%m == 0 && monkey[i] !=0)
    //         {
    //             monkey[i] = 0;
    //             newNumber = 1;
    //             beginNumber = i+1;
    //         }
            
    //         if (monkey[i]!=0)
    //         {
    //             newNumber++;
    //             beginNumber %= 6;
    //         }
            
    //         if (i==n-1 && )
    //         {
    //             /* code */
    //         }
            
    //     }
        
        

    //     // int sum = 0;
    //     // for (size_t i = 0; i < n; i++) //判断还有几个数
    //     // {
    //     //     if (monkey[i] == i+1) //切忌不要写成=，不然0又恢复了
    //     //     {
    //     //         sum ++;
    //     //     }
    //     // }
    //     // if (sum == 1) quit = 1; //如果只有一个数，退出
        
    // }
    
    //print king
    for (int i = 0; i < n; i++)
    {
        if (monkey[i] != 0)
        {
            printf("%d\n", i+1);
        }
        
    }
    

    return 0;
}