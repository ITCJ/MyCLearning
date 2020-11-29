/*
读取目标字符串
读取搜索字符串
读取原文

匹配目标字符串的四种情况
    步进指针
    每步匹配，strlen位
*/

#include <stdio.h>
#include <string.h>

int main ()
{
    char replace[21];
    char search[21];
    char passage[202];
    char passageReplaced[202] = {0};
    int *p;

    scanf("%s", replace);
    scanf("%s", search);
    scanf("%s", passage);

    const int searchLen = strlen(search);
    
    int i = 0;
    int i2 = 0;
    while (passahe[i] != '0')
    {
        if (passage [i] != toupper(search[0]) && passage [i] != tolower(search[0]) )
        {
            passageReplaced[i2] = passage[i];
            i2++;
        }else
        {
            
        }
        
           
    }













    // while (passage[i] != '\0')
    // {
    //     int j = 0;
    //     int isSearch = 1;
    //     if (passage[i] == search[0])
    //     {
    //         while ( j<searchLen )
    //         {
    //             if (passage[i+j] != search[j])
    //             {
    //                 isSearch = 0;
    //             }
    //         }

    //         if (isSearch == 1)
    //         {
                
    //         }
            
    //     }
        

    //     i++;
    // }
    




    return 0;
}