//平均数
    //变量 输入的数 计数的数 加和的数
    //用-1 跳出

#include <stdio.h>

int main () 
{
    int read, count, all = 0;
    scanf("%d", &read);

    while (read != -1)
    {
        all += read;
        count++;
        scanf("%d", &read);  
    }
    
    printf("%f", 1.0*all/count);


    return 0;


}