#include <stdio.h>

int main () 
{
    int ihour, imin;
    scanf("%d:%d", &ihour, &imin);
//不能忽略12点 0 点
    if (ihour >= 12 && ihour <24)
    {
        if (ihour > 12)
        {
        ihour -= 12;
        }
        printf("%d:%d PM", ihour, imin);
    }
    else
    {
        if (ihour == 24)
        {
            ihour -= 24;
        }
        printf("%d:%d AM", ihour, imin);
    }



return 0;    

}