//从多重循环中跳出
/* 可行的
printf("引号内\n",
    a, b, c);
*/

//break 和 continue 对最内层有效
//因此有 接力break
//法二 goto out； --- out；  标号是任意的 建议只在循环跳出使用

#include <stdio.h>

int main ()
{
    int x;
    scanf("%d", &x);
    int one, two, five;

    for ( one = 1; one < x*10; one++)
    {
        for ( two = 1; two < x*10; two++)
        {
            for ( five = 1; five < x*10; five++)
            {
                if (one + 2*two + 5*five == x*10)
                {
                    printf("%d个一角，%d个贰角，%d个伍角可以组成%d元", 
                    one, two, five, x);
                    goto out;
                }
                
            }
            
        }
        
    }
    out:


    return 0;
}
