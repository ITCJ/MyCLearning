/*
输入正整数
得到各位数字
    取10余
    除10
各位数字阶乘
    for 0~该数字
判断阶乘和是否等于该数
    是 Yes换行
    不是 No换行

【输入样例2】
 
1400
 
【输出样例2】
 
1400,1!+4!+0!+0!=27
No

*/
#include <stdio.h>
#include <stdlib.h>

int judgePowReadNumber (int readNumber);
void catchEveryNum(int everyNum[] ,int readNumber);
int fact(int input);

int main ()
{
    int readNumber;
    int* everyNum;
    int factSum = 0;
    
    scanf("%d", &readNumber);

    int num = judgePowReadNumber(readNumber);
    everyNum = (int*)malloc(num * sizeof(int));

    catchEveryNum(everyNum ,readNumber);

    for (size_t i = 0; i < num; i++)
    {
        factSum += fact(everyNum[i]);
    }

    printf("%d,", readNumber);
    for (int i = num-1 ; i >= 0 ; i--)
    {
        printf("%d!", everyNum[i]);
        if (i>0)
        {
            printf("+");
        }
    }
    printf("=%d\n", factSum);

    if (factSum == readNumber)
    {
        printf("Yes");
    }else
    {
        printf("No");
    }


    free(everyNum);
    return 0;
}

int judgePowReadNumber (int readNumber)
{
    int pow = 0;
    while (readNumber != 0)
    {
        readNumber /= 10;
        pow++;
    }

    return pow;
}

void catchEveryNum(int everyNum[] ,int readNumber)
{
    int i = 0;
    while (readNumber != 0)
    {
        everyNum[i] = readNumber%10;
        readNumber /= 10;
        
        i++;
    }

}

int fact(int input)
{
    int result = 1;
    while (input != 0)
    {
        result *= input;
        input--;        
    }
    
    return result;
}