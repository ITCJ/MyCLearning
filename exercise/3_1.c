#include <stdio.h>

int main () 
{
    int day = 0;
    scanf("%d", &day);

    if (day%5 == 0) 
    //if (x % 5 > 0 && x % 5 < 4)
    {
        printf("Drying ");
    }
    else if (day%5 <= 3)
    {
        printf("Fishing ");
    }
    else
    {
        printf("Drying ");
    }

    printf("in day %d\n", day);

    return 0;
    
}