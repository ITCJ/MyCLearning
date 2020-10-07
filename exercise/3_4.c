#include <stdio.h>

int main () 
{
    int x;
    scanf("%d", &x);

    switch (x/10)
    {
        case 10:
        case 9:
            printf("A");
            break;
        case 8:
            printf("B");
        case 7:
            printf("C");
        case 6:
            printf("D");
        default:
            printf("E");
    }


return 0;
}