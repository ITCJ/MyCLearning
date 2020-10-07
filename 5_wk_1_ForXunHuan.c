#include <stdio.h>

int main () 
{
    //for 对于一开始定义i，当（）情况执行，结束后使得++--，
    //求和 初始化0，求积初始化1
    //for 定义在内使用， c99标准 (int i = 1; ; )

    //对求阶乘，1开始是不是没有用 1！直接跳过for循环

    int fact = 1;
    int i = 1;
    int n = 1;
    scanf("%d", &n);

    for (i = 1; i <= n; i++)  //对于定义i=2，，而n=1，不会进行，可用
    {
        fact *= i;
    }

    printf("%d!=%d\n", n, fact);
    printf("%d", i);

    //for (i = 0; i < n; i++)
    //for (i = 1; i <= n; i++) 都对循环次数有影响

    // for (;条件；)== while（条件）

    //有固定次数 for
    //必须做一次 do——thile
    //其他 while



    return 0;
}