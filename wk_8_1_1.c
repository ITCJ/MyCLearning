/*
输入[0,9]整数，统计每一种数字出现次数，-1结束
*/


#include <stdio.h>

int main ()
{
    const int number = 10;  //c99 magic number! 用number换掉方便理解
    int x;
    int count[10];
    scanf("%d", &x);

    for (int i = 0; i < 10; i++) //初始化数组
    {
        count [i] = 0;
    }
    
    while (x != 1)
    {
        if (x>=0 && x<=9)
        {
            count[x] ++; //数组参与运算
        }
        scanf("%d", &x);
    }
    for (int i = 0; i < 10; i++) //遍历数组输出
    {
        printf("%d:%d", i, count[i]);
    }


    return 0;
}