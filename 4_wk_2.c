#include <stdio.h>

int main () 
{
//文字思路 核心：循环
    //人们往往考虑终止的条件
    // 随机数number
    // 次数计量count
    // count++
    // a与number的关系
    //     大
    //     等
    //     小
    srand(time(0));
    int number = rand();
    int count = 0;
    int a =0;

    
    // %100 得到100以内的数
        //printf("%d\n", a%100);
    do
    {
        printf("请随机猜出一个0~99的数：\n");
        scanf("%d", &a);

        number %= 100;
        if (a > number)
        {
            printf("你猜的大了\n");
        }
        else if (a < number)
        {
            printf("你猜的小了\n");
        }

        count ++;
    } while (a != number);
    
    printf("你猜对了,你猜了%d次\n", count);
    if (count >= 7)
    {
        printf("你个沙雕怎么猜了这么多次\n");
    }




    
return 0;





}