/*  没有重复的三位数

个位a    十位b    百位c
0-9     不等于  不等于不等于

位数
*/
#include <stdio.h>

int main () 
{
    int a, b, c;
    int result;

    int cnt = 0;
    int begin;
    int end;
    scanf("%d", &begin);
    end = begin + 3;

    // index j\k
    for (c = begin;c <= end;c++)
    {
        for ( b = begin; b <= end; b++)
        {
            for ( a = begin; a <= end; a++)
            {
                if (a != b && b != c && c !=a ) //筛选的方法
                {
                    result = a + 10*b + 100*c;  //&c result会等于0
                    printf("%d", result);
                    cnt++;

                    if (cnt < 6)
                    {
                        printf("\t");
                    }
                    else
                    {
                        printf("\n");
                        cnt = 0;
                    }
                    
                    
                }
                                
            }
            
        }
        
    }
    



    return 0;
}