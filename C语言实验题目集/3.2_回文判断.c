/*
回文判断
【问题描述】
回文是正读和倒读都一样的句子。读入一个最大长度不超过50个字符的句子，判断其是否是回文。
【输入形式】
输入一个最大长度不超过50个字符的句子
【输出形式】
Yes/No
【输入样例】
abcba
【输出样例】
Yes

【样例说明】
输入abcba，判断出它是回文。
【评分标准】
该题要求输出一个判断值,答对得20分,每个测试点4分，提交程序文件名为c0604.c。
*/

#include <stdio.h>
#include <string.h>

/*
创建51 一维数组
读入字符 不超过50
判断输入了多少字符
    str函数
判断是否回文
    左右i++j--
*/

//int main()  //不难，看代码能不能写的更简洁漂亮
//{
//    char string[51];
//    int lenth;
//    int judge = 1;
//    scanf("%s", &string);
//
//    lenth = strlen(string);
//
//    for (int i = 0, j = lenth - 1; i <= j; i++, j--)
//    {
//        // if (lenth == 2)
//        // {
//        //     if (string[0] == string[1])
//        //     {
//        //         judge ==1;
//        //         break;
//        //     }
//        //     else
//        //     {
//        //         judge = 0;
//        //         break;
//        //     }
//        // }
//
//        if (string[i] != string[j])
//        {
//            judge = 0;
//            break;
//        }
//    }
//
//    if (judge == 1)
//    {
//        printf("Yes\n");
//    }
//    else
//    {
//        printf("No\n");
//    }
//
//    return 0;
//}