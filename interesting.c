/*
以二进制输出八的倍数
store + 8 printf
依次增加回车行数 1 2 4

100%2 = 50%2 = 25 
*/



#include <stdio.h>

int main ()
{
    long long int store = 8;
    long long int store2 = 0;
    long long int a = 0;
    int difference = 3;
    long long int i = 1;
    long long int cache = 0;
    int number = 1, mask = 1;

    //数生成器
    for (int j = 0; j < 128; j++)
    {

        //转换二进制
        store2 = store;
        while (store2 != 0)
        {
            a = store2%2;
            a *= i;
            store2 /= 2;
            
            cache += a;
            i *= 10;
            
            if (store2 == 0)
            {
                printf("%16d", cache);
                i = 1;
                cache = 0;
            }
        }

        //换行器
        if (number%6 == 0)
        {
            printf("\n");
        }
        if (number++ == mask)
        {
            printf("\n");
            mask*=2;
            number = 1;
        }        
        store += difference;
        // number ++;
    }

    return 0;
}