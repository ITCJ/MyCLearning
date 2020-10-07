/*
单字符输入输出
putchar
    int putchar(int c);
    向标准输出写一个字符
    返回写了几个字符，EOF(-1)表示失败 end of fail
getchar
    int getchar(void);
    从标准输入读入一个字符
    返回类型时int为了返回EOF(-1)
        win -> ctrl+z
        unix -> ctrl+d
    键盘-shell-程序
    行编辑


字符串函数STRLEN
    string.h
    strlen strcmp strcpy 
    strcat strchr strstr

    strlen 返回s的字符串长度，不包括结尾的0
        size_t strlen(const char *s);
    
    strcmp compare 比较两个字符串
        int strcmp(const char *s1, const char *s2)
        0: s1 = s2
        1: s1>s2
        -1: s1<s2

        s1 == s2比较的是地址
        每一个s1[] - s2[]
*/
#include <stdio.h>

size_t mylen (const char* s)//strlen
{
    int cnt = 0;
    while (s[cnt] != '\0')
    {
        cnt++;
    }
}

int mycmp(const char* s1, const char* s2)
{
//常见两种方法
    
    //当作数组，用一个整数当下标
    //int idx = 0;
    // while ( 1 )
    // {
    //     if ( s1[idx] == s2[idx] )
    //     {
    //         break;
    //     }
    //     else if ( s1[idx] == '\0')
    //     {
    //         break;
    //     }
    //     idx++;
    // }
    // return s1[idx] - s2[idx];

    // while ( s1[idx] == s2[idx] && s1[idx] != '\0')
    // {
    //     // if ( s1[idx] == s2[idx] )
    //     // {
    //     //     break;
    //     // }
    //     // else if ( s1[idx] == '\0')
    //     // {
    //     //     break;
    //     // }
    //     idx++;
    // }
    
    //直接用指针
    while ( *s1 == *s2 && *s1 != '\0')
    {
        s1++;
        s2++;//两种编译器代码可能差不多
    }
    
    //return s1[idx] - s2[idx];
    return *s1 - *s2;

}

int main (int argc, char const *argv[])
{
    int ch;
    while ( (ch = getchar()) != EOF )
    {
        putchar(ch);
    }

    return 0;
}