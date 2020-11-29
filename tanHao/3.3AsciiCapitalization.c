#include <stdio.h>

int main ()
{
    char receive;
    char gap = 'a' - 'A'; 
    //char gap = 32;

    scanf("%c", &receive);
    printf("%c", receive + gap);

    return 0;
}