/*
读取目标字符串
读取搜索字符串
读取原文

匹配目标字符串的四种情况
    步进指针
    每步匹配，strlen位
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
        if (wenBen[i] == chaZhao[j] || abs(wenBen[i + piPei] - chaZhao[j + piPei]) == 32 
            &&  wenBen[i + piPei] != 0
            &&  chaZhao[j + piPei] != 0)
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


// #include<stdio.h>
// #include<math.h>
// #include<string.h>
// int main()
// {
//     char a[20]={};
//     char b[20]={};
//     char c[200]={};
    
    
//     int z;
//     for (z = 0;; z++)
//     {
//         *(a + z) = getchar();
//         if (*(a + z) == 10)
//         {
//             break;
//         }
//     }

//     int x;
//     for (x = 0;; x++)
//     {
//         *(b + x) = getchar();
//         if (*(b + x) == 10)
//         {
        
//             break;
//         }
//     }

//     int v;
//     for (v = 0;; v++)
//     {
//         *(c + v) = getchar();
//         if (*(c + v) == 10)
//         {
            
//             break;
//         }
//     }
//     /*
//     gets(a);//输入字符串
//     gets(b);
//     gets(c);
//     */
    
//     int rem=0;
//     int i,j,q,k;//循环变量
//     i=0;
//     int index;
//     int p=0;//标记
//     int first=0;//从0号元素开始Print
//     for(j=0;j<strlen(c)-1;j++)
//     {
//         if(a[0]==c[j]||(a[0]-c[j]==32))
//         {
//             index=j;//出现a数组首字符时c字符下标
//             int n=j;
            
//             for(k=0;k<strlen(a)-1;k++,n++)
//             {
//                 if(a[k]!= c[n]&&(a[k]-c[n]!=32))
//                 {
//                     p=1;
//                 }
//             }
//         }
//         else
//         {
//             continue;
//         }
//         if(p==0)
//         {
//             for(q=first;q<index;q++)
//             {
//                 printf("%c",c[q]);//输出替换字符前原字符串
//             }
//             for(q=0;q<strlen(b)-1;q++)
//             {
//                 printf("%c",b[q]);//输出替换字符串
//             }
//             first=index+strlen(a)-1;
//             rem=index;
//         }
        
//         p=0;    
//     }
//     for(i=rem+strlen(a)-1;i<strlen(c)-1;i++)
//     {
//         printf("%c",c[i]);
//     }

//     return 0;
// }