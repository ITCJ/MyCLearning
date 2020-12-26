/*
    测试机
    1001 19
    5555 55
    9999 99
    19 1001
    9999 1
    超长正整数
    A 正整数

    数组A[81]
    数组B[81]

    输入
    %10
    /10
    从低位开始80 --
        
        各位 -48计算
        相加 -96
    
*/

#include <stdio.h>

int main ()
{
    char a[81] = {0};
    int ai = 0;
    char b[81] = {0};
    int bi = 0;
    char result [81] = {0};
    int ci;

    int bigger = 1;
    int width;
    
    for(ai = 0; ai<81; ai++)
    {
        char c = getchar();
        if(c == '\n') break;
        a[ai] = c;
    }
    
    for(bi = 0; bi<81; bi++)
    {
        char c = getchar();
        if(c == '\n') break;
        b[bi] = c;
    }
    
     ai--;
     bi--;

    if (ai>bi)
    {
        ci = ai+1;
        bigger = 1;
        width = ai;
    }else
    {
        ci = bi+1;
        bigger = 0;
        width = bi;
    }

    int nextNum = 0;
    int thisNum = 0;
    while(ai>=0 && bi>=0)
    {
        thisNum = a[ai]%48 + b[bi]%48;
        result[ci] += 48 + thisNum%10 + nextNum; //确定本位数
        nextNum = thisNum/10;

        ai--;
        bi--;
        ci--;
    }
    
    while(ci>=0)
    {
        char *cache;
        if(bigger == 1) cache = a-1;
        else cache = b-1;
        
        thisNum = result[ci]%48 + cache[ci]%48 + nextNum;
        result[ci] += 48 + thisNum%10 ; //确定本位数
        nextNum = thisNum/10;

        ci--;
    }
    
    // while(ci >= 0)
    // {
    //     char *cache;
    //     if(bigger == 1) cache = a-1;
    //     else cache = b-1;
    //     result[ci] += cache[ci];
    //     ci --;
    // }

    ci = 0;
    while (result[ci] == '0')
    {
        ci++;
    }

    int limit = ci+width;
    while (ci <= limit)
    {
        printf("%c", result[ci]);
        ci++;
    }
    
    


    return 0;
}