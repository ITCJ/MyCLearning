/*
    接受    math eng cs pro1 pro2
    eng > 95 100
    math || cs > 95 100
    pro1 + pro2 /2 >95 && >60 200
*/

#include <stdio.h>

int main ()
{
    int score[5] = {0};
    int judge[5] = {0};
    int price = 0;
    
    for (int i = 0; i < 5; i++)
    {
        printf("输入第%d科成绩：", i+1);
        scanf("%d", &score[i]);
        // printf("\n");

        if (score[i] > 95)
        {
            judge[i] = 1;
        }
    }
    
    if (judge[1])
    {
        price += 100;
        printf("英语奖金100\t");
    }
    
    if (judge[0] || judge[2])
    {
        price += 100;
        printf("高数或计算机奖金100\t");
    }
    
    if ( (score[3] + score[4])/2 > 95 && judge[0] && judge[1] && judge[2])
    {
        price += 200;
        printf("专业平均奖金200\t");
    }
    printf("\n");
    printf("共计%d", price);

    return 0;    
}