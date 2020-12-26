/*
【问题描述】

编写程序将一行英文中指定的字符串替换为另一字符串后输出。注意：查找指定字符串时，大小写无关，而且有可能多次出现。

【输入形式】

先从标准输入中分行输入两个英文字符串（每个字符串不为空，长度不超过20，且字符串中不会出现空格），分别表示被替换的字符串和替换成的字符串，然后在下一行输入一行英文（长度不超过200），行末有回车换行。

【输出形式】

将输入的英文按指定字符串替换后输出到标准输出上，末尾应有一个回车换行。

【样例输入】

th
Hello
This second edition of "The C Programming Language" describes C as defined by the ANSI standard. Modern compilers already support most features of the standard.

【样例输出】

Hellois second edition of "Helloe C Programming Language" describes C as defined by Helloe ANSI standard. Modern compilers already support most features of Helloe standard.

【样例说明】

样例中输入的被替换的字符串为th，由于是大小写无关查找替换，所以下一行英文信息中有四个子串要替换：Th、Th、th和th，分别替换为Hello，其它信息原样输出。

【评分标准】该题要求编程实现指定字符串的大小写无关查找替换，提交程序文件名为exam2.c或exam2.cpp。
*/

/*
    //！ 不一定要对数组操作，只要输出即可
    读取 查找、替换、文本 数组
    对文章进行查找匹配，若匹配，输出替换文本
        逐字匹配，当相等时停止输出，进行计数
            当全部相等，输出替换，在原有的index+长度 
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char chaZhao[21] = { 0 };
    char tiHuan[21] = {0};
    char wenBen[201] = {0};
    int lenth;
    gets(chaZhao);
    gets(tiHuan);
    gets(wenBen);
    lenth = strlen(chaZhao);

    for (int i = 0; wenBen[i] != 0; i++)
    {
        int j = 0;
        int piPei = 0;
        if (wenBen[i] == chaZhao[j] || wenBen[i] == chaZhao[j]+32 || wenBen[i] +32 == chaZhao[j] || wenBen[i]+32 == chaZhao[j]+32)
        {
            while (wenBen[i + piPei] == chaZhao[j + piPei] ||
                    abs(wenBen[i + piPei] - chaZhao[j + piPei]) == 32
                    &&  wenBen[i + piPei] != 0
                    &&  chaZhao[j + piPei] != 0)
                piPei++;
        }
        

        if (piPei == lenth)
            printf("%s", tiHuan);

        i += piPei;
        
        printf("%c", wenBen[i]);
    }
    
    return 0;
}




// 网友
#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char a[20] = {0};
    char b[20] = {0};
    char c[200] = {0};

    int z;
    for (z = 0;; z++)
    {
        *(a + z) = getchar();
        if (*(a + z) == 10)
        {
            break;
        }
    }

    int x;
    for (x = 0;; x++)
    {
        *(b + x) = getchar();
        if (*(b + x) == 10)
        {

            break;
        }
    }

    int v;
    for (v = 0;; v++)
    {
        *(c + v) = getchar();
        if (*(c + v) == 10)
        {

            break;
        }
    }

    int rem = 0;
    int i, j, q, k;//循环变量
    i = 0;
    int index;
    int p = 0;//标记
    int first = 0;//从0号元素开始Print
    for (j = 0; j < strlen(c) - 1; j++)
    {
        if (a[0] == c[j] || (a[0] - c[j] == 32))
        {
            index = j;//出现a数组首字符时c字符下标
            int n = j;

            for (k = 0; k < strlen(a) - 1; k++, n++)
            {
                if (a[k] != c[n] && (a[k] - c[n] != 32))
                {
                    p = 1;
                }
            }
        }
        else
        {
            continue;
        }
        if (p == 0)
        {
            for (q = first; q < index; q++)
            {
                printf("%c", c[q]);//输出替换字符前原字符串
            }
            for (q = 0; q < strlen(b) - 1; q++)
            {
                printf("%c", b[q]);//输出替换字符串
            }
            first = index + strlen(a) - 1;
            rem = index;
        }

        p = 0;
    }
    for (i = rem + strlen(a) - 1; i < strlen(c) - 1; i++)
    {
        printf("%c", c[i]);
    }

    return 0;
}
