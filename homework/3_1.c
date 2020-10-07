/*

接受字符
    输出ascll码
if 数字
    + 'A' - '0'
*/

#include <stdio.h>

int main ()
{
    char x;
    scanf("%c", &x);
    printf("%d\n", x);

    if ( '0'<=x && x<='9' )
    {
        printf("%c", x + 'A' - '0');
    }

    return 0;
}