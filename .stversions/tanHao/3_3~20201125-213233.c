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
    int newNumber = 1;
    scanf("%d %d %d", &n, &m, &q);
    int * monkey = (int*)malloc(n*sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        monkey[i] = i+1;
    }
    
    int beginNumber = q;
    while (quit == 0)
    {
        //重开起始
        for (size_t i = beginNumber; i < n; i++)
        {
            if(newNumber%m == 0 && monkey[i] !=0)
            {
                monkey[i] = 0;
                newNumber = 1;
                beginNumber = i+1;
                break;
            }
            if (monkey[i]!=0)
            {
                newNumber++;
            }
        }
        beginNumber%=n-1;

        
        int sum = 0;
        for (size_t i = 0; i < n; i++) //判断还有几个数
        {
            if (monkey[i] = i+1)
            {
                sum ++;
            }
        }
        if (sum == 1) quit = 1; //如果只有一个数，退出
        
    }
    
    for (size_t i = 0; i < n; i++)
    {
        if (monkey[i] != 0)
        {
            printf("%d\n", monkey[i]);
        }
        
    }
    

    return 0;
}