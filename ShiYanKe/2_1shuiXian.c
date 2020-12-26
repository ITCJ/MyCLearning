/*水仙数
下限m 上限n m<=n<=1 0000
输出所有水仙数 从小到大
判断水仙数 开始数字~结束数字
    取位
没有 No Answer
*/

#include <stdio.h>
#include <math.h>

int shuiXian(int number);

int main ()
{
    int m,n;
    int judge = 0;
    scanf("%d %d", &m, &n);
    if (n>999) n = 999;

    for (int i = m; i <= n; i++)
    {
        if (i == shuiXian(i) && i>99)
        {
            printf("%d ", i);
            judge = 1;
        }
    }
    
    if (judge == 0) printf("No Answer\n");

    return 0;
}

int shuiXian(int number)
{
    int first, second, third;
    first = number%10;
        number /= 10;
    second = number%10;
        number /= 10;
    third = number%10;
        number /= 10;

    return (pow(first,3) + pow(second,3) + pow(third,3));
}