/*
【问题描述】

一个正整数如果等于组成它的各位数字的阶乘之和，则该正整数称为阶乘和数。例如正整数145，1!+4!+5!等于145，因此145就是一个阶乘和数。输入一个正整数，计算它的各位数字的阶乘之和，并判断它是否是一个阶乘和数。注意：输入的正整数，以及组成它的各位数字的阶乘之和都不会超过int类型的表示范围，并且输入的正整数的最高位不为0。

【输入形式】

从控制台输入一个正整数。

【输出形式】

先输出输入的正整数和一个逗号“,”，并从最高位开始输出组成该正整数的各位数字的阶乘相加形式，然后输出等号“=”和各位数字阶乘之和，最后在下一行输出字符串“Yes”表示该正整数是阶乘和数，否则输出字符串“No”表示该正整数不是阶乘和数，输出Yes或No后输出回车换行符。所有输出字符之间都没有空格分隔。

【输入样例1】

145

【输出样例1】

145,1!+4!+5!=145
Yes


【输入样例2】

1400

【输出样例2】

1400,1!+4!+0!+0!=27
No

【输入样例3】

4

【输出样例3】

4,4!=24
No

【样例说明】

样例1中输入的正整数为145，组成它的各位数字的阶乘之和为145，所以145为阶乘和数。样例2中输入的正整数为1400，组成它的各位数字的阶乘之和为27，所以1400不是阶乘和数。样例3中输入的正整数为4，组成它的只有一位数字，其阶乘为24，也不是阶乘和数。

【评分标准】

该题要求判断输入的正整数是否为阶乘和数，提交程序文件名为fact.c或fact.cpp。
*/

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
//#include <stdio.h>
//#include <stdlib.h>
//
//int judgePowReadNumber(int readNumber);
//void catchEveryNum(int everyNum[], int readNumber);
//int fact(int input);
//
//int main()
//{
//    int readNumber;
//    int* everyNum;
//    int factSum = 0;
//
//    scanf("%d", &readNumber);
//
//    int num = judgePowReadNumber(readNumber);
//    everyNum = (int*)malloc(num * sizeof(int)); //动态数组
//
//    catchEveryNum(everyNum, readNumber);
//
//    for (size_t i = 0; i < num; i++)
//    {
//        factSum += fact(everyNum[i]);
//    }
//
//    printf("%d,", readNumber);
//    for (int i = num - 1; i >= 0; i--)
//    {
//        printf("%d!", everyNum[i]);
//        if (i > 0)
//        {
//            printf("+");
//        }
//    }
//    printf("=%d\n", factSum);
//
//    if (factSum == readNumber)
//    {
//        printf("Yes");
//    }
//    else
//    {
//        printf("No");
//    }
//
//
//    free(everyNum);
//    return 0;
//}
//
//int judgePowReadNumber(int readNumber) //判断输入了几位数
//{
//    int pow = 0;
//    while (readNumber != 0)
//    {
//        readNumber /= 10;
//        pow++;
//    }
//
//    return pow;
//}
//
//void catchEveryNum(int everyNum[], int readNumber)  //把每位数字记录下，其实可以和上一个函数合并
//{
//    int i = 0;
//    while (readNumber != 0)
//    {
//        everyNum[i] = readNumber % 10;
//        readNumber /= 10;
//
//        i++;
//    }
//
//}
//
//int fact(int input) //求阶乘
//{
//    int result = 1;
//    while (input != 0)
//    {
//        result *= input; //从大到小乘，直到0
//        input--;
//    }
//
//    return result;
//}