#include <stdio.h>

void main ()
{
    char para[100] = {0};
    int a=0, e=0, i=0, o=0, u=0;
    int j;
    gets(para);
    for (j=0; j<100; j++)
    {
        if (para[j] == 'A' || para[j] == 'a') a++;
        if (para[j] == 'E' || para[j] == 'e') e++;
        if (para[j] == 'I' || para[j] == 'i') i++;
        if (para[j] == 'O' || para[j] == 'o') o++;
        if (para[j] == 'U' || para[j] == 'u') u++;
    }

    printf("元音a：%d个\n",a);
    printf("元音e：%d个\n",e);
    printf("元音i：%d个\n",i);
    printf("元音o：%d个\n",o);
    printf("元音u：%d个\n",u);
    printf("总元音：%d个\n",a+e+i+o+u);

}