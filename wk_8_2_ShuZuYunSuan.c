/*
数组的集成初始化
    int a[] = {2,4,6,8,10,12,12,16,17,10,11,12,13,};
        最后的逗号留下?
            不影响结果
            用于70-80年代装13
    int a[13] = {2}; //后12个数都是0
    int a[13] = {0}; //初始化数组
集成初始化的定位
    int a[10] = {
        [0] = 2, [2] = 3, 6,
    }; //c99
    [n] 在初始化数据中给出定位
    没有定位的数据接在前面位置的后面
    其他位置初始化为0
    可以不给出数组大小，让编译器算
    特别适合数据稀疏的数组
数组的大小
    sizeof 给出整个数组所占据内容的大小，单位是字节

    sizeof (a)/sizeof(a[0])

数组的赋值
    int b[] = a;不可
    数组变量本身不能被赋值
    要将一个数组赋给另一个数组，只能遍历
遍历数组
    通常使用for循环，让循环变量i从0到<数组的长度
    常见错误
        <=数组长度
        离开循环后，继续使用i做数组元素下标
数组作为函数参数，必须利用另一个参数传入数组大小
    不能再[]中给出数组的大小
    不能利用sizeof计算数组元素个数
*/

//素数
/*
    去掉偶数，每次加2
    只需sqrt(x)
    判断是否能被已知且<x的素数整除
*/

/*
构造n以内素数表，让循环次数少
    令x = 2
    2x 3x 4x  ax<n 标记为非素数
    令x为下一个没有标记为非素数的数，重复2，直到所有
*/
#include <stdio.h>

int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes)
{
    int ret = 1;
    int i;

    for ( i = 0; i < numberOfKnownPrimes; i++)
    {
        if ( x % knownPrimes[i] == 0)
        {
            ret = 0;
            break;
        }
    }

    return ret;
}

int main ()
{
    const int number = 100;
    int prime[number] = {2};
    int count = 1;
    int i = 3;

    while ( count < number)
    {
        if ( isPrime(i, prime, count))
        {
            prime[count++] = i; //常用方法
        }
    
        {
            //大括号调试 c99直到新的定义i，c89，再一个大括号

        }
        
        i++;
    }

    for ( i=0; i<number; i++)
    {
        printf("%d", prime[i]);
        if ( (i+1)%5 ) printf("\t");
        else printf("\n");
    }
    
    return 0;
}