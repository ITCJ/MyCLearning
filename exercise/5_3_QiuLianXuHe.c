/* 求a连续和

输入两个整数a和n，a的范围是[0,9]，n的范围是[1,8]，求数列之和S = a+aa+aaa+...+aaa...a（n个a）。如a为2、n为8时输出的是2+22+222+...+22222222的和。

输入格式：

输入在一行中给出两个整数，先后表示a和n。

输出格式：

在一行中输出要求的数列之和。

输入样例：
2 4
输出样例：
2468

n 递减*字面次数 
    store = n
    n--
*/
#include <stdio.h>


int main ()
{
    int a, n;
    int store;
    int sum = 0;
    int multi = 1;
    int count = 1;
    scanf("%d %d", &a, &n);

    while (n > 0)
    {   
        count = n;
        while (count > 0)
        {
            store = count;
            for (int i = 1; i < store; i++)
            {
            multi *= 10;
            }
            multi *= a; 
            sum += multi;
            multi = 1;
            count--;
        }
        n --;
    }
    printf("%d", sum);
    
    return 0;
}

//example
// #include <stdio.h>
// #include <math.h>
 
// int main()
// {
// 	int a, n, i, s = 0;
// 	scanf("%d%d", &a, &n);
// 	for(i=1; i<=n; ++i)
// 	{
// 		s += (pow(10.0,i)-1) * a / 9;
// 	}
// 	printf("%d", s);
	
// 	return 0;
// }

// 0*10+2 2*10+2 (2*10+2)*10+2
// for ( i = 0; i < n; i++)
// {
//     t = t*10 + a;
//     sum += t;
// }
