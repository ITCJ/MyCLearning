/* 念数字

输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出“fu”字。十个数字对应的拼音如下：
0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu

输入格式：
输入在一行中给出一个整数，如：1234。
提示：整数包括负数、零和正数。
输出格式：
在一行中输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。如yi er san si。

输入样例：
-600
输出样例：
fu liu ling ling

读入数字 
正负判断
分解
    count top store 
    数位数/ 
    取最高位/ 
        存最高位 
            输出语音 switch 
        去最高位%

*/
#include <stdio.h>

int main ()
{
    //int count;
    //int top;
    int reduce = 1;
    int store;
    int x;
    scanf("%d", &x);
    
    if (x < 0)
    {
        printf("fu ");
    }
    

    store = x;
    if ( store > 10 || store < -10)
    {
        while (store != 0)
        {
            store /= 10;
            reduce *= 10;
        }
        reduce /= 10;
    }

    while (reduce != 0)
    {
        store = x/reduce;
        switch (store)
        {
        case 0:
            printf("ling");
            break;
        
        case 1:
            printf("yi");
            break;
        
        case 2:
            printf("er");
            break;

        case 3:
            printf("san");
            break;

        case 4:
            printf("si");
            break;

        case 5:
            printf("wu");
            break;

        case 6:
            printf("liu");
            break;

        case 7:
            printf("qi");
            break;

        case 8:
            printf("ba");
            break;
        
        case 9:
            printf("jiu");
            break;
        }
        x %= reduce;
        reduce /= 10;
        
        if (reduce > 0)
        {
            printf(" ");
        }
        
    }
    return 0;
}

//example
// #include <stdio.h>
// #include <string.h>
// char str[20];
// const char *num[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
 
// int main()
// {
// 	int i, k;
// 	scanf("%s", str);
// 	k = strlen(str);
// 	if ( str[0] == '-') printf("fu");
// 	else 
// 		printf("%s", num[str[0]-'0']);
// 	for ( i=1; i<k; i++ )
// 	{
// 		printf(" %s", num[str[i]-'0']);
// 	}
// 	printf("\n");
 
// 	return 0;
// }