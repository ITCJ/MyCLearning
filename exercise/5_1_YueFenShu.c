#include <stdio.h>
/*
约分最简分式
分数可以表示为“分子/分母”的形式。编写一个程序，要求用户输入一个分数，然后将其约分为最简分式。最简分式是指分子和分母不具有可以约分的成分了。如6/12可以被约分为1/2。当分子大于分母时，不需要表达为整数又分数的形式，即11/8还是11/8；而当分子分母相等时，仍然表达为1/1的分数形式。

a = fenzi 
b = fenmu
辗转相除 c
c = a % b
a = b
b = c


*/

int main ()
{
    int fenzi, fenmu;
    int a, b, c;
    c = 1;
    scanf("%d %d", &fenzi, &fenmu);
    a = fenzi;
    b = fenmu;
    if (a > b);
    else
    {
        c = a;
        a = b;
        b = c;
    }
    
    while (c != 0)
    {
        c = a%b;
        a = b;
        b = c;
    }
    fenzi /= a;
    fenmu /= a;

    printf("%d/%d", fenzi, fenmu);

    
    return 0;
}

//example 1
	// int a, b;
	// scanf("%d/%d", &a, &b);
	// int i;
	// int min;
	// int ret;
	// if (a > b) {
	// 	min = b;
	// }
	// else {
	// 	min = a;
	// }
	// for (i = 1; i <= min; i++) {
	// 	if (a % i == 0 &&  b% i == 0) {
	// 		ret = i;
	// 	}
	// }
	// printf("%d/%d", a/ret, b/ret);

    //example 2
    // int dividend, divisor;
    // scanf("%d/%d", &dividend, &divisor);
    
    // int a = dividend;
    // int b = divisor;
    // int t;

    // while (b>0)
    // {
    //     t = a%b;
    //     a = b;
    //     b = t;
    // }
    // printf("%d/%d\n", dividend, divisor);

    // return 0;
    
