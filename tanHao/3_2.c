#include<stdio.h>
#include <string.h>
/*
创建51 一维数组
读入字符 不超过50 
判断输入了多少字符
    str函数
判断是否回文
    左右i++j--
*/

int main ()
{
    char string[51];
    int lenth;
    int judge =1;
    scanf("%s", &string);

    lenth = strlen(string);

    for(int i=0, j=lenth-1; i<=j ; i++,j--)
    {
        // if (lenth == 2)
        // {
        //     if (string[0] == string[1])
        //     {
        //         judge ==1;
        //         break;
        //     }
        //     else
        //     {
        //         judge = 0;
        //         break;
        //     }
        // }
        
        if (string[i] != string[j])
        {
            judge = 0;
            break;
        }
    }

    if (judge == 1)
    {
        printf("Yes\n");
    }else
    {
        printf("No\n");
    }
    
    
    return 0;
}